/*
 * ════════════════════════════════════════════════════════════════════
 *
 *   _|_|_|    _|_|      _|_|_|  _|_|_|  _|_|          _|_|_|
 *  _|        _|    _|  _|_|      _|    _|    _|  _|  _|
 *  _|        _|    _|      _|_|  _|    _|    _|  _|  _|
 *    _|_|_|    _|_|    _|_|_|    _|    _|    _|  _|    _|_|_|
 *
 *    _|_|_|    _|_|  _|_|_|    _|_|_|  _|_|_|    _|_|    _|    _|  _|  _|_|_|  _|_|_|  
 *  _|        _|    _|  _|    _|  _|    _|    _|  _|    _|  _|    _|  _|  _|          _|    _|  _|  
 *  _|        _|    _|  _|    _|  _|    _|    _|  _|    _|  _|    _|  _|  _|_|_|      _|    _|  _|  
 *    _|_|_|    _|_|  _|_|_|    _|_|_|  _|_|_|      _|_|    _|_|_|  _|  _|        _|_|_|  _|  _|  
 *
 * ────────────────────────────────────────────────────────────────────
 *
 *  _|_|_|  _|_|      _|_|    _|_|_|_|    _|_|_|  _|_|_|      _|_|    _|      _|_|_|
 *  _|    _|    _|  _|_|_|_|    _|      _|    _|  _|    _|  _|    _|  _|  _|  _|
 *  _|    _|    _|  _|          _|      _|    _|  _|    _|  _|    _|  _|  _|  _|
 *  _|    _|    _|    _|_|_|      _|_|    _|_|_|  _|_|_|      _|_|    _|  _|    _|_|_|
 *
 *  _|_|_|  _|_|        _|_|_|  _|_|          _|_|_|  _|  _|_|  _|    _|
 *  _|    _|    _|  _|  _|    _|    _|  _|  _|        _|_|      _|    _|
 *  _|    _|    _|  _|  _|    _|    _|  _|  _|        _|        _|    _|
 *  _|    _|    _|  _|  _|    _|    _|  _|    _|_|_|  _|          _|_|_|
 *
 * ════════════════════════════════════════════════════════════════════
 */

#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 5
#define LED_COUNT 35

const char* ssid = "metabolic_mimi";
const char* password = "11111111";

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
WebServer server(80);
DNSServer dnsServer;

const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 4, 1);

// Global parameters
uint8_t currentPattern = 0;
uint8_t globalBrightness = 128;
uint8_t globalSpeed = 50;
bool isPlaying = true;
bool patternNeedsReset = false;
unsigned long lastUpdate = 0;
uint16_t globalHueShift = 0;   // 0-65535
int32_t  globalMonoHue  = -1;  // -1=off, 0-65535=active hue
float xyX = 0.5f, xyY = 0.5f; // XY pad position 0..1
uint8_t xyBright = 0;          // XY overlay intensity, decays per frame

// Pattern state
float patternPhase = 0;
uint8_t patternState[LED_COUNT];

// LED layout: Kern (0) + Ring 1 (1-6) + Ring 2 (7-18) + Ring 3 (19-34)
// ARM_COUNT=3 represents the 3 rings; patterns loop ring by ring.
const int ARM_COUNT  = 3;
const int ARM_START[]  = {1,  7,  19};
const int ARM_LENGTH[] = {6, 12,  16};
// Arm angles spread evenly so angle-based patterns cycle across rings
const float ARM_ANGLE[] = {0, 120, 240};


// Physical LED positions — ring layout: Kern (idx 0) + 3 Ringe,
// Datenpfad Kern → Ring1 UZS → Ring2 UZS → Ring3 UZS.
// Koordinaten aus dem Bauplan (mm, 190×190mm Fläche), normalisiert 0..1.
// x=0 links, y=0 oben.
const float LED_X[35] = {
  0.500f,0.500f,0.637f,0.637f,0.500f,0.363f,0.363f,  // Kern
  0.500f,0.658f,0.774f,0.816f,0.774f,0.658f,0.500f,  // Ring 1
  0.342f,0.226f,0.184f,0.226f,0.342f,0.500f,0.674f,
  0.816f,0.916f,0.947f,0.916f,0.816f,0.674f,0.500f,
  0.332f,0.184f,0.089f,0.053f,0.089f,0.184f,0.332f
};
const float LED_Y[35] = {
  0.500f,0.342f,0.421f,0.579f,0.658f,0.579f,0.421f,  // Kern
  0.184f,0.226f,0.342f,0.500f,0.658f,0.774f,0.816f,  // Ring 1
  0.774f,0.658f,0.500f,0.342f,0.226f,0.053f,0.089f,
  0.184f,0.332f,0.500f,0.674f,0.816f,0.916f,0.947f,
  0.916f,0.816f,0.674f,0.500f,0.332f,0.184f,0.089f
};
// === Quorum Sensing tuning ===
#define QS_SECRETION   0.80f  // AI units produced per arm per tick
#define QS_DIFFUSION   0.10f  // fraction that diffuses to each neighbor per tick
#define QS_THRESHOLD   80.0f  // AI level that triggers firing
#define QS_REFRACTORY  50     // ticks an arm stays dark after firing
#define QS_QUORUM_MIN  2      // arms fired in 5-tick window that counts as Quorum

// Forward declarations
void handleRoot();
void handleSet();
void handleXY();
void handleManifest();
String getHTML();
void updatePattern();
void applyGlobalEffects();
void pattern_SolarFlare();
void pattern_OrbitalRings();
void pattern_Pinwheel();
void pattern_DataStream();
void pattern_BreathingGradient();
void pattern_Glitch();
void pattern_QuantumStates();
void pattern_SynapseFire();
void pattern_SpectralScan();
void pattern_DNAHelix_v1();
void pattern_PulseWave_v1();
void pattern_ParticleDecay_v1();
void pattern_DataStream_v1();
void pattern_BreathingGrad_v1();
void pattern_Glitch_v1();
void pattern_QuantumStates_v1();
void pattern_SynapseFire_v1();
void pattern_SpectralScan_v1();
void pattern_TuringSpot();
void pattern_SolarFlare_v2();
void pattern_QuorumSensing();
void pattern_QuorumSensing_v2();
void pattern_Bioluminescence();

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n\n=== METABOLIC MIMICRY STARTING ===");
  
  // Initialize NeoPixel
  strip.begin();
  strip.setBrightness(globalBrightness);
  strip.fill(strip.Color(0, 255, 0));
  strip.show();
  
  // Disconnect from any previous WiFi
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  delay(500);
  WiFi.mode(WIFI_AP);
  delay(500);
  
  Serial.println("Starting Access Point...");
  
  // Configure AP
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(ssid, password);
  delay(500);
  
  // Start DNS Server (captive portal)
  dnsServer.start(DNS_PORT, "*", apIP);
  
  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());
  
  strip.fill(strip.Color(0, 0, 255));
  strip.show();
  
  // Setup server routes
  server.onNotFound(handleRoot);
  server.on("/", HTTP_GET, handleRoot);
  server.on("/set", HTTP_GET, handleSet);
  server.on("/manifest.json", HTTP_GET, handleManifest);
  server.on("/generate_204", HTTP_GET, handleRoot);
  server.on("/fwlink", HTTP_GET, handleRoot);
  server.on("/xy", HTTP_GET, handleXY);
  
  server.begin();
  Serial.println("Server Started!");
  
  strip.fill(strip.Color(255, 255, 255));
  strip.show();
  delay(500);
  strip.clear();
  strip.show();
}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
  
  unsigned long currentTime = millis();
  unsigned long interval = (unsigned long)(500.0 * pow(0.004, globalSpeed / 100.0));
  
  if (isPlaying && currentTime - lastUpdate >= interval) {
    lastUpdate = currentTime;
    updatePattern();
    applyGlobalEffects();
    strip.setBrightness(globalBrightness);
    strip.show();
  }
}

void handleRoot() {
  server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate");
  server.sendHeader("Pragma", "no-cache");
  server.sendHeader("Expires", "-1");
  server.send(200, "text/html", getHTML());
}

void handleManifest() {
  String manifest = "{";
  manifest += "\"name\":\"Metabolic Mimicry\",";
  manifest += "\"short_name\":\"Metabolic\",";
  manifest += "\"start_url\":\"/\",";
  manifest += "\"display\":\"standalone\",";
  manifest += "\"background_color\":\"#000000\",";
  manifest += "\"theme_color\":\"#000000\",";
  manifest += "\"orientation\":\"portrait\",";
  manifest += "\"icons\":[{";
  manifest += "\"src\":\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 512 512'%3E%3Crect width='512' height='512' fill='%23000'/%3E%3Ctext x='256' y='280' font-size='200' text-anchor='middle' fill='%23ffff00' font-family='monospace'%3EM%3C/text%3E%3C/svg%3E\",";
  manifest += "\"sizes\":\"512x512\",";
  manifest += "\"type\":\"image/svg+xml\"";
  manifest += "}]";
  manifest += "}";
  server.send(200, "application/json", manifest);
}

