---
tags:
  - werkzeug
  - typografie
  - terminal
  - medienkunst
typ: referenz
bereich: werkzeug
---

# ASCII Art — Zeichen als Bild

> Text der zum Bild wird. **ASCII Art** nutzt Zeichen aus dem druckbaren Zeichensatz um Bilder, Logos und Muster zu formen — ohne Pixel, ohne Farbe, nur durch Anordnung von Symbolen im Zeichenraster. Die älteste Form digitaler Bildgebung.

**Verwandte Themen:** [[zellulaere_automaten]] | [[biosemiotik]] | [[pataphysik]] | [[konzept_moodboard|Petroglyphen]] | [[__cosmicbrain__]]

---

## Was ist ASCII Art?

**ASCII** (American Standard Code for Information Interchange) ist ein 7-Bit-Zeichensatz mit 128 Zeichen — Buchstaben, Ziffern, Satzzeichen, Steuerzeichen. ASCII Art entstand in den 1960er–70ern als Drucker und Terminals keine Grafik konnten: Form durch Zeichen.

Heute: Unicode erweitert das Repertoire auf über 140.000 Zeichen inklusive Blockzeichen (`█ ▓ ▒ ░`), Linienzeichen (`╔ ═ ╗ ║`), geometrische Formen — das Prinzip bleibt dasselbe.

```
 ██████   ███████   ██████  ███    ███ ██  ██████  
██    ██ ██     ██ ██    ██ ████  ████ ██ ██    ██ 
██       ██     ██ ██       ██ ████ ██ ██ ██       
██       ██     ██  ██████  ██  ██  ██ ██ ██       
██       ██     ██       ██ ██      ██ ██ ██       
██    ██ ██     ██ ██    ██ ██      ██ ██ ██    ██ 
 ██████   ███████   ██████  ██      ██ ██  ██████  

████████  ████████     ███    ████ ██    ██ 
██     ██ ██     ██   ██ ██    ██  ███   ██ 
██     ██ ██     ██  ██   ██   ██  ████  ██ 
████████  ████████  ██     ██  ██  ██ ██ ██ 
██     ██ ██   ██   █████████  ██  ██  ████ 
██     ██ ██    ██  ██     ██  ██  ██   ███ 
████████  ██     ██ ██     ██ ████ ██    ██ 
```

---

## figlet — Block-Lettern aus dem Terminal

**figlet** ist ein Unix-Kommandozeilenwerkzeug (1991, Glenn Chappell & Ian Chai) das Text in große ASCII-Buchstaben verschiedener Stilrichtungen (*Fonts*) umwandelt.

### Installation

```bash
brew install figlet       # macOS
apt install figlet        # Debian/Ubuntu
```

### Grundnutzung

```bash
figlet "COSMIC"           # Standard-Font (big)
figlet -f banner3 "COSMIC"   # Banner3-Font: gefüllte Blöcke mit #
figlet -l "langer text"   # linksbündig
figlet -c "zentriert"     # zentriert
figlet -w 120 "breit"     # Ausgabebreite setzen
```

### Fonts — Auswahl

| Font | Charakter |
|---|---|
| `big` | Standard, klassische ASCII-Striche |
| `banner3` | Gefüllte Rechteck-Blöcke mit `#` |
| `banner4` | Ähnlich banner3, schmalere Proportionen |
| `block` | Dicke Blöcke, schlechte Lesbarkeit bei kurzen Worten |
| `lean` | Schräg, dynamisch |
| `mini` | Klein, kompakt |
| `slant` | Kursiv-Stil |

Alle installierten Fonts auflisten:
```bash
figlet -I2          # Fontverzeichnis ausgeben
ls $(figlet -I2)    # alle .flf-Dateien anzeigen
```

---

## Font-Galerie — Beispiel: `cosmiccannibalism`

