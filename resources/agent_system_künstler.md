# Agent-System — Einzelner Künstler

---

Ein Solo-Künstler ist gleichzeitig Creative Director, Produzent, Entwickler, Texter, Archivar und Forscher. Das ist die Stärke (volle Kontrolle, keine Abstimmungsverluste) und die Grenze (Kapazität ist gedeckelt).

Agents sind keine Tools — sie sind Mitarbeiter. Du schulst sie, gibst Aufträge, reviewst Ergebnisse. Du bist nicht Ausführer — du bist **Creative Director**.

```
OHNE AGENTS            MIT AGENTS
──────────────         ──────────────────────────────
Du = 1 Person          Du = Creative Director
Kapazität = 8h         Team = Agents die parallel ausführen
                       Kapazität = deine Entscheidungsgeschwindigkeit
```

---

## Das Team

### Stammmitarbeiter — immer aktiv, alle Projekte

| Agent | Aufgabe | Quelle |
|---|---|---|
| **Glossar-Assistent** | Neue Begriffe einsortieren, Einträge schreiben | Instructions aus `__cosmicbrain__.md` |
| **Vault-Verlinker** | Jedes neue Dokument auf verlinkbare Begriffe scannen, Wiki-Links setzen | Dauerhafte Instructions |
| **Stil-Wächter** | Schreibt in deinem Ton — Deutsch, präzise, medienkünstlerischer Kontext | Persönliche Instructions |

### Projektmitarbeiter — aufgabenspezifisch

| Agent | Aufgabe | Kontext |
|---|---|---|
| **Primordial-Soup-Agent** | Spezies-Logik, LFO-Struktur, Merge-Konflikte, Kamera-Interaktion | kennt das Regelset der Simulation |
| **DNA-Sequencer-Agent** | Code kommentieren, .ino-File dokumentieren | kennt Arduino-Konventionen, `konzept_objekt.md` |
| **Petroglyphen-Agent** | Konzept ausarbeiten, Recherche, Moodboard-Struktur | kennt das Projektkonzept |

### Wie du sie schulst

| Schulungsmittel | Was es ist | Wirkung |
|---|---|---|
| **Instructions** (`.instructions.md`) | Dauerhaftes Regelwerk | automatisch aktiv für alle passenden Sessions |
| **Prompt-Files** (`.prompt.md`) | Vorgefertigter Auftrag | startet Session mit vollständigem Briefing |
| **Principles Layer** | Ästhetische Regeln als Datei | hält Konsistenz über alle Outputs |
| **Feedback & Korrekturen** | Abgelehnte Outputs dokumentieren | Agent lernt was *nicht* gemeint ist |

---

## Die Wissensbase — `__cosmicbrain__` als Schulungsmaterial

Der Vault ist mehr als Notizsammlung — er ist die **Unternehmenskultur als Datei**: Begriffe, Denkweisen, Prinzipien die jeder Agent beim Start kennt.

Die KI-Instruktions-Blöcke in `__cosmicbrain__.md` sind bereits Schulungsmaterial. Mit `.instructions.md`-Dateien und `applyTo`-Frontmatter werden sie permanent und automatisch — ohne dass du die Datei jedes Mal öffnen musst.

---

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

### Wie die Kommandozentrale funktioniert

```
Auftrag erteilen   →  Session starten, Prompt formulieren
Parallel arbeiten  →  mehrere Sessions gleichzeitig, verschiedene Projekte
Zwischenstand      →  Changes Panel: alle Dateiänderungen im Diff-View
Feedback geben     →  direkt in den Diff kommentieren
Abliefern          →  Commit / Merge / Discard aus dem Changes Panel
```

---

## Design → Code — Figma & After Effects im Workflow

```
DU (Vision, Entscheidungen, Handwerk in den Tools)
│
├── baust in Figma          → Agent liest aus, generiert Code
├── animierst in AE         → Lottie-Export, Agent bindet ein
├── definierst Principles   → Agent wendet an auf alles
└── reviewst Outputs        → Agent iteriert
```

| Agent | Mensch |
|---|---|
| Tokens extrahieren & übersetzen | Gefühl und Ästhetik-Entscheidungen |
| Inkonsistenzen finden | Review ob Output zur Vision passt |
| Boilerplate generieren | Animationen und Motion-Handwerk in AE |
| Struktur dokumentieren | Business-Logik und Edge Cases |

```
Figma-Variante   →  QML State
Figma-Transition →  QML Transition / Behavior
Design Token     →  Theme.qml Objekt
AE-Animation     →  Lottie JSON → LottieAnimation { }
```

---

## Was sich verschiebt

**Von:** *„ich muss das noch selbst umsetzen"*
**Zu:** *„ich entscheide ob das stimmt"*

Das ist der eigentliche Gewinn — nicht Geschwindigkeit, sondern **Tiefe**. Die kreative Energie fließt in Entscheidungen, nicht in Ausführung.