void handleSet() {
  if (server.hasArg("pattern")) {
    currentPattern = server.arg("pattern").toInt();
    patternPhase = 0;
    patternNeedsReset = true;
    memset(patternState, 0, sizeof(patternState));
  }
  if (server.hasArg("speed")) {
    globalSpeed = server.arg("speed").toInt();
  }
  if (server.hasArg("brightness")) {
    globalBrightness = server.arg("brightness").toInt();
  }
  if (server.hasArg("hueshift")) {
    globalHueShift = (uint16_t)((server.arg("hueshift").toInt() * 65535L) / 359);
  }
  if (server.hasArg("monohue")) {
    int v = server.arg("monohue").toInt();
    globalMonoHue = (v == 0) ? -1L : (int32_t)(((v - 1) * 65535L) / 359);
  }
  if (server.hasArg("action")) {
    String action = server.arg("action");
    if (action == "play") isPlaying = true;
    else if (action == "pause") isPlaying = false;
    else if (action == "reset") {
      patternPhase = 0;
      patternNeedsReset = true;
      memset(patternState, 0, sizeof(patternState));
    }
    else if (action == "next") {
      currentPattern = (currentPattern + 1) % 23;
      patternPhase = 0;
      patternNeedsReset = true;
      memset(patternState, 0, sizeof(patternState));
    }
    else if (action == "prev") {
      currentPattern = (currentPattern == 0) ? 22 : currentPattern - 1;
      patternPhase = 0;
      patternNeedsReset = true;
      memset(patternState, 0, sizeof(patternState));
    }
  }
  server.send(200, "text/plain", "OK");
}

void handleXY() {
  if (server.hasArg("x")) xyX = constrain(server.arg("x").toInt(), 0, 100) / 100.0f;
  if (server.hasArg("y")) xyY = constrain(server.arg("y").toInt(), 0, 100) / 100.0f;
  xyBright = 255;
  server.send(200, "text/plain", "OK");
}

void updatePattern() {
  patternPhase += 0.05;
  
  switch(currentPattern) {
    case 0: pattern_SolarFlare(); break;
    case 1: pattern_OrbitalRings(); break;
    case 2: pattern_Pinwheel(); break;
    case 3: pattern_DataStream(); break;
    case 4: pattern_BreathingGradient(); break;
    case 5: pattern_Glitch(); break;
    case 6: pattern_QuantumStates(); break;
    case 7: pattern_SynapseFire(); break;
    case 8: pattern_SpectralScan(); break;
    case 9:  pattern_DNAHelix_v1(); break;
    case 10: pattern_PulseWave_v1(); break;
    case 11: pattern_ParticleDecay_v1(); break;
    case 12: pattern_DataStream_v1(); break;
    case 13: pattern_BreathingGrad_v1(); break;
    case 14: pattern_Glitch_v1(); break;
    case 15: pattern_QuantumStates_v1(); break;
    case 16: pattern_SynapseFire_v1(); break;
    case 17: pattern_SpectralScan_v1(); break;
    case 18: pattern_SolarFlare_v2(); break;
    case 19: pattern_QuorumSensing(); break;
    case 20: pattern_QuorumSensing_v2(); break;
    case 21: pattern_Bioluminescence(); break;
    case 22: pattern_TuringSpot(); break;
  }
  patternNeedsReset = false;
}

// Pattern 0: Blackout — alle LEDs aus, nur XY-Pad als Lichtquelle
void pattern_SolarFlare() {
  strip.clear();
}

// Pattern 18: Solar Flare — arms fire outward in sequence like solar prominences
void pattern_SolarFlare_v2() {
  float t = patternPhase * 0.6;
  int activeArm = (int)t % ARM_COUNT;
  float fireProgress = fmod(t, 1.0);

  strip.clear();
  float centerGlow = (sin(patternPhase * 2) + 1.0) / 2.0;
  strip.setPixelColor(0, strip.Color(255, (uint8_t)(80 * centerGlow), 0));

  for(int a = 0; a < ARM_COUNT; a++) {
    int age = (activeArm - a + ARM_COUNT) % ARM_COUNT;
    for(int i = 0; i < ARM_LENGTH[a]; i++) {
      int idx = ARM_START[a] + i;
      float armFrac = i / (float)(ARM_LENGTH[a] - 1);
      if(a == activeArm) {
        float dist = fireProgress - armFrac;
        if(dist >= 0 && dist < 0.5) {
          float intensity = 1.0 - dist / 0.5;
          strip.setPixelColor(idx, strip.Color((uint8_t)(255 * intensity), (uint8_t)(100 * intensity * (1.0 - armFrac)), 0));
        }
      } else {
        float fade = 1.0 - age / (float)ARM_COUNT;
        if(fade > 0.05) {
          uint8_t val = (uint8_t)(fade * fade * 40);
          strip.setPixelColor(idx, strip.Color(val, val / 4, 0));
        }
      }
    }
  }
}

// Pattern 1: Orbital Rings — concentric rings pulse outward in sequence
void pattern_OrbitalRings() {
  const int maxLen = 7;
  strip.clear();

  float centerPulse = (sin(patternPhase * 1.5) + 1.0) / 2.0;
  strip.setPixelColor(0, strip.ColorHSV((uint16_t)(patternPhase * 2000) % 65536, 200, (uint8_t)(centerPulse * 255)));

  for(int ring = 0; ring < maxLen; ring++) {
    float ringPhase = patternPhase - ring * 0.5;
    float pulse = (sin(ringPhase * 1.5) + 1.0) / 2.0;
    uint16_t hue = ((uint16_t)(patternPhase * 1500) + ring * 8192) % 65536;
    for(int a = 0; a < ARM_COUNT; a++) {
      if(ring < ARM_LENGTH[a]) {
        strip.setPixelColor(ARM_START[a] + ring, strip.ColorHSV(hue, 255, (uint8_t)(pulse * 255)));
      }
    }
  }
}

// Pattern 2: Pinwheel — hue spins angularly like a color wheel
void pattern_Pinwheel() {
  uint16_t rotation = (uint16_t)(patternPhase * 3000) % 65536;
  strip.setPixelColor(0, strip.ColorHSV(rotation, 80, 200));

  for(int a = 0; a < ARM_COUNT; a++) {
    uint16_t armHue = (rotation + (uint16_t)(a * 8192)) % 65536;
    for(int i = 0; i < ARM_LENGTH[a]; i++) {
      float brightness = 0.3 + 0.7 * (i + 1.0) / ARM_LENGTH[a];
      strip.setPixelColor(ARM_START[a] + i, strip.ColorHSV(armHue, 255, (uint8_t)(brightness * 255)));
    }
  }
}

// Pattern 3: Bloom — center opens outward arm by arm like a flower
void pattern_DataStream() {
  float t = patternPhase * 0.4;
  float openFrac = fmod(t, 1.0);
  int leadArm = (int)t % ARM_COUNT;

  strip.clear();
  float centerBrightness = (sin(patternPhase * 1.2) + 1.0) / 2.0;
  uint16_t centerHue = (uint16_t)(patternPhase * 800) % 65536;
  strip.setPixelColor(0, strip.ColorHSV(centerHue, 180, (uint8_t)(centerBrightness * 255)));

  for(int a = 0; a < ARM_COUNT; a++) {
    int offset = (a - leadArm + ARM_COUNT) % ARM_COUNT;
    float armDelay = offset / (float)ARM_COUNT;
    float armOpen = openFrac - armDelay;
    if(armOpen < 0) armOpen += 1.0;
    float armFrac = constrain(armOpen * 2.0, 0.0, 1.0);

    uint16_t hue = (centerHue + (uint16_t)(a * 4096)) % 65536;
    int litCount = (int)(armFrac * ARM_LENGTH[a]);
    for(int i = 0; i < ARM_LENGTH[a]; i++) {
      if(i < litCount) {
        float b = 0.4 + 0.6 * (i + 1.0) / ARM_LENGTH[a];
        strip.setPixelColor(ARM_START[a] + i, strip.ColorHSV(hue, 255, (uint8_t)(b * 255)));
      }
    }
  }
}

