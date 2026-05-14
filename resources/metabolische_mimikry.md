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
projekt: Metabolische Mimikry
flächen:
  - 19x19cm
  - 9x9cm
---

# Metabolische Mimikry

*LED-Konzepte für eine audio-visuelle Installation — Bogenhanf, Papierblüten, Projektionsmapping*

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

**Verhalten:**
- `STATISCH` — Glider als Zustand (Generation wählbar, 0–3), kein Tick
- `ANIMATION` — Conway B3/S23 live, Glider traversiert das Raster, Loop wenn er den Rand erreicht
- `FARBKODIERUNG` — lebend: grün / gerade gestorben: rot (fade, 500ms) / gerade geboren: blau (flash, 200ms)
- `WOLFRAM` — 1D-Regelautomat: Zeile 0 = Seed, jede nächste Zeile = nächste Generation Rule 110. Das Raster zeigt Raumzeit statt Raum.
- `SOUND-SYNC` — jeder neue lebende Zellzustand triggert einen kurzen Impuls (Tonhöhe = LED-Position im Raster)

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

**Verhalten:**
- `PULS` — Kern (warm-gelb) atmet auf, Inhibitorring (kalt-blau) folgt mit Verzögerung, dann Umkehr — stehende Welle, Atemrhythmus ~4 Sek.
- `SPOT-FORMATION` — alle off → Kern zündet → Aktivatorfeld diffundiert nach außen (Ring 1, 2, 3 mit Delay) → Inhibitorring schließt sich. Zeigt die Entstehung des Musters.
- `MULTI-SPOT` — Kern-Position wechselt zwischen 3 Positionen im Raster (je 8 Sek), Spot reformiert sich.
- `INTERFERENZ` — zwei Blüten mit V2 reagieren aufeinander: wenn ihre Inhibitorfelder räumlich überlappen, dunkeln beide ab. Gegenseitige Auslöschung.
- `SOUND` — Spot-Radius als Tonhöhe: enger Spot = hoher Ton, breiter Spot = tiefer Ton. Atemrhythmus setzt Taktgeber.

---

## Variante 3 — "Schwarm"

**Konzept:** [[quorum_sensing]] | [[emergenz]] | [[biosemiotik]]
**LEDs:** 22 (5 Cluster à 3–5 LEDs, organisch verteilt, kein Raster)
**Platzierung:** Cluster haben interne Dichte, freier Abstand zueinander
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

**Verhalten:**
- `BASELINE` — alle Cluster dim, individuelle Pulsfrequenz (A: 2.3s, B: 1.8s, C: 3.1s, D: 2.7s, E: 1.5s) — absichtlich asynchron
- `ANNÄHERUNG` — wenn Sound-Pegel steigt: einzelne Cluster hellen auf, Pulse beschleunigen sich proportional
- `QUORUM-BURST` — Schwellenwert überschritten: alle 22 LEDs gleichzeitig 100% weiß, 800ms gehalten, dann fade-out über 3 Sekunden
- `FARBE` — pre-Quorum: kühles Blau (einzelne Zelle, allein) → Annäherung: türkis → Quorum: weiß (kollektiv)
- `MULTI-QUORUM` — jeder Cluster hat eigene Schwelle; wenn ein Cluster kippt, erhöht das den effektiven Autoinduktor-Level der Nachbarcluster → Dominoeffekt möglich

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

**Verhalten:**
- `SIGNAL-IN` — Impulse erscheinen zufällig im Außenring (o), wandern mit individueller Wahrscheinlichkeit durch m in Richtung Z. Manche werden blockiert (faden in m aus). Manche kommen durch (Z zündet kurz).
- `SIGNAL-OUT` — Z sendet periodisch Bursts, die sich durch m nach außen fortpflanzen. Dämpfung durch m reduziert die Helligkeit — das Außen empfängt nur Echo.
- `STRESS` — bei hohem Sound-Pegel: m-Ring wird rot (geschlossen), kein Signal passiert mehr. Kern pulsiert alleine.
- `OSMOSE` — langsame Helligkeit-Drift: wenn Z heller als o, diffundiert Helligkeit langsam von innen nach außen über m (analoge Aufhellung, kein diskretes Wandern)
- `FARBE` — Z: warm-weiß / m: phosphorgrün (aktiv transparent) oder rot (geschlossen) / o: kalt-blau

---

## Variante 5 — "Biofilm"

**Konzept:** [[bakterielle_vermehrung]] | [[quorum_sensing]] | [[anabolismus_katabolismus]] | [[autophagie]]
**LEDs:** 13 (7 Gründungskolonie dicht + 6 Expansionszellen verteilt)
**Platzierung:** frei, organisch — kein Raster, Kern-Cluster engstehend (~22mm Mindestabstand, PCB = 17mm), Expansion ~28–35mm Abstand
**Datenpfad:** G0–G6 intern → E0–E5 in Expansionsreihenfolge

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

**Verhalten:**
- `PHASE 1 — Adhesion` — nur G-Cluster, dim amber/orange, langsames Metabolismusblinken (unregelmäßig, 1–3s Intervall). e-Zellen: aus.
- `PHASE 2 — Wachstum` — G-Cluster heller; e-Zellen zünden nacheinander (je ~8s Abstand), frisches Grün, kurzes Aufflackern dann stabiles Glühen
- `PHASE 3 — Matrix` — alle 13 LEDs stabil; G warm-orange, e kühler Grün; Licht pulsiert leicht (gemeinsamer Rhythmus, synchronisiert — Quorum erreicht)
- `PHASE 4 — Sporulation` — G-Cluster beginnt zu blinken (Signal: Ressourcenknappheit), e-Zellen dimmen nacheinander ab (Dispersal) → zurück zu Phase 1
- `LOOP` — Lebenszyklus, unendlich. Durchlaufzeit: ~3–5 Min.
- `SOUND` — Phase-Übergänge triggern akustische Ereignisse: Adhesion = tiefes Summen, Wachstum = zunehmende Dichte, Sporulation = Klicksequenz

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

**Verhalten:**
- `SEQUENZ` — LEDs zünden in Reihenfolge 1→13, je 200ms Abstand: die Entstehungsspirale wird sichtbar
- `FIBONACCI-WELLE` — Helligkeitswelle läuft in Fibonacci-Reihenfolge (1,1,2,3,5,8,13 → modulo 13) durch die LEDs: kein erkennbares Muster in der Position, aber ein klarer Rhythmus in der Zeit
- `ROTATION` — alle 13 LEDs an, Farbgradient (Regenbogen) rotiert im Schritt von 137.5° durch die Nummerierung: benachbarte Farben im Nummernsystem sind räumlich weit entfernt, aber das Auge sieht trotzdem Ordnung
- `WACHSTUM` — alle off, dann: LED 1 an, bleibt an, LED 2 dazu, bleibt an, ... bis alle 13 leuchten, dann von außen abdimmen (13→1): Entstehung und Vergehen der Blüte
- `SOUND` — LED-Index als MIDI-Note: Reihenfolge 1–13 erzeugt Fibonacci-Melodie (Index → Tonhöhe nach festem Mapping). Phyllotaxis als Klangstruktur.
