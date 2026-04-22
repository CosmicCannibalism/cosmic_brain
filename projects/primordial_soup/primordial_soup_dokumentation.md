---
tags:
  - projekt
  - medienkunst
  - zellulaere_automaten
  - software
  - simulation
typ: dokumentation
bereich: projekt
status: in-progress
---

# Primordial Soup — Dokumentation

> Ein lebender Bildschirm. Kein Video, kein Loop — ein System das sich selbst erzeugt, verändert, zerfällt und neu beginnt. Die Frage ist nicht was es zeigt, sondern was es *ist* während es läuft.

**Verwandte Themen:** [[artificial_bacteria_konzept]] | [[zellulaere_automaten]] | [[quorum_sensing]] | [[biosemiotik]] | [[reaktions_diffusion]] | [[emergenz]] | [[pataphysik]] | [[turing_land_duchamp_land]] | [[konzept_moodboard]]

---

## Was es ist

*Primordial Soup* ist eine browserbasierte Echtzeit-Simulation auf Basis von [[zellulaere_automaten|Conway's Game of Life]] — erweitert um fünf konkurrierende Spezies, modulare LFO-Steuerung, Kamera-Interaktion und drei lebende Wissenschafts-Visualisierungen. Das System läuft auf einer einzigen HTML-Datei, braucht keinen Server, kein Framework, keine Bibliothek. Es ist vollständig autonom.

Die Arbeit existiert ausschließlich im Moment ihrer Ausführung. Kein Speicher, kein finales Bild — nur Zustand, Regel, Zeit.

---

## Das Bild und seine Schichten

### Die Simulation — [[zellulaere_automaten|Zellulärer Automat]]

Das Raster ist der Kern. Jede Zelle hat genau zwei Informationen: ihren Typ (wer sie ist) und ihr Alter (wie lange sie schon lebt). Alles andere — Farbe, Helligkeit, Bewegung — entsteht aus der Wechselwirkung dieser zwei Werte mit den acht Nachbarn.

Im **Classic Mode** gibt es keine fünf Spezies — aber auch keine Monochromie. Jede Zelle wird nach ihrer *Überlebenssituation* eingefärbt: Zellen die mit zwei Nachbarn überleben (Ränder, Gleiter-Flügel, isolierte Strukturen) leuchten in einem anderen Ton als Zellen die mit drei Nachbarn überleben (dichte Kerne, Still-Life-Zentren). Geburt ist ein dritter Ton. Mutation ein vierter. Das klassische Conway-Gitter wird zum chromatischen Zustandsraum — obwohl die Regeln identisch bleiben.

In den Mehr-Spezies-Modi konkurrieren fünf Typen um denselben Raum, jeder mit eigenen Geburts- und Überlebensbedingungen:

| Spezies | Charakter | Grundfarbe |
|---|---|---|
| **Pioneer** | klassisches Conway B3/S23 — der Standard | Cyan-Blau |
| **Spreader** | expansiv, kolonisiert dünn besiedelte Flächen | Violett |
| **Clusterer** | dichtes Wachstum, bleibt in Gruppen | Rot-Pink |
| **Nomad** | robust, überlebt auch in Isolation | Gelb |
| **Ghost** | zäh, lebt an Randzonen und Nahtstellen | Grün |

Alle fünf Farben sind gleichmäßig auf dem Farbkreis verteilt — 72° Abstand. Das bedeutet: Ein einziger `hueShift`-Parameter dreht die gesamte Palette synchron. Bei +72° tauschen Pioneer und Spreader die Farben. Bei +180° ist alles komplementär. Der Hue-Drift LFO macht daraus eine langsam atmende chromatische Bewegung.

### Das Farbsystem — Hue als lebendiger Parameter

Farbe ist hier kein Styling-Entscheid — sie ist Information. Sättigungsgrad und Farbton hängen direkt an Simulationsparametern. Der LFO kann den Hue oszillieren lassen. Die Kamera kann über Helligkeitszonen beeinflussen, welche Spezies geboren werden. Der Trail-Decay lässt vergangene Generationen als Spur im Bild stehen.

Das Bild ist ein Zeitschnitt durch einen laufenden Prozess — und es sieht so aus.

### Wissenschafts-Panels — lebende Diagramme

Drei kleine Panels in der oberen rechten Ecke sind keine Dekoration. Sie zeigen parallele lebende Systeme:

**// LORENZ ATTRACTOR** — Die chaotische Flugbahn im dreidimensionalen Phasenraum des Lorenz-Systems (σ=10, ρ=28, β=8/3). Ein System das deterministisch ist — und trotzdem unvorhersagbar. Die Bahn kehrt nie an denselben Punkt zurück. Zwei infinitesimal benachbarte Startpunkte divergieren ([[schmetterlings_effekt|Schmetterlingseffekt]]). Das ist kein Fehler, das ist die Struktur des Systems.

**// SEMIOSE SIGNAL** — Shannon-Entropie der aktuellen Speziesverteilung. Wenn alle Zellen einer Spezies angehören: Entropie = 0, maximale Ordnung. Wenn alle fünf gleichverteilt sind: Entropie = maximum, maximale Unordnung. Die Kurve zeigt in Echtzeit wo das System zwischen Kristall und Rauschen steht. Das ist [[biosemiotik|Biosemiotik]] als Messwert: die Informationsdichte des lebenden Systems.

**// QUORUM STATE** — Populationsanteil jeder Spezies als gestapelter Balken. Wenn eine Spezies kollabiert oder explodiert, ist es hier sofort sichtbar — bevor das Auge es im Raster erkennt. [[quorum_sensing|Quorum Sensing]] als visuelles Protokoll.

Diese drei Panels sind bewusst klein gehalten. Sie sind Instrumente, keine Präsentation.

---

## Die Bedienoberfläche — ein Hybrid

Das Steuerfeld ist verborgen. Es öffnet sich durch Klick, schließt sich wieder. Diese Entscheidung ist keine UX-Konvention — sie ist eine künstlerische Setzung: Das System soll primär als lebendiges Bild wahrnehmbar sein, nicht als Kontrollpanel mit Simulation dahinter.

Wenn das Panel offen ist, zeigt es:

**Simulation** — Wiedergabe, Muster-Seeds (Noise, Glider Gun, Pulsar, [[zellulaere_automaten|Langton Ant]]), Modi, Farbsystem, Zellgröße, Dichte

**Parameter-Sliders mit LFO-Routing** — Jeder Parameter kann einem der drei LFOs zugewiesen werden. Speed, Mutation, Trail, Radius, Hue, Saturation, Drift, Glow, Age Brightness — alle modulierbar, alle in Echtzeit

**LFO-Panel** — drei Low-Frequency-Oszillatoren mit Wellenform (sin/tri/rect/rnd), Geschwindigkeit (lo/mid/hi Range), Offset, Dämpfung (Attenuation), FM-Modulation zwischen LFOs, Pause. Jeder LFO visualisiert sich selbst als lebende Kurve.

**Preset-System** — vollständige Systemzustände als JSON speichern und laden. Das erlaubt komponierte Momente: reproduzierbare Stimmungen, Ausgangspunkte für Performances.

---

## Kamera-Interaktion — Körper als Eingriff

Die Kamera-Modi übersetzen Körperbewegung direkt in Systemeingriffe. Fünf Logiken, alle wählbar:

**Motion → Burst/Void** — Bewegungsintensität bestimmt ob Chaos oder Leere entsteht. Schwache Bewegung öffnet Voids — stille Löcher im Lebenden. Starke Bewegung wirft Chaos-Bursts an die Stelle der Bewegung im Raum. Das Bild antwortet auf Anwesenheit.

**Flow → Meteore** — Bewegungsrichtung wird zu Wurfvektor. Schnell nach rechts bewegen bedeutet: ein Meteor fliegt von links nach rechts durch das Grid. Der Körper wirft Steine in den Ozean.

**Zonen → Lokale Bursts** — Das Kamerabild ist in ein 3×3-Raster aufgeteilt. Jede Zone die Bewegung detektiert zündet einen lokalen Eingriff an der entsprechenden Position auf dem Canvas. Kopf oben links = Aktivität oben links in der Simulation. Proximale Kartografie.

**Stille = Tod** — Das System wartet. Nach ~5 Sekunden ohne Bewegung beginnt ein Void der von außen nach innen frisst. Bewegung unterbricht den Tod. Die Simulation stirbt wenn niemand da ist.

**Brightness → Species** — Die Helligkeit der bewegten Körperbereiche bestimmt welche Spezies gespawnt wird. Helle Zonen (Hände, Gesicht) gebären andere Typen als dunkle. Der Körper als Saatmaschine.

**Silhouette** — Hintergrund einmal einfrieren (`⊙ bg`-Button oder `B`-Taste), dann aus dem Bild treten. Wenn der Körper wieder ins Bild tritt, entstehen Zellen exakt dort wo er vom Hintergrund abweicht — unabhängig von Beleuchtungsniveau. Das Gesicht, die Hände, die Silhouette werden zur lebenden Zellmasse. Kein Tracking, keine KI — nur Differenz: Pixel die jetzt anders sind als vorher.

**Kanten** — Einfacher Sobel-Filter auf jedem Kamera-Frame. Zellen spawnen auf Kanten: Gesichtsumriss, Augen, Mund, Finger — die Kontur als Zeichnung aus lebenden Zellen. Keine Bewegung nötig, reines Bildmaterial.

**Verfolgung** — Die Zellkolonie folgt der Silhouette. Innerhalb der Körpermaske werden kontinuierlich Zellen gespawnt. Außerhalb der Maske sterben Zellen langsam ab. Wenn man sich bewegt bleibt eine kurz absterbende Spur hinter einem — und vor einem entsteht sofort neues Leben. Die Kolonie driftet nach, sie "jagt" die Form.

### Hintergrund einfrieren — `⊙ bg` / Taste `B`

Die Modi Silhouette, Kanten und Verfolgung brauchen einen Referenz-Hintergrund. Das System weiß sonst nicht was Körper ist und was Raum.

**Workflow:**
1. Kamera einschalten, Modus wählen
2. Aus dem Bild treten — nur der leere Raum ist sichtbar
3. `⊙ bg` klicken oder `B` drücken — das System friert diesen Moment ein
4. In den Raum zurücktreten — alles was jetzt anders ist als der eingefrorene Hintergrund, bist du

**Ideale Bedingungen:** Helle, gleichmäßige Wand hinter der Person (weiß oder hell), Licht von vorne, kein Gegenlicht (kein Fenster im Rücken). Bewegliches Licht (Schatten durch Wolken, wechselnde Quellen) verfälscht die Maske nach dem Einfrieren.

Alle sieben Modi sind über Buttons wählbar (Single-Select), die erst erscheinen wenn die Kamera aktiv ist. Die Verarbeitung läuft auf einem 80×45 Pixel-Miniaturbild — nur jeden dritten Frame. Performant auf einem MacBook.

---

## Medienkünstlerische Einordnung

### Zellulärer Automat als Medium

Game of Life ist 1970. Primordial Soup verwendet es nicht als historische Referenz, sondern als Arbeitsmaterial — als das niedrigste mögliche Regelwerk für [[emergenz|emergentes Leben]]. Die Erweiterung auf fünf Spezies ist keine Verbesserung des Conway-Systems, sie ist eine Übersetzung: Weg vom binären Zustand (tot/lebendig) hin zu einem [[anabolismus_katabolismus|metabolischen Spektrum]] (wer bist du, wie lange schon, unter welchem Druck).

Das entspricht dem Kern von [[artificial_bacteria_konzept]]: nicht mehr zwei Zustände, sondern fünf — Geburt, [[bakterielle_vermehrung|Expansion]], Stabilisierung, [[bakterielle_adaptation|Widerstand]], Auflösung.

### Echtzeit als Aussage

Die Arbeit gibt es nicht als Datei, nicht als Screenshot, nicht als Video. Sie existiert nur im laufenden Prozess. Jede Instanz ist einmalig — gleiche Parameter, verschiedene Zufallsseeds, anderer Körper vor der Kamera, andere Tageszeit. Der Preset-Export ist keine Konservierung, er ist ein Anker — ein Ausgangspunkt der den Prozess nicht fixiert, sondern orientiert.

Das ist [[pataphysik|Pataphysik]] im technischen Sinn: ein System das sein eigenes Einmaliges produziert.

### Das Bild als Protokoll

Die Info-Panels unten links zeigen Generation und Population. Zahlen im Bild — wie Vitaldaten auf einem Monitor. Das ist keine Metapher, das ist das System das über sich selbst berichtet. Die Wissenschafts-Panels zeigen parallele Systeme die laufen während das Hauptsystem läuft. Alles gleichzeitig, alles lebendig, alles im selben Frame.

Das Bild ist ein Protokoll eines laufenden Prozesses. Der Betrachter liest nicht — er beobachtet.

### Kamera und Körper

Die Kamera ist optional. Das System läuft ohne sie — autonom, geschlossen. Mit Kamera öffnet es sich für Eingriff. Diese Öffnung ist riskant: Bursts können das System destabilisieren, Voids können es leeren, Meteore können Strukturen zerstören die sich über Stunden gebildet haben.

Das ist keine Game-Mechanik, das ist ein Verhältnis: Der Körper kann zerstören was das System gebaut hat. Er kann aber auch neues Leben einbringen — Spezies-Seeding, Chaos der Ordnung nachfolgt. Die Kamera ist kein Controller, sie ist ein Eingriff.

---

## Technische Eckdaten

| Parameter | Wert |
|---|---|
| Format | Single-file HTML, kein Framework |
| Renderer | ImageData Pixel-Buffer (kein Canvas-API per Zelle) |
| Grid | variabel, 3–12px Zellgröße |
| Spezies | 5 (Classic: 3 Zustände) |
| LFOs | 3, FM-modulierbar |
| Kamera-Modi | 8 (Burst, Flow, Zonen, Stille, Brightness, Silhouette, Kanten, Verfolgung) |
| Wissenschafts-Panels | 3 (Lorenz, Entropie, Quorum) |
| Motion-Analyse | 80×45px, alle 3 Frames |
| Kamera-Auflösung | 320×240 (limitiert für Performance) |

---

## Offene Entwicklungslinien

- **Audio-Reaktion** — Mikrofon als Trigger-Quelle analog zur Kamera
- **Netzwerk-Spezies** — mehrere Browser-Instanzen die über WebSocket ihren Zustand teilen
- **Export als Druckvorlage** — Momentaufnahme → SVG → Holzschnitt-Vorlage für [[konzept_moodboard|Petroglyphen einer Denkmaschine]]
- **Metabolischer Modus** — pH-analoges Drift-System: Spezies beeinflussen globale Parameter die ihre eigene Überlebensfähigkeit verändern ([[reaktions_diffusion|Reaktions-Diffusion]] als Vorbild)

---

*Letzte Aktualisierung: 18. April 2026 — Kamera-Modi erweitert (Silhouette, Kanten, Verfolgung), Hintergrund-Capture dokumentiert*

---

## Generatives MIDI-Soundmapping & Künstlerisches Soundkonzept

> Siehe auch: [[artificial_bacteria_konzept]], [[emergenz]], [[quorum_sensing]], [[biosemiotik]], [[pataphysik]]

### Künstlerische Aussage

Das MIDI-System von *Primordial Soup* ist mehr als eine technische Erweiterung: Es ist ein künstlerisches Experiment, das die Prinzipien von Emergenz, Selbstorganisation und künstlichem Leben in den Klangraum übersetzt. Die Musik entsteht nicht durch Komposition im klassischen Sinn, sondern als hörbares Protokoll eines lebenden, generativen Systems. Der Mensch gibt nur den Rahmen vor (Instrumente, Effekte, Soundästhetik in Ableton), die eigentliche Komposition ist das Resultat der Interaktion zahlloser Zellen, Spezies und Ereignisse im Automaten. 

**Künstlerische Leitidee:**
Das System macht die Schönheit und Unvorhersehbarkeit von [[emergenz|emergenten Prozessen]] erfahrbar. Klang wird zum Medium für künstliches Leben, für kollektive Intelligenz, für das Wechselspiel von Ordnung und Chaos. Die Musik ist nie gleich, sie ist ein auditives Abbild des „Zustandsraums“ – ein klingendes, kosmisches Gehirn, das sich selbst beobachtet und verändert. Die Zuhörenden werden Zeug:innen eines Prozesses, nicht eines Werks. Das Soundmapping ist so gestaltet, dass es die Dynamik, Dichte und Ereignisse des Systems direkt in musikalische Parameter übersetzt. 

**Vault-Bezüge:**
- [[biosemiotik]]: Klänge als Zeichen und Signale eines künstlichen Ökosystems
- [[quorum_sensing]]: Cluster und Populationen steuern globale Soundparameter
- [[pataphysik]]: Musik als spekulatives Experiment, als Labor für Möglichkeiten
- [[artificial_bacteria_konzept]]: Zellen als Klangquellen, Bakterien als Komponisten

### Soundmapping & MIDI-Parameter

**Grundprinzip:**
Jede relevante Zellaktion (Geburt, Tod, Clusterbildung, Mutation, Events) erzeugt ein MIDI-Event. Die vier MIDI-Kanäle in Ableton werden mit unterschiedlichen Instrumenten/Sounds belegt. Die Musik ist generativ, der Mensch stellt nur die Instrumente ein, alles andere kommt aus dem System.

**Mapping-Tabelle:**

| Game of Life-Element         | MIDI-Event/Parameter         | Künstlerische Bedeutung / Soundidee                |
|-----------------------------|------------------------------|----------------------------------------------------|
| Zellgeburt (Birth)          | Note On (Pitch = X/Y-Pos)    | Neue Klangzelle, frischer Impuls, perkussiv/hell   |
| Zelltod (Death)             | Note Off / Release           | Klang verklingt, Dämpfung, Echo, Reverb            |
| Zell-Cluster (Nachbarschaft)| Velocity/CC (Anzahl Nachbarn)| Dichte, Lautstärke, Filter, Textur                 |
| Zellmutation (Regeländerung)| Modulation Wheel/CC          | Sound morphing, Glitch, Pitchbend                  |
| Lebensdauer einer Zelle     | Aftertouch/CC                | Entwicklung von Klangfarbe, z.B. langsam wachsend  |
| Gesamtaktivität im Grid     | Globaler CC (z.B. Filter)    | Dynamik, Dichte, Mastereffekte                     |
| **Burst-Event**             | CC#12, mehrere Noten         | Plötzliche Sound-Explosion, FX, rhythmische Welle  |
| **Meteor-Event**            | CC#13, tiefer Note-On        | Einschlag, Noise, globaler Effekt, Reverb/Glitch   |

**Empfohlene MIDI-CC-Parameter:**
- CC#1: Modulation (Grid-Aktivität, Dichte)
- CC#10: Pan (X-Position im Grid)
- CC#74: Brightness (Clustergröße)
- CC#12: Burst-Intensity (Event)
- CC#13: Meteor-Impact (Event)

**Kanalbelegung (Beispiel):**
- Channel 1: Percussion/Noise (Geburten, schnelle Impulse)
- Channel 2: Bass/Drone (Cluster, Dichte)
- Channel 3: Melodische Elemente (isolierte Zellen, Bewegung)
- Channel 4: FX/Glitch (Mutationen, Events)

### Chaos-Management & Event-Strategien

- **Event-Filterung:** Pro Zeiteinheit werden nur begrenzt viele MIDI-Events gesendet (z.B. max. 8–16 Noten pro 100ms), um Überflutung zu vermeiden.
- **Gruppierung:** Nahe beieinander liegende Zell-Events werden zu Akkorden oder rhythmischen Patterns zusammengefasst.
- **Dichtekontrolle:** Ein globaler CC (z.B. CC#1) steuert Lautstärke, Filter oder Effektintensität in Abhängigkeit von der Gesamtaktivität.
- **Randomisierung:** Velocity, Timing und CC-Werte werden leicht variiert, um organische, weniger maschinelle Klänge zu erzeugen.

**Spezielle Events:**
- **Burst:** Löst eine Welle von Noten und CC#12 aus, limitiert auf wenige gleichzeitige Noten, kann Delay/Distortion erhöhen.
- **Meteor:** Triggert einen tiefen, kurzen Sound (Note-On mit hoher Velocity + CC#13), globaler Effekt wie Reverb-Boost oder Filter-Sweep.

### Künstlerische Wirkung

Das System bleibt generativ und unvorhersehbar, aber durch Filterung, Gruppierung und gezielte CC-Steuerung entsteht eine kontrollierte, organisch-chaotische Klanglandschaft. Spezielle Events wie Meteor und Burst sorgen für dramaturgische Akzente und machen das System performativ spannend. Die Musik evoziert mikroskopische Prozesse, kollektive Intelligenz und die fragile Balance zwischen Ordnung und Chaos. Sie ist ein auditives Protokoll künstlichen Lebens – ein „klingendes Gehirn“ im Sinne des cosmic_brain Vaults.