// Pattern 4: Pulsar — opposite arm pairs fire alternately, rotating
void pattern_BreathingGradient() {
  float t = patternPhase * 1.2;
  int activePair = (int)(t * 0.5) % 4;
  float pairPhase = fmod(t, 1.0);
  float pulse = sin(pairPhase * PI);
  if(pulse < 0) pulse = 0;

  strip.clear();
  uint16_t hue = (uint16_t)(patternPhase * 1200) % 65536;
  strip.setPixelColor(0, strip.ColorHSV(hue, 100, (uint8_t)(pulse * 200)));

  for(int a = 0; a < ARM_COUNT; a++) {
    int pair = a % 4;
    bool isActive = (pair == activePair);
    float brightness = isActive ? pulse : pulse * 0.08;
    uint16_t armHue = isActive ? hue : (hue + 32768) % 65536;
    for(int i = 0; i < ARM_LENGTH[a]; i++) {
      float falloff = 1.0 - i / (float)ARM_LENGTH[a] * 0.5;
      strip.setPixelColor(ARM_START[a] + i, strip.ColorHSV(armHue, 255, (uint8_t)(brightness * falloff * 255)));
    }
  }
}

// Pattern 5: Wormhole — tips implode to center then explode outward
void pattern_Glitch() {
  float cycle = fmod(patternPhase * 0.5, 1.0);
  bool imploding = cycle < 0.5;
  float progress = imploding ? cycle * 2.0 : (cycle - 0.5) * 2.0;

  strip.clear();
  uint16_t hue = (uint16_t)(patternPhase * 2000) % 65536;

  if(imploding) {
    float centerPulse = progress * progress;
    strip.setPixelColor(0, strip.ColorHSV(hue, 255, (uint8_t)(centerPulse * 255)));
    for(int a = 0; a < ARM_COUNT; a++) {
      for(int i = 0; i < ARM_LENGTH[a]; i++) {
        float armFrac = i / (float)(ARM_LENGTH[a] - 1);
        float threshold = 1.0 - progress;
        if(armFrac >= threshold) {
          float intensity = (armFrac - threshold) / (1.0 - threshold);
          uint16_t h = (hue + (uint16_t)(i * 3000)) % 65536;
          strip.setPixelColor(ARM_START[a] + i, strip.ColorHSV(h, 255, (uint8_t)(intensity * 255)));
        }
      }
    }
  } else {
    strip.setPixelColor(0, strip.ColorHSV(hue, 255, (uint8_t)((1.0 - progress) * 255)));
    for(int a = 0; a < ARM_COUNT; a++) {
      for(int i = 0; i < ARM_LENGTH[a]; i++) {
        float armFrac = i / (float)(ARM_LENGTH[a] - 1);
        if(armFrac <= progress) {
          float intensity = 1.0 - armFrac;
          uint16_t h = (hue + (uint16_t)(i * 3000)) % 65536;
          strip.setPixelColor(ARM_START[a] + i, strip.ColorHSV(h, 255, (uint8_t)(intensity * 255)));
        }
      }
    }
  }
}

// Pattern 6: Compass — single glowing arm sweeps around like a radar/compass needle
void pattern_QuantumStates() {
  float angle = fmod(patternPhase * 0.8, TWO_PI);
  float angleDeg = angle * 180.0 / PI;

  strip.clear();
  uint16_t hue = (uint16_t)(patternPhase * 1000) % 65536;
  strip.setPixelColor(0, strip.ColorHSV(hue, 60, 180));

  for(int a = 0; a < ARM_COUNT; a++) {
    float diff = fabs(ARM_ANGLE[a] - angleDeg);
    if(diff > 180.0) diff = 360.0 - diff;
    float proximity = constrain(1.0 - diff / 60.0, 0.0, 1.0);
    bool isActive = diff < 22.5;

    for(int i = 0; i < ARM_LENGTH[a]; i++) {
      float radialBrightness = (i + 1.0) / ARM_LENGTH[a];
      uint8_t val;
      if(isActive) {
        val = (uint8_t)(radialBrightness * 255);
        strip.setPixelColor(ARM_START[a] + i, strip.ColorHSV(hue, 200, val));
      } else {
        val = (uint8_t)(proximity * proximity * radialBrightness * 60);
        strip.setPixelColor(ARM_START[a] + i, strip.ColorHSV((hue + 16384) % 65536, 255, val));
      }
    }
  }
}

// Pattern 7: Cosmic Web — random arms fire as synaptic bursts, decay per arm
void pattern_SynapseFire() {
  static uint8_t armState[8] = {0};
  static uint8_t armHues[8] = {0};

  if(patternNeedsReset) {
    memset(armState, 0, sizeof(armState));
    memset(armHues, 0, sizeof(armHues));
  }

  int phaseInt = (int)(patternPhase * 20);
  if(phaseInt % 6 == 0) {
    int a = random(ARM_COUNT);
    if(armState[a] == 0) {
      armState[a] = 255;
      armHues[a] = random(256);
    }
  }

  strip.clear();
  uint8_t centerVal = 0;
  for(int a = 0; a < ARM_COUNT; a++) centerVal = max(centerVal, armState[a]);
  strip.setPixelColor(0, strip.ColorHSV((uint16_t)centerVal * 256, 180, centerVal / 2));

  for(int a = 0; a < ARM_COUNT; a++) {
    if(armState[a] > 0) {
      uint16_t h = (uint16_t)armHues[a] * 256;
      for(int i = 0; i < ARM_LENGTH[a]; i++) {
        float radialFade = 1.0 - i / (float)ARM_LENGTH[a] * 0.4;
        strip.setPixelColor(ARM_START[a] + i, strip.ColorHSV(h, 255, (uint8_t)(armState[a] * radialFade)));
      }
      if(armState[a] > 12) armState[a] -= 12;
      else armState[a] = 0;
    }
  }
}

// Pattern 8: Gravity Well — center is brightest, brightness falls off radially outward
void pattern_SpectralScan() {
  float breath = (sin(patternPhase * 0.7) + 1.0) / 2.0;
  float pulse  = (sin(patternPhase * 2.3) + 1.0) / 2.0;
  uint16_t hue = (uint16_t)(patternPhase * 600) % 65536;

  uint8_t centerVal = (uint8_t)(180 + 75 * pulse);
  strip.setPixelColor(0, strip.ColorHSV(hue, 80, centerVal));

  for(int a = 0; a < ARM_COUNT; a++) {
    for(int i = 0; i < ARM_LENGTH[a]; i++) {
      float dist = (i + 1.0) / ARM_LENGTH[a];
      float gravity = (1.0 - dist) * (1.0 - dist);
      float wave = (sin(patternPhase * 1.5 - dist * 3.0) + 1.0) / 2.0;
      float brightness = gravity * (0.6 + 0.4 * wave) * breath;
      uint16_t armHue = (hue + (uint16_t)(dist * 8192)) % 65536;
      strip.setPixelColor(ARM_START[a] + i, strip.ColorHSV(armHue, 220, (uint8_t)(brightness * 255)));
    }
  }
}

// Classic patterns v1 (original 0–8, now at indices 9–17)
void pattern_DNAHelix_v1() {
  for(int i = 0; i < LED_COUNT; i++) {
    float angle = (i * 0.5) + patternPhase;
    float wave1 = sin(angle);
    float wave2 = sin(angle + PI);
    uint8_t r = wave1 > 0.5 ? 255 : 0;
    uint8_t g = wave2 > 0.5 ? 255 : 0;
    strip.setPixelColor(i, strip.Color(r, g, 80));
  }
}

void pattern_PulseWave_v1() {
  int center = LED_COUNT / 2;
  float pulse = abs(sin(patternPhase));
  for(int i = 0; i < LED_COUNT; i++) {
    float distance = abs(i - center) / (float)center;
    uint8_t value = pulse * (1.0 - distance) * 255;
    strip.setPixelColor(i, strip.Color(value, value, value));
  }
}

void pattern_ParticleDecay_v1() {
  int phaseInt = (int)(patternPhase * 10);
  if (phaseInt % 30 == 0) patternState[random(LED_COUNT)] = 255;
  for(int i = 0; i < LED_COUNT; i++) {
    if (patternState[i] > 10) patternState[i] -= 10; else patternState[i] = 0;
    uint16_t hue = ((i * 14) % 255) * 256;
    strip.setPixelColor(i, strip.ColorHSV(hue, 255, patternState[i]));
  }
}

void pattern_DataStream_v1() {
  int offset = (int)patternPhase % LED_COUNT;
  for(int i = 0; i < LED_COUNT; i++) {
    int pos = (i + offset) % LED_COUNT;
    if ((pos % 3) == 0) strip.setPixelColor(i, strip.Color(0, 255, 200));
    else strip.setPixelColor(i, strip.Color(0, 0, 20));
  }
}

void pattern_BreathingGrad_v1() {
  float breath = (sin(patternPhase * 0.5) + 1.0) / 2.0;
  for(int i = 0; i < LED_COUNT; i++) {
    float pos = i / (float)LED_COUNT;
    strip.setPixelColor(i, strip.Color(
      (uint8_t)(pos * 255 * breath),
      (uint8_t)((1.0 - pos) * 128 * breath),
      (uint8_t)((128 + pos * 127) * breath)));
  }
}

