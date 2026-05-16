---
tags:
  - hardware
  - led
  - ws2812
  - konzept
  - medienkunst
  - installation
  - bogenhanf
  - projektionsmapping
  - sound
  - skulptur
typ: konzept
bereich: hardware
projekt: Metabolic Mimicry
flächen:
  - 19x19cm
  - 9x9cm
---

# Metabolic Mimicry

*LED concepts for an audio-visual installation — Bogenhanf, Papierblüten, Projektionsmapping*

**Visualizer:** [metabolic_mimicry.html](../metabolic_mimicry.html) — alle 6 Konzepte animiert, auswählbar per Dropdown

**Verwandte Themen:** [[zellulaere_automaten]] | [[reaktions_diffusion]] | [[quorum_sensing]] | [[semipermeable_membran]] | [[biosemiotik]] | [[leopardenmuster]] | [[bakterielle_vermehrung]] | [[emergenz]] | [[anabolismus_katabolismus]] | [[autophagie]] | [[biomodalitaet]] | [[artificial_bacteria_konzept]] | [[turing_land_duchamp_land]] | [[pataphysik]] | [[__cosmicbrain__]]

---

## Die Installation

Eine lebende [[__cosmicbrain__#B|Bogenhanf]]-Pflanze (*Sansevieria trifasciata*) trägt mehrere handgeformte Blüten — gebogen aus Draht, geformt aus Zeitungspapier und Kleister, weiß gesprüht. Hinter dem Zentrum jeder Blüte sitzt ein **1mm Diffusor-Plexiglas**. Dahinter: ein Array aus einzeln adressierbaren WS2812B RGB-LEDs.

Die Blüten sind tot. Die Pflanze ist lebendig. Die LEDs simulieren biologische Prozesse.

Auf die gesamte Installation fällt **Projektionsmapping** — der Bogenhanf und seine Blüten werden zur Projektionsfläche für Muster die ihrem eigenen Entstehungsprinzip entstammen. **Sound** reagiert auf den Zustand des Systems und formt gleichzeitig dessen Verhalten.

Die Frage der Installation: Was ist der Unterschied zwischen einem Organismus und einem Objekt das so tut als wäre es eines?

---

## Material als Konzept

### Der Bogenhanf — lebender Träger

*Sansevieria trifasciata* ist eine der widerstandsfähigsten Zimmerpflanzen überhaupt. Kein Wasser, kein Licht — sie überlebt. Dabei betreibt sie gleichzeitig aktiven Stoffwechsel: Anabolismus (Wachstum, Photosynthese), [[autophagie|Katabolismus und Autophagie]] (Zellreparatur, Recycling), [[quorum_sensing|chemische Kommunikation]] mit ihrer Rhizosphäre.

Ihre Blätter tragen ein charakteristisches Bandmuster — Streifen in Grün und Graugrün, manchmal gold gerandet. Dieses Muster entsteht durch **denselben Mechanismus** wie das [[leopardenmuster|Leopardenmuster]]: ein [[reaktions_diffusion|Reaktions-Diffusions-System]] in der Epidermis, bei dem Aktivator (Chlorophyll-Synthese) und Inhibitor in räumlichem Wettbewerb stehen und dabei stabile Bänder erzeugen. Die Pflanze ist bereits ein Turing-Muster — sie trägt die Gleichung auf ihrer Haut.

Die Projektion wird diese Gleichung zurück auf die Pflanze werfen. Der Träger ist das Thema.

### Die Blüte — totes Material in lebender Form

**Draht** als Skelett: extrazellulare Matrix, Haltestruktur, Knochen.
**Zeitungspapier** als Fleisch: archiviertes menschliches Denken, Sprache, Datum — dead information, eingeweicht und neu geformt. Das [[autophagie|Autophagie-Prinzip]] in handfester Materialität: Abbau einer bestehenden Form (gedruckte Zeitung) → Recycling zu neuem Baustein → Aufbau einer neuen Struktur. [[anabolismus_katabolismus|Anabolismus aus Katabolismus]].
**Kleister** als Matrix: das Bindemittel zwischen den Einheiten, wie die extrazelluläre Matrix eines Biofilms — weder fest noch flüssig.
**Weißes Spray** als Auslöschung: Neutralisierung der ursprünglichen Information. Der Text unter dem Weiß existiert noch — er ist nur nicht mehr lesbar. Palimpsest.

Die Blütenform ist kein Zitat von Natur — sie ist ein Archetyp. Blüten haben dieses Muster weil [[reaktions_diffusion|Reaktions-Diffusion]] Petalen erzeugt, weil phyllotaktische Algorithmen Symmetrie erzwingen. Die Form ist eine algorithmische Notwendigkeit.

### Der Diffusor — Membran des Systems

Ein 1mm Diffusor-Plexi sitzt zwischen dem LED-Array und der Außenwelt. Dahinter: diskrete Lichtpunkte, klare Positionen, harter Code. Davor: ein gleichmäßiger Glanz, keine Quelle erkennbar, nur das Phänomen.

Der Diffusor ist eine [[semipermeable_membran|semipermeable Membran]]: er lässt Licht durch, aber transformiert seine Gestalt. Er macht die individuelle LED unsichtbar und damit das kollektive Muster erst sichtbar. Die Grenze zwischen Algorithmus und Erfahrung ist 1mm stark.

### Projektion & Sound — der äußere Kontext

**Projektion:** Beamer-Projektionsmapping auf Pflanze und Blüten. Mögliche Inhalte: Reaktions-Diffusions-Simulationen, zelluläre Automaten, biochemische Zeitverläufe. Das Muster im Raum spiegelt das Muster auf der Pflanze, das Muster in den LEDs — drei Ebenen desselben Prinzips.

**Sound:** Nicht dekorativ — strukturell. Sound als [[quorum_sensing|Quorum-Signal]]: wenn mehrere Blüten gleichzeitig einen Zustandsschwellenwert erreichen, löst das kollektiv akustische Ereignisse aus. Umgekehrt kann Sound-Input das LED-Verhalten modulieren. Die Grenze zwischen Sender und Empfänger wird unscharf — [[biosemiotik|Biosemiotik]] in akustisch-luminärer Form.

---

## Hardware

- **LED-Modul:** WS2812B auf PCB — Modul 17mm × 10mm, LED-Chip 5×5mm
- **LED-Position auf PCB:** 7mm vom linken Rand (inkl. Pads) / 5mm vom rechten Rand
- **Steuerung:** Arduino / ESP32 + FastLED oder NeoPixel Library
- **Diffusor:** Acryl-Plexiglas matt, 1mm

```
        ←— 17mm ——→
   ┌────────────────┐  ↑
   │ VCC  ▓▓▓  VCC │  │
   │  DO  ▓▓▓  DI  │ 10mm
   │ GND  ▓▓▓  GND │  │
   └────────────────┘  ↓
     ←7→  ←5→  ←5→  (mm)

   links: VCC | DO | GND   (Datenausgang → nächstes Modul DI)
   rechts: VCC | DI | GND  (Dateneingang ← vorheriges Modul DO)
```

> **Datenpfad:** Die Lötreihenfolge (DO→DI von Modul zu Modul) definiert den LED-Index (0, 1, 2…). Der Datenpfad durch das Layout bestimmt wie Animationen durch den Raum fließen — Spiralen, Wellen, Zeilen. Der Pfad ist Teil des Konzepts.

> **Handwerk-Toleranz:** Alle Abstände in den Varianten sind Zielwerte für Handbiegen und Handlöten. Reale Toleranz: ±3–5mm. Mindest-Mittenabstand zwischen zwei Modulen: **22mm** (17mm PCB-Breite + ~5mm Löt- und Biegespielraum). Engere Abstände sind mechanisch möglich aber unkomfortabel beim Löten.

---

## Animationslogik — Raster & Bewegung

Jede Variante basiert auf einem **räumlichen Raster** — kartesisch (V1), polar/ringförmig (V2, V4), topologisch (V3), radial (V5) oder spiralförmig (V6). Der Raster definiert die Koordinaten jeder LED und damit die Richtung in der sich Muster **bewegen** können.

**Grundprinzip: Dauerschleife.** Das Licht bewegt sich immer. Kein eingefrorenes Bild, kein Ruhezustand. Die `PRIMÄRE ANIMATION` ist der Normalzustand der Installation. Variationen (Sound, Quorum-Events, Farbwechsel) überlagern die Bewegung — ersetzen sie nicht.

**Datenpfad = Bewegungspfad.** Die Lötreihenfolge (Index 0→n) definiert nicht nur die Adressierung — eine Welle die in Index-Reihenfolge läuft, folgt dem physischen Pfad durch das Layout und erzeugt im Raum eine sichtbare Bewegungsrichtung.

---

# 19×19cm — Blütenkerne (groß)

## Variante 1 — "Glider"

**Konzept:** [[zellulaere_automaten]] | [[alan_turing]]
**LEDs:** 49 (7×7 Raster)
**Spacing:** 27mm — 6 Lücken × 27mm = 162mm innerhalb 19cm (Rand ~14mm je Seite)
**Datenpfad:** Boustrophedon — Schlangenlinie, Zeile für Zeile, Index 0 oben links

```
○ ○ ○ ○ ○ ○ ○
○ ○ ● ○ ○ ○ ○
○ ○ ○ ● ○ ○ ○
○ ● ● ● ○ ○ ○
○ ○ ○ ○ ○ ○ ○
○ ○ ○ ○ ○ ○ ○
○ ○ ○ ○ ○ ○ ○

● aktiv  ○ inaktiv  — gezeigt: Glider, Generation 1 (B3/S23)
```

**Medienkünstlerischer Text:**
Der Glider ist das kleinste selbstbewegende Objekt in Conway's Game of Life — fünf Zellen, vier Generationen, diagonale Bewegung durch ein potenziell unendliches Universum. Er ist Ikone: das erste Zeichen dass aus simplen Regeln echtes Verhalten entsteht. Nicht simuliertes Verhalten — *dasselbe* Verhalten, das entsteht wenn lokale Regeln global komplexe Strukturen erzwingen.

Diese Blüte zeigt einen Glider als eingefrorenen Moment. Hinter dem Diffusor der weißen Papierblüte rechnet ein 7×7-Raster. Es kennt keine globale Steuerung — jede LED kennt nur ihre acht Nachbarn. Die lebende Bogenhanf-Pflanze um die Blüte herum tut dasselbe: jede Zelle kennt nur ihre unmittelbare biochemische Umgebung, und doch wächst ein komplexer Organismus.

Projektion wirft die nächsten Generationen des Automaten auf die umgebenden Bogenhanf-Blätter. Das Spiel zieht sich aus der Blüte in den Raum.

→ [[zellulaere_automaten]] | [[alan_turing]] | [[emergenz]]

**Primäre Animation (Dauerschleife):**
`CONWAY B3/S23` — Game of Life läuft live auf dem 7×7-Raster. Der Glider bewegt sich diagonal, stellt sich am Rand auf, beginnt neu. Muster entstehen, sterben, werden neu geboren — endlos, ohne Eingriff. Geschwindigkeit: 1 Generation / 300ms. Das Raster ist das Universum. Es bewegt sich immer.

**Variationen:**
- `FARBKODIERUNG` — lebend: grün / gerade gestorben: rot (fade 500ms) / gerade geboren: blau (flash 200ms)
- `WOLFRAM` — alternativer Modus: 1D-Automat Rule 110. Jeder Tick scrollt alle Zeilen nach unten, neue Generation wächst oben nach — Raster zeigt Raumzeit: Raum (x) × Zeit (y, scrollend)
- `SOUND-SYNC` — jede neue lebende Zelle triggert einen Impuls (Tonhöhe = x-Position im Raster, 0–6)
- `DEBUG` — eingefroren auf einer bestimmten Generation (nur Testbetrieb)

> **Entscheidung:** Für die finale Installation wurde **V2 — Turing Spot** für beide Flächenformate (19×19cm + 9×9cm) gewählt. Die *Sansevieria* trägt auf ihrer Haut Turing-Muster (Bandmuster durch Reaktions-Diffusion) — V2 materialisiert exakt das Prinzip das die Pflanze selbst verkörpert. Konzentrische Ringstruktur skaliert verlustfrei auf beide Formate. → *Bauplan am Ende dieses Dokuments*

---

## Variante 2 — "Turing Spot"

**Konzept:** [[reaktions_diffusion]] | [[leopardenmuster]] | [[alan_turing]]
**LEDs:** 35 (1 Kern + 6 Ring-1 + 12 Ring-2 + 16 Ring-3)
**Radien:** 0 / 3cm / 6cm / 8.5cm — max 8.5cm < 9.5cm Halbbreite ✓
**Datenpfad:** Spirale von innen nach außen (Index 0 = Kern)

```
         I  I  I  I  I  I  I
      I  ·  ·  ·  ·  ·  ·  ·  I
    I  ·  A  ·  ·  ·  ·  A  ·  I
    I  ·  ·  a  ·  a  a  ·  ·  I
    I  A  ·  a  ·  Z  a  ·  A  I     Z  Kern, 1 LED
    I  ·  ·  a  a  a  ·  ·  ·  I     a  Aktivator-Ring (6 + 12 LEDs)
    I  ·  A  ·  ·  ·  ·  A  ·  I     A  Übergangszone (Teil Ring-2)
      I  ·  ·  ·  ·  ·  ·  ·  I     I  Inhibitor-Ring (16 LEDs)
         I  I  I  I  I  I  I

Datenpfad: Z → Ring-1 im UZS → Ring-2 im UZS → Ring-3 im UZS
```

**Medienkünstlerischer Text:**
1952 veröffentlichte Alan Turing *The Chemical Basis of Morphogenesis* — und erklärte damit wie aus chemischer Gleichgewichtslosigkeit biologische Form entsteht. Zwei Substanzen diffundieren mit unterschiedlicher Geschwindigkeit. Eine verstärkt sich lokal (Aktivator), eine dämpft weitreichend (Inhibitor). Das Ergebnis: stabile Flecken. Das Leopardenmuster. Das Zebramuster. Die Bänder des Bogenhanfs.

Diese Blüte materialisiert den Spot — das ur-biologische Muster der Turinggleichung — als weißes Licht hinter weißem Papier. Der Diffusor macht die Ringstruktur weich: der Übergang von Aktivator zu Inhibitor ist nicht scharf sondern graduell, genau wie das chemische Feld in der Biologie. Und das Raster drum herum — die Bogenhanf-Blätter — trägt auf ihrer Haut das Ergebnis derselben Gleichung, die in der Blüte leuchtet.

Die Projektion kann die Gray-Scott-Gleichung in Echtzeit berechnen und auf die gesamte Pflanzenfläche projizieren. Das Blatt empfängt die Visualisierung des Musters, das es selbst ist.

→ [[reaktions_diffusion]] | [[leopardenmuster]] | [[alan_turing]] | [[biosemiotik]]

**Primäre Animation (Dauerschleife ~8 Sek.):**
`DIFFUSIONSWELLE` — Kern (Z, warm-gelb) zündet. Aktivatorwelle breitet sich radial nach außen aus: Ring-1 (+300ms), Ring-2 (+600ms), Ring-3 (+900ms, blau = Inhibitor). Kurze Pause. Dann Rückwelle: Ring-3 dimmt, Ring-2, Ring-1, Kern erliöscht. Das Licht wandert hinaus und zurück — Diffusion sichtbar gemacht. Endlosschleife.

**Variationen:**
- `ROTATION` — innerhalb der Ringe läuft gleichzeitig eine Helligkeitswelle im Uhrzeigersinn (~1 Sek./Umdrehung), überlagert die radiale Welle
- `MULTI-SPOT` — nach jedem Zyklus wechselt die Kern-Position zwischen 3 Positionen; Spot reformiert sich neu
- `INTERFERENZ` — bei zwei V2-Blüten: Inhibitorringe reagieren aufeinander, dunkeln sich gegenseitig ab
- `SOUND` — Spot-Radius als Tonhöhe: enger Aktivatorkern = hoher Ton, breite Diffusion = tiefer Ton

> **Gewähltes Konzept für beide Flächenformate.** Die *Sansevieria trifasciata* trägt auf ihrer Haut Turing-Muster — V2 materialisiert das Prinzip das die Pflanze selbst verkörpert. Konzentrische Ringstruktur (Aktivator innen / Inhibitor außen) skaliert verlustfrei: 35 LEDs für 19×19cm, 15 LEDs für 9×9cm. → *Bauplan am Ende dieses Dokuments*

---

## Variante 3 — "Schwarm"

**Konzept:** [[quorum_sensing]] | [[emergenz]] | [[biosemiotik]]
**LEDs:** 22 (5 Cluster à 3–5 LEDs; topologischer Raster — Cluster-Zentren als räumliches Netz, Abstandsmatrix definiert Bewegungsreihenfolge zwischen Kolonien)
**Platzierung:** Cluster haben interne Dichte, freier Abstand zueinander — intern: LEDs in Index-Reihenfolge (lokale Bewegungsachse)
**Datenpfad:** innerhalb jedes Clusters sequenziell; Cluster A→B→C→D→E

```
[19×19cm, 1 Zeichen ≈ 1cm]

·  ·  ·  ·  ·  ·  D  ·  D  D  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  D  D  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  E  E  E  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  E  E  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  C  C  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  C  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  A  A  A  A  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  A  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  B  B  B  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  B  B  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·

A(5)  B(5)  C(3)  D(5)  E(4)
```

**Medienkünstlerischer Text:**
Kein Bakterium kennt die Gesamtpopulation. Jede Zelle produziert Autoinduktor-Moleküle — sie diffundieren, akkumulieren, lösen sich in der Umgebung. Erst wenn die lokale Konzentration einen Schwellenwert überschreitet, schaltet die Zelle ihr Verhalten um. Das Quorum entscheidet. Nicht ein Anführer — die Dichte.

Diese Blüte zeigt fünf Kolonien auf weißem Grund: isoliert, weit voneinander entfernt, unterschiedlich groß. Jede Kolonie pulsiert leise für sich. Sound ist das Medium der Kommunikation: der Schalldruckpegel im Raum wird als Proxy für Autoinduktor-Konzentration gewertet. Wenn der Lärmpegel aller Kolonien summiert einen Schwellenwert überschreitet — wenn genug Besucher genug Geräusch machen — kollektiver Burst. Alle 22 LEDs gleichzeitig, voll, weiß. Der Raum ist das Petri-Dish. Die Besucher sind die Bakterien.

Nach dem Burst: langsames Abdimmen, Rückkehr in den pre-Quorum-Zustand. Der Zyklus beginnt neu.

→ [[quorum_sensing]] | [[emergenz]] | [[bakterielle_vermehrung]] | [[biosemiotik]]

**Primäre Animation (Dauerschleife ~45–90 Sek.):**
`AUTOINDUKTOR-AKKUMULATION` — alle Cluster pulsieren asynchron und dim (A: 2.3s, B: 1.8s, C: 3.1s, D: 2.7s, E: 1.5s). Intern bewegt sich Licht in jedem Cluster in Index-Reihenfolge (Zirkulationswelle). Über Zeit gleichen sich Frequenzen an — Kolonien synchronisieren sich graduell. Wenn Synchronisation vollständig: kollektiver Burst (alle 22 LEDs, weiß, 800ms), dann Reset auf Asynchron. Endlosschleife.

**Variationen:**
- `SOUND-QUORUM` — Sound-Pegel als externer Autoinduktor: mehr Lärm = schnellere Synchronisation
- `WELLE A→E` — statt simultanem Burst: Aktivierungswelle läuft in räumlicher Reihenfolge durch die Cluster (nächster Nachbar zuerst)
- `FARBE` — pre-Sync: kühles Blau → Synchronisation: türkis → Burst: weiß → Reset: blaues Fade-out
- `MULTI-QUORUM` — jeder Cluster hat eigene Schwelle; Dominoeffekt wenn einer kippt

> **Entscheidung:** Für die finale Installation wurde **V2 — Turing Spot** für beide Flächenformate (19×19cm + 9×9cm) gewählt. Die *Sansevieria* trägt auf ihrer Haut Turing-Muster (Bandmuster durch Reaktions-Diffusion) — V2 materialisiert exakt das Prinzip das die Pflanze selbst verkörpert. Konzentrische Ringstruktur skaliert verlustfrei auf beide Formate. → *Bauplan am Ende dieses Dokuments*

---

# 9×9cm — Blütenkerne (klein)

## Variante 4 — "Membran"

**Konzept:** [[semipermeable_membran]] | [[biosemiotik]] | [[biomodalitaet]]
**LEDs:** 15 (1 Kern + 6 innere Membran + 8 äußere Zone)
**Radien:** 0 / 2.5cm / 3.8cm — max 3.8cm < 4.5cm Halbbreite ✓
**Abstände:** innerer Ring ~26mm (6 LEDs auf ⌀5cm), äußerer Ring ~30mm (8 LEDs auf ⌀7.6cm) — beide handlötbar
**Datenpfad:** Kern (0) → innerer Ring 1–6 im UZS → äußerer Ring 7–14 im UZS

```
      o   o   o
   o              o
     m   m   m
  o  m       m  o
     m   Z   m
  o  m       m  o
     m   m   m
   o              o
      o   o   o

Z Kern (1)  m innere Membran (6)  o äußere Zone (8)
```

**Medienkünstlerischer Text:**
Die Zellmembran ist keine Wand. Sie ist ein Interface — aktiv, selektiv, kontextsensitiv. Sie entscheidet was hineinkommt und was hinausgeht. Bei Stress schließt sie sich. Bei Hunger öffnet sie Ionenkanäle. Bei Tod verliert sie ihre Selektivität — und das Innen-Außen-Gefälle kollabiert.

Diese kleine Blüte hat drei Ebenen: Kern, Membran, Außenwelt. Drei Lichtzonen. Drei Verhaltensschichten. Die 1mm Plexiglasscheibe vor dem Ganzen ist die vierte Membran — die zwischen Algorithmus und Wahrnehmung.

Signale kommen von außen. Manche kommen durch. Manche nicht. Der Betrachter sieht: ein Licht entsteht im Außenring, bewegt sich nach innen, und erlischt. Oder erlischt vorher. Oder erscheint neu im Kern ohne erkennbaren Auslöser. Das Interface kommuniziert. Es ist nur schwer zu lesen.

In der Installation ist diese Blüte die philosophische: sie thematisiert die Grenze selbst. Das ist auch [[turing_land_duchamp_land|Duchamp-Land]] — die Membran als Readymade des Bedeutungsübergangs.

→ [[semipermeable_membran]] | [[biosemiotik]] | [[biomodalitaet]] | [[turing_land_duchamp_land]]

**Primäre Animation (Dauerschleife):**
`SIGNAL-WANDERUNG` — Endloser Wechsel zweier Bewegungsrichtungen: *(1)* Lichtimpuls erscheint im Außenring (o), wandert Ring für Ring nach innen (o→m→Z, je +200ms) — 70% kommen durch, 30% erlischen in m. *(2)* Alle ~3 Sekunden sendet Z einen Echo-Burst nach außen (Z→m→o, gedämpft). Beide Richtungen laufen gleichzeitig. Das Licht bewegt sich immer — hinein und hinaus.

**Variationen:**
- `ROTATION` — nach jedem durchkommenden Impuls dreht sich die offene Stelle in m um eine Position im Uhrzeigersinn (Membran rotiert, ist nicht gleichmäßig permeabel)
- `STRESS` — bei hohem Sound-Pegel: m-Ring rot, alle Signale blockiert, Z pulsiert isoliert
- `OSMOSE` — Langzeit-Drift: wenn Z dauerhaft heller als o, diffundiert Helligkeit kontinuierlich nach außen (kein Impuls, analoge Aufhellung)
- `FARBE` — Z: warm-weiß / m: phosphorgrün (offen) oder rot (Stress) / o: kalt-blau

> **Entscheidung:** Für die finale Installation wurde **V2 — Turing Spot** für beide Flächenformate (19×19cm + 9×9cm) gewählt. Die *Sansevieria* trägt auf ihrer Haut Turing-Muster (Bandmuster durch Reaktions-Diffusion) — V2 materialisiert exakt das Prinzip das die Pflanze selbst verkörpert. Konzentrische Ringstruktur skaliert verlustfrei auf beide Formate. → *Bauplan am Ende dieses Dokuments*

---

## Variante 5 — "Biofilm"

**Konzept:** [[bakterielle_vermehrung]] | [[quorum_sensing]] | [[anabolismus_katabolismus]] | [[autophagie]]
**LEDs:** 13 (7 Gründungskolonie dicht + 6 Expansionszellen verteilt)
**Platzierung:** radialer Raster — G-Cluster = Zentrum (Ring 0), e-Zellen = äußerer Ring (Ring 1). Bewegung = Wachstumsfront radial von Zentrum nach außen und zurück. Mindestabstand ~22mm.
**Datenpfad:** G0–G6 intern (zirkulär) → E0–E5 in radialer Expansionsreihenfolge (nächste zuerst)

```
[9×9cm, 1 Zeichen ≈ 1cm]

·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  e  ·  ·
·  ·  G  G  G  ·  ·  ·  e
·  ·  G  G  G  ·  ·  ·  ·
·  ·  G  ·  ·  ·  e  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·
e  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  e  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  e  ·  ·

G Gründungskolonie (7)  e Expansionszellen (6)
```

**Medienkünstlerischer Text:**
Das Zeitungspapier dieser Blüte war einmal Informationsträger. Es wurde eingeweicht, zerbrochen, mit Kleister — der Matrix — zu einer neuen Form verbunden. Das ist keine Metapher für [[autophagie|Autophagie]]: es ist Autophagie. Altes Material wird abgebaut, seine Bestandteile recycelt, eine neue Struktur entsteht. Die Blüte ist ihr eigenes Konzept, materialisiert.

Im Kern leuchten sieben LEDs eng beieinander — die Gründungskolonie, der erste Biofilm. Um sie herum, verstreut auf der Fläche, sechs Expansionszellen. Sie sind schon losgelöst, schon abgewandert, schon auf der Suche nach neuer Oberfläche.

Die Kupferdrähte die sie verbinden sind die Matrix — das extrazelluläre Netzwerk das die Kolonie zusammenhält auch wenn sie sich räumlich ausbreitet. Ohne Matrix: keine Kolonie. Nur Individuen. Kleister als Biofilm-Analog. Zeitungspapier als archivierte Information die in neue Strukturen umgebaut wird. [[anabolismus_katabolismus|Anabolismus aus Katabolismus]] — auf der Werkbankkebene.

→ [[bakterielle_vermehrung]] | [[quorum_sensing]] | [[autophagie]] | [[anabolismus_katabolismus]] | [[artificial_bacteria_konzept]]

**Primäre Animation (Dauerschleife ~3–5 Min.):**
Vier Phasen laufen endlos. Bewegung = Wachstumsfront die sich vom Kern nach außen und wieder zurückzieht.

`PHASE 1 — Adhesion` — G-Cluster dim amber/orange, unregeläßiges Blinken (1–3s). G-LEDs feuern intern in Indexreihenfolge (G0→G1→...→G6→G0) — Zirkulationsbewegung im Kern. e-Zellen: aus.

`PHASE 2 — Wachstum` — G-Cluster hellt auf. e-Zellen zünden einzeln in radialer Reihenfolge (nächste zuerst, ~8s Abstand). Die Wachstumsfront bewegt sich sichtbar vom Zentrum nach außen.

`PHASE 3 — Quorum` — alle 13 LEDs stabil, gemeinsames synchronisiertes Pulsieren. G: warm-orange, e: kühles Grün. Die gesamte Fläche atmet.

`PHASE 4 — Sporulation` — G-Cluster blinkt unruhig, e-Zellen dimmen radial ab (entfernteste zuerst). Front zieht sich zurück in den Kern. → Phase 1.

**Variationen:**
- `SOUND` — Phase-Übergänge triggern akustische Events: Adhesion = tiefes Summen, Wachstum = akkumulierende Frequenz, Sporulation = Klicksequenz
- `SPEED` — Sound-Pegel moduliert Durchlaufgeschwindigkeit des Lebenszyklus

> **Entscheidung:** Für die finale Installation wurde **V2 — Turing Spot** für beide Flächenformate (19×19cm + 9×9cm) gewählt. Die *Sansevieria* trägt auf ihrer Haut Turing-Muster (Bandmuster durch Reaktions-Diffusion) — V2 materialisiert exakt das Prinzip das die Pflanze selbst verkörpert. Konzentrische Ringstruktur skaliert verlustfrei auf beide Formate. → *Bauplan am Ende dieses Dokuments*

---

## Variante 6 — "Phyllotaxis"

**Konzept:** [[reaktions_diffusion]] | [[zellulaere_automaten]] | [[emergenz]]
**LEDs:** 13 (Goldener Winkel: n-te LED bei Winkel n × 137.5°, Radius √n × 1.15cm)
**Max. Radius:** √13 × 1.15cm ≈ 4.15cm < 4.5cm ✓
**Datenpfad:** sequenziell 1→13 (Spiralreihenfolge = Entstehungsreihenfolge)

```
Positionen in cm (Ursprung = Flächenmittelpunkt 4.5/4.5):

Nr   Winkel    r       x    y
 1   137.5°   1.15   3.6  5.3
 2   275.0°   1.63   4.6  2.9
 3    52.5°   1.99   5.7  6.1
 4   190.0°   2.30   2.2  4.1
 5   327.5°   2.57   6.7  3.1
 6   105.0°   2.82   3.8  7.2
 7   242.5°   3.04   3.1  1.8
 8    20.0°   3.25   7.6  5.6
 9   157.5°   3.45   1.3  5.8
10   295.0°   3.64   6.0  1.2
11    72.5°   3.81   5.7  8.1
12   210.0°   3.98   1.1  2.5
13   347.5°   4.16   8.6  3.6
```

```
[9×9cm — Draufsicht, grob]

·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  7  ·  ·  ·  ·  ·  ·
·  B  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  2  ·  ·  ·  ·  ·
·  ·  4  ·  ·  ·  ·  8  ·
9  ·  ·  ·  1  ·  ·  ·  ·
·  ·  ·  ·  ·  3  ·  ·  ·
·  ·  ·  ·  ·  ·  6  ·  ·

(B = LED 12)
```

**Medienkünstlerischer Text:**
Die Blüte an der diese LED-Matrix hängt, hat Petalen. Die Petalen folgen einer Spirale. Die Spirale folgt dem goldenen Winkel (137.5°) — der irrationalsten aller Zahlen, dem einzigen Winkel der garantiert, dass kein Blatt je exakt über einem anderen steht. Das Ergebnis: maximale Lichtausbeute, maximale Raumnutzung, aus einer einzigen rekursiven Entscheidung.

Die dreizehn LEDs hinter dem Diffusor folgen exakt demselben Algorithmus. Kein Raster. Keine Achse. Keine offensichtliche Ordnung. Und doch: eine Spirale — zwei Spiralen — wenn man die richtigen Subsequenzen verfolgt (Fibonacci-Teilmengen: 1→2→3→5→8→13). Das Muster ist mathematisch notwendig aber visuell nicht offensichtlich.

Das ist [[emergenz|Emergenz]] aus einer einzigen Konstante: 137.5°. Das ist auch der Draht der Blüte darum herum. Und die Bogenhanf-Blätter die sich nach oben spiralisieren. Dasselbe dreimal. Und das ist [[pataphysik|Pataphysik]] im besten Sinne: die unerwartete Syzygy zwischen Blumenform, LED-Layout und Pflanzenwachstum — drei Systeme die dieselbe Gleichung lösen ohne voneinander zu wissen.

→ [[reaktions_diffusion]] | [[zellulaere_automaten]] | [[emergenz]] | [[pataphysik]]

**Primäre Animation (Dauerschleife):**
`SPIRALWELLE` — Eine Helligkeitswelle läuft kontinuierlich in Index-Reihenfolge (1→2→3→...→13→1→...) durch alle LEDs, ~150ms pro Schritt. Weil Index-Reihenfolge = Entstehungsspirale: das Auge sieht eine Welle die sich spiralförmig durch die Blüte dreht. Immer in Bewegung, endlos.

**Variationen:**
- `FIBONACCI-PULS` — LEDs mit Fibonacci-Indizes (1, 2, 3, 5, 8, 13) leuchten bei jedem Spiraldurchlauf kurz heller auf
- `WACHSTUM` — Einmal-Intro: LED 1 an, bleibt an, LED 2 dazu... bis alle leuchten. Dann Übergang in SPIRALWELLE.
- `ROTATION` — Farbgradient rotiert im Schritt von 137.5°/Tick durch die Nummerierung
- `SOUND` — bei jedem Spiralschritt ein MIDI-Impuls (Index → Tonhöhe): Phyllotaxis als Melodie

> **Entscheidung:** Für die finale Installation wurde **V2 — Turing Spot** für beide Flächenformate (19×19cm + 9×9cm) gewählt. Die *Sansevieria* trägt auf ihrer Haut Turing-Muster (Bandmuster durch Reaktions-Diffusion) — V2 materialisiert exakt das Prinzip das die Pflanze selbst verkörpert. Konzentrische Ringstruktur skaliert verlustfrei auf beide Formate.

---

## Bauplan — V2 Turing Spot (beide Flächen)

Entscheidung: **V2 für alle Blüten.** Beide Formate, dasselbe konzentrische Muster — unterschiedliche Skalierung.

**Begründung:**
- *Sansevieria trifasciata* trägt auf ihrer Haut Turing-Muster (Bandmuster = Reaktions-Diffusion, Aktivator/Inhibitor). V2 zeigt exakt dieses Prinzip in LED-Form.
- Konzentrische Ringstruktur skaliert verlustfrei: 35 LEDs (19×19cm) → 15 LEDs (9×9cm), Animationslogik identisch.
- Radiale Diffusionswelle (Aktivator → Inhibitor → zurück) ist durch 1mm Diffusor klar lesbar.

**PCB-Ausrichtung:** tangential — 17mm-Achse entlang des Kreisbogens, 10mm-Achse radial.  
**Koordinaten:** ab linke obere Ecke der Blütenfläche. 0° = 12 Uhr, Winkel uhrzeigersinn.  
**Lötfolge:** Kern → Ring 1 uhrzeigersinn → Ring 2 → Ring 3 (nur 19×19cm).

→ [[reaktions_diffusion]] | [[leopardenmuster]] | [[alan_turing]]

---

### 19×19cm — 35 LEDs

| Ring | Funktion | n | Radius | Δ Winkel | Mittenabstand |
|------|----------|---|--------|----------|--------------|
| 0 Kern | Aktivator-Quelle | 1 | — | — | — |
| 1 | Aktivator innen | 6 | 30mm | 60° | 31mm |
| 2 | Aktivator außen | 12 | 60mm | 30° | 31mm |
| 3 | Inhibitor | 16 | 85mm | 22.5° | 33mm |

```
[19×19cm · 1 Zeichen ≈ 1cm]
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  3  ·  ·  3  ·  ·  3  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  3  ·  ·  ·  ·  ·  2  ·  ·  ·  ·  ·  3  ·  ·  ·
·  ·  ·  ·  ·  ·  2  ·  ·  ·  ·  ·  2  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  3  ·  ·  2  ·  ·  ·  ·  1  ·  ·  ·  ·  2  ·  ·  3  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  1  ·  ·  ·  ·  ·  1  ·  ·  ·  ·  ·  ·
·  3  ·  2  ·  ·  ·  ·  ·  Z  ·  ·  ·  ·  ·  2  ·  3  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  1  ·  ·  ·  ·  ·  1  ·  ·  ·  ·  ·  ·
·  3  ·  ·  2  ·  ·  ·  ·  1  ·  ·  ·  ·  2  ·  ·  3  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  2  ·  ·  ·  ·  ·  2  ·  ·  ·  ·  ·  ·
·  ·  ·  3  ·  ·  ·  ·  ·  2  ·  ·  ·  ·  ·  3  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  3  ·  ·  3  ·  ·  3  ·  ·  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·
Z Kern  1 Aktivator-R1  2 Aktivator-R2  3 Inhibitor-R3
```

#### Koordinaten Ring 0 + Ring 1

| # | Ring | ° | x mm | y mm |
|---|------|---|------|------|
| 0 | Kern | — | 95 | 95 |
| 1 | R1 | 0 | 95 | 65 |
| 2 | R1 | 60 | 121 | 80 |
| 3 | R1 | 120 | 121 | 110 |
| 4 | R1 | 180 | 95 | 125 |
| 5 | R1 | 240 | 69 | 110 |
| 6 | R1 | 300 | 69 | 80 |

#### Koordinaten Ring 2

| # | ° | x mm | y mm | | # | ° | x mm | y mm |
|---|---|------|------|-|---|---|------|------|
| 7 | 0 | 95 | 35 | | 13 | 180 | 95 | 155 |
| 8 | 30 | 125 | 43 | | 14 | 210 | 65 | 147 |
| 9 | 60 | 147 | 65 | | 15 | 240 | 43 | 125 |
| 10 | 90 | 155 | 95 | | 16 | 270 | 35 | 95 |
| 11 | 120 | 147 | 125 | | 17 | 300 | 43 | 65 |
| 12 | 150 | 125 | 147 | | 18 | 330 | 65 | 43 |

#### Koordinaten Ring 3 — Inhibitor

| # | ° | x mm | y mm | | # | ° | x mm | y mm |
|---|---|------|------|-|---|---|------|------|
| 19 | 0 | 95 | 10 | | 27 | 180 | 95 | 180 |
| 20 | 22.5 | 128 | 17 | | 28 | 202.5 | 63 | 174 |
| 21 | 45 | 155 | 35 | | 29 | 225 | 35 | 155 |
| 22 | 67.5 | 174 | 63 | | 30 | 247.5 | 17 | 128 |
| 23 | 90 | 180 | 95 | | 31 | 270 | 10 | 95 |
| 24 | 112.5 | 174 | 128 | | 32 | 292.5 | 17 | 63 |
| 25 | 135 | 155 | 155 | | 33 | 315 | 35 | 35 |
| 26 | 157.5 | 128 | 174 | | 34 | 337.5 | 63 | 17 |

#### Datenpfad 19×19cm

```
Arduino DATA → [0 Kern]
                   ↓ 12-Uhr-Richtung
        [1]→[2]→[3]→[4]→[5]→[6]         Ring 1, uhrzeigersinn
                             ↓ radial nach außen, 12-Uhr-Position
        [7]→[8]→[9]→...→[18]             Ring 2, uhrzeigersinn
                              ↓ radial nach außen, 12-Uhr-Position
        [19]→[20]→...→[34]               Ring 3, uhrzeigersinn
                               ↓ weiter zur nächsten Blüte
```

Ringwechsel-Drähte immer an der **12-Uhr-Position (0°)** radial herausführen — keine Kreuzungen. LED 7 liegt direkt über LED 1, LED 19 direkt über LED 7.

---

### 9×9cm — 15 LEDs

| Ring | Funktion | n | Radius | Δ Winkel | Mittenabstand |
|------|----------|---|--------|----------|--------------|
| 0 Kern | Aktivator-Quelle | 1 | — | — | — |
| 1 | Aktivator | 5 | 19mm | 72° | 22mm |
| 2 | Inhibitor | 9 | 35mm | 40° | 24mm |

```
[9×9cm · 1 Zeichen = 1cm]
·  ·  ·  ·  2  ·  ·  ·  ·
·  ·  2  ·  ·  ·  2  ·  ·
·  ·  ·  ·  1  ·  ·  ·  ·
·  2  1  ·  ·  ·  1  2  ·
·  ·  ·  ·  Z  ·  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·
·  2  ·  1  ·  1  ·  2  ·
·  ·  ·  2  ·  2  ·  ·  ·
·  ·  ·  ·  ·  ·  ·  ·  ·
Z Kern  1 Aktivator-R1  2 Inhibitor-R2
```

#### Koordinaten Ring 0 + Ring 1

| # | Ring | ° | x mm | y mm |
|---|------|---|------|------|
| 0 | Kern | — | 45 | 45 |
| 1 | R1 | 0 | 45 | 26 |
| 2 | R1 | 72 | 63 | 39 |
| 3 | R1 | 144 | 56 | 60 |
| 4 | R1 | 216 | 34 | 60 |
| 5 | R1 | 288 | 27 | 39 |

#### Koordinaten Ring 2

| # | ° | x mm | y mm | | # | ° | x mm | y mm |
|---|---|------|------|-|---|---|------|------|
| 6 | 0 | 45 | 10 | | 11 | 200 | 33 | 78 |
| 7 | 40 | 68 | 18 | | 12 | 240 | 15 | 63 |
| 8 | 80 | 80 | 39 | | 13 | 280 | 11 | 39 |
| 9 | 120 | 75 | 63 | | 14 | 320 | 23 | 18 |
| 10 | 160 | 57 | 78 | | | | | |

> **Achtung LED 6** (45mm, 10mm): 10mm von der oberen Blütenkante. PCB ragt tangential bis y ≈ 5mm. Papiermaché oben weiter formen — oder LED 6 auf y = 15mm setzen (Δ +5mm).

#### Datenpfad 9×9cm

```
Arduino DATA → [0 Kern]
                   ↓
        [1]→[2]→[3]→[4]→[5]   Ring 1, uhrzeigersinn
                          ↓
        [6]→[7]→...→[14]       Ring 2, uhrzeigersinn
                         ↓ weiter zur nächsten Blüte
```

---

### Verdrahtung (beide Formate)

```
5V  ──────────────────────── VCC aller PCBs (Busleitung, parallel)
GND ──────────────────────── GND aller PCBs (Busleitung, parallel)

Arduino DATA ─► [LED 0] ─► [LED 1] ─► ... ─► [LED n] ─► (nächste Blüte)
                .DIN       .DI         .DI       .DI
```

VCC + GND als gemeinsame Busleitung (0.5mm²) parallel zu allen PCBs — **nicht** über die Datenkette. Stromversorgung: 19×19cm max 2.1A @5V, 9×9cm max 0.9A @5V — je Blüte separaten 5V-Zweig ziehen.

---

### Bau-Reihenfolge

1. Drahtrahmen formen → Papiermaché (Zeitungspapier + Kleister) → trocknen lassen
2. Weiß sprühlackieren → trocknen
3. **Kreuzfaden:** zwei Fäden durch die Blüte (H + V). Schnittpunkt = Kern (LED 0). Bleistift.
4. Zirkel auf Kern: Radien 1 / 2 / (3) aufzeichnen, Winkel einteilen, Positionen markieren
5. PCBs mit kleiner Menge Heißkleber fixieren — **tangential ausrichten** (17mm-Achse entlang Kreisbogen)
6. VCC + GND Busleitung löten (parallel, 0.5mm² Kupferdraht)
7. Datenkette löten: DO → DI, Kern → Ring 1 → Ring 2 (→ Ring 3)
8. Diffusor-Plexi (1mm) aufsetzen und fixieren
9. Test: FastLED `colorWipe()` — alle LEDs einzeln adressieren prüfen
