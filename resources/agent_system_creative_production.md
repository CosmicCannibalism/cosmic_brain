# Agent-System für kreative Produktion

---

## Konzept — Die Mitarbeiter-Metapher

> Agents sind keine Tools. Sie sind Mitarbeiter. Ein Tool wartet auf Bedienung. Ein Mitarbeiter versteht Kontext, arbeitet selbstständig, berichtet zurück und entwickelt sich durch Feedback weiter.

Du baust dir ein Team zusammen. Du schulst es. Du gibst Aufträge. Du reviewst Ergebnisse.
Du bist nicht Ausführer — du bist **Creative Director, Auftraggeber, Qualitätsinstanz.**

### Die zwei Mitarbeiter-Typen

| Typ | Scope | Wie definiert |
|---|---|---|
| **Stammmitarbeiter** | alle Projekte, immer aktiv | `.instructions.md` mit `applyTo` — läuft automatisch |
| **Projektmitarbeiter** | ein Projekt / eine Aufgabe | `.agent.md` oder Session-Konfiguration |

### Wie du sie schulst

| Schulungsmittel | Was es ist | Wirkung |
|---|---|---|
| **Instructions** (`.instructions.md`) | Dauerhaftes Regelwerk | automatisch aktiv für alle passenden Sessions |
| **Skills** | Portables Wissenspaket | wird geladen wenn relevant |
| **Prompt-Files** (`.prompt.md`) | Vorgefertigter Auftrag | startet Session mit vollständigem Briefing |
| **Principles Layer** | Ästhetische / fachliche Regeln als Datei | hält Konsistenz über alle Outputs |
| **Feedback & Korrekturen** | Abgelehnte Outputs dokumentieren | Agent lernt was *nicht* gemeint ist |

### Wie du sie führst — die Kommandozentrale

Das **VS Code Agents Window** ist die Kommandozentrale: alle laufenden Sessions, alle Mitarbeiter-Profile, alle offenen Aufträge — parallel, projektübergreifend, auf einen Blick.

```
Auftrag erteilen   →  Session starten, Prompt formulieren
Parallel arbeiten  →  mehrere Sessions gleichzeitig, verschiedene Projekte
Zwischenstand      →  Changes Panel: alle Dateiänderungen im Diff-View
Feedback geben     →  direkt in den Diff kommentieren ("Add Feedback")
Abliefern          →  Commit / Merge / Discard aus dem Changes Panel
```

Kein Mitarbeiter entscheidet ohne dich. Du gibst frei — oder nicht.

> **Der Qualitätssprung kommt nicht aus besseren Modellen — er kommt aus besserem Schulungsmaterial.**
> Wer seine Agents präzise instruiert, bekommt präzise Ergebnisse.

---

# Teil I — Einzelner Künstler

## Ausgangslage

Ein Solo-Künstler ist gleichzeitig Creative Director, Produzent, Entwickler, Texter, Archivar und Forscher. Das ist die Stärke (volle Kontrolle, keine Abstimmungsverluste) und die Grenze (Kapazität ist gedeckelt).

```
OHNE AGENTS            MIT AGENTS
──────────────         ──────────────────────────────
Du = 1 Person          Du = Creative Director
Kapazität = 8h         Team = Agents die parallel ausführen
                       Kapazität = deine Entscheidungsgeschwindigkeit
```

## Team-Aufbau

### Stammmitarbeiter (projektübergreifend)

| Agent | Aufgabe | Quelle |
|---|---|---|
| **Glossar-Assistent** | Neue Begriffe einsortieren, Einträge schreiben | Instructions aus `__cosmicbrain__.md` |
| **Vault-Verlinker** | Jedes neue Dokument auf verlinkbare Begriffe scannen, Wiki-Links einfügen | Dauerhafte Instructions |
| **Stil-Wächter** | Schreibt in deinem Ton — Deutsch, präzise, medienkünstlerischer Kontext | Persönliche Instructions |

### Projektmitarbeiter (aufgabenspezifisch)

