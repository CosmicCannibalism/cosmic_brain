---
tags:
  - readme
  - setup
typ: meta
bereich: system
---

# cosmic_brain — Obsidian Vault

Persönliches Wissenssystem für Medienkunst-Recherche, Theoriefragmente und Projektdokumentation.
Ideen, Begriffe, Projekte und offene Fragen landen hier — strukturiert, verlinkbar, durchsuchbar.

**Öffentlich auf GitHub:** [CosmicCannibalism/cosmic_brain](https://github.com/CosmicCannibalism/cosmic_brain)

---

## Inhalt

- [Die vier Ebenen](#die-vier-ebenen-des-vaults)
- [Struktur](#struktur)
- [Glossar-Workflow](#glossar-workflow)
- [Setup](#setup)
- [Projekte](#projekt-readmes)

---

## Werkzeuge & Workflow

Der Vault wird mit zwei Tools parallel bearbeitet:

| Tool | Rolle |
|:--|:--|
| **Obsidian** | Lesen, Navigieren, Graph View, Backlinks, Dataview |
| **VS Code + GitHub Copilot** | Neue Files generieren, Code schreiben, Vault-weite Operationen (Frontmatter, Verlinkung, Umbenennung) |

Der typische Workflow mit VS Code:
- Copilot kennt den Vault-Kontext und erstellt neue Theorie- und Infodateien im bestehenden Stil
- Massenoperationen (z.B. Frontmatter über alle Files, Umbenennung von Links) laufen über Copilot
- Code-Dateien (HTML-Simulationen, Algorithmen) entstehen in VS Code und werden direkt im Vault abgelegt
- Glossar-Einträge, Verlinkungen und Properties werden auf Zuruf aktualisiert

### Git & GitHub

Der Vault ist vollständig mit Git versioniert und öffentlich zugänglich:

**[https://github.com/CosmicCannibalism/cosmic_brain](https://github.com/CosmicCannibalism/cosmic_brain)**

```bash
# Stand pushen
git add . && git commit -m "update" && git push

# Was hat sich geändert?
git status
git log --oneline -10
```

> `resources/security.md` ist über `.gitignore` vom Tracking ausgeschlossen.

---

## Die vier Ebenen des Vaults

Jede Information im Vault existiert auf vier Ebenen gleichzeitig. Sie ergänzen sich — keine ersetzt die andere.

### Ebene 1 — `[[Links]]` · Navigation

Wikilinks zwischen Dateien. Bilden das Netz im Graph View. Klickbar. Bidirektional — Obsidian zeigt unter jeder Datei welche anderen sie verlinken (*Backlinks*).

**Wann:** immer wenn ein Begriff in einem Text auftaucht der ein eigenes File hat.

```
[[quorum_sensing]] · [[feuer]] · [[cosmicalchemys#Leo]]
```

---

### Ebene 2 — `#tags` · Kategorien

Labels die mehrere Dateien zu Gruppen zusammenfassen. Im Tag-Pane alle Dateien einer Kategorie auf einen Blick.

**Wann:** beim Erstellen — 2–4 Tags die die Zugehörigkeit beschreiben.

```yaml
tags:
  - biologie
  - emergenz
```

---

### Ebene 3 — Properties · Metadaten

YAML-Frontmatter oben in jeder Datei. Obsidian rendert es als Formular. Mit **Dataview** abfragbar wie eine Datenbank.

**Konsistente Properties im Vault:**

| Property | Werte | Beispiel |
|:--|:--|:--|
| `typ` | `element` · `sternzeichen` · `konzept` · `theorie` · `technik` · `rezept` · `referenz` · `meta` · `scratch` · `template` · `anleitung` · `praxis` · `algorithmus` | `typ: theorie` |
| `bereich` | `biologie` · `theorie` · `cosmicalchemy` · `projekt` · `psychologie` · `ki` · `praxis` · `system` | `bereich: biologie` |
| `element` | `feuer` · `erde` · `luft` · `wasser` · `aether` | `element: feuer` |
| `modalitaet` | `kardinal` · `fix` · `mutable` | `modalitaet: kardinal` |
| `status` | `in-progress` · `done` · `draft` | `status: in-progress` |
| `projekt` | `esp_ai_art` · *(weitere Projekte)* | `projekt: esp_ai_art` |

**Dataview-Beispiele:**
````
```dataview
TABLE typ, bereich FROM "resources"
WHERE typ = "theorie"
SORT bereich ASC
```
````
````
```dataview
LIST FROM "resources/sternzeichen"
WHERE element = "feuer"
```
````

---

### Ebene 4 — [[__cosmicbrain__]] · Bedeutung

Das Glossar ist die semantische Ebene — nicht Navigation, nicht Kategorisierung, sondern Bedeutung. Jeder Begriff wird definiert, kontextualisiert, medienkünstlerisch eingebettet.

**Wann:** wenn ein Begriff *verstanden* werden soll, nicht nur gefunden.

→ Workflow: [[readme#Glossar-Workflow]]

---

## Struktur

```
__cosmicbrain__.md    Begriffe aus Recherche & Theorie — alphabetisch, medienkünstlerisch kontextualisiert
__sandbox__.md        Rohe Ideen, Fragmente, offene Fragen
readme.md             dieses File
daily/                Tagesnotizen & Kalenderevents
projects/             Projektdokumentation (als Symlinks oder direkt)
resources/            Referenzmaterial geordnet nach Thema
  elemente/           Feuer, Erde, Luft, Wasser, Äther
  sternzeichen/       alle 12 Zeichen
  biologie/           Biosemiotik, Quorum Sensing, Membranen …
  theorie/            Pataphysik, Petrochemie, Turing/Duchamp …
```

---

## Glossar-Workflow

Das Glossar [[__cosmicbrain__]] sammelt Begriffe aus Recherche, Lektüre und Projekten.
Zwei Workflows, zwei Codeblöcke am Ende der Glossar-Datei.

### Workflow 1 — Begriff ins Glossar

1. `__cosmicbrain__.md` öffnen
2. Begriff in den **ersten Codeblock** am Ende eintragen (roh, optional mit Notiz):
```
Quorum Sensing
Polysaccharide — Schutzmatrix in Biofilmen
```
3. Copilot sagen: **`sortier das Glossar`**

Copilot: schreibt medienkünstlerische Beschreibung → sortiert alphabetisch → verlinkt → leert Codeblock.

---

### Workflow 2 — Neues Dokument erstellen

1. `__cosmicbrain__.md` öffnen
2. Begriff in den **zweiten Codeblock** am Ende eintragen:
```
Quorum Sensing
Epigenetics
```
3. Copilot sagen: **`erstell die neuen files`**

Copilot: erstellt vollständiges `.md`-File → legt es in `resources/` ab → verlinkt in bestehenden Dokumenten → trägt es ins Glossar ein → leert Codeblock.

---

### Struktur der Glossar-Datei

```
## A–Z          alphabetische Einträge mit Beschreibung + Links
---
Block 1:        rohe Begriffe → werden ins Glossar einsortiert
Block 2:        rohe Begriffe → werden zu neuen Dokumenten
```

→ KI-Instruktionen im Callout-Block direkt in [[__cosmicbrain__]]

---

## Setup

### Symlinks

Ein Symlink ist eine Verknüpfung im Dateisystem — der echte Ordner bleibt wo er ist, Obsidian sieht ihn als Teil des Vaults.

```bash
# Erstellen
ln -s /pfad/zur/quelle /pfad/zum/ziel

# Beispiel esp_ai_art
ln -s ~/Desktop/art/cosmiccannibalism/esp_ai_art/doc/md ~/Brain/projects/esp_ai_art

# Prüfen
ls -la ~/Brain/projects/

# Löschen (kein / am Ende!)
rm ~/Brain/projects/esp_ai_art
```

> Wichtig: kein `/` am Ende beim Löschen — sonst wird der Inhalt des echten Ordners gelöscht.

---

### Obsidian-Einstellungen

| Was | Wo |
|:--|:--|
| Symlinks aktivieren | Settings → Files & Links → **Follow symlinks** → an |
| Ordner aus Suche & Graph ausblenden | Settings → Files & Links → **Excluded files** |
| Ordner komplett aus Explorer ausblenden | Plugin **File Hider** → Rechtsklick → "Hide" |

### CSS Snippets

Eigene Styles für den Vault unter `.obsidian/snippets/` ablegen:

```
.obsidian/snippets/
  mein-style.css
  typography.css
```

Aktivieren: Settings → Appearance → CSS snippets → Toggle

Nützlich für: eigene Typografie, farbige Tags, Callout-Styles, Property-Darstellung, Dark-Mode-Feintuning.

---

## Projekt-Readmes

- [[projects/esp_ai_art/README.md]] — ESP AI Art: ML-Installationen mit ESP32

*(weitere Projekte hier ergänzen)*

> Tipp: Im Graph-View nach Projekten filtern: `path:projects/esp_ai_art/`

