---
tags:
  - biologie
  - algorithmus
  - emergenz
  - medienkunst
typ: theorie
bereich: biologie
---

# Bakterielle Vermehrung — Crash Kurs & Überleitung zu algorithmischem Leben

> Bakterien sind die ältesten Programmierer. Ihr Programm: DNA. Ihre Ausgabe: identische Kopien, Populationswachstum, kollektives Verhalten — alles ohne Bewusstsein, ohne Zentrum, ohne Plan. Daraus folgt die Frage: was ist der Unterschied zwischen einem Programm und einem Organismus?

**Verwandte Themen:** [[anabolismus_katabolismus]] | [[quorum_sensing]] | [[biosemiotik]] | [[zellulaere_automaten]] | [[artificial_bacteria_konzept]] | [[biomodalitaet]] | [[zellteilung]] | [[bakterielle_adaptation]]

---

## 1 — Binäre Spaltung: Das einfachste Programm

Das Standardverfahren bakterieller Vermehrung. Eine Zelle wird zu zwei Zellen.

```
ZELLE A  →  [DNA-Replikation]  →  ZELLE A' + ZELLE A''
```

**Schritte:**
1. **DNA-Replikation** — der kreisförmige Chromosomenstrang wird vollständig kopiert
2. **Elongation** — die Zelle streckt sich, die zwei DNA-Kopien wandern zu den Enden
3. **Septumbildung** — eine Trennwand wächst von außen nach innen
4. **Zelltrennung** — zwei identische Tochterzellen

→ [[zellteilung]]

Verdopplungszeit je nach Art und Bedingungen:
| Bakterium | Verdopplungszeit |
|---|---|
| *E. coli* (optimal) | ~20 Minuten |
| *Mycobacterium tuberculosis* | ~15–20 Stunden |
| Tiefseebakterien | Tage bis Wochen |

Aus **einer** Zelle werden nach 10 Stunden bei *E. coli* theoretisch **2³⁰ ≈ 1 Milliarde Zellen**.

> Exponentielles Wachstum ist kein Sonderfall — es ist der Grundzustand sobald die Bedingungen stimmen. Das Limit ist nicht die Vermehrungsrate sondern die Umwelt.

---

## 2 — Wachstumsphasen: Das System lernt seine eigene Grenze

Eine Bakterienpopulation durchläuft vier Phasen. Kein einzelnes Bakterium steuert das — es emergiert aus dem Kollektiv:

```
Zellzahl
   │                     ┌────────────────┐
   │                    /                  \
   │                   /                    \
   │                  / ← Log-Phase          ←── Stationär, dann Tod
   │_________________/
   │  ← Lag-Phase
   └────────────────────────────────────────── Zeit
```

| Phase | Was passiert | Was das System "lernt" |
|---|---|---|
| **Lag-Phase** | Zellen akklimatisieren, produzieren Enzyme, messen Umgebung | Ist das Substrat verwertbar? |
| **Log-Phase** | Exponentielles Wachstum, N(t) = N₀ · 2^(t/g) | Alle Ressourcen verfügbar — maximale Rate |
| **Stationäre Phase** | Wachstum = Sterberate, Population konstant | Quorum erreicht, Nährstoffe limitieren |
| **Absterbephase** | Sterberate > Wachstum | Ressourcen erschöpft oder Abfallprodukte toxisch |

Die Formel: $N(t) = N_0 \cdot 2^{\frac{t}{g}}$

wobei $g$ = Generationszeit, $N_0$ = Startpopulation.

**Logistisches Wachstum** (mit Kapazitätsgrenze K):

$$\frac{dN}{dt} = r \cdot N \cdot \left(1 - \frac{N}{K}\right)$$

Wenn $N \to K$: Wachstum → 0. Das System reguliert sich selbst — ohne dass irgendein Bakterium die Gesamtzahl kennt.

---

## 3 — Jenseits der Spaltung: Andere Vermehrungsstrategien

### Sporulation
Bei Nährstoffmangel bilden manche Bakterien (*Bacillus*, *Clostridium*) **Endosporen**: eine extreme Ruhephase. DNA in eine widerstandsfähige Hülle eingeschlossen. Hitze, Strahlung, Trockenheit — egal. Die Spore "wartet". Reaktivierung wenn Bedingungen besser werden.