| Agent | Aufgabe | Kontext |
|---|---|---|
| **Primordial-Soup-Agent** | Spezies-Logik, LFO-Struktur, Merge-Konflikte, Kamera-Interaktion | kennt das Regelset der Simulation |
| **DNA-Sequencer-Agent** | Code kommentieren, .ino-File dokumentieren | kennt Arduino-Konventionen, `konzept_objekt.md` |
| **Petroglyphen-Agent** | Konzept ausarbeiten, Recherche, Moodboard-Struktur | kennt das Projektkonzept |

### Die Wissensbase

Der `__cosmicbrain__`-Vault ist mehr als Notizsammlung — er ist die **Unternehmenskultur als Datei**: Begriffe, Denkweisen, Prinzipien die jeder Agent beim Start kennt.

Die KI-Instruktions-Blöcke in `__cosmicbrain__.md` sind bereits Schulungsmaterial. Mit `.instructions.md`-Dateien und `applyTo`-Frontmatter werden sie permanent und automatisch — ohne dass du die Datei jedes Mal öffnen musst.

## Workflow — ein konkreter Tag

Der Künstler arbeitet an *Primordial Soup*. Gleichzeitig laufen:

```
Sessions-Liste (Agents Window)
│
├── 🔄 Primordial Soup   → Merge-Konflikt camera_interaction auflösen
├── 🔄 __cosmicbrain__   → Glossar sortieren: 1D Automaten, Transhumanismus…
└── 🔄 DNA Sequencer     → dna_sequencer.ino kommentieren
```

Kein Context-Switch. Kein Abbruch der Kreativarbeit.
Du reviewst die Änderungen im Changes Panel wenn du bereit bist — und gibst frei oder nicht.

## Was sich verschiebt

**Von:** *„ich muss das noch selbst umsetzen"*
**Zu:** *„ich entscheide ob das stimmt"*

Das ist der eigentliche Gewinn — nicht Geschwindigkeit, sondern **Tiefe**. Die kreative Energie fließt in Entscheidungen, nicht in Ausführung.

---

# Teil II — stellar design und engineering

## Kontext