### smslant — ✦ kompakt, kursiv, clean
```
                     _                        _ __        ___
 _______  ___ __ _  (_)__________ ____  ___  (_) /  ___ _/ (_)__ __ _
/ __/ _ \(_-</  ' \/ / __/ __/ _ `/ _ \/ _ \/ / _ \/ _ `/ / (_-</  ' \
\__/\___/___/_/_/_/_/\__/\__/\_,_/_//_/_//_/_/_.__/\_,_/_/_/___/_/_/_/
```

### slant — elegant, größer
```
  _________  _________ ___  (_)_____________ _____  ____  (_) /_  ____ _/ (_)
 / ___/ __ \/ ___/ __ `__ \/ / ___/ ___/ __ `/ __ \/ __ \/ / __ \/ __ `/ / /
/ /__/ /_/ (__  ) / / / / / / /__/ /__/ /_/ / / / / / / / / /_/ / /_/ / / /
\___/\____/____/_/ /_/ /_/_/\___/\___/\__,_/_/ /_/_/ /_/_/_.___/\__,_/_/_/
```

### speed — futuristisch, underscored
```
__________________________ ______(_)_________________ _________________(_)
_  ___/  __ \_  ___/_  __ `__ \_  /_  ___/  ___/  __ `/_  __ \_  __ \_  /
/ /__ / /_/ /(__  )_  / / / / /  / / /__ / /__ / /_/ /_  / / /  / / /  /
\___/ \____//____/ /_/ /_/ /_//_/  \___/ \___/ \__,_/ /_/ /_//_/ /_//_/
```

### lean — minimalistisch, dynamisch
```
    _/_/_/    _/_/      _/_/_/  _/_/_/  _/_/          _/_/_/    _/_/_/
 _/        _/    _/  _/_/      _/    _/    _/  _/  _/        _/
_/        _/    _/      _/_/  _/    _/    _/  _/  _/        _/
 _/_/_/    _/_/    _/_/_/    _/    _/    _/  _/    _/_/_/    _/_/_/
```

### block — massiv, quadratisch
```
  _|_|_|    _|_|      _|_|_|  _|_|_|  _|_|          _|_|_|    _|_|_|
_|        _|    _|  _|_|      _|    _|    _|  _|  _|        _|
_|        _|    _|      _|_|  _|    _|    _|  _|  _|        _|
  _|_|_|    _|_|    _|_|_|    _|    _|    _|  _|    _|_|_|    _|_|_|
```

### shadow — abgeflacht, Schatten-Effekt
```
  __|  _ \   __| __ `__ \  |  __|  __|  _` | __ \  __ \  | __ \   _` | | |
 (    (   |\__ \ |   |   | | (    (    (   | |   | |   | | |   | (   | | |
\___|\___/ ____/_|  _|  _|_|\___|\___|\__,_|_|  _|_|  _|_|_.__/ \__,_|_|_|
```

### graffiti — street art, asymmetrisch
```
  ____  ____  ______ _____ |__| ____  ____ _____    ____   ____ |__\_ |__
_/ ___\/  _ \/  ___//     \|  |/ ___\/ ___\\__  \  /    \ /    \|  || __ \
\  \__(  <_> )___ \|  Y Y  \  \  \__\  \___ / __ \|   |  \   |  \  || \_\ \
 \___  >____/____  >__|_|  /__|\___  >___  >____  /___|  /___|  /__||___  /
     \/          \/      \/        \/    \/     \/     \/     \/        \/
```

### cosmic — ornamental, komplex
```
  .,-:::::     ...      .::::::. .        :   :::  .,-:::::   .,-:::::
,;;;'````'  .;;;;;;;.  ;;;`    ` ;;,.    ;;;  ;;;,;;;'````' ,;;;'````'
[[[        ,[[     \[[,'[==/[[[[,[[[[, ,[[[[, [[[[[[        [[[
$$$        $$$,     $$$  '''    $$$$$$$$$"$$$ $$$$$$        $$$
`88bo,__,o,"888,_ _,88P 88b    dP888 Y88" 888o888`88bo,__,o,`88bo,__,o,
  "YUMMMMMP" "YMMMMMP"   "YMmMY" MMM  M'  "MMMMMM  "YUMMMMMP" "YUMMMMMP"
