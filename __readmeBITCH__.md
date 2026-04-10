# Symlinks — Obsidian Brain Vault

Ein Symlink ist eine Verknüpfung im Dateisystem.
Der echte Ordner bleibt wo er ist — Obsidian sieht ihn trotzdem als Teil des Vaults.

---

## Symlink erstellen

```bash
ln -s /pfad/zur/quelle /pfad/zum/ziel
```

### Beispiel esp_ai_art:
```bash
ln -s ~/Desktop/art/cosmiccannibalism/esp_ai_art/doc/md ~/Brain/projects/esp_ai_art
```

### Weiteres Projekt hinzufügen:
```bash
ln -s ~/Desktop/art/cosmiccannibalism/projekt2/md ~/Brain/projects/projekt2
```

---

## Symlink prüfen

```bash
ls -la ~/Brain/projects/
```

Ausgabe zeigt Pfeil zur Quelle:
```
esp_ai_art -> /Users/cosmic/Desktop/art/cosmiccannibalism/esp_ai_art/doc/md
```

---

## Symlink löschen

```bash
rm ~/Brain/projects/esp_ai_art
```

> Wichtig: kein `/` am Ende — sonst wird der Inhalt des echten Ordners gelöscht!
> `rm` löscht nur den Symlink, nicht die echten Files.

---

## Obsidian: Symlinks aktivieren

Settings → Files & Links → **Follow symlinks** → einschalten

---

## Übersicht

| Aktion | Befehl |
|---|---|
| Erstellen | `ln -s <quelle> <ziel>` |
| Prüfen | `ls -la <ordner>` |
| Löschen | `rm <symlink>` (kein `/` am Ende!) |

---

## Ordner in Obsidian ausblenden

### Aus Suche & Graph-View (nativ)

`Settings → Files & Links → Excluded files` → Pfad eintragen:
```
projects/esp_ai_art/_templates
projects/esp_ai_art/pdf
```
Ordner werden grau im Explorer angezeigt, aber nicht durchsucht.

### Komplett aus dem Explorer ausblenden (Plugin)

Plugin: **File Hider** (Community Plugins → Browse → installieren → aktivieren)

Danach:
1. Rechtsklick auf den Ordner im File Explorer
2. **"Hide"** klicken → Ordner verschwindet komplett

Versteckte Ordner verwalten:
`Settings → File Hider` → Liste der versteckten Pfade

> Hinweis: Bei Symlink-Ordnern kann es Probleme geben — teste zuerst mit einem normalen Vault-Ordner.
> Falls es nicht klappt: Obsidian neu starten nach Plugin-Aktivierung.


---

## Glossar-Workflow

Das Glossar [[__glossar__]] sammelt Begriffe aus Recherche, Lektüre und Projekten.
Zwei Workflows, zwei Codeblöcke am Ende der Glossar-Datei.

---

### Workflow 1 — Neuen Begriff ins Glossar

Du liest etwas, verstehst einen Begriff nicht oder willst ihn festhalten:

1. `__glossar__.md` öffnen
2. Begriff in den **ersten Codeblock** am Ende eintragen (roh, optional mit Notiz):
```
Quorum Sensing
Polysaccharide — Schutzmatrix in Biofilmen
```
3. Copilot sagen: **`sortier das Glossar`**

Copilot:
- schreibt medienkünstlerische Beschreibung
- sortiert alphabetisch ein
- verlinkt erste Vorkommen in bestehenden Dokumenten
- leert den Codeblock

---

### Workflow 2 — Neues File zu einem Thema erstellen

Du willst zu einem Begriff ein vollständiges Dokument:

1. `__glossar__.md` öffnen
2. Begriff in den **zweiten Codeblock** am Ende eintragen:
```
Quorum Sensing
Epigenetics
```
3. Copilot sagen: **`erstell die neuen files`**

Copilot:
- erstellt vollständige `.md`-Datei (Struktur: Definition, Verwandte Themen, Sektionen, Mermaid, Summary EN)
- legt sie im passenden Unterordner ab
- verlinkt sie in bestehenden Dokumenten
- trägt den Begriff automatisch in Workflow 1 (Glossar) ein
- leert den Codeblock

---

### Struktur der Glossar-Datei

```
## A–Z          alphabetische Einträge mit Beschreibung + Links
---
Block 1:        rohe Begriffe → werden ins Glossar einsortiert
Block 2:        rohe Begriffe → werden zu neuen Dokumenten
```

→ KI-Instruktionen direkt in [[__glossar__#Glossar-Workflow — KI-Instruktionen]]