→ Algorithmus-Analogie: **Checkpoint-Speicherstand**. Systemzustand einfrieren, später fortsetzen.

→ [[bakterielle_adaptation#Teil 1 — Endosporen: Eingefrorener Systemzustand|Endosporen]]

### Konjugation (Horizontaler Gentransfer)
Zwei Bakterien bauen eine Verbindung (**Pilus**). Plasmid-DNA wird übertragen. Das Empfänger-Bakterium erhält neue Eigenschaften — Antibiotikaresistenz, neue Stoffwechselwege — **ohne** Zellteilung.

→ Algorithmus-Analogie: **Laufzeit-Code-Injektion**. Ein Programm verändert ein anderes während beide laufen.

### Transformation & Transduktion
- **Transformation:** Zelle nimmt freie DNA aus der Umgebung auf (DNA "liegt rum", wird integriert)
- **Transduktion:** Viren (Phagen) übertragen DNA versehentlich von Zelle zu Zelle

Dies kollektiv: **[[bakterielle_adaptation#Teil 2 — Horizontaler Gentransfer: Laufzeit-Code-Injektion|Horizontaler Gentransfer]]** — Evolution ohne Fortpflanzung. Das Netzwerk lernt, nicht das Individuum.

---

## 4 — Die entscheidende Abstraktion: Lokale Regel → globales Verhalten

Alle bakteriellen Verhaltensweisen haben eine gemeinsame Struktur:

**Jede Zelle kennt nur:**
- Ihren eigenen Zustand (Energiestand, DNA-Schäden, pH)
- Ihre unmittelbare chemische Umgebung (Nährstoffe, Signalmoleküle, Sauerstoff)

**Keine Zelle kennt:**
- Die Gesamtpopulation
- Den globalen Zustand des Systems
- Was "das Richtige" für die Gruppe ist

Und trotzdem entstehen: Wachstumsphasen, Biofilme, [[quorum_sensing|kollektive Entscheidungen]], Antibiotikaresistenz-Netzwerke, Schwärmen.

> Das ist die biologische Formulierung des Kernprinzips zellulärer Automaten — und aller dezentralen Systeme. → [[emergenz]]

---

## 5 — Überleitung: Von der Zelle zur Simulation

### Was zelluläre Automaten von Bakterien gelernt haben

[[zellulaere_automaten|Conway's Game of Life]] (1970) abstrahiert genau diese Logik:

| Biologisches Bakterium | Game of Life Zelle |
|---|---|
| Kennt chemische Umgebung | Kennt 8 Nachbarzellen |
| Teilt sich wenn Bedingungen stimmen | Wird lebendig bei genau 3 Nachbarn |
| Stirbt bei Ressourcenmangel oder Überfüllung | Stirbt bei < 2 oder > 3 Nachbarn |
| DNA = Reproduktionsregel | Regelset `B3/S23` |
| Populationsverhalten emergiert | Gliders, Oszillatoren emergieren |

Der Unterschied: Bakterien haben **Kontinuität** (Energie, Chemie, Zeit). GoL hat **Diskretheit** (Ticks, binär, pixelig). Das Interessante liegt im Raum zwischen beiden.

### Life Simulations — eine Taxonomie des algorithmischen Lebens

```
DISKRET ←────────────────────────────────────────→ KONTINUIERLICH
   │                                                      │
GoL (binär, diskret)                          Lenia (kontinuierlich)
   │                                                      │
   ▼                                                      ▼
Leben/Tod                                   Aktivierungsfeld 0.0–1.0
Tick für Tick                               Faltungskernel, Glättung
B3/S23                                      beliebige Wachstumsfunktion
```

**Game of Life (Conway, 1970)**
Die Referenz. Drei Zahlen (`B3/S23`) → Turing-Vollständigkeit. Kein Bakterium, kein biologisches Vorbild direkt — aber dieselbe Logik. Stärke: Beweisbar. Schwäche: zu diskret um wie Leben auszusehen.

**Lenia (Bert Wang-Chak Chan, 2019)**
Kontinuierlicher zellulärer Automat. Jede Zelle hat einen Wert zwischen 0 und 1. Nachbarschaft wird über einen **Faltungskernel** berechnet (wie eine Heatmap). Wachstumsfunktion entscheidet ob Zelle wächst oder schrumpft. Ergebnis: bewegliche, selbst-erhaltende Strukturen die wie Mikroorganismen aussehen. Kein Zufall — emergente Form aus mathematisher Funktion.

> Biological intuition: Nährstoffgradient als Faltungskernel. Wachstumsfunktion als Metabolismus. Lenia *ist* ein metabolisches Modell.

**Smooth Life / Continuous GoL**
Zwischenstufe: GoL-Regeln auf kontinuierlichen Raum übertragen. Weichere Übergänge, flüssigere Bewegung, trotzdem binäre Logik im Kern.

**Neural Cellular Automata (Mordvintsev et al., 2020)**
Jede Zelle ist ein kleines neuronales Netz. Die Regeln werden nicht manuell definiert — das System **lernt** seine eigenen Regeln aus einem Ziel-Zustand. Anwendung: Selbst-reparierende Texturen, die nach Schäden in ihre Form zurückwachsen. Direkte Analogie: Wundheilung, Geweberegenerierung.

**Reaction-Diffusion Systeme (Turing, 1952)**
Alan Turing beschreibt 1952 wie zwei diffundierende Chemikalien (Aktivator + Inhibitor) durch ihre Wechselwirkung Muster erzeugen — Streifen, Flecken, Spiralen. Das Leopardenmuster ist kein Zufall: es ist eine partielle Differentialgleichung.

$$\frac{\partial u}{\partial t} = D_u \nabla^2 u + f(u,v)$$
$$\frac{\partial v}{\partial t} = D_v \nabla^2 v + g(u,v)$$

$u$ = Aktivator (lokale Verstärkung), $v$ = Inhibitor (weitreichende Dämpfung). Das Verhältnis der Diffusionsraten $D_u / D_v$ bestimmt welches Muster entsteht. Direkte biologische Grundlage: Hautmuster, Herzrhythmus, chemische Wellen in Zellkulturen.

---

## 6 — Was all das verbindet: Die medienkünstlerische Lesart

Das Interessante ist nicht das Modell — sondern was das Modell über Kontrolle sagt.

**Biologische Systeme:**
- Kein Programmierer
- Kein Debugger
- Kein Reset
- Verhalten emergiert aus den Regeln der Physik

**Zelluläre Automaten & Life Simulations:**
- Der Künstler/Entwickler setzt die **Regeln** — nicht das **Verhalten**
- Das Verhalten ist prinzipiell nicht vorhersagbar (Turing-Vollständigkeit)
- Das System überrascht seinen Erschaffer

> Das ist der Unterschied zwischen *Programmieren* und *Züchten*. Bei Life Simulations züchtet man Verhalten aus Regeln — wie Bakterien ihre Populationsdynamik aus DNA züchten.

**Drei Fragen für die Praxis:**

1. **Was ist das Regelset?** — DNA / `B3/S23` / Faltungskernel / Differentialgleichung
2. **Was sind die Anfangsbedingungen?** — Startkonfiguration bestimmt alles (Schmetterlings-Effekt)
3. **Was ist die Kapazitätsgrenze?** — Nährstoffe / Gittergröße / Rechenzeit

Medienkunst mit Life Simulations ist oft die Frage: *Wer ist Autor wenn das Verhalten nicht vorhersehbar ist?*

---

## Referenzen & Weiterdenken

- **Lenia**: [chakazul.github.io/Lenia](https://chakazul.github.io/Lenia/) — im Browser spielbar
- **Neural CA**: Mordvintsev et al. *"Growing Neural Cellular Automata"* (2020), distill.pub
- **Reaction-Diffusion**: Karl Sims, Pearson's Parametermap, Gray-Scott Model
- **Turing 1952**: *"The Chemical Basis of Morphogenesis"* — Originaltext, kurz, lesbar

→ [[zellulaere_automaten]] für das formale Fundament der zellulären Automaten
→ [[quorum_sensing]] für das biologische Vorbild kollektiver Schwellenwert-Logik
→ [[artificial_bacteria_konzept]] für die Umsetzung dieser Prinzipien im physischen Werk
→ [[biosemiotik]] für die Frage: was *bedeutet* das Signal einer Zelle?
