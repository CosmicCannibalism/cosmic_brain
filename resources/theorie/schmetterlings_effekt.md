---
tags:
  - theorie
  - algorithmus
  - emergenz
  - medienkunst
typ: theorie
bereich: theorie
---

# Schmetterlings-Effekt — Sensitive Abhängigkeit von Anfangsbedingungen

> Ein Schmetterling schlägt in Brasilien mit den Flügeln. Drei Wochen später Tornado in Texas. Nicht weil der Flügelschlag ihn *verursacht* — sondern weil das System so empfindlich auf Anfangsbedingungen reagiert dass minimale Unterschiede zu radikal verschiedenen Ergebnissen führen. Determinismus ohne Vorhersagbarkeit.

**Verwandte Themen:** [[zellulaere_automaten]] | [[emergenz]] | [[bakterielle_vermehrung]] | [[reaktions_diffusion]] | [[alan_turing]] | [[__cosmicbrain__]]

---

## Lorenz und das Wetterproblem

**Edward Lorenz**, Meteorologe am MIT, 1963. Beim Neustart einer Wettersimulation gibt er einen Anfangswert mit weniger Dezimalstellen ein: `0.506` statt `0.506127`. Das Ergebnis nach einigen simulierten Wochen: vollständig andere Wettermuster.

Erkenntnis: das System ist **deterministisch** — gegeben exakt derselbe Startzustand, kommt exakt dasselbe Ergebnis. Aber jede infinitesimal kleine Änderung der Anfangsbedingungen wächst exponentiell. Langfristige Vorhersage ist prinzipiell unmöglich.

### Der Lorenz-Attraktor

```
dx/dt = σ(y − x)
dy/dt = x(ρ − z) − y  
dz/dt = xy − βz
```

Standardparameter: σ=10, ρ=28, β=8/3. Die Lösung beschreibt eine Flugbahn im dreidimensionalen Phasenraum — nie schließt sie sich, nie wiederholt sie sich exakt, aber sie bleibt immer in einem begrenzten Bereich. Die charakteristische Schmetterlingsform.

---

## Formale Definition

Ein System zeigt **sensitive Abhängigkeit von Anfangsbedingungen** wenn:

$$\exists \varepsilon > 0 \, \forall \delta > 0 \, \exists t > 0 : |x_0 - y_0| < \delta \Rightarrow |x(t) - y(t)| > \varepsilon$$

Auf Deutsch: Es gibt immer eine Zeit $t$ nach der zwei Bahnen — egal wie nah ihre Startpunkte — weiter als $\varepsilon$ voneinander entfernt sind.

Der **Lyapunov-Exponent** $\lambda$ misst die Rate der Divergenz. $\lambda > 0$ → chaotisches System.

---

## Chaos ≠ Zufall

Der häufigste Irrtum:

| | Chaos | Zufall |
|---|---|---|
| Determinismus | **ja** | nein |
| Reproduzierbar | **bei exakt gleichem Start** | nein |
| Vorhersagbar | langfristig nicht | nie |
| Struktur | **Attraktoren, Fraktale** | keine |

Chaos ist **deterministische Unvorhersagbarkeit**. Das System folgt Regeln — aber die Regeln erzeugen Sensitivität.

---

## Schmetterlings-Effekt in Life Simulations

Conway's [[zellulaere_automaten|Game of Life]] ist Turing-vollständig und deterministisch. Aber:

**Experiment:** Starte zwei identische Konfigurationen und ändere eine einzige Zelle. Nach wenigen Generationen: vollständig verschiedene Muster.

Die Startkonfiguration ist das "Programm" des Systems. Kein Designer kennt die Ausgabe nach 1000 Generationen. Das System ist nicht zufällig — es ist sensibel.

```
Generation 0:    ■ □ □ ■ □            ■ □ □ □ □
                 □ ■ □ □ □            □ ■ □ □ □
                 □ □ ■ □ □            □ □ ■ □ □
                 [Startkonfig A]      [Konfig B — eine Zelle anders]

Generation 50:   [völlig verschiedene Muster]
```

**In Reaktions-Diffusions-Systemen:** Kleine Parametervariationen ($F$ ± 0.001 im Gray-Scott) erzeugen qualitativ völlig verschiedene Mustertypen — Übergang zwischen Spots und Worms liegt auf einer Linie.

---

## Die drei Konsequenzen

### 1. Autorschaft wird relational
Wer ein chaotisch-sensitives System entwirft, entscheidet über die Regeln — nicht über das Ergebnis. Die Startkonfiguration ist Mitautor. Bei interaktiver Kunst: der Besucher, der die erste Zelle setzt, ist Mitautor.

### 2. Simulation ersetzt Vorhersage
Bei sensitiven Systemen gibt es keine schnellere Vorhersage als das System selbst ablaufen zu lassen. Keine Formel, kein Kürzel. Das ist der Grund warum Wettervorhersage über 10 Tage prinzipiell unzuverlässig wird — nicht wegen mangelnder Rechenleistung, sondern wegen Physik.

### 3. Geschichte ist unwiederholbar
Dieselben Regeln, andere Anfangsbedingungen → anderes Universum. Das Schmetterlingssystem trennt Regelkenntnis von Verlaufskenntnis. Man kann das System vollständig verstehen und trotzdem nicht wissen was es tut.

---

## Medienkünstlerische Perspektive

Das Konzept transformiert wie man über generative Systeme denkt:

**Nicht:** "Das System tut was ich will"  
**Sondern:** "Das System tut was die Anfangsbedingungen erzwingen"

Die Anfangsbedingungen sind die Komposition. Das Ablaufen ist die Aufführung. Beide Male ist die Ausgabe dasselbe — aber nur wenn die Bedingungen atomgenau identisch sind. Jede Aufführung ist einzigartig.

In der Praxis: ein interaktives System das Chaos implementiert ist nicht "unzuverlässig" — es ist **historisch**. Jede Begegnung hinterlässt eine Spur die nicht reproduzierbar ist.

---

## Summary (EN)

Sensitive dependence on initial conditions (the "butterfly effect") was formalised by Lorenz (1963): deterministic systems can exhibit exponential divergence from arbitrarily close starting points. The Lorenz attractor visualises this — bounded, never repeating. Lyapunov exponent λ > 0 characterises chaos. Crucially: chaos ≠ randomness. The system is fully deterministic, but long-term prediction is structurally impossible regardless of computational power. In generative art: starting conditions are the composition, execution is the performance, and no two runs are identical unless conditions are exact to infinite precision.