[stellar](https://www.stellar.de/) (Ulm, gegründet 1996) — High-End Interaction Design für Automotive, Application und Mobile. ~50 Personen aus Interaction- und Industriedesign, Informatik, Engineering. Kunden aus Transportation, Automotive, Telekommunikation.

*„Bevor wir über die Gestalt nachdenken, interessiert uns der Kontext, die Nutzergruppe und die Funktion."*

Bei stellar kommt ein Agent-System nicht *statt* eines Teams — es kommt *zu* einem Team. Agents sind **spezialisierte Assistenten die jedem Mitarbeiter zur Seite stehen.**

## Team-Architektur

```
stellar (~50 Personen)
│
├── Interaction Designer
│   ├── Figma → QML Agent        Komponenten aus Figma-Spec generieren
│   ├── Domain-Agent              Regularien, Nutzergruppen, Normen der Branche
│   └── Principles-Agent          prüft Outputs gegen stellars CI
│
├── Entwickler
│   ├── Code-Agent                Boilerplate, Theme-System, Property-Bindings
│   ├── Review-Agent              prüft gegen Principles vor dem Code-Review
│   └── Plattform-Agent           Qt-Target-Spezifika: Embedded, QNX, HUD
│
└── Stamm-Agents (Unternehmens-IP)
    ├── Principles Layer          stellars Gestaltungsauffassung, maschinenlesbar
    ├── Komponenten-Bibliothek    alle bewährten QML-Komponenten
    └── Domain-Agents             MedTech · Rail · Energie — akkumuliertes Branchenwissen
```

### Stamm-Agents als Unternehmens-IP

Ein Principles-Agent der nach zwei Automotive-Projekten stellars Designsprache verinnerlicht hat, ist wertvoller als ein generischer Copilot. Er ist durch stellars Projekte trainiert — nicht durch ein Wettbewerber-Tool ersetzbar.

Jeder abgelehnte Output, jede Korrektur, jedes Kundenfeedback das ins System zurückfließt macht ihn spezifischer. Nach fünf Jahren ist er ein **Destillat der Expertise des gesamten Büros**.

### Schulungs-Hierarchie

| Ebene | Inhalt | Wer pflegt es |
|---|---|---|
| **Unternehmens-Instructions** | Prinzipien, CI, Qualitätsstandards | Agent Architect |
| **Projekt-Instructions** | Kunde, Plattform, spezifische Constraints | Projektleitung |
| **Persönliche Instructions** | individuelle Arbeitsweise | jeder Mitarbeiter |
| **Domain-Agents** | Branchen-Wissen, Regularien, Nutzergruppen | Agent Architect + Domänen-Lead |

Die Ebenen stacken sich — persönlich ergänzt Projekt ergänzt Unternehmen. Klare Hierarchie, kein Widerspruch.

**Agent Architect** ist eine neue Rolle: pflegt den Principles Layer, definiert und schult neue Agents, sammelt Feedback ein, überwacht Output-Qualität. Diese Rolle existierte in keinem Stellenprofil 2020.

## Produktions-Pipeline — Design → Code

```
Figma-Komponente   →  Agent generiert .qml-File
Figma-Variante     →  QML State
Figma-Transition   →  QML Transition / Behavior
Design Token       →  Theme.qml (zentral, versioniert)
AE-Animation       →  Lottie JSON → Qt Quick LottieAnimation
```

| Heute (manuell) | Mit Agent-System |
|---|---|
| Figma → QML: Stunden pro Komponente | Agent regeneriert bei Figma-Update |
| Tokens manuell synchron halten | Automatisch durch Codebasis propagiert |
| Junior-Output variiert in Qualität | Principles als eingebetteter Constraint |
| Neues Projekt: von vorne aufsetzen | Erbt alle Principles automatisch |

**Der Engpass verschiebt sich von Ausführung zu Entscheidung** — dort wo stellars Expertise den größten Wert hat.

## Perspektive: Designer

**Was sich verbessert:**

- **Vom Prototyp zum echten Verhalten — sofort.** Agent-generierter QML-Code aus Figma-Struktur läuft früher auf echtem Hardware. Designer sehen früher die Realität, nicht den Figma-Prototyp.
- **Token-Änderungen ohne Entwickler-Ticket.** Farbe ändert sich in Figma → Agent propagiert durch Codebasis → Designer sieht Diff direkt.
- **Motion bleibt in Designhand.** Motion Design System mit Timing-Tokens und Easing-Kurven in Figma → Agent überträgt 1:1. Die Kurve die definiert ist, ist die Kurve die ausgeliefert wird.
- **Review auf echten Targets.** Agent prüft generierten Output auf verschiedenen Display-Targets (Dashboard 12", Instrument Cluster 7", HUD) automatisch gegen Figma-Specs — Abweichungen kommen vor dem Code-Review.

**Was das verändert:**

Figma wird konsequent zur Single Source of Truth. Das zwingt zu mehr Präzision in der Spec — eliminiert dafür Nachverhandlungen in der Entwicklungsphase. Kulturell: von *„wir klären das noch im Dev"* zu *„wenn es nicht in Figma ist, existiert es nicht."*

Jede Design-Entscheidung trägt weiter — wirkt auf mehr Komponenten, mehr Targets, mehr States. Designer die in Systemen denken werden erheblich wirksamer. Für stellar — mit dem Anspruch auf sachliche Gestaltung und höchste Qualität — ist das keine Zumutung sondern eine natürliche Entsprechung.

**Der Shift: von der Einzelentscheidung zur Systemverantwortung.**

## Perspektive: Entwickler

**Was sich verbessert:**

- **Boilerplate und Scaffolding** entfallen: QML-Komponenten, Property-Bindings, States, Transitions aus Figma-Spezifikation — Agent schreibt die Verdrahtung.
- **Konsistenz-Checks** vor Code-Review: Agent prüft ob generierter Code die Principles verletzt, bevor der Mensch es tut.
- **Plattform-Komplexität**: Qt auf Embedded Linux, QNX, Windows, Android — plattformspezifische Anpassungen systematisch ausgerollt.
- **Onboarding**: Agent kennt Komponentensystem, Principles und Plattform-Eigenheiten — neues Teammitglied stellt Fragen, bekommt projektspezifischen Kontext.

**Architektur als Sparringspartner:**
Den Agent aktiv in Architekturentscheidungen einbeziehen: Welche QML-Struktur ist wartbarer? Wo ist Qt Widgets besser als QML? Agent spielt Optionen durch, Entwickler entscheidet.

**Custom MCP Server** als echter Wettbewerbsvorteil: stellar könnte einen eigenen MCP Server entwickeln der das interne Komponentensystem, Projekt-Constraints und das Build-System (Qt Creator / CMake) anbindet. Proprietäres Tooling das kein Wettbewerber hat.

**Generative Tests aus Figma-Specs:** Figma-Prototypen beschreiben Interaction-Flows. Agent generiert daraus QML-Tests — jeder definierte State ist ein Testcase. Schließt die Lücke zwischen Design-Spec und QA.

**Der Shift: vom Übersetzer zum Architekten.**

## Neue Märkte — Skalierung durch Agent-System

Die Automobilindustrie steht unter Druck: OEM-Budgets schrumpfen, chinesische Konkurrenz, EV-Transition. Stellars eigentliches Asset ist nicht der Automotive-Fokus — es ist die Fähigkeit **komplexe, sicherheitsrelevante, hochwertige Interaktion** zu gestalten und zu implementieren. Das ist in anderen Industrien genauso gefragt.

### Branchen mit Potential

| Branche | Warum stellar passt | Technologie |
|---|---|---|
| **MedTech** | Safety-Anforderungen (IEC 62304, FDA), embedded Targets, komplexe States — strukturell wie Automotive | Qt in MedTech etabliert |
| **Rail** | Führerstandsysteme, Fahrgastinfo, Leitsysteme — Safety (EN 50128), kaum Büros mit Design + Implementierung | Qt auf Industrial-Targets |
| **Industrie 4.0** | SCADA-Interfaces, Maschinensteuerungen — Fachkräftemangel macht gute Bedienbarkeit zum Wettbewerbsfaktor | Qt auf Embedded |
| **Energie / Renewables** | Leitstellen für Wind/Solar, Smart Grid — komplexe Datenvisualisierung, Echtzeit, Investitionsdruck | Qt auf Industrial-Targets |
| **Verteidigung** | Fahrzeug-HMI, taktische Displays — hohe Qualitätsanforderungen, wenig preissensitiv | diverse Targets |

### Wie der Markteintritt funktioniert

```
Neue Branche
     ↓
Domain-Agent aufbauen: Normen, Nutzergruppen, Fehlermuster
     ↓
Principles Layer adaptieren (nicht neu erfinden)
     ↓
Erste Komponenten-Bibliothek in Wochen statt Monaten
     ↓
Pitch mit funktionalem Prototyp auf echtem Target
```

Ohne Agent-System: neues Team, neuer Stack, neue Einarbeitungszeit — jeder Branchen-Einstieg ist ein Neustart.
Mit Agent-System: stellars HMI-Expertise wird portierbar.

**Der Engpass ist nicht Expertise — der Engpass ist Kapazität und Einstiegsgeschwindigkeit.**

## Domain-Agents — Branchenwissen im Workflow

Wenn stellar in MedTech, Rail oder Energie einsteigt, steht der Designer vor der Frage: *Ich kann Interaction Design — aber ich kenne die Branche nicht.*

Ein Domain-Agent ist kein Code-Generator sondern ein **eingebetteter Domänen-Experte** der parallel zur Designarbeit läuft.

```
Domain-Agent MedTech
├── Normen-Kontext      IEC 62366, FDA HF, ISO 62304
├── Nutzer-Profile      Chirurg (OP, Stress, Sterilität) · Radiologe · Intensivpfleger
├── Fehlermuster        bekannte Use Errors aus der Literatur
├── Visuelle Normen     ISO 80601 Alarmfarben, Touch-Targets, Lesbarkeit auf Targets
├── Projektwissen       aktuelles Projekt, Kunde, spezifische Anforderungen
└── Principles Layer    stellars Gestaltungsauffassung auf MedTech angewendet
```

Designer stellen Fragen während der Arbeit — ohne Recherche-Pause:

> *„Ich habe einen Bestätigungs-Dialog für eine kritische Aktion — reicht zweistufige Bestätigung nach IEC 62366?"*
> *„Ich plane ein rotes Element für eine Warnung — Konflikte mit normierten Alarmfarben?"*
> *„Nutzer ist OP-Assistent mit sterilen Handschuhen — welche Touch-Target-Größen sind realistisch?"*

| Ohne Domain-Agent | Mit Domain-Agent |
|---|---|
| Wochen Einarbeitung vor Projektstart | Recherche läuft parallel zum Design |
| Externer Berater für Regulatorik | Agent gibt sofortige Orientierung |
| Fehler im Usability-Test gefunden | Viele Fehlermuster früher ausgeschlossen |
| Jedes MedTech-Projekt startet neu | Agent kumuliert Wissen über Projekte |
| Senior muss Junior briefen | Agent übernimmt strukturiertes Domänen-Briefing |

Der Agent lernt aus jedem Projekt — nach zwei MedTech-Projekten erheblich spezifischer als nach dem ersten. Kein Ersatz für echte Branchenerfahrung, aber er komprimiert den Weg dorthin.

## Kundenkommunikation

Briefings, Präsentationen, Konzeptpapiere, Statusupdates, Angebote, Spezifikationen — erheblicher Zeitaufwand der nicht direkt gestalterisch ist, aber Expertise erfordert.

### Pitch in neue Branchen

```
Pitch-Anfrage (z.B. MedTech)
     ↓
Domain-Agent: Branchenkontext, Normen, Schmerzpunkte des Kunden
     ↓
Agent generiert ersten Entwurf Konzeptpapier / Executive Summary
     ↓
Projektleiter verfeinert, fügt stellars Perspektive ein
     ↓
Prototyp aus bestehender QML-Bibliothek — auf MedTech-Kontext angepasst
     ↓
Pitch in Tagen statt Wochen — mit funktionalem Material, nicht Folien
```

### Projektbegleitende Kommunikation

- **Statuszusammenfassung**: Agent fasst zusammen was sich in Figma und Code verändert hat — in kundentauglicher Sprache, nicht technischen Terms
- **Entscheidungsdokumente**: offene Designentscheidungen als strukturierte Optionen aufbereitet, Projektleiter ergänzt Empfehlung
- **Angebotsbausteine**: Scope aus Briefing ableiten, Standardbausteine branchenangepasst durch Domain-Agent

### Sprache die den Kunden trifft

```
Design-Entscheidung (intern): „primärer Workflow vereinfacht"
     ↓
Automotive:   „reduced task completion time, supports SOTIF requirements"
MedTech:      „reduces use error probability, supports IEC 62366 task analysis"
Rail:         „operator workload reduction, EN 50128 human factors alignment"
```

Wer in der Sprache des Kunden spricht zeigt dass er seine Welt versteht — das ist kein Rhetorik-Trick sondern echter Verständnisbeweis.

## Was sich strategisch verschiebt

Die Automotive-Krise ist für stellar ein Zeitfenster. Branchen wie MedTech, Rail und Energie suchen genau das was stellar kann — aber sie haben noch keinen Lieferanten mit dieser Kombination aus Design-Qualität und technischer Tiefe.

Mit Agent-System: kleineres Team, schnellerer Einstieg, keine Qualitätseinbuße.
Nicht Wachstumsstrategie für bessere Zeiten — **Resilienz-Tool für jetzt**.

---

## Technologie & Limitierungen

### Stack

| Tool | Rolle |
|---|---|
| **Figma** (mit MCP) | visuelle Quelle, Single Source of Truth — Lesen produktionsreif, Schreiben limitiert |
| **After Effects → Lottie** | Motion-Handwerk bleibt beim Menschen, Export wird automatisch eingebunden |
| **Qt / QML** | Zielplattform — deklarativ, designnah, States/Transitions als First-Class |
| **Theme.qml** | zentrales Token-System, versioniert |
| **VS Code Agents Window** | Kommandozentrale, Sessions-Management |
| **MCP Server** | Anbindung externer Tools — intern oder als Custom Server |

### Offene Punkte

- Schreibzugriff in Figma via MCP noch limitiert
- Komplexe Interaction Logic und Business-Logik bleiben manuell
- Einmaliger Aufwand: Principles Layer sauber definieren und dokumentieren
- Feedback-Loop muss organisiert sein: abgelehnte Outputs müssen ins System zurückfließen
- Agents Window aktuell Preview — nicht alle Features stabil
