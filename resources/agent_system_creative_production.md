# Agent-System für kreative Produktion — Gesprächszusammenfassung

---

## 1. Kontext: Einzelner Künstler / cosmicbrain

Ein Agent-System ermöglicht einer einzelnen Person die Ausgabe eines ganzen Produktionsteams zu erreichen. Der Künstler behält volle kreative Kontrolle — das System übernimmt Ausführung, Übersetzung und Konsistenz.

### Das Modell

```
DU (Vision, Entscheidungen, Handwerk in den Tools)
│
├── baust in Figma          → Agent liest aus, generiert Code
├── animierst in AE         → Lottie-Export, Agent bindet ein
├── definierst Principles   → Agent wendet an auf alles
├── reviewst Outputs        → Agent iteriert
│
└── ERGEBNIS: produktionsreife App
```

### Workflow-Prinzip

- **Figma** als visuelle Quelle: Komponenten, Design Tokens, Varianten, Prototype-Transitions
- **After Effects → Lottie** für Animationen: Handwerk bleibt beim Künstler, Export wird automatisch eingebunden
- **Principles Layer**: ästhetische Regeln einmalig definiert, gelten für alle Outputs
- **Agent**: liest Tools aus, generiert Code (HTML/CSS/QML), hält Konsistenz, iteriert auf Feedback

### Wo der Mensch reinkommt

| Agent | Mensch |
|---|---|
| Tokens extrahieren & übersetzen | Gefühl und Ästhetik-Entscheidungen |
| Inkonsistenzen finden | Review ob Output zur Vision passt |
| Boilerplate generieren | Animationen und Motion-Handwerk in AE |
| Struktur dokumentieren | Business-Logik und Edge Cases |

### Technologie-Empfehlung

**QML (Qt Quick)** als Zielplattform — deklarativ, designnah, States und Transitions als First-Class-Konzepte. Passt am besten zum Figma-Denken und ist gut agent-generierbar.

```
Figma-Variante  →  QML State
Figma-Transition →  QML Transition / Behavior
Design Token    →  Theme.qml Objekt
AE-Animation    →  Lottie JSON → LottieAnimation { }
```

### Subagent-Architektur (wenn nötig)

```
PRINCIPLES LAYER (einmalig definiert)
        ↓
├── Figma-Agent      → liest/extrahiert Design
├── Motion-Agent     → AE/Lottie einbinden
├── Code-Agent       → generiert QML-Komponenten
└── Review-Agent     → prüft gegen Principles
```

---

## 2. Kontext: stellar design und engineering