void pattern_Glitch_v1() {
  int phaseInt = (int)(patternPhase * 20);
  if (phaseInt % 10 == 0) {
    for(int i = 0; i < LED_COUNT; i++)
      if (random(100) < 30) patternState[i] = random(2);
  }
  for(int i = 0; i < LED_COUNT; i++) {
    if (patternState[i] == 1) strip.setPixelColor(i, strip.Color(255, 0, 255));
    else strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
}

void pattern_QuantumStates_v1() {
  for(int i = 0; i < LED_COUNT; i++) {
    float state = sin(patternPhase + i * 0.3);
    strip.setPixelColor(i, strip.Color(
      state > 0 ? 255 : 0,
      state < 0 ? 255 : 0,
      abs(state) < 0.3 ? 255 : 0));
  }
}

void pattern_SynapseFire_v1() {
  int phaseInt = (int)(patternPhase * 15);
  if (phaseInt % 8 == 0) {
    int start = random(LED_COUNT - 4);
    for(int i = 0; i < 4; i++) patternState[start + i] = 255;
  }
  for(int i = 0; i < LED_COUNT; i++) {
    if (patternState[i] > 15) patternState[i] -= 15; else patternState[i] = 0;
    strip.setPixelColor(i, strip.Color(patternState[i], patternState[i] / 2, 0));
  }
}

void pattern_SpectralScan_v1() {
  int scanPos = (int)(patternPhase * 2) % LED_COUNT;
  for(int i = 0; i < LED_COUNT; i++) {
    int d = abs(i - scanPos);
    if (d == 0) strip.setPixelColor(i, strip.Color(255, 255, 255));
    else if (d < 3) {
      int hueInt = (int)(patternPhase * 1000) % 65535;
      strip.setPixelColor(i, strip.ColorHSV(hueInt, 255, (3 - d) * 85));
    } else strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
}

// Pattern 19: Quorum Sensing — biological autoinducer simulation
// Each arm accumulates AI (autoinducer) per tick. Neighbors diffuse AI to each
// other. When an arm's AI exceeds QS_THRESHOLD it fires, resets to 0, and enters
// refractory. When QS_QUORUM_MIN arms fire within a 5-tick window → Quorum event.
void pattern_QuorumSensing() {
  static float   ai[ARM_COUNT]    = {0};   // autoinducer level 0.0–255.0
  static int16_t refr[ARM_COUNT]  = {0};   // refractory countdown (0 = ready)
  static uint8_t flash[ARM_COUNT] = {0};   // firing flash brightness 255→0
  static int16_t quorumFlash      = 0;     // center quorum explosion countdown
  static uint8_t fireBuf[5]       = {0};   // ring buffer: fired-arm bitmask per tick
  static uint8_t fireBufIdx       = 0;

  if (patternNeedsReset) {
    for (int a = 0; a < ARM_COUNT; a++) {
      ai[a]    = (float)random(0, 55);     // wide spread → instant staggered cascade
      refr[a]  = 0;
      flash[a] = 0;
    }
    quorumFlash = 0;
    memset(fireBuf, 0, sizeof(fireBuf));
    fireBufIdx = 0;
  }

  // ── SIMULATION ─────────────────────────────────────────────────────────────

  // 1. Secretion + neighbor diffusion (skip refractory arms)
  float newAI[ARM_COUNT];
  for (int a = 0; a < ARM_COUNT; a++) {
    if (refr[a] > 0) { newAI[a] = 0; continue; }
    int prev = (a + ARM_COUNT - 1) % ARM_COUNT;
    int next = (a + 1) % ARM_COUNT;
    float recv = 0;
    if (refr[prev] == 0) recv += ai[prev] * QS_DIFFUSION;
    if (refr[next] == 0) recv += ai[next] * QS_DIFFUSION;
    float loss = ai[a] * QS_DIFFUSION * 2.0f;
    float sec = QS_SECRETION * (0.80f + random(0, 40) / 100.0f); // biological noise
    newAI[a] = constrain(ai[a] + sec + recv - loss, 0.0f, 255.0f);
  }

  // 2. Fire check — arm crosses threshold
  uint8_t firedThisTick = 0;
  for (int a = 0; a < ARM_COUNT; a++) {
    if (refr[a] > 0) {
      refr[a]--;
    } else if (newAI[a] >= QS_THRESHOLD) {
      refr[a]  = QS_REFRACTORY;
      newAI[a] = 0;
      flash[a] = 255;
      firedThisTick |= (1 << a);
    }
    ai[a] = newAI[a];
  }

  // 3. Quorum detection via 5-tick sliding window bitmask ring buffer
  fireBufIdx = (fireBufIdx + 1) % 5;
  fireBuf[fireBufIdx] = firedThisTick;
  uint8_t allRecent = fireBuf[0] | fireBuf[1] | fireBuf[2] | fireBuf[3] | fireBuf[4];
  uint8_t recentCount = 0;
  for (uint8_t b = allRecent; b; b >>= 1) recentCount += (b & 1);
  if (firedThisTick && recentCount >= QS_QUORUM_MIN && quorumFlash <= 0) {
    quorumFlash = 120;
  }

  // ── RENDER ─────────────────────────────────────────────────────────────────
  strip.clear();

  // Center: Quorum explosion (white→warm) or ambient glow from avg AI
  if (quorumFlash > 0) {
    float q  = quorumFlash / 120.0f;
    uint8_t w  = (uint8_t)(q * q * 255);
    uint8_t wb = (uint8_t)(q * 180);
    strip.setPixelColor(0, strip.Color(w, wb, (uint8_t)(wb * 0.4f)));
    quorumFlash--;
  } else {
    float avgAI = 0;
    for (int a = 0; a < ARM_COUNT; a++) avgAI += ai[a];
    avgAI /= ARM_COUNT;
    float frac = constrain(avgAI / QS_THRESHOLD, 0.0f, 1.0f);
    float cCurve = frac * frac;
    float cFlicker = 1.0f + (random(-80, 80) / 100.0f) * (1.0f - frac * 0.8f) * 0.15f;
    uint8_t cBright = (uint8_t)(constrain(cCurve * cFlicker * 110.0f, 0.0f, 110.0f));
    strip.setPixelColor(0, strip.ColorHSV(4800, 210, cBright));
  }

  // Arms
  for (int a = 0; a < ARM_COUNT; a++) {

    if (flash[a] > 0) {
      // ── FIRING: ignition front sweeps root→tip in ~0.7s ──
      float flashFrac = flash[a] / 255.0f;         // 1.0→0.0
      float progress  = 1.0f - flashFrac;          // 0.0=root, 1.0=tip
      for (int i = 0; i < ARM_LENGTH[a]; i++) {
        float radPos = i / (float)(ARM_LENGTH[a] - 1);
        float d = progress - radPos;  // <0=ahead of front, >0=behind
        uint8_t r, g, b;
        if (d < 0.0f) {
          // Ahead of front: arm still at peak charge — hot white-yellow
          // Seamless continuation of sub-quorum blazing state, no bruch
          r = 255; g = 200; b = 50;
        } else if (d < 0.28f) {
          // Ignition front itself: brief blinding white spike
          float f = 1.0f - d / 0.28f;
          r = 255;
          g = (uint8_t)(200 + f * 55);
          b = (uint8_t)(f * 180);
        } else {
          // Wake: orange embers, collapse quadratically as flash drains
          float wake = constrain(1.0f - (d - 0.28f) / 0.72f, 0.0f, 1.0f);
          wake *= flashFrac * flashFrac;
          r = (uint8_t)(wake * 240);
          g = (uint8_t)(wake * 55);
          b = 0;
        }
        strip.setPixelColor(ARM_START[a] + i, strip.Color(r, g, b));
      }
      if (flash[a] > 12) flash[a] -= 12; else flash[a] = 0;

    } else if (refr[a] > 0) {
      // ── REFRACTORY: cool blue-indigo, squared decay ──
      float f = refr[a] / (float)QS_REFRACTORY;
      uint8_t v = (uint8_t)(f * 80);
      for (int i = 0; i < ARM_LENGTH[a]; i++) {
        strip.setPixelColor(ARM_START[a] + i, strip.ColorHSV(43500, 255, v));
      }

    } else {
      // ── SUB-QUORUM: tension curve — dark + flicker early, blazing near threshold ──
      float aiFrac = constrain(ai[a] / QS_THRESHOLD, 0.0f, 1.0f);
      // Power curve: stays almost invisible until ~60%, then explosive brightening
      float curve = powf(aiFrac, 2.5f);
      // Flicker amplitude: strong when dim, steadies as arm locks in near threshold
      float flickerAmp = (1.0f - aiFrac * 0.85f) * 0.22f;
      curve *= constrain(1.0f + (random(-100, 100) / 100.0f) * flickerAmp, 0.1f, 2.0f);
      curve = constrain(curve, 0.0f, 1.0f);
      // Color heats: deep amber → hot yellow-white as AI peaks
      uint16_t armHue = (uint16_t)(4600 + aiFrac * 900);
      uint8_t  armSat = (uint8_t)(240 - aiFrac * 65);
      for (int i = 0; i < ARM_LENGTH[a]; i++) {
        float rootBias = 1.0f - (i / (float)ARM_LENGTH[a]) * 0.60f;
        uint8_t v = (uint8_t)(curve * rootBias * 245);
        strip.setPixelColor(ARM_START[a] + i, strip.ColorHSV(armHue, armSat, v));
      }
    }
  }
}

// Pattern 20: Quorum Sensing v2 — distinct arms, individual metabolism
// Each arm has a unique secretion rate assigned at reset (0.5×–2.0×).
// This creates genuine temporal asymmetry: arms fire solo, never in unison.
// Tension curve: tiny constant ember → near-invisible buildup → explosive ignition.
// Long dark refractory. Short punchy flash. Arms are recognizable individuals.
void pattern_QuorumSensing_v2() {
  static float   ai[ARM_COUNT]      = {0};
  static float   armRate[ARM_COUNT] = {0};  // per-arm secretion multiplier, set at reset
  static int16_t refr[ARM_COUNT]    = {0};
  static uint8_t flash[ARM_COUNT]   = {0};
  static int16_t quorumFlash        = 0;
  static uint8_t fireBuf[5]         = {0};
  static uint8_t fireBufIdx         = 0;

  const float THRESHOLD  = 100.0f;
  const float BASE_SEC   = 1.2f;
  const float DIFFUSION  = 0.04f;  // low diffusion → arms stay independent
  const int   REFRACTORY = 80;     // long dark window: ~2.5s at speed=50

  if (patternNeedsReset) {
    for (int a = 0; a < ARM_COUNT; a++) {
      armRate[a] = 0.50f + random(0, 151) / 100.0f;          // 0.50 → 2.00
      ai[a]      = (float)random(0, (int)(THRESHOLD * 0.5f)); // staggered starts
      refr[a]    = 0;
      flash[a]   = 0;
    }
    quorumFlash = 0;
    memset(fireBuf, 0, sizeof(fireBuf));
    fireBufIdx  = 0;
  }

  // ── SIMULATION ──────────────────────────────────────────────────────────────
  float newAI[ARM_COUNT];
  for (int a = 0; a < ARM_COUNT; a++) {
    if (refr[a] > 0) { newAI[a] = 0; continue; }
    int prev = (a + ARM_COUNT - 1) % ARM_COUNT;
    int next = (a + 1)             % ARM_COUNT;
    float recv = 0;
    if (refr[prev] == 0) recv += ai[prev] * DIFFUSION;
    if (refr[next] == 0) recv += ai[next] * DIFFUSION;
    float loss = ai[a] * DIFFUSION * 2.0f;
    float sec  = BASE_SEC * armRate[a] * (0.85f + random(0, 30) / 100.0f);
    newAI[a]   = constrain(ai[a] + sec + recv - loss, 0.0f, 255.0f);
  }

  uint8_t firedThisTick = 0;
  for (int a = 0; a < ARM_COUNT; a++) {
    if (refr[a] > 0) {
      refr[a]--;
    } else if (newAI[a] >= THRESHOLD) {
      refr[a]  = REFRACTORY;
      newAI[a] = 0;
      flash[a] = 255;
      firedThisTick |= (1 << a);
    }
    ai[a] = newAI[a];
  }

  // Quorum: 5+ distinct arms fired in last 5-tick window
  fireBufIdx = (fireBufIdx + 1) % 5;
  fireBuf[fireBufIdx] = firedThisTick;
  uint8_t allRecent  = fireBuf[0]|fireBuf[1]|fireBuf[2]|fireBuf[3]|fireBuf[4];
  uint8_t recentCnt  = 0;
  for (uint8_t bm = allRecent; bm; bm >>= 1) recentCnt += (bm & 1);
  if (firedThisTick && recentCnt >= 2 && quorumFlash <= 0) quorumFlash = 100;

  // ── RENDER ──────────────────────────────────────────────────────────────────
  strip.clear();

  // Center: quorum burst or average-charge ember
  if (quorumFlash > 0) {
    float q = quorumFlash / 100.0f;
    strip.setPixelColor(0, strip.Color(
      (uint8_t)(q * q * 255), (uint8_t)(q * 160), (uint8_t)(q * 40)));
    quorumFlash--;
  } else {
    float avgAI = 0;
    for (int a = 0; a < ARM_COUNT; a++) avgAI += ai[a];
    avgAI /= ARM_COUNT;
    float cf = powf(constrain(avgAI / THRESHOLD, 0.0f, 1.0f), 2.0f);
    strip.setPixelColor(0, strip.ColorHSV(4800, 220, (uint8_t)(cf * 85)));
  }

  // Arms
  for (int a = 0; a < ARM_COUNT; a++) {

    if (flash[a] > 0) {
      // ── FIRING: fast crisp wavefront, short wake ──────────────────────────
      float ff = flash[a] / 255.0f;   // 1.0→0.0  (total: ~14 ticks ≈ 0.45s)
      float pr = 1.0f - ff;           // wavefront position root→tip
      for (int i = 0; i < ARM_LENGTH[a]; i++) {
        float rp = i / (float)(ARM_LENGTH[a] - 1);
        float d  = pr - rp;
        uint8_t r, g, b;
        if (d < 0.0f) {
          // Ahead of wavefront: peak-charge hot yellow-white
          r = 255; g = 210; b = 60;
        } else if (d < 0.25f) {
          float f = 1.0f - d / 0.25f;
          r = 255; g = (uint8_t)(210 + f * 45); b = (uint8_t)(f * 200);
        } else {
          // Wake: collapses fast with ff² → crisp, not soupy
          float wk = constrain(1.0f - (d - 0.25f) / 0.75f, 0.0f, 1.0f) * ff * ff;
          r = (uint8_t)(wk * 230); g = (uint8_t)(wk * 50); b = 0;
        }
        strip.setPixelColor(ARM_START[a] + i, strip.Color(r, g, b));
      }
      if (flash[a] > 18) flash[a] -= 18; else flash[a] = 0;

    } else if (refr[a] > 0) {
      // ── REFRACTORY: arm-unique cool hue, quadratic fade ──────────────────
      float rf = refr[a] / (float)REFRACTORY;
      // armRate 0.5=slow→deep blue-violet / 2.0=fast→cyan-teal
      uint16_t refHue = (uint16_t)(43000 + armRate[a] * 2500);
      uint8_t  rv = (uint8_t)(rf * rf * 75);
      for (int i = 0; i < ARM_LENGTH[a]; i++) {
        float rad = 1.0f - (i / (float)ARM_LENGTH[a]) * 0.5f;
        strip.setPixelColor(ARM_START[a] + i, strip.ColorHSV(refHue, 255, (uint8_t)(rv * rad)));
      }

    } else {
      // ── CHARGING: ember floor + pow³ explosion near threshold ─────────────
      float aiFrac = constrain(ai[a] / THRESHOLD, 0.0f, 1.0f);
      // 2% floor so arm is never completely invisible — tension via "barely there"
      float curve = 0.020f + 0.980f * powf(aiFrac, 3.0f);
      // Flicker peaks in mid-charge (50%) where buildup is most suspenseful
      float flickAmp = 0.30f * (1.0f - fabsf(aiFrac - 0.50f) * 1.8f);
      flickAmp = constrain(flickAmp, 0.0f, 0.30f);
      curve *= constrain(1.0f + (random(-100,100)/100.0f) * flickAmp, 0.12f, 1.88f);
      curve = constrain(curve, 0.0f, 1.0f);
      // Hue identity per arm (armRate maps to distinct orange spectrum position)
      // heats toward yellow-white as arm approaches threshold
      uint16_t baseHue = (uint16_t)(3600 + armRate[a] * 550);
      uint16_t armHue  = baseHue + (uint16_t)(aiFrac * 1300);
      uint8_t  armSat  = (uint8_t)(252 - aiFrac * 75);
      for (int i = 0; i < ARM_LENGTH[a]; i++) {
        float rootBias = 1.0f - (i / (float)ARM_LENGTH[a]) * 0.58f;
        uint8_t v = (uint8_t)(curve * rootBias * 255);
        strip.setPixelColor(ARM_START[a] + i, strip.ColorHSV(armHue, armSat, v));
      }
    }
  }
}

// Pattern 21: Bioluminescence — Kuramoto coupled oscillators
// Models colonial marine organisms (Noctiluca scintillans / Pennatulacea):
//   Each arm = independent organism at its own incommensurable natural frequency.
//   Kuramoto coupling K breathes 0→0.07→0 over ~25s: chaos → partial sync → chaos.
//   When arms synchronize, center bursts white (colonial nerve net response).
//   Palette: cold blue-white flash (470nm peak) → green luciferin oxidation glow.
//   Never repeats: irrational frequency ratios + stochastic phase noise.
void pattern_Bioluminescence() {
  static float phase[ARM_COUNT]  = {0};
  static float omega[ARM_COUNT]  = {0};
  static float coupPhase         = 0.0f;
  static float centerPh          = 0.0f;
  static float syncSmooth        = 0.0f;

  if (patternNeedsReset) {
    // Incommensurable base frequencies — no pair has ratio p/q for small integers.
    // At speed=50 (~32ms/tick): arm0≈10.7s period, arm7≈4.3s period.
    const float BASE[8] = { 0.0184f, 0.0239f, 0.0271f, 0.0307f,
                             0.0349f, 0.0389f, 0.0421f, 0.0463f };
    for (int a = 0; a < ARM_COUNT; a++) {
      phase[a] = random(0, 628) / 100.0f;               // random initial phase 0..2π
      omega[a] = BASE[a] + random(-8, 8) / 10000.0f;   // per-run micro-variation
    }
    coupPhase  = random(0, 628) / 100.0f;
    centerPh   = random(0, 628) / 100.0f;
    syncSmooth = 0.0f;
  }

  // ── SIMULATION ──────────────────────────────────────────────────────────────

  // Coupling K breathes via sin²: 0→0.07→0 over 2π/0.008 ≈ 785 ticks (~25s).
  // K≈0: arms drift freely, each clearly individual.
  // K≈0.07: arms slowly entrain → collective synchrony event.
  coupPhase += 0.008f;
  float halfK = 1.0f - cosf(coupPhase);          // 0..2
  float K     = 0.035f * halfK;                  // 0..0.07

  // Center colony nerve: own slower rhythm, independent of arm coupling
  centerPh = fmodf(centerPh + 0.012f, TWO_PI);

  // Kuramoto order parameter R (0=chaos, 1=full synchrony)
  float sumS = 0.0f, sumC = 0.0f;
  for (int a = 0; a < ARM_COUNT; a++) {
    sumS += sinf(phase[a]);
    sumC += cosf(phase[a]);
  }
  float R   = sqrtf(sumS*sumS + sumC*sumC) / ARM_COUNT;
  float Psi = atan2f(sumS, sumC);                 // mean phase direction
  syncSmooth = syncSmooth * 0.96f + R * 0.04f;   // smoothed sync level

  // Update phases: natural frequency + Kuramoto coupling + stochastic jitter
  for (int a = 0; a < ARM_COUNT; a++) {
    float noise = random(-25, 25) / 10000.0f;
    phase[a] = fmodf(phase[a] + omega[a] + K * sinf(Psi - phase[a]) + noise + TWO_PI, TWO_PI);
  }

  // ── RENDER ──────────────────────────────────────────────────────────────────
  strip.clear();

  // Center: colonial nerve net — dim self-pulse + sync bonus
  // Blazes white when syncSmooth² is high (collective synchrony event)
  {
    float cp = sinf(centerPh);
    if (cp < 0) cp = 0;
    float basePulse = cp * cp * 0.22f;
    float syncB     = syncSmooth * syncSmooth;
    float total     = basePulse + syncB * 0.78f;
    uint8_t cv = (uint8_t)(total * 255);
    uint8_t cg = (uint8_t)(basePulse * 160 + syncB * 210);
    uint8_t cr = (uint8_t)(syncB * 180);
    strip.setPixelColor(0, strip.Color(
      (uint8_t)min(255,(int)cr),
      (uint8_t)min(255,(int)cg),
      (uint8_t)min(255,(int)cv)));
  }

  for (int a = 0; a < ARM_COUNT; a++) {
    float ph = phase[a];
    uint8_t r, g, b;

    if (ph < PI) {
      // ── FLASH PHASE (0..π): bioluminescent discharge ──────────────────────
      // Rises from near-zero to blinding peak at π/2, falls back at π.
      float flash  = sinf(ph);          // 0→1→0
      float flash2 = flash * flash;     // crisp power curve
      float total  = 0.016f + flash2 * 0.984f;

      // Color: near-black teal → saturated cyan-blue → pure cold white at peak
      // hue 40500→35000 (blue→cyan), saturation 252→15 (colored→white)
      uint16_t hue = (uint16_t)(40500 - flash * 5500);
      uint8_t  sat = (uint8_t)(252 - flash * 237);
      uint8_t  val = (uint8_t)(total * 255);
      uint32_t c   = strip.ColorHSV(hue, sat, val);
      r = (c >> 16) & 0xFF;
      g = (c >> 8)  & 0xFF;
      b =  c        & 0xFF;

    } else {
      // ── GLOW PHASE (π..2π): luciferin oxidation afterglow ─────────────────
      // Green phosphorescence peaks at 3π/2, fully decays by 2π.
      // Represents oxidized coelenteramide — the chemical memory of the flash.
      float glow  = sinf(ph - PI);      // 0→1→0 over π..2π
      float glow2 = glow * glow;

      // Basal teal (organism never completely off — metabolic baseline)
      uint8_t gv = (uint8_t)(glow2 * 120);           // green peak ~120
      uint8_t bv = (uint8_t)(0.016f * 200 + glow * 22); // slight blue in glow
      r = 0;
      g = gv;
      b = bv;
    }

    // Radial falloff: attachment point (root) has denser tissue → brighter
    for (int i = 0; i < ARM_LENGTH[a]; i++) {
      float rb = 1.0f - (i / (float)ARM_LENGTH[a]) * 0.42f;
      strip.setPixelColor(ARM_START[a] + i, strip.Color(
        (uint8_t)((float)r * rb),
        (uint8_t)((float)g * rb),
        (uint8_t)((float)b * rb)));
    }
  }
}


// Pattern 22: Turing Spot — Gray-Scott reaction-diffusion
// Nachbartopologie entspricht der physischen Ringgeometrie (Bauplan 19×19cm).
// Jede LED diffundiert mit ihren echten geometrischen Nachbarn (< 45mm).
const int8_t LED_NBR[35][7] = {
  {  1,  4,  2,  3,  5,  6, -1},
  {  0,  7,  2,  6,  8, 18, -1},
  {  3,  0,  1,  9, 10,  8, -1},
  {  2,  0,  4, 11, 10, 12, -1},
  {  0, 13,  3,  5, 12, 14, -1},
  {  6,  0,  4, 15, 16, 14, -1},
  {  5,  0,  1, 17, 16, 18, -1},
  { 19,  1,  8, 18, 34, 20, -1},
  { 20,  7, 21,  9,  1,  2, 19},
  { 22,  2, 10, 21,  8, 23, -1},
  { 23,  9, 11,  2,  3, 22, 24},
  { 24,  3, 10, 25, 12, 23, -1},
  { 26, 13, 25, 11,  4,  3, 27},
  { 27,  4, 12, 14, 28, 26, -1},
  { 28, 13, 29, 15,  4,  5, 27},
  { 30,  5, 16, 29, 14, 31, -1},
  { 31, 15, 17, 32,  5,  6, 30},
  { 32,  6, 16, 33, 18, 31, -1},
  { 34,  7, 33, 17,  1,  6, 19},
  {  7, 34, 20,  8, 18, -1, -1},
  {  8, 21, 19,  7, -1, -1, -1},
  {  8,  9, 20, 22, -1, -1, -1},
  {  9, 23, 21, 10, -1, -1, -1},
  { 10, 22, 24,  9, 11, -1, -1},
  { 11, 25, 23, 10, -1, -1, -1},
  { 11, 12, 24, 26, -1, -1, -1},
  { 12, 25, 27, 13, -1, -1, -1},
  { 13, 28, 26, 12, 14, -1, -1},
  { 14, 27, 29, 13, -1, -1, -1},
  { 14, 15, 30, 28, -1, -1, -1},
  { 15, 29, 31, 16, -1, -1, -1},
  { 16, 32, 30, 15, 17, -1, -1},
  { 17, 31, 33, 16, -1, -1, -1},
  { 17, 18, 32, 34, -1, -1, -1},
  { 18, 19, 33,  7, -1, -1, -1}
};
const uint8_t LED_NBR_CNT[35] = {6,6,6,6,6,6,6,6,7,6,7,6,7,6,7,6,7,6,7,5,4,4,4,5,4,4,4,5,4,4,4,5,4,4,4};

void pattern_TuringSpot() {
  static float A[35];  // Aktivator
  static float B[35];  // Inhibitor
  static bool  tsInit = false;

  // Gray-Scott Parameter — Spots-Regime
  const float dA   = 0.90f;
  const float dB   = 0.45f;
  const float feed = 0.055f;
  const float kill = 0.062f;
  const float dt   = 0.30f;

  if (patternNeedsReset || !tsInit) {
    for (int i = 0; i < LED_COUNT; i++) { A[i] = 1.0f; B[i] = 0.0f; }
    // Seed: zufällige Aktivator-Spots
    for (int s = 0; s < 7; s++) {
      int si = random(LED_COUNT);
      A[si] = 0.50f; B[si] = 0.25f;
    }
    tsInit = true;
  }

  // Diskrete Laplacians über die Ring-Nachbartopologie
  float lapA[35] = {};
  float lapB[35] = {};
  for (int i = 0; i < LED_COUNT; i++) {
    int n = LED_NBR_CNT[i];
    float sA = 0, sB = 0;
    for (int k = 0; k < n; k++) { sA += A[LED_NBR[i][k]]; sB += B[LED_NBR[i][k]]; }
    lapA[i] = sA - (float)n * A[i];
    lapB[i] = sB - (float)n * B[i];
  }

  // Gray-Scott Update: dA/dt = dA·∇²A − A·B² + feed·(1−A)
  //                   dB/dt = dB·∇²B + A·B² − (feed+kill)·B
  for (int i = 0; i < LED_COUNT; i++) {
    float a = A[i], b = B[i], rxn = a*b*b;
    A[i] = constrain(a + dt*(dA*lapA[i] - rxn + feed*(1.0f-a)), 0.0f, 1.0f);
    B[i] = constrain(b + dt*(dB*lapB[i] + rxn - (feed+kill)*b),  0.0f, 1.0f);
  }

  // Render: Aktivator → Helligkeit, langsamer Farbdrift
  uint16_t hue = (uint16_t)(patternPhase * 400) % 65536;
  for (int i = 0; i < LED_COUNT; i++) {
    float v = A[i]*A[i]*A[i];  // Kontrast-Boost
    uint16_t lh = (hue + (uint16_t)((1.0f - A[i]) * 12000)) % 65536;
    strip.setPixelColor(i, strip.ColorHSV(lh, 210, (uint8_t)(v*255)));
  }
}


// Global post-processing: hue shift + mono hue, applied after every pattern frame
static uint16_t _rgbToHue(uint8_t r, uint8_t g, uint8_t b) {
  uint8_t mx = max(r, max(g, b));
  uint8_t mn = min(r, min(g, b));
  if (mx == mn) return 0;
  int32_t delta = mx - mn;
  int32_t h;
  if      (mx == r) h = (int32_t)(g - b) * 10922 / delta + (g < b ? 65536 : 0);
  else if (mx == g) h = (int32_t)(b - r) * 10922 / delta + 21845;
  else              h = (int32_t)(r - g) * 10922 / delta + 43690;
  return (uint16_t)(h & 0xFFFF);
}

void applyGlobalEffects() {
  if (globalHueShift == 0 && globalMonoHue < 0 && xyBright == 0) return;
  // Hue / mono pass
  if (globalHueShift != 0 || globalMonoHue >= 0) {
    for (int i = 0; i < LED_COUNT; i++) {
      uint32_t c = strip.getPixelColor(i);
      uint8_t r = (c >> 16) & 0xFF;
      uint8_t g = (c >> 8)  & 0xFF;
      uint8_t b =  c        & 0xFF;
      uint8_t val = max(r, max(g, b));
      if (val == 0) continue;
      if (globalMonoHue >= 0) {
        strip.setPixelColor(i, strip.ColorHSV((uint16_t)globalMonoHue, 255, val));
      } else {
        uint8_t sat = (uint8_t)(((uint16_t)(val - min(r, min(g, b))) * 255) / val);
        uint16_t hue = (_rgbToHue(r, g, b) + globalHueShift) & 0xFFFF;
        strip.setPixelColor(i, strip.ColorHSV(hue, sat, val));
      }
    }
  }
  // XY pad spotlight overlay
  if (xyBright > 0) {
    for (int i = 0; i < LED_COUNT; i++) {
      // Physical grid position from LED_X / LED_Y lookup
      float lx = LED_X[i];
      float ly  = LED_Y[i];
      float dx = lx - xyX, dy = ly - xyY;
      float dist = sqrtf(dx * dx + dy * dy);
      if (dist < 0.2f) {
        float inf = 1.0f - dist / 0.2f;
        inf *= inf;
        uint8_t boost = (uint8_t)(inf * xyBright);
        if (boost > 0) {
          uint32_t c = strip.getPixelColor(i);
          uint8_t br, bg, bb;
          if (globalMonoHue >= 0) {
            uint32_t hc = strip.ColorHSV((uint16_t)globalMonoHue, 255, boost);
            br = (hc >> 16) & 0xFF;
            bg = (hc >> 8)  & 0xFF;
            bb =  hc        & 0xFF;
          } else {
            br = bg = bb = boost;
          }
          uint8_t nr = (uint8_t)min(255, (int)((c >> 16) & 0xFF) + (int)br);
          uint8_t ng = (uint8_t)min(255, (int)((c >> 8)  & 0xFF) + (int)bg);
          uint8_t nb = (uint8_t)min(255, (int)(c          & 0xFF) + (int)bb);
          strip.setPixelColor(i, strip.Color(nr, ng, nb));
        }
      }
    }
    if (xyBright > 8) xyBright -= 8; else xyBright = 0;
  }
}

String getHTML() {
  return String() + 
"<!DOCTYPE html>" +
"<html>" +
"<head>" +
"  <meta charset='UTF-8'>" +
"  <meta name='viewport' content='width=device-width,initial-scale=1,maximum-scale=1,user-scalable=no,viewport-fit=cover'>" +
"  <meta name='apple-mobile-web-app-capable' content='yes'>" +
"  <meta name='apple-mobile-web-app-status-bar-style' content='black-translucent'>" +
"  <meta name='apple-mobile-web-app-title' content='Metabolic'>" +
"  <meta name='mobile-web-app-capable' content='yes'>" +
"  <meta name='theme-color' content='#000000'>" +
"  <link rel='manifest' href='/manifest.json'>" +
"  <title>Metabolic Mimicry</title>" +
"  <style>" +
"    *{margin:0;padding:0;box-sizing:border-box;-webkit-tap-highlight-color:transparent}" +
"    html,body{width:100%;height:100%;overflow:hidden;position:fixed}" +
"    body{font-family:-apple-system,BlinkMacSystemFont,'Segoe UI',sans-serif;background:#000;color:#fff;position:relative}" +
"    .tabs{display:flex;position:fixed;bottom:0;left:0;right:0;height:44px;padding-bottom:env(safe-area-inset-bottom);background:#000;border-top:1px solid #222;z-index:10}" +
"    .tab-btn{flex:1;background:none;border:none;color:#555;font-size:11px;letter-spacing:1.5px;text-transform:uppercase;cursor:pointer;font-family:inherit;border-top:2px solid transparent}" +
"    .tab-btn.active{color:#fff;border-top-color:#ff0}" +
"    .tab-pane{display:none;position:absolute;top:0;left:0;right:0;bottom:calc(44px + env(safe-area-inset-bottom))}" +
"    .tab-pane.active{display:block}" +
"    #pane-ctrl{overflow:hidden;display:flex;justify-content:center;align-items:flex-start}" +
"    .container{width:100%;max-width:400px;padding:12px 18px 6px}" +
"    h1{font-size:16px;font-weight:300;margin-bottom:14px;letter-spacing:2px;text-align:center}" +
"    .control-group{margin-bottom:12px}" +
"    label{display:block;font-size:10px;letter-spacing:1px;text-transform:uppercase;margin-bottom:5px;color:#888}" +
"    select{width:100%;background:#000;color:#fff;border:1px solid #fff;padding:10px;font-size:13px;cursor:pointer;font-family:inherit}" +
"    .transport{display:flex;gap:20px;justify-content:center;align-items:center}" +
"    button{background:transparent;border:none;color:#fff;cursor:pointer;font-size:32px;transition:all .2s;padding:0;width:auto;height:auto}" +
"    button:active{color:#888}" +
"    button.play{color:#ff0;font-size:36px}" +
"    button.play:active{color:#aa0}" +
"    input[type=range]{width:100%;height:2px;background:#333;outline:none;-webkit-appearance:none}" +
"    input[type=range]::-webkit-slider-thumb{-webkit-appearance:none;width:20px;height:20px;background:#fff;cursor:pointer;border:2px solid #000}" +
"    input[type=range]::-moz-range-thumb{width:20px;height:20px;background:#fff;cursor:pointer;border:2px solid #000}" +
"    .value-display{text-align:left;font-size:18px;margin-top:3px;color:#ff0;font-weight:300}" +
"    #pane-xy{overflow:hidden;background:#000}" +
"    #xyCanvas{width:100%;height:100%;display:block;touch-action:none;cursor:crosshair}" +
"  </style>" +
"</head>" +
"<body>" +
"  <div class='tabs'>" +
"    <button class='tab-btn active' id='btn-ctrl' onclick='switchTab(\"ctrl\")'>CTRL</button>" +
"    <button class='tab-btn' id='btn-xy' onclick='switchTab(\"xy\")'>XY PAD</button>" +
"  </div>" +
"  <div class='tab-pane active' id='pane-ctrl'>" +
"    <div class='container'>" +
"    <h1>METABOLIC MIMICRY</h1>" +
"    <div class='control-group'>" +
"      <label>Pattern</label>" +
"      <select id='pattern' onchange='changePattern(this.value)'>" +
"        <option value='0'>XY Pad</option>" +
"        <option value='1'>Orbital Rings</option>" +
"        <option value='2'>Pinwheel</option>" +
"        <option value='3'>Bloom</option>" +
"        <option value='4'>Pulsar</option>" +
"        <option value='5'>Wormhole</option>" +
"        <option value='6'>Compass</option>" +
"        <option value='7'>Cosmic Web</option>" +
"        <option value='8'>Gravity Well</option>" +
"        <option value='9'>DNA Helix</option>" +
"        <option value='10'>Pulse Wave</option>" +
"        <option value='11'>Particle Decay</option>" +
"        <option value='12'>Data Stream</option>" +
"        <option value='13'>Breathing Gradient</option>" +
"        <option value='14'>Glitch</option>" +
"        <option value='15'>Quantum States</option>" +
"        <option value='16'>Synapse Fire</option>" +
"        <option value='17'>Spectral Scan</option>" +
"        <option value='18'>Solar Flare</option>" +
"        <option value='19'>Quorum Sensing</option>" +
"        <option value='20'>Quorum Sensing v2</option>" +
"        <option value='21'>Bioluminescence</option>" +
"        <option value='22'>Turing Spot</option>" +
"      </select>" +
"    </div>" +
"    <div class='control-group'>" +
"      <div class='transport'>" +
"        <button onclick='prevPattern()'>&#9664;</button>" +
"        <button class='play' id='playBtn' onclick='togglePlay()'>&#9654;</button>" +
"        <button onclick='nextPattern()'>&#9654;</button>" +
"        <button onclick='resetPattern()' style='font-size:22px'>&#8635;</button>" +
"      </div>" +
"    </div>" +
"    <div class='control-group'>" +
"      <label>Speed</label>" +
"      <input type='range' id='speed' min='0' max='100' value='50' oninput='updateSlider(\"speed\",this.value)'>" +
"      <div class='value-display' id='speedVal'>50</div>" +
"    </div>" +
"    <div class='control-group'>" +
"      <label>Brightness</label>" +
"      <input type='range' id='brightness' min='0' max='255' value='128' oninput='updateSlider(\"brightness\",this.value)'>" +
"      <div class='value-display' id='brightnessVal'>128</div>" +
"    </div>" +
"    <div class='control-group'>" +
"      <label>Hue Shift</label>" +
"      <input type='range' id='hueshift' min='0' max='359' value='0' oninput='updateHueShift(this.value)'>" +
"      <div class='value-display' id='hueShiftVal'>0&deg;</div>" +
"    </div>" +
"    <div class='control-group'>" +
"      <label>Mono Hue</label>" +
"      <input type='range' id='monohue' min='0' max='360' value='0' oninput='updateMonoHue(this.value)'>" +
"      <div class='value-display' id='monoHueVal'>OFF</div>" +
"    </div>" +
"    </div>" +
"  </div>" +
"  <div class='tab-pane' id='pane-xy'><canvas id='xyCanvas'></canvas></div>" +
"  <script>" +
"    var isPlaying=true,sliderTimers={},currentPattern=0;" +
"    function send(p){fetch('/set?'+p).catch(e=>console.error(e))}" +
"    function changePattern(p){currentPattern=parseInt(p);send('pattern='+p)}" +
"    function nextPattern(){currentPattern=(currentPattern+1)%23;document.getElementById('pattern').value=currentPattern;send('action=next')}" +
"    function prevPattern(){currentPattern=(currentPattern==0)?22:currentPattern-1;document.getElementById('pattern').value=currentPattern;send('action=prev')}" +
"    function resetPattern(){send('action=reset')}" +
"    function updateSlider(n,v){document.getElementById(n+'Val').textContent=v;if(sliderTimers[n])clearTimeout(sliderTimers[n]);sliderTimers[n]=setTimeout(function(){send(n+'='+v)},15)}" +
"    function updateHueShift(v){document.getElementById('hueShiftVal').innerHTML=v+'&deg;';if(sliderTimers.hs)clearTimeout(sliderTimers.hs);sliderTimers.hs=setTimeout(function(){send('hueshift='+v)},15)}" +
"    function updateMonoHue(v){var d=document.getElementById('monoHueVal');d.innerHTML=v==0?'OFF':(v-1)+'&deg;';if(sliderTimers.mh)clearTimeout(sliderTimers.mh);sliderTimers.mh=setTimeout(function(){send('monohue='+v)},15)}" +
"    function togglePlay(){isPlaying=!isPlaying;var b=document.getElementById('playBtn');b.innerHTML=isPlaying?'&#9654;':'&#10074;&#10074;';send('action='+(isPlaying?'play':'pause'))}" +
"    function switchTab(t){document.querySelectorAll('.tab-btn,.tab-pane').forEach(function(e){e.classList.remove('active')});document.getElementById('btn-'+t).classList.add('active');document.getElementById('pane-'+t).classList.add('active');if(t=='xy')initXY();}" +
"    var xyActive=false,xyTmr=null,xyPos={x:0.5,y:0.5};" +
"    function initXY(){var c=document.getElementById('xyCanvas');c.width=c.offsetWidth;c.height=c.offsetHeight;drawXY(xyPos.x,xyPos.y);if(c._i)return;c._i=true;c.addEventListener('touchstart',onXY,{passive:false});c.addEventListener('touchmove',onXY,{passive:false});c.addEventListener('touchend',function(e){e.preventDefault()},{passive:false});c.addEventListener('mousedown',function(e){xyActive=true;onXY(e)});c.addEventListener('mousemove',function(e){if(xyActive)onXY(e)});c.addEventListener('mouseup',function(){xyActive=false});}" +
"    function onXY(e){e.preventDefault();var c=document.getElementById('xyCanvas');var r=c.getBoundingClientRect();var cx=e.touches?e.touches[0].clientX:e.clientX;var cy=e.touches?e.touches[0].clientY:e.clientY;xyPos.x=Math.max(0,Math.min(1,(cx-r.left)/r.width));xyPos.y=Math.max(0,Math.min(1,(cy-r.top)/r.height));drawXY(xyPos.x,xyPos.y);if(xyTmr)clearTimeout(xyTmr);xyTmr=setTimeout(function(){fetch('/xy?x='+Math.round(xyPos.x*100)+'&y='+Math.round(xyPos.y*100)).catch(function(){})},15);}" +
"    function drawXY(x,y){var c=document.getElementById('xyCanvas');if(!c.width||!c.height)return;var ctx=c.getContext('2d'),w=c.width,h=c.height,cx2=w/2,cy2=h/2,s=Math.min(w,h)*0.44;ctx.clearRect(0,0,w,h);var rn=[30/85,60/85,1],rc=[6,12,16],da=[60,30,22.5];ctx.strokeStyle='#1a1a1a';ctx.lineWidth=1;for(var r=0;r<3;r++){ctx.beginPath();ctx.arc(cx2,cy2,rn[r]*s,0,Math.PI*2);ctx.stroke();}ctx.beginPath();ctx.arc(cx2,cy2,4,0,Math.PI*2);ctx.fillStyle='#222';ctx.fill();for(var r=0;r<3;r++){for(var i=0;i<rc[r];i++){var a=(i*da[r]-90)*Math.PI/180;ctx.beginPath();ctx.arc(cx2+Math.cos(a)*rn[r]*s,cy2+Math.sin(a)*rn[r]*s,4,0,Math.PI*2);ctx.fillStyle='#222';ctx.fill();}}var px=x*w,py=y*h,rd=Math.min(w,h)*0.12;var g=ctx.createRadialGradient(px,py,0,px,py,rd);g.addColorStop(0,'rgba(255,255,0,0.7)');g.addColorStop(1,'rgba(255,255,0,0)');ctx.beginPath();ctx.arc(px,py,rd,0,Math.PI*2);ctx.fillStyle=g;ctx.fill();ctx.beginPath();ctx.arc(px,py,7,0,Math.PI*2);ctx.fillStyle='#ff0';ctx.fill();}" +
"  </script>" +
"</body>" +
"</html>";
}