```

### small — 3-zeilig, kompakt
```
 __ ___ ____ __ (_)__ __ __ _ _ _  _ _ (_) |__  __ _| (_)____ __
/ _/ _ (_-< '  \| / _/ _/ _` | ' \| ' \| | '_ \/ _` | | (_-< '  \
\__\___/__/_|_|_|_\__\__\__,_|_||_|_||_|_|_.__/\__,_|_|_/__/_|_|_|
```

### mini — 2-zeilig, maximal kompakt
```
 _ _  _._ _ o _ _ _.._ ._ o|_  _.|o _._ _
(_(_)_>| | ||(_(_(_|| || |||_)(_|||_>| | |
```

### doom — klassisch (Standard-big)
```
  ___ ___  ___ _ __ ___  _  ___ ___ __ _ _ __  _ __  _| |__   __ _| |_ ___
 / __/ _ \/ __| '_ ` _ \| |/ __/ __/ _` | '_ \| '_ \| | '_ \ / _` | | / __|
| (_| (_) \__ \ | | | | | | (_| (_| (_| | | | | | | | | |_) | (_| | | \__ \
 \___\___/|___/_| |_| |_|_|\___\___\__,_|_| |_|_| |_|_|_.__/ \__,_|_|_|___/
```

---

### Zeichenersatz für Unicode-Blocks

figlet gibt `#` aus — durch Unicode-Blockzeichen ersetzen:

```bash
figlet -f banner3 "COSMIC" | sed 's/#/█/g'
```

Andere Varianten:

```bash
sed 's/#/▓/g'   # dunkelgrauer Block
sed 's/#/▒/g'   # mittelgrauer Block
sed 's/#/░/g'   # heller Block
sed 's/#/■/g'   # kleines Quadrat
sed 's/#/*/g'   # Sternchen, klassischer ASCII-Stil
```

### In Datei schreiben

```bash
figlet -f banner3 "TEXT" | sed 's/#/█/g' > banner.txt
```

Mit Kommentar-Prefix (für CSS, Code-Dateien):
```bash
figlet -f banner3 "TEXT" | sed 's/#/█/g' | while IFS= read -r line; do echo "** $line"; done
```

---

## Medienkünstlerische Perspektive

ASCII Art ist das älteste digitale Bildmedium — und gleichzeitig das primitivste. Es arbeitet mit der Grundeinheit aller digitalen Kommunikation: dem Zeichen. Kein Pixel, kein Rasterformat, nur der Buchstabe als Baustein.

Die Verwandtschaft zu [[konzept_moodboard|Petroglyphen]] liegt auf der Hand: beide formen Bedeutung durch Einritzen in ein Raster — dort Stein, hier Terminal-Grid. Beide sind körperlos in ihrer Herstellung, reduziert auf Kontur und Kontrast.

In der Medienkunst: ASCII Art als Kommentar auf Bildgebung selbst. Wenn ein `█` ein Pixel ist, was ist dann ein Pixel? Die Auflösung des Unterschieds zwischen *Zeichen* und *Bild* ist das Thema — [[biosemiotik]] macht dasselbe für biologische Signale: Was ist der Unterschied zwischen einem Zeichen und dem was es auslöst?

---

## Summary (EN)

ASCII Art uses printable characters to form images — the oldest form of digital image-making. **figlet** is a Unix CLI tool that renders text in large block-letter styles. Install via `brew install figlet`, use flag `-f banner3` for filled block style, pipe through `sed 's/#/█/g'` for Unicode block characters. Mediakünstlerisch relevant as the intersection of typography, code aesthetics and the question of what constitutes a *sign* vs. an *image*.