[stellar](https://www.stellar.de/) (Ulm, gegründet 1996) entwickelt High-End Interaction Design für Automotive, Application und Mobile. ~50-köpfiges Team aus Interaction- und Industriedesignern, Informatikern und Ingenieuren. Kunden aus Transportation, Automotive, Telekommunikation.

*"Bevor wir über die Gestalt nachdenken, interessiert uns der Kontext, die Nutzergruppe und die Funktion."*

### Relevanz des Agent-Systems

Für ein Büro wie stellar adressiert das Agent-System die zentralen Effizienz- und Qualitätshebel im High-End Interaction Design Prozess.

### Design → Code Pipeline

- **Figma MCP**: Design Tokens und Komponentenstruktur automatisch in Qt/QML übersetzen
- Konsistenz über große Projekte und mehrere Designer hinweg ohne manuelle Synchronisation
- Token-Änderungen propagieren automatisch durch die gesamte Codebasis
- Figma-Varianten → QML States: 1:1 Mapping, agent-generierbar

### Qt / QML als Kern

stellars Automotive- und HMI-Fokus passt direkt zu Qt/QML als Produktionstechnologie:

```
Figma-Komponente  →  Agent generiert .qml-File
AE-Animation      →  Lottie → Qt Quick LottieAnimation
Design Token      →  Theme.qml (zentral, versioniert)
Qt Widgets        →  Architektur / Platform-Integration
QML              →  alle visuellen und animierten Schichten
```

### Principles Layer als Unternehmens-IP

stellars Gestaltungsauffassung (sachlich, hochwertig, funktional, nutzerzentriert) wird maschinenlesbar:

- CI als Ruleset — nicht nur als PDF-Guideline
- Motion Design System: Timing-Tokens, Easing-Kurven, Hierarchy of Motion
- Beispiel-Bibliothek: *"mach es wie X, nicht wie Y"* — Referenzen statt Regeln
- Review-Agent prüft jeden Output gegen diese Constraints

### Effizienzgewinn für das Team

| Heute (manuell) | Mit Agent-System |
|---|---|
| Figma → QML: Stunden pro Komponente | Agent regeneriert bei Figma-Update |
| Tokens manuell synchron halten | Automatisch propagiert |
| Junior-Output variiert in Qualität | Principles eingebettet als Constraint |
| Neues Projekt: von vorne aufsetzen | Erbt alle Principles automatisch |

**Der Engpass verschiebt sich von Ausführung zu Entscheidung** — dort wo stellars Expertise als Pioniere im Interaction Design den größten Wert hat.

### Offene Punkte

- Schreibzugriff in Figma via MCP noch limitiert (Lesen ist produktionsreif)
- Complex Interaction Logic und Business-Logik bleiben manuell
- Einmaliger Aufwand: Principles Layer sauber definieren und pflegen
- Feedback-Loop: abgelehnte Agent-Outputs müssen ins System zurückfließen

---

### Perspektive: Entwickler bei stellar

stellar hat Informatiker und Ingenieure im Team — für diese verändert das Agent-System nicht nur die Arbeitsgeschwindigkeit sondern die Art der Arbeit fundamental.

#### Was sich verbessert / erleichtert

**Boilerplate und Scaffolding**
- QML-Komponenten aus Figma-Spezifikation generieren lassen statt von Hand ableiten
- Property-Bindings, States, Transitions: Agent kennt die Figma-Struktur und schreibt die Verdrahtung
- Neue Features erben automatisch das bestehende Theme-System — kein manuelles Nachziehen

**Debugging und Konsistenz**
- Agent prüft ob generierter Code gegen die definierten Principles verstößt — noch vor Code-Review
- Tokens in Theme.qml ändern sich → Agent identifiziert alle betroffenen Komponenten
- Regression-Checks: Agent vergleicht Visual Output vor/nach Änderung gegen Figma-Referenz

**Plattform-Komplexität managen**
- Qt läuft auf Embedded Linux, QNX, Windows, Android — Plattform-spezifische Anpassungen kann der Agent systematisch ausrollen
- HMI-Targets mit unterschiedlichen Auflösungen und DPIs: Agent generiert passende Skalierungslogik aus Figma-Constraints
- Safety-relevante Anforderungen (Automotive): Agent kann als erster Filter für Compliance-Checks eingesetzt werden

#### Wo Entwickler weiter denken können

**Agent als Architektur-Sparringspartner**
Nicht nur Code generieren lassen — sondern den Agenten aktiv in Architekturentscheidungen einbeziehen. Welche QML-Struktur ist bei diesem Interaction-Pattern wartbarer? Wo ist Qt Widgets besser als QML? Der Agent kann Optionen durchspielen, der Entwickler entscheidet.

**Custom MCP Server für interne Tools**
stellar könnte einen eigenen MCP Server entwickeln der:
- das interne Komponentensystem exponiert
- Projekt-spezifische Constraints und Plattform-Infos bereitstellt
- Build-System (Qt Creator / CMake) anbindet
Das wäre proprietary tooling — ein echter Wettbewerbsvorteil.

**Generative Tests aus Figma-Specs**
Figma-Prototypen beschreiben Interaction-Flows. Agent könnte daraus automatisch QML-Tests generieren — jeder definierte State ist ein Testcase. Das schließt die Lücke zwischen Design-Spec und QA.

**Semantic Versioning für Design Tokens**
Token-Änderungen haben Breaking-Change-Potenzial im Code. Ein Agent-Workflow der Token-Diffs analysiert und automatisch einschätzt welche Änderungen breaking sind gibt Entwicklern frühzeitig Kontrolle über Release-Planung.

**Wissenstransfer und Onboarding**
stellars Projekte sind komplex, Automotive-HMI hat steile Lernkurven. Ein Agent der das Komponentensystem, die Principles und die Plattform-Eigenheiten kennt ist ein permanenter Onboarding-Assistent — neues Teammitglied stellt Fragen, Agent antwortet mit projektspezifischem Kontext.

#### Das größere Bild für Entwickler

Der Shift ist: **vom Übersetzer zum Architekten.**

Heute verbringen Entwickler einen erheblichen Teil damit Design-Intent in Code zu übersetzen — Token-Werte nachschlagen, States ableiten, Pixelwerte übertragen. Das ist notwendig aber nicht die eigentliche Expertise.

Mit Agent-System fällt dieser Übersetzungsanteil weg. Was bleibt — und mehr Raum bekommt — ist die eigentliche Ingenieursarbeit: Systemarchitektur, Performance-Optimierung auf Embedded-Targets, Plattform-Integration, Safety und die wirklich schwierigen Interaction-Probleme die kein Agent alleine löst.

---

### Perspektive: Designer bei stellar

Interaction Designer und Industriedesigner sind bei stellar die primäre gestalterische Kraft. Für sie verändert das Agent-System vor allem den Feedback-Loop und die Reichweite ihrer Entscheidungen.

#### Was sich verbessert / erleichtert

**Vom Prototyp zum echten Verhalten — sofort**
Der größte Bruch im HMI-Design ist zwischen Figma-Prototyp und realem Code. States die im Prototype-Modus "irgendwie" funktionieren verhalten sich im QML-Target anders — andere Timing-Charakteristik, andere Easing, andere Performance. Mit Agent-Pipeline ist die Lücke kleiner: generierter QML-Code aus der Figma-Struktur läuft früher auf echtem Hardware, Designer sehen früher die Realität.

**Token-Änderungen ohne Entwickler-Ticket**
Heute: Designer ändert Farbe in Figma → Ticket → Entwickler zieht Token nach → Review → Merge. Mit Agent: Token ändert sich in Figma → Agent propagiert durch Codebasis → Designer sieht Diff. Der Loop wird direkter. Kleinere Korrekturen brauchen keine Entwickler-Kapazität.

**Review auf echten Targets**
Agent kann einen Screenshot/Render des generierten Outputs auf verschiedenen Display-Targets (Dashboard 12", Instrument Cluster 7", HUD) automatisch gegen die Figma-Specs prüfen. Designer bekommt Abweichungen gemeldet bevor der Code-Review beginnt.

#### Wo Designer weiter denken können

**Figma als Single Source of Truth — konsequent**
Wenn der Agent aus Figma generiert muss Figma wirklich vollständig sein: alle States, alle Varianten, alle Edge Cases. Das zwingt Designer zu mehr Präzision in der Spec — was auf den ersten Blick nach Mehraufwand aussieht aber in Wirklichkeit Nachverhandlungen in der Entwicklungsphase eliminiert.

Das ist eine kulturelle Verschiebung: von *"wir klären das noch im Dev"* zu *"wenn es nicht in Figma ist, existiert es nicht."*

**Motion als Designentscheidung — nicht als Entwickler-Interpretation**
Heute landen Timing-Entscheidungen oft beim Entwickler weil die Spec nicht präzise genug ist. Mit einem Motion Design System (Timing-Tokens, Easing-Kurven als benannte Werte in Figma) und einem Agent der diese 1:1 überträgt, bleibt Motion in der Hand des Designers. Die Kurve die im Figma-Prototyp definiert ist, ist die Kurve die ausgeliefert wird.

**Systematisch denken statt Einzelscreens**
Wenn jede Design-Entscheidung durch den Agent-Filter geht und auf das gesamte System angewendet wird, hat jede Entscheidung mehr Gewicht. Designer können (und müssen) mehr in Systemen denken: Was bedeutet diese Farbentscheidung für alle Dark-Mode Varianten? Was bedeutet dieser Spacing-Wert für alle Touch-Target-Größen auf allen Targets?

Der Agent macht Konsequenzen sichtbar die vorher im manuellen Prozess unsichtbar blieben.

**Design-Critique mit Agent-Unterstützung**
Agent kann als strukturierter Gegenüber in der Kritik eingesetzt werden: *"Hier sind 3 Varianten — welche hält sich am besten an unsere Principles?"* Nicht als Entscheidungsinstanz sondern als schnellen Resonanzboden der Argumente liefert bevor die Gruppe diskutiert.

#### Das größere Bild für Designer

Der Shift ist: **von der Einzelentscheidung zur Systemverantwortung.**

Mit Agent-Pipeline trägt jede Design-Entscheidung weiter — sie wirkt auf mehr Komponenten, mehr Targets, mehr States. Das ist Macht und Verantwortung zugleich. Designer die in Systemen denken können werden erheblich wirksamer. Solche die im Einzelscreen denken werden schneller mit den Konsequenzen ihrer Entscheidungen konfrontiert.

Für stellar — mit dem Anspruch *"sachliche Gestaltung und höchste Qualität"* — ist das kein Problem sondern eine natürliche Entsprechung: wer so denkt hat schon immer systematisch gearbeitet, das Agent-System gibt diesem Denken einfach mehr Reichweite.

---

### Neue Märkte — Chancen durch Agent-System

Die Automobilindustrie steht unter massivem Druck: OEM-Budgets schrumpfen, chinesische Konkurrenz drückt auf Margen, die EV-Transition bindet Kapital. Für stellars bisherigen Kern-Kundenkreis bedeutet das Zurückhaltung bei Investitionen in neue HMI-Projekte.

Das Agent-System ist hier kein Luxus sondern ein strategisches Mittel um **stellars Expertise in neue Branchen zu skalieren** — ohne jedes Mal von vorne aufzubauen.

#### Die Logik dahinter

Stellars eigentliches Asset ist nicht der Automotive-Fokus. Es ist die Fähigkeit **komplexe, sicherheitsrelevante, hochwertige Interaktion** zu gestalten und zu implementieren. Das ist in anderen Industrien genauso gefragt — und oft noch weniger abgedeckt.

Mit einem Agent-System wird der Einstieg in neue Branchen signifikant günstiger:
- Principles Layer einmal definiert → per Branche angepasst, nicht neu erfunden
- QML/Qt-Komponentenbibliothek portierbar auf neue Targets
- Figma → Code Pipeline funktioniert branchenunabhängig
- Einarbeitungszeit in neue Domänen sinkt weil das Handwerk schon systemisch eingebettet ist

#### Konkrete Branchen mit Potential

**MedTech / Medizintechnik**
Medizinische Geräte — Ultraschall, OP-Systeme, Patientenmonitoring, Laborautomation — haben ähnliche Anforderungen wie Automotive HMI: Safety-relevanz (IEC 62304, FDA), embedded Targets, komplexe States, hohe Qualitätsanforderungen. Der Markt wächst strukturell und ist in Europa nicht von chinesischer Konkurrenz dominiert. Qt ist in MedTech bereits etabliert.

**Rail / Öffentlicher Nahverkehr**
Europäische Schieneninfrastruktur wird massiv ausgebaut (Klimaziele, Mobility-Shift). Führerstandsysteme, Fahrgastinformation, Leitsysteme — alles HMI-Domänen mit Safety-Anforderungen (EN 50128). Wenige Büros können hier sowohl Design als auch technische Implementierung. stellar könnte.

**Industrielle Steuerung / Industry 4.0**
Fabrikautomation, Maschinensteuerungen, SCADA-Interfaces — historisch hässlich und schwer bedienbar. Mit steigendem Fachkräftemangel wird gute Bedienbarkeit industrieller Systeme ein echter Wettbewerbsfaktor. Agent-System erlaubt stellar schnell ganze Komponentenbibliotheken für neue Maschinenhersteller aufzubauen.

**Energie / Renewables**
Leitstellen für Wind- und Solarparks, Energiemanagement-Systeme, Smart Grid Interfaces — enormer Investitionsbedarf durch Energiewende. Komplexe Datenvisualisierung, Echtzeit-Monitoring, Safety. Qt läuft auf den entsprechenden Industrial-Targets.

**Verteidigung / Defense**
Europa erhöht Rüstungsausgaben strukturell. Fahrzeug-HMI, taktische Displays, Lagebilder — hohe Anforderungen an Robustheit und Bedienbarkeit unter Stress. Ähnliche Qualitätsanforderungen wie Automotive, aber weniger preissensitiv.

#### Wie das Agent-System den Markteintritt beschleunigt

```
Neue Branche (z.B. MedTech)
        ↓
Branchenspezifische Constraints ergänzen (IEC 62304, FDA-Anforderungen)
        ↓
Principles Layer von Automotive adaptieren, nicht neu aufbauen
        ↓
Erste Komponenten-Bibliothek in Wochen statt Monaten
        ↓
Pitch mit funktionalem Prototyp auf echtem Target
```

Ohne Agent-System: neues Team, neuer Stack, neue Einarbeitungszeit — jeder Branchen-Einstieg ist ein Neustart. Mit Agent-System: stellars HMI-Expertise wird portierbar.

#### Das strategische Bild

Die Automotive-Krise ist für stellar ein Zeitfenster. Branchen wie MedTech, Rail und Energie suchen genau das was stellar kann — aber sie haben noch keinen Lieferanten mit dieser Kombination aus Design-Qualität und technischer Tiefe.

**Der Engpass ist nicht Expertise — der Engpass ist Kapazität und Einstiegsgeschwindigkeit.**

Ein Agent-System löst genau das: kleineres Team, schnellerer Einstieg, keine Qualitätseinbuße. Das ist kein Wachstumsstrategie für bessere Zeiten — das ist ein Resilienz-Tool für jetzt.

---

### Subagent als Domain-Expert: Designer schnell in neue Branchen bringen

Wenn stellar in MedTech, Rail oder Energie einsteigt, steht der Designer vor einer echten Frage: *Ich kann Interaction Design — aber ich kenne die Branche nicht.* Was sind die regulatorischen Constraints? Wie denken Ärzte, Operateure, Lokführer? Welche mentalen Modelle haben die Nutzer? Welche Fehler darf das Interface nie produzieren?

Heute bedeutet das Monate Einarbeitung oder externe Berater. Mit einem branchenspezifischen Subagenten komprimiert sich das.

#### Das Prinzip: Domain-Agent als permanenter Gegenüber

Der Subagent wird nicht als Code-Generator eingesetzt sondern als **eingebetteter Domänen-Experte** der parallel zur Designarbeit läuft.

```
Designer arbeitet in Figma
        ↓
Stellt dem Domain-Agent Fragen während der Arbeit
        ↓
Agent kennt: Regularien, Nutzergruppen, Normen,
             Fehlermuster der Branche, Best Practices
        ↓
Designer trifft informiertere Entscheidungen
— ohne die Arbeit zu unterbrechen
```

Kein separates Recherche-Projekt. Kein Warten auf den nächsten Workshop. Die Domänen-Expertise ist im Workflow eingebettet.

#### Konkret: MedTech Domain-Agent

Ein MedTech-Agent für stellar würde folgendes wissen:

**Regulatorik als Designconstraint**
- IEC 62366 (Usability Engineering für Medizinprodukte): welche Anforderungen hat ein Usability-Test zu erfüllen?
- FDA Human Factors Guidance: was sind Use Error Analysen, wie fließen sie in Figma-States ein?
- Was muss dokumentiert sein damit eine Zulassung möglich ist?

**Nutzergruppen und mentale Modelle**
- Wie arbeitet ein Chirurg im OP (Stress, Sterilität, eingeschränkte Motorik)?
- Wie arbeitet ein Radiologe (Bild-zentriert, schnelle Klassifikation, hohe Wiederholung)?
- Wie arbeitet ein Intensivpfleger (multiple Geräte, Alarme, Zeit-Druck)?

**Visuelle und Interaction-Konventionen der Branche**
- Warum sind medizinische Interfaces oft bewusst konservativ?
- Welche Farbcodierungen sind normiert (z.B. ISO 80601 Alarmfarben)?
- Was sind bekannte Fehlermuster aus der Medizintechnik-Literatur?

**Fragen die der Designer während der Arbeit stellen kann:**
> *"Ich habe hier einen Bestätigungs-Dialog für eine kritische Aktion — ist eine zweistufige Bestätigung nach IEC 62366 ausreichend oder brauche ich mehr?"*

> *"Ich plane ein rotes Element für eine Warnung — gibt es Konflikte mit normierten Alarmfarben?"*

> *"Der Nutzer ist ein OP-Assistent mit sterilen Handschuhen — welche Touch-Target-Größen sind realistisch?"*

Der Agent antwortet sofort. Der Designer muss nicht recherchieren, muss kein Buch aufschlagen, muss keinen Berater anrufen.

#### Aufbau eines Domain-Agents — wie das geht

Ein solcher Agent ist keine Black Box sondern eine strukturierte Wissensbasis:

```
Domain-Agent MedTech
├── Normen-Kontext:    IEC 62366, FDA HF, ISO 62304 (zusammengefasst)
├── Nutzer-Profile:    Chirurg, Radiologe, Pfleger, Techniker (Personas mit Kontext)
├── Fehlermuster:      bekannte Use Errors aus der Literatur
├── Visuelle Normen:   Alarmfarben, Touch-Targets, Lesbarkeit auf Targets
├── Projektwissen:     aktuelles Projekt, Kunde, spezifische Anforderungen
└── Principles Layer:  stellars Gestaltungsauffassung — hier auf MedTech angewendet
```

Der Agent lernt aus jedem Projekt: abgelehnte Designs, gefundene Edge Cases, Kundenfeedback fließen zurück. Nach zwei MedTech-Projekten ist der Agent erheblich spezifischer als nach dem ersten.

#### Was das für das stellar-Team bedeutet

Ein Interaction Designer bei stellar muss nicht mehr Branchenexperte sein bevor er anfangen kann — er wird es **während** der Arbeit, Schritt für Schritt, projektbegleitend.

| Ohne Domain-Agent | Mit Domain-Agent |
|---|---|
| Wochen Einarbeitung vor Projektstart | Recherche läuft parallel zum Design |
| Externer Berater für Regulatorik | Agent gibt sofortige Orientierung |
| Fehler werden im Usability-Test gefunden | Viele Fehlermuster werden früher ausgeschlossen |
| Jedes neue MedTech-Projekt startet neu | Agent kumuliert Wissen über Projekte hinweg |
| Senior muss Junior briefen | Agent übernimmt strukturiertes Domänen-Briefing |

Das ist kein Ersatz für echte Branchenerfahrung — die entsteht über Zeit und echte Projekte. Aber es komprimiert den Weg dorthin erheblich. Und es erlaubt stellar **sofort** glaubwürdig in eine neue Branche einzusteigen, ohne auf die fertige Expertise warten zu müssen.

---

### Agent-System in der Kundenkommunikation

Kundenkommunikation ist bei einem Büro wie stellar keine Nebensache — es ist ein erheblicher Zeitaufwand. Briefings, Präsentationen, Konzeptpapiere, Statusupdates, Angebote, Spezifikationen. Vieles davon ist hochwertige Arbeit die Expertise erfordert aber nicht direkt gestalterisch ist.

Ein Agent-System verändert hier die Ökonomie dieser Arbeit grundlegend.

#### Pitch und Neukundengewinnung

Der teuerste Moment in der Kundenkommunikation ist der Pitch in eine neue Branche: man muss zeigen dass man die Branche versteht, bevor man einen Auftrag hat. Heute bedeutet das erhebliche Vorinvestition ohne Sicherheit.

Mit Domain-Agent und bestehender Komponentenbibliothek:

```
Pitch-Anfrage MedTech-Kunde
        ↓
Domain-Agent: Branchenkontext, Normen, typische Schmerzpunkte
        ↓
Agent generiert ersten Entwurf Konzeptpapier / Executive Summary
        ↓
Designer / Projektleiter verfeinert, fügt stellars Perspektive ein
        ↓
Prototyp aus bestehenden QML-Komponenten — angepasst auf MedTech-Kontext
        ↓
Pitch in Tagen statt Wochen — mit echtem funktionalem Material
```

Der Kunde sieht beim ersten Gespräch bereits einen konkreten Prototypen der seine Sprache spricht. Das ist ein anderer Einstieg als eine Folienpräsentation.

#### Während des Projekts: Statusupdates und Reviews

Projektbegleitende Kommunikation ist oft ineffizient: Was wurde gemacht? Was ist der nächste Schritt? Was braucht der Kunde zu entscheiden?

Agent-unterstützte Projektkommunikation:
- **Automatische Statuszusammenfassung**: Agent fasst zusammen was seit letztem Update in Figma und Code verändert wurde — in kundentauglicher Sprache, nicht in technischen Terms
- **Entscheidungsdokumente**: Agent bereitet offene Designentscheidungen als strukturierte Optionen auf, Projektleiter ergänzt Empfehlung und Kontext
- **Meeting-Vorbereitung**: Agent kennt Projektstand und Kundenhistorie — erstellt Agenda und relevante Fragen für das nächste Kundengespräch

#### Angebote und Spezifikationen

Angebote für komplexe HMI-Projekte sind aufwändig: Scope definieren, Aufwände schätzen, Risiken benennen, Leistungen abgrenzen. Jedes Mal von vorne.

Mit Agent:
- Scope-Beschreibung aus Briefing-Notizen und Figma-Bestand ableiten lassen
- Aufwandsschätzung auf Basis vergangener Projekte (wenn Projekthistorie im System ist)
- Standardbausteine für Leistungsbeschreibungen — branchenangepasst durch Domain-Agent
- Erster Entwurf in Stunden, nicht Tagen — Projektleiter korrigiert und zeichnet ab

#### Sprache die den Kunden trifft

Hier ist ein subtiler aber wichtiger Punkt: **verschiedene Kunden sprechen verschiedene Sprachen.**

Ein Automotive-Ingenieur denkt in Requirements, FMEAs, Freigabeprozessen. Ein MedTech-Entwicklungsleiter denkt in Zulassungsrisiken, Use Errors, Clinical Evaluations. Ein Energie-Projektleiter denkt in Verfügbarkeit, Ausfallkosten, Normenkonformität.

Der Domain-Agent kennt diese Sprachen. Er kann denselben Sachverhalt — *"wir haben den primären Workflow vereinfacht"* — in der Sprache des jeweiligen Kunden formulieren. Das ist nicht Rhetorik sondern Verständnis: wer in der Sprache des Kunden spricht zeigt dass er seine Welt versteht.

```
Design-Entscheidung (intern)
        ↓
Domain-Agent übersetzt in Kundensprache
        ↓
Automotive:   "reduced task completion time, supports SOTIF requirements"
MedTech:      "reduces use error probability, supports IEC 62366 task analysis"
Rail:         "operator workload reduction, EN 50128 human factors alignment"
```

#### Das größere Bild

Kundenkommunikation ist heute oft der Flaschenhals der nicht als Flaschenhals wahrgenommen wird — weil er verteilt ist über viele kleine Aufwände. Briefing nachlesen, Präsentation aufbauen, Angebot formulieren, Update schreiben.

Mit Agent-Unterstützung wird dieser Flaschenhals sichtbar und dann kleiner. Das bedeutet nicht weniger Qualität in der Kommunikation — im Gegenteil. Wer weniger Zeit mit Formulieren verbringt hat mehr Zeit für die eigentliche Entscheidung: *Was wollen wir diesem Kunden sagen? Was ist unsere Position?*

Das ist der gleiche Shift wie in der Designarbeit: von Ausführung zu Entscheidung.

---

## 3. Wie baut man solche Agents — durch Vibe Chatting

Agents klingen komplex. In der Praxis beginnt der Aufbau nicht mit Architektur-Diagrammen oder Code — sondern mit Gesprächen. Das ist Vibe Chatting: iterativ, explorativ, durch Sprache.

### Das Prinzip

Du brauchst keine Programmierkenntnisse um einen nützlichen Agent zu bauen. Du brauchst die Fähigkeit **zu beschreiben was du willst** — und die Bereitschaft mehrmals zu sagen *"nein, nicht so — eher so."*

Das ist kein Witz. Ein Agent entsteht durch genau diesen Loop:

```
Beschreib was der Agent wissen / können soll
        ↓
Agent antwortet — oft nicht ganz richtig
        ↓
Du sagst was falsch ist und warum
        ↓
Agent passt an
        ↓
wiederholen bis es stimmt
        ↓
das erfolgreiche Gespräch wird zur Basis des Agents
```

### Schritt 1: Anfangen mit einem Gespräch nicht mit einem Plan

Statt zuerst eine Spezifikation zu schreiben: starte ein Gespräch mit dem Ziel das du willst.

> *"Du bist ein MedTech Design Assistent. Ich bin Interaction Designer und arbeite an einem OP-Assistenzsystem. Ich brauche dich um mich bei regulatorischen Fragen zu IEC 62366 zu unterstützen während ich Figma-Screens designe. Stell dich vor und sag mir was du weißt."*

Was der Agent antwortet zeigt dir sofort: Was fehlt? Was ist zu vage? Was ist falsch? Du korrigierst — und aus diesen Korrekturen wird der Agent präziser.

### Schritt 2: Durch Fragen den Agent formen

Jede echte Arbeitssituation die du durchspielst schärft den Agent. Du musst nicht alle Anforderungen im Voraus kennen — sie entstehen durch die Arbeit.

> *"Ich habe gerade einen Alarm-Dialog mit rotem Hintergrund designed. Ist das konform?"*

Wenn die Antwort zu allgemein ist: *"Das ist zu vage — ich brauche die konkrete Norm-Stelle und was das für meinen konkreten Dialog bedeutet."*

Wenn die Antwort falsch ist: *"Nein — rot ist bei Alarmen zulässig, das Problem ist die Sättigung. Erkläre das nochmal."*

Durch diese Korrekturen entsteht implizit eine Wissensbasis — du machst den Agent besser ohne eine Datenbank zu befüllen.

### Schritt 3: Erfolgreiche Antworten als Vorlage nutzen

Wenn der Agent einmal genau richtig antwortet — in der richtigen Tiefe, mit der richtigen Sprache, mit den richtigen Referenzen — dann ist das der Moment zum Innehalten:

> *"Diese Antwort war genau richtig. Merke dir dieses Format und diesen Detailgrad für alle weiteren Fragen dieser Art."*

Du trainierst den Agent nicht technisch — du trainierst ihn durch Feedback in natürlicher Sprache.

### Schritt 4: Den Agent mit Kontext füttern

Ein Agent wird besser wenn er mehr Kontext hat. Das geht nicht durch Programmierung sondern durch Dokumente die du ihm gibst:

- **Normen-Zusammenfassungen**: nicht die 200-seitige Norm — eine komprimierte Version der relevanten Teile
- **Projektdokumente**: Briefing, Kundenprofil, bisherige Entscheidungen
- **Principles**: stellars Gestaltungsauffassung als Text — ein paar Seiten reichen
- **Negative Beispiele**: *"So soll es nicht aussehen — und warum"*

Je präziser diese Dokumente sind, desto präziser der Agent. Das Schreiben dieser Dokumente ist selbst wertvolle Arbeit — es zwingt zu Klarheit über das was man eigentlich denkt.

### Schritt 5: Den Agent in echte Arbeit integrieren

Der Schritt von *"interessantes Gespräch"* zu *"nützliches Werkzeug"* passiert wenn der Agent in echte Arbeit eingebunden wird — nicht als Experiment sondern als Schritt im Workflow.

Konkret: Öffne den Agent parallel zu Figma. Stelle Fragen während du designst. Nicht nach der Arbeit zur Reflexion — während der Arbeit zur Entscheidung.

Das verändert die Qualität des Outputs sofort. Und es zeigt schnell was der Agent noch nicht kann — was ihn besser macht.

### Was Vibe Chatting nicht ist

- Kein Promptengineering mit versteckter Syntax
- Keine Datenbank die befüllt werden muss
- Kein einmaliges Setup das dann fertig ist
- Kein Ersatz für eigenes Denken

Vibe Chatting ist ein **kontinuierlicher Dialog** zwischen deinem Wissen und dem Agent. Du bist die Intelligenz — der Agent ist die Infrastruktur die dein Wissen skaliert und verfügbar macht.

### Der eigentliche Wert

Der Prozess des Aufbaus ist selbst lehrreich. Indem du versuchst dem Agent zu erklären was er wissen soll, merkst du was du selbst noch nicht klar genug denkst. Viele Annahmen die implizit in der täglichen Arbeit stecken werden explizit wenn du sie formulieren musst.

Ein gut aufgebauter Agent ist deshalb nicht nur ein Werkzeug — er ist **externalisiertes Wissen** das du sonst nur im Kopf hättest.

---

## 4. Datenschutz, Sicherheit und ISMS — die unbequeme Seite

Agent-Systeme sind mächtig — aber sie haben eine Seite die man nicht ignorieren kann: **was passiert mit den Daten die du ihnen gibst?**

Für einen Einzelkünstler ist das überschaubar. Für ein Büro wie stellar das mit Automotive-OEMs, MedTech-Firmen oder Verteidigungskunden arbeitet, ist es ein zentrales Thema.

### Das eigentliche Problem

Wenn du einem Agent einen Figma-Link gibst, einen Kundenbriefing-Text, ein Lastenheft oder eine Nutzerforschungs-Datei — dann verlässt dieser Inhalt dein System. Er wird an einen Server geschickt. Dieser Server steht in den meisten Fällen bei einem US-amerikanischen Anbieter: OpenAI (Microsoft Azure), Anthropic (AWS), Google.

Das ist kein theoretisches Problem. Es ist ein konkretes rechtliches und vertragliches Risiko.

```
Dein Rechner
    ↓
Agent-System (VS Code Copilot, ChatGPT, Claude...)
    ↓
API-Call → Server in US/EU-Region
    ↓
Inference → Antwort zurück
    ↓
Daten waren — für Millisekunden oder länger — auf fremder Infrastruktur
```

### Wo das relevant wird — nach Branche

**Automotive / OEM**
Lastenheft-Inhalte, Designspezifikationen, interne Projektnamen und Codewörter stehen oft unter NDA. OEMs haben zunehmend explizite Vertragsklauseln zu AI-Tools. Manche verbieten das Hochladen von Projektmaterial auf externe Server vollständig — einschließlich AI-Assistenten.

**MedTech**
Nutzerdaten aus Usability-Tests (auch anonymisiert) unterliegen DSGVO. Patientennahe Daten erst recht. Technische Dokumentation für Zulassungsverfahren hat oft Vertraulichkeitsstufen. Die Frage ist nicht nur rechtlich sondern auch zulassungsrelevant: wenn Trainingsdaten in die Zulassungsdokumentation einfließen müssen diese nachvollziehbar sein.

**Rail / Kritische Infrastruktur**
Systeme die in kritischer Infrastruktur laufen (Leitstellen, Steuerungssysteme) haben oft Geheimhaltungsanforderungen die externe Cloud-Dienste ausschließen. KRITIS-Regulierung in Deutschland.

**Defense**
Kein Cloud. Punkt. Verschlusssachen, Exportkontrolle (ITAR/EAR), nationale Sicherheitsanforderungen. AI-Tools auf geheimem oder vertraulichem Material ist in diesem Kontext illegal.

### ISMS — was das bedeutet

Ein **ISMS (Information Security Management System)** nach ISO 27001 ist ein strukturierter Rahmen für den Umgang mit Informationssicherheit in einer Organisation. Für stellar in der Praxis:

- Klassifizierung von Informationen: was ist öffentlich, intern, vertraulich, geheim?
- Klare Regeln welche Tools auf welcher Klassifizierungsstufe erlaubt sind
- Dokumentierter Prozess für neue Tools (AI-Assistenten, MCP-Server, etc.)
- Lieferantenmanagement: welche Verträge hat stellar mit AWS, Microsoft, Anthropic?

Ohne ISMS passiert das implizit — jeder Mitarbeiter entscheidet selbst was er hochlädt. Das ist das eigentliche Risiko.

### DSGVO konkret

DSGVO gilt wenn personenbezogene Daten verarbeitet werden. In der Design-Arbeit tauchen diese öfter auf als gedacht:

- Nutzertests: Videoaufzeichnungen, Transkripte, Personas mit echten Interviews
- Kundenkontakte: E-Mails, Meetingnotizen mit Namen
- Mitarbeiterdaten: intern, aber relevant

Wenn diese Daten in einen Prompt fließen und an einen US-Server geschickt werden ist das eine Datenübermittlung in ein Drittland. Das erfordert eine Rechtsgrundlage (Standardvertragsklauseln, adequacy decision, etc.). Die meisten großen AI-Anbieter haben inzwischen entsprechende Vertragswerke — aber sie müssen aktiv abgeschlossen und dokumentiert sein.

### Praktische Lösungsansätze

**Tiering: welches Material geht wohin**

```
Öffentlich / generisch    →  kommerzielle AI-Dienste (Copilot, Claude, GPT)
Intern / nicht-sensitiv   →  AI-Dienste mit EU-Datenhaltung, BAAs
Vertraulich / NDA         →  lokale Modelle oder Private Deployment
Geheim / KRITIS           →  kein Cloud-AI, Offline-Only
```

**Lokale Modelle als Alternative**
Für sensitives Material gibt es lokale Alternativen: Ollama + open-weight Modelle (Llama, Mistral, Qwen) laufen vollständig auf eigenem Hardware. Kein Datentransfer. Geringere Qualität als GPT-4 oder Claude — aber für viele Anwendungsfälle ausreichend und rechtlich sauber.

**Private Deployment**
Azure OpenAI Service mit EU-Region und Private Endpoint: Daten verlassen nicht die eigene Azure-Instanz, kein Training auf Kundendaten, DSGVO-konform konfigurierbar. Microsoft bietet dafür entsprechende Vertragswerke (DPA). Das ist für ein Büro wie stellar der pragmatischste Mittelweg.

**Prompt-Hygiene als einfachste Maßnahme**
Keine echten Namen, keine Projektnamen, keine internen Codewörter in Prompts. Anonymisieren bevor man es dem Agent gibt. Das ist keine vollständige Lösung aber reduziert das Risiko erheblich und kostet nichts.

### Was das für stellar bedeutet

stellar arbeitet mit Kunden deren Material oft sensitiv ist. Ein ISMS ist kein bürokratischer Overhead — es ist ein Wettbewerbsvorteil gegenüber kleineren Wettbewerbern die das nicht haben.

**Konkret:** Ein Automotive-OEM oder ein MedTech-Unternehmen wird bei der Auftragsvergabe fragen: *"Wie geht ihr mit unseren Daten um? Welche AI-Tools nutzt ihr und unter welchen Bedingungen?"*

Ein Büro das diese Frage mit einem strukturierten Konzept beantwortet — Tiering, lokale Alternativen, EU-Deployment, dokumentierte Prozesse — hat einen erheblichen Vorteil gegenüber einem das antwortet: *"Wir passen auf."*

Das ist kein Quatsch. Das ist die Grundvoraussetzung für bestimmte Kundensegmente.

---

## 5. Kosten, Abhängigkeit und Souveränität

### Was Agent-Nutzung wirklich kostet

AI-Dienste fühlen sich günstig an — bis man sie ernsthaft nutzt. Die Kosten entstehen nicht durch eine Lizenz sondern durch **Token-Verbrauch**: jeder Prompt, jede Antwort, jeder Kontext der mitgeschickt wird kostet.

**Beispiel-Größenordnungen (Stand 2025/26, variiert je Anbieter und Modell):**

```
GPT-4o:        ~$2.50 / 1M Input-Token, ~$10 / 1M Output-Token
Claude Sonnet: ~$3 / 1M Input-Token,   ~$15 / 1M Output-Token
Lokales Modell: Strom + Hardware — effektiv $0 pro Token
```

Ein langer Kontext (großes Figma-File, langes Lastenheft, Projekt-Historik) kann schnell 50.000–200.000 Token pro Session bedeuten. Bei intensiver täglicher Nutzung im Team: mehrere hundert Dollar pro Monat, leicht mehr.

Das ist für die meisten Projekte vertretbar — aber es ist eine laufende Betriebskosten-Linie die geplant werden muss.

**Was die Kosten treibt:**
- Kontext-Länge: je mehr Dokumente du dem Agent gibst, desto teurer
- Anzahl Agents: Subagent-Architektur multipliziert die Calls
- Häufigkeit: ein Agent der bei jedem Figma-Speichern triggered kostet anders als einer der auf Anfrage antwortet
- Modellwahl: kleinere Modelle (GPT-4o mini, Haiku) sind 10-20x günstiger für einfachere Tasks

### Vendor Lock-in — das eigentliche Risiko

Kosten sind das sichtbare Problem. Das unsichtbarere ist **Abhängigkeit**.

Wenn stellar einen Workflow aufbaut der auf Claude basiert und Anthropic ändert die Preise, ändert das Modellverhalten, oder stellt den Dienst ein — ist der Workflow beschädigt. Das ist kein theoretisches Szenario: OpenAI hat Modelle deprecated, Preise mehrfach angepasst, APIs inkompatibel verändert.

```
Vendor-Abhängigkeiten im Agent-Stack:
├── Modell-API (OpenAI, Anthropic, Google)
├── Hosting-Plattform (Azure, AWS, GCP)
├── Figma API (proprietär, änderbar)
├── MCP-Server Implementierungen (community, teils schlecht gepflegt)
└── VS Code / Copilot als Interface (Microsoft)
```

Jede dieser Abhängigkeiten ist ein Risiko. Nicht sofort — aber über einen Zeithorizont von 3-5 Jahren ist mindestens eine davon eine Überraschung.

### Vollständige Unabhängigkeit: was das bedeutet

Alles selbst hosten ist technisch möglich. Was es bedeutet:

**Hardware**
- Für ernsthafte lokale Inferenz: mindestens eine NVIDIA RTX 4090 (24GB VRAM) oder besser A100/H100 (Serverklasse)
- RTX 4090: ~1.800€ — läuft Llama 3.3 70B, Qwen 2.5 72B in guter Qualität
- A100 80GB: ~10.000–15.000€ gebraucht — läuft größere Modelle, schneller
- Für Teams mit parallelen Nutzern: mehrere GPUs, dedizierter Server, Netzwerk-Setup

**Software-Stack**
- Ollama oder vLLM als Inference-Engine
- Open-Weight Modelle: Llama (Meta), Qwen (Alibaba), Mistral, DeepSeek
- Eigener MCP-Server statt cloud-basierter Dienste
- Eigenes Figma-Polling statt offizieller MCP (Reverse-Engineering der API)

**Aufwand**
- Initiales Setup: mehrere Tage bis Wochen je nach Komplexität
- Laufender Betrieb: Updates, Monitoring, Hardware-Wartung
- Modell-Updates: neue Versionen manuell herunterladen und testen
- Kein Support — nur Community und eigenes Wissen

**Qualitäts-Tradeoff**
Lokale Modelle sind gut aber nicht gleich wie GPT-4o oder Claude Sonnet. Für Code-Generierung, strukturierte Outputs, Norm-Recherche: 80-90% der Qualität bei langen Kontexten. Für Kreativität, nuanciertes Denken, unbekannte Domänen: spürbarer Unterschied.

**Wann es sich lohnt:**
- Sensitives Material das nicht die Infrastruktur verlassen darf
- Sehr hohes Token-Volumen wo Cloud-Kosten die Hardware-Investition übersteigen
- Teams die vollständige Kontrolle über Modellverhalten brauchen (Compliance, Audit)

**Wann es sich nicht lohnt:**
- Kleines Team, moderate Nutzung — Cloud ist günstiger als Hardware + Aufwand
- Wenn die neuesten Modelle relevant sind — lokale Open-Weight Modelle sind 6-12 Monate hinter dem State-of-the-Art
- Wenn niemand im Team die Infrastruktur betreiben kann oder will

### Der pragmatische Mittelweg: Hybrid

```
Sensitiv / NDA-Material    →  lokales Modell (Ollama + RTX 4090)
Standard-Arbeit            →  Azure OpenAI (EU, Private Endpoint)
Experimentelles / Neues    →  kommerzielle Dienste (Copilot, Claude)
```

Das gibt Souveränität wo sie nötig ist ohne den Aufwand vollständiger Selbst-Infrastruktur für alles.

---

## 6. Bereiche mit weniger Sicherheitsrisiko — lukrativ und zugänglich

Nicht jede Branche hat strenge Datenschutz- und Sicherheitsanforderungen. Für ein Agent-System ohne schwere Compliance-Last gibt es attraktive Felder.

### Retail und E-Commerce

Produktdaten, Konfigurationsoberflächen, Checkout-Flows — keine Safety-Relevanz, kein NDA-Material das nicht ohnehin veröffentlicht wird. Agent-Workflows für Design-Systeme und Frontend-Generierung sind hier sofort einsetzbar, günstig und ohne rechtliche Komplexität.

**Warum lukrativ:** enorme Menge an Projekten, schnelle Iterationszyklen, hoher Bedarf an Konsistenz über viele Touchpoints. Wer hier schnell und günstig skaliert gewinnt.

### SaaS / B2B-Software

Enterprise-Software ist oft visuell veraltet — die Firmen wissen es und wollen es ändern. Design-Debt ist riesig, Design-Systeme fehlen oder sind fragmentiert. Kein embedded Target, kein Safety-Framework, Daten sind meist Business-Daten ohne besondere Schutzanforderungen.

Agent-Workflow: Figma → React/Vue Komponentenbibliothek, automatische Token-Synchronisation, Subagent für Accessibility-Checks (WCAG). Hoher Wert, geringe Compliance-Last.

### Gaming / Interactive Media

Game UI, Menüsysteme, HUDs — kreativ anspruchsvoll, technisch komplex, aber keine regulatorischen Anforderungen. Figma → Engine (Unity UI Toolkit, Unreal UMG) Pipelines sind noch wenig automatisiert. Großes ungenutztes Potential.

Kein NDA-Problem bei eigenem IP. Iterationsgeschwindigkeit ist der Hauptwert.

### Education Tech / Learning Platforms

Lernplattformen, Kurs-Interfaces, Gamification-Systeme — wachsender Markt, DSGVO relevant für Nutzerdaten aber nicht für Design-Arbeit an sich. Agent-System für schnelle Iteration von Interface-Varianten, A/B-Test-Material, lokalisierte Versionen.

### Hospitality / Tourism

Hotel-Apps, Booking-Systeme, In-Room-Interfaces — High-End Anspruch, visuell anspruchsvoll, keine Safety-Anforderungen. Wenig Wettbewerb mit echtem Design-Niveau. Figma → Web oder native App Pipeline ohne Compliance-Overhead.

### Consumer Apps allgemein

Fitness, Finance (Consumer, kein Banking), Food, Lifestyle — große Projekte, kurze Zyklen, kein Automotive-ähnliches Zulassungsregime. Agent-System für Design-System-Aufbau und Komponenten-Generierung ist hier der direkteste Wertbeitrag.

### Baumaschinen / Material Handling / Logistik

Das ist der am meisten unterschätzte Bereich — und einer mit direktem Fit zu stellars bestehender Kompetenz.

**Warum er interessant ist:**

Bagger, Krane, Gabelstapler, Lagerverwaltungssysteme, Flurförderzeuge, autonome Transport-Fahrzeuge im Lager — alles hat Bedienoberflächen. Und diese Interfaces sind historisch katastrophal. Physische Tasten, monochrome Displays, kein konsistentes Designsystem, keine UX-Logik die über einzelne Maschinen hinausgeht.

Der Markt transformiert sich gerade: Elektrifizierung, Autonomisierung, Vernetzung. Neue Maschinengenerationen brauchen neue Interfaces — Touchscreens im Führerhaus, mobile Operator-Apps, Fleet-Management-Dashboards, Remote-Monitoring.

**Der Fit zu stellar:**

```
Baumaschinen-HMI:
├── Embedded Target (oft Linux, teilweise QNX oder Windows CE)
├── Qt / QML bereits verbreitet in der Branche
├── Safety-Relevanz vorhanden aber unterhalb Automotive ISO 26262
│   (Machinery Directive, EN ISO 13849 — lösbar, nicht prohibitiv)
├── Extreme Umgebungsbedingungen: Handschuhe, Staub, Vibration,
│   direktes Sonnenlicht → Touch-Target-Design, Kontrast, Haptik
└── Nutzergruppe: Maschinisten, Lagerlogistiker — kein Tech-Background
```

Das ist Automotive-HMI-Kompetenz in einem neuen Kontext. stellar kann direkt transferieren.

**Konkrete Anwendungsfälle:**

- **Führerhaus-Interface**: Bagger, Kran, Dumper — Touchscreen-Displays die unter Vibration und Handschuhen funktionieren, State-Maschinen für komplexe Arbeitsabläufe
- **Fleet-Management-Dashboard**: Flottenstatus, Wartungsintervalle, Standort, Auslastung — Web oder native App, keine Safety-Anforderungen, großes Datenvolumen visualisieren
- **Warehouse Management UI**: Lagersteuerung, Pick-by-Light, AGV-Disposition — oft noch browserbasiert und hässlich, strukturiertes Design-System fehlt
- **Operator Onboarding**: neue Maschinen, neue Nutzer — interaktive Einführungs-Interfaces, kontextsensitive Hilfe direkt am Display
- **Remote Diagnostics**: Maschinenzustand aus der Ferne — Datenvisualisierung, Alarme, Fehlerdiagnose

**Compliance-Einschätzung:**

Nicht sicherheitsfrei — Baumaschinen können töten. Aber das Regime ist handhabbar:
- Machinery Directive (2006/42/EG): CE-Kennzeichnung, risikobasiert
- EN ISO 13849: Safety functions (Not-Aus, Begrenzungen) — klar abgegrenzt vom UI-Layer
- Keine IEC 62304, keine ISO 26262, kein FDA
- NDAs vorhanden aber weniger restriktiv als OEM-Automotive

Sensitives Material: Maschinen-Architektur, Produktionsdaten — mittlere Schutzstufe. Standard Azure EU-Deployment reicht für die meisten Fälle.

**Warum jetzt:**

Caterpillar, Liebherr, Kion (STILL, Linde, Jungheinrich), Komatsu — alle investieren in neue Interface-Generationen. Gleichzeitig gibt es kaum Agenturen mit echter HMI-Kompetenz in diesem Bereich. Die meisten Maschinenhersteller entwickeln intern oder beauftragen IT-Dienstleister ohne Designkompetenz. Das Ergebnis sieht man an den heutigen Interfaces.

Das ist eine Marktlücke. stellar könnte sie füllen — mit direkt transferierbarer Kompetenz und einem Agent-System das die Einstiegsgeschwindigkeit auf ein Niveau bringt das internal teams nicht erreichen.

### Das Muster

```
Hohe Compliance-Last:     Automotive, MedTech, Defense, Rail, Banking
Mittlere Compliance-Last: Baumaschinen/Material Handling, Finance (Consumer),
                          Health (Wellness), B2B Enterprise
Niedrige Compliance-Last: Logistik-Software, Retail, SaaS, Gaming,
                          Education, Consumer Apps, Hospitality
```

Für stellar als Büro das bisher im hohen Compliance-Bereich arbeitet wären mittlere und niedrige Bereiche eine **strategische Diversifikation** — nicht als Ersatz für den Kern sondern als Puffer wenn Automotive-Budgets einbrechen.

Und aus Agent-System-Perspektive: diese Bereiche sind der einfachste Einstieg. Kein Tiering, kein ISMS, keine lokale Infrastruktur notwendig. Volle Geschwindigkeit, voller Komfort der kommerziellen Tools — und trotzdem dieselbe Principals-Layer-Qualität die stellar ausmacht.

---

## 7. Mitarbeiter schulen und schrittweise implementieren

Das größte Risiko bei der Einführung eines Agent-Systems ist nicht die Technologie — es ist die Einführung selbst. Zu schnell, zu abstrakt, zu viel auf einmal: das System wird als Bedrohung oder als Spielzeug wahrgenommen, aber nicht als Werkzeug.

Der einzige Weg der funktioniert: **klein anfangen, echten Wert zeigen, dann ausbauen.**

### Phase 0 — Verständnis schaffen (Woche 1–2)

Bevor irgend jemand ein Tool öffnet: ein gemeinsames Bild schaffen was Agent-Systeme sind und was sie nicht sind.

**Was das nicht ist:**
- Kein Ersatz für Menschen
- Kein System das Entscheidungen trifft
- Keine Magie die alles automatisch macht

**Was es ist:**
- Ein Werkzeug das wiederkehrende Ausführungsarbeit übernimmt
- Ein Assistent der Recherche und Strukturierung beschleunigt
- Eine Infrastruktur die Wissen skalierbar macht

Format: **ein offenes Gespräch**, nicht eine PowerPoint-Präsentation. Fragen zulassen. Ängste benennen. Konkrete Beispiele aus der eigenen Arbeit zeigen — kein abstraktes Zukunftsbild.

Am Ende von Phase 0 sollte jeder im Team eine ehrliche Antwort auf eine Frage geben können: *"Welche Aufgabe in meiner Arbeit würde ich am liebsten nicht mehr machen?"*

Das sind die ersten Agent-Kandidaten.

### Phase 1 — Piloten mit Freiwilligen (Woche 3–6)

Nicht das gesamte Team zwingen. 2-3 Personen die neugierig sind — ein Designer, ein Entwickler, jemand aus dem Projektmanagement — beginnen mit echten kleinen Aufgaben.

**Konkrete Einstiegsaufgaben:**

Für Designer:
- Figma-Komponente beschreiben lassen → Agent erklärt was fehlt in der Spec
- Branchenrecherche: *"Was sind typische Usability-Probleme bei Baumaschinen-Interfaces?"*
- Ersten Entwurf eines Entscheidungsdokuments für den Kunden generieren lassen

Für Entwickler:
- QML-Boilerplate für eine bestehende Figma-Komponente generieren lassen
- Token-Inkonsistenzen in einem Theme.qml identifizieren lassen
- Dokumentation für eine bestehende Komponente schreiben lassen

Für Projektmanagement:
- Meeting-Zusammenfassung strukturieren lassen
- Ersten Entwurf eines Statusupdates für den Kunden generieren lassen
- Agenda für Review-Meeting vorbereiten lassen

**Wichtig:** die Piloten dokumentieren was funktioniert und was nicht. Keine Erfolgsgeschichten erzwingen — echte Beobachtungen sind wertvoller.

### Phase 2 — Lernen aus den Piloten (Woche 7–8)

Piloten präsentieren ihre Erfahrungen im Team. Nicht als Demonstration sondern als ehrlicher Bericht:

- Was hat Zeit gespart?
- Was hat nicht funktioniert?
- Was war überraschend?
- Was würde ich anders machen?

Aus diesen Berichten entstehen die ersten **internen Playbooks**: kurze Dokumente die zeigen wie ein spezifischer Workflow mit Agent-Unterstützung aussieht. Keine Theorie — konkrete Schritt-für-Schritt-Beschreibungen die ein Kollege direkt nachvollziehen kann.

Beispiel Playbook-Titel:
- *"Statusupdate für Kunden in 15 Minuten statt 1 Stunde"*
- *"QML-State-Struktur aus Figma-Varianten in 10 Minuten"*
- *"MedTech Normen-Check während Figma-Arbeit"*

### Phase 3 — Breiter ausrollen (Monat 3–4)

Mit echten Playbooks und echten Erfahrungen aus Phase 1/2 ist die Einführung im restlichen Team konkret statt abstrakt.

**Format: keine Schulung — Begleitung**

Keine halbtägigen Workshops mit Folien. Stattdessen: Pairing. Ein Pilot-Teilnehmer arbeitet für einen Tag zusammen mit einem Kollegen der noch nicht eingestiegen ist — zeigt wie der Workflow in echten Aufgaben aussieht, beantwortet Fragen direkt im Kontext.

Das ist schneller, glaubwürdiger und nachhaltiger als jede Schulung.

**Gleichzeitig: Infrastruktur aufbauen**

- Principles Layer dokumentieren (wer definiert ihn? wer pflegt ihn?)
- Erste Domain-Agents aufsetzen: welche Branchen sind relevant, wer sammelt das Wissen?
- Datenschutz-Tiering klären: interne Richtlinie welche Tools für welches Material
- Feedback-Kanal: wo melden Mitarbeiter wenn ein Agent falsch liegt?

### Phase 4 — Systemisch machen (Monat 5–12)

Der Übergang von *"wir nutzen Agent-Tools"* zu *"das ist wie wir arbeiten"*.

**Onboarding neuer Mitarbeiter**
Agent-Nutzung ist Teil des Onboardings — nicht als optionales Extra sondern als Standardwerkzeug wie Figma und VS Code. Neue Mitarbeiter lernen von Tag 1 mit dem Agent-Stack zu arbeiten, haben weniger Eingewöhnungszeit und integrieren das Wissen schneller.

**Retrospektiven einbauen**
In jedem Projekt-Abschluss: Was hat das Agent-System in diesem Projekt gebracht? Was hat gefehlt? Was fließt zurück in den Principles Layer oder den Domain-Agent?

Das ist der Mechanismus durch den das System besser wird statt statisch zu bleiben.

**Messung — aber die richtigen Dinge messen**

Nicht: *"wie viele Prompts wurden gesendet"*
Sondern:
- Verkürzt sich die Zeit von Figma-Übergabe zu erstem QML-Draft?
- Werden Pitch-Dokumente schneller fertig?
- Nimmt die Anzahl von Design-Dev-Rückfragen ab?
- Steigt die Qualität von Ersteinreichungen an den Kunden?

```
Implementierungs-Zeitplan (Überblick)

Woche 1–2:   Phase 0 — offenes Gespräch, Verständnis schaffen
Woche 3–6:   Phase 1 — Piloten mit 2-3 Freiwilligen, echte Aufgaben
Woche 7–8:   Phase 2 — Auswertung, Playbooks schreiben
Monat 3–4:   Phase 3 — Breiter Rollout durch Pairing, Infrastruktur aufbauen
Monat 5–12:  Phase 4 — Systemisch machen, Onboarding, Retrospektiven, Messung
```

### Was scheitern lässt — und wie man es vermeidet

| Häufiger Fehler | Gegenmittel |
|---|---|
| Zu viele Tools auf einmal einführen | Ein Workflow, ein Tool, bis es sitzt |
| Top-Down Pflicht ohne Sinn | Freiwillige Piloten, echte Ergebnisse zuerst zeigen |
| Abstrakte Schulungen ohne Praxisbezug | Pairing mit echten Aufgaben statt Folien |
| Kein Feedback-Kanal wenn Agent falsch liegt | Expliziter Kanal, schnelle Korrekturen sichtbar machen |
| Principles Layer nie definiert | Mindestens ein halber Tag: was sind unsere Gestaltungsregeln? |
| Datenschutz ungeklärt | Klare interne Richtlinie bevor das System produktiv geht |

### Das Ziel

Nach 12 Monaten sollte das Agent-System unsichtbar sein — nicht weil niemand es nutzt, sondern weil es selbstverständlich ist. Wie Versionskontrolle. Wie Figma. Niemand erklärt mehr warum man Git nutzt. Es ist einfach wie man arbeitet.

Das ist der Maßstab für eine erfolgreiche Implementierung.

---

*Erstellt: 13. Mai 2026 — Aktualisiert: 14. Mai 2026*
