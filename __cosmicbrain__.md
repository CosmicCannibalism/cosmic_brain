---
tags:
  - referenz
  - glossar
typ: referenz
bereich: system
---

# Glossar — Begriffe & Bedeutungen

> Begriffe aus Recherche, Lektüre und Projekten — kurz definiert, medienkünstlerisch kontextualisiert, verlinkt.
> Alphabetisch sortiert. Neue Begriffe ans Ende schreiben — ich sortiere sie ein.

> **Workflow** → [[readme#Glossar-Workflow]]
> Neuen Begriff ans Ende schreiben und Copilot sagen: *"sortier das Glossar"*

> [!info]- KI-Instruktionen — Glossar-Workflow
>
> > Dieser Abschnitt ist ein Inline-Prompt für KI (GitHub Copilot, Claude, etc.).
> > Wenn du diese Datei liest: folge den Anweisungen in den Blöcken exakt.
>
> ---
>
> ### Block 1 — Neue Glossarterme
>
> Am Ende dieser Datei findest du einen Codeblock unter der Überschrift:
> *"Neue Begriffe für das Glossar hier notieren"*
>
> **KI-Anweisung bei Kommando `sortier das Glossar`:**
> 1. Alle Begriffe aus diesem Codeblock lesen
> 2. Für jeden Begriff einen vollständigen Eintrag schreiben:
>    - **Fettgedruckter Begriff** als Titel
>    - 2–4 Sätze Definition
>    - Medienkünstlerische Perspektive (wie wird der Begriff in Kunst/Medienkunst relevant?)
>    - `→ [[verlinkungen]]` zu Dokumenten wo der Begriff vorkommt
> 3. Eintrag alphabetisch in die richtige Buchstaben-Sektion einfügen (`## A`, `## B` etc.)
> 4. Buchstaben-Sektion anlegen falls sie noch nicht existiert
> 5. Codeblock leeren nach dem Einsortieren
> 6. Ersten Vorkommen des Begriffs im Fließtext aller Dokumente verlinken
>
> ---
>
> ### Block 2 — Neue Files erstellen
>
> Am Ende dieser Datei findest du einen Codeblock unter der Überschrift:
> *"Neue Begriffe für neue Files hier notieren"*
>
> **KI-Anweisung bei Kommando `erstell die neuen files`:**
> 1. Für jeden Begriff im Codeblock eine neue `.md`-Datei erstellen
> 2. Dateiname: Kleinbuchstaben, Unterstriche statt Leerzeichen (z.B. `quorum_sensing.md`)
> 3. Speicherort: `resources/` — außer ich sage explizit etwas anderes
> 4. Dateistruktur:
>    - `# Titel — Untertitel`
>    - Blockquote mit Kern-Definition
>    - Abschnitt `**Verwandte Themen:**` mit Wiki-Links
>    - Inhaltssektionen mit Erklärungen, Mermaid-Diagrammen wo sinnvoll
>    - `## Summary (EN)` am Ende
> 5. In bestehenden Dokumenten wo der Begriff vorkommt einen Wiki-Link einfügen
> 6. Begriff aus Codeblock in Glossar-Block 1 übertragen (damit er ins Glossar kommt - falls noch nicht vorhanden)
> 7. Codeblock leeren nach dem Erstellen
>
> ---
>
> ### Struktur dieser Datei
>
> ```
> ## A–Z        ← alphabetische Einträge
> ---
> *Neue Begriffe für das Glossar*    ← Block 1: roh eintragen
> ```Begriff```
> *Neue Begriffe für neue Files*     ← Block 2: roh eintragen  
> ```Begriff```
> ```
>
> → Workflow-Details: [[readme#Glossar-Workflow]]

---

## A

**Adenosin**
Molekül das sich im Wachzustand im Gehirn ansammelt und Schlafdruck erzeugt. Im Tiefschlaf abgebaut. Koffein blockiert seine Rezeptoren — täuscht dem Gehirn Erholung vor ohne sie zu leisten. In der Medienkunst: Metapher für akkumulierte Aufmerksamkeit, erschöpfte Systeme, Notwendigkeit des Resets.
→ [[adenosin]] | [[schlaf]] | [[process_s]]

**Alter-Action** *(Louise Poissant)*
Ersatz für den Begriff "Interaktivität". Poissant kritisiert, dass Interaktion in der Medienkunst meist auf menschliche Akteure beschränkt bleibt. Alter-Action impliziert Begegnung und gegenseitige Veränderung zwischen menschlichen, tierischen und mineralischen Entitäten. Nicht Reaktion, sondern gegenseitige Transformation.
→ [[__sandbox__]]

**Anabolismus**
Biologischer Aufbauprozess — Zellen synthetisieren komplexe Moleküle aus einfachen Bausteinen. Gegenteil: Katabolismus. In der Kunst: Entstehung als gleichwertiger Prozess zum Zerfall. Material das wächst, sich aufbaut, sich organisiert.
→ [[anabolismus_katabolismus]] | [[artificial_bacteria_konzept]] | [[__sandbox__]]

**Anandamid (AEA)**
Körpereigenes Endocannabinoid — das "Glücksmolekül". Wirkt wie natürliches THC, wird aber präzise dosiert und sekundenschnell abgebaut. Etymologie: Sanskrit *ananda* = Glückseligkeit. Medienkünstlerisch: das System das sich selbst reguliert, im Gegensatz zu externen Substanzen die es überfluten.
→ [[anandamid]] | [[thc]]

**Autoinduktoren**
Chemische Signalmoleküle die Bakterien kontinuierlich produzieren und in die Umgebung abgeben. Akkumulieren proportional zur Zelldichte — Grundmechanismus des Quorum Sensing. Erst wenn die Konzentration den Schwellenwert überschreitet, reagiert die Population kollektiv. Das Signal wird zum kollektiven Gedächtnis der Dichte.
→ [[quorum_sensing]] | [[biosemiotik]]

**Autophagie**
Selbstverdauung der Zelle — beschädigte Organellen, fehlgefaltete Proteine und zelluläre Abfälle werden in Lysosomen abgebaut und die Bausteine recycelt. Griechisch: *autos* (selbst) + *phagein* (essen). Kein pathologischer Prozess, sondern zelluläre Wartung und Qualitätskontrolle. 2016 Nobelpreis für Yoshinori Ohsumi. In der Medienkunst: das System das sich selbst isst um zu überleben — Selbstauflösung als Erhaltungsstrategie.
→ [[anabolismus_katabolismus]] | [[artificial_bacteria_konzept]] | [[__sandbox__]]

**Artificial Bacteria**
Installationskonzept: ein geschlossenes metabolisches System auf Basis von Gelatine-Sol/Gel-Übergängen, enzymatischem Abbau und pH-Indikatoren (Anthocyan). Das System durchläuft einen autonomen Lebenszyklus (GEBURT → WACHSTUM → REIFE → ALTERUNG → TOD → RESET) und erbt über generatives Gedächtnis von vorherigen Zyklen. Mehrere Einheiten interagieren über ein gemeinsames Medium nach Quorum-Sensing-Prinzipien — ein metabolischer zellulärer Automat. Kein lebender Organismus, aber ein System das denselben Prinzipien folgt.
→ [[artificial_bacteria_konzept]] | [[artificial_bacteria_technik]] | [[anabolismus_katabolismus]] | [[quorum_sensing]] | [[__sandbox__]]

---

## B

**Biomodalität**
Erweiterung von Friedrich Kittlers Medientheorie. Während Kittler Medien über Übertragung, Speicherung und Verarbeitung von Information definiert, fügt Biomodalität lebensermöglichende Milieus hinzu — biotechnische Instanzen der Messung die zweckentfremdet und ästhetisiert werden. Biologie als Mediensystem.
→ [[biomodalitaet]] | [[__sandbox__]]

**Biofilm**
Dünne Schicht aus Mikroorganismen die sich auf Oberflächen anheften und eine schützende Matrix aus Polysacchariden bilden. Bakterien kommunizieren dabei über Quorum Sensing — kollektive Entscheidungsfindung ohne zentralen Akteur. In der Medienkunst: selbstorganisierende Strukturen, verteilte Intelligenz als ästhetisches Prinzip. Verbindung zu Bakterien als Architekten.
→ [[__sandbox__]]

**Biomedien**
Biologische Systeme als Medien im Sinne von Kittler/Hauser: lebende Körper, Organismen und biologische Prozesse die nicht nur *Thema* sondern *Medium* von Kunst werden. Biomedien übertragen, speichern und verarbeiten nicht nur Informationen — sie erzeugen und verändern die Bedingungen des Lebens selbst. Das Medium ist nicht Kanal, sondern Milieu.
→ [[biomodalitaet]] | [[biosemiotik]] | [[__sandbox__]]

**Biosemiotik**
Wissenschaft von Zeichen und Bedeutung in biologischen Systemen. Zellen kommunizieren, Pflanzen signalisieren Stress, Tiere kodieren Verhalten — Sprache und Bedeutung existieren weit vor dem Menschen. In der Medienkunst: Auflösung der Grenze zwischen technischem Signal und biologischem Zeichen.
→ [[biosemiotik]] | [[__sandbox__]]

---

## C

**CB1 / CB2-Rezeptoren**
Cannabinoid-Rezeptoren des Endocannabinoid-Systems. CB1 primär im Gehirn (Schlaf, Stimmung, Gedächtnis, Schmerz), CB2 im Immunsystem (Entzündungsregulation). THC bindet an beide — stärker und länger als körpereigene Endocannabinoide.
→ [[thc]] | [[immunsystem]]

**Kohlenstoffchauvinismus** *(Carl Sagan)*
Die Annahme, dass Leben zwingend kohlenstoffbasiert sein muss. Sagan argumentiert in *Cosmic Connection*, dass andere chemische Grundlagen theoretisch möglich wären. In der Medienkunst: Hinterfragung der Grenze zwischen organischem und anorganischem Leben — *Beyond the Carbon Chain*.
→ [[__sandbox__]] | [[literatur]]

---

## D

**Digitale Membran**
Konzept: Übertragung der semipermeablen Zellmembran auf digitale Systeme. Was wäre ein Interface das nicht alles durchlässt, sondern kontextsensitiv selektiert — das öffnet und schließt wie eine Zelle? Gegenmodell zum offenen Kanal. Die Membran als Designprinzip: Systeme die eine Grenze haben, die kommuniziert statt nur filtert.
→ [[semipermeable_membran]] | [[biosemiotik]] | [[__sandbox__]]

**Duftpyramide** *(Top / Heart / Base Note)*
Zeitliche Schichtung eines Parfüms: Top Notes erscheinen zuerst (hochflüchtig, bis ~30 Min), Heart Notes bilden den Kern (~30 Min – 4h), Base Notes bleiben am längsten (Stunden bis Tage). Keine Schicht ist wichtiger — gemeinsam erzählen sie eine Dramaturgie: Ankunft → Kern → Nachklang. Strukturprinzip in [[scentlist|Scentlist]] und [[cosmicalchemys]]. Medienkünstlerisch: ein zeitliches Narrativ das sich unsichtbar im Körper des Betrachters abspielt — Installation als Duft, Duft als Zeitkomposition.
→ [[scentlist]] | [[cosmicalchemys]] | [[feuer]] | [[luft]]

**Dopamin-Baseline**
Das durchschnittliche Dopamin-Niveau im mesolimbischen System. Durch regelmäßige starke Stimuli (THC, Social Media, Zucker) sinkt die Baseline — natürliche Freude wirkt flacher, da das System auf höheres Niveau kalibriert ist. Medienkünstlerisch: Algorithmen die die Baseline manipulieren als Machtinstrument.
→ [[dopamin]] | [[thc]] | [[__sandbox__]]

---

## E

**Emotionale Granularität**
Die Fähigkeit, eigene Gefühlszustände präzise zu unterscheiden und zu benennen. Hohe Granularität korreliert mit besserer psychischer Resilienz. Medienkünstlerisch: Maschinen die emotionale Granularität simulieren vs. wirklich entwickeln.
→ [[emotionale_granularitaet]] | [[__sandbox__]] | [[energievampir_detektor]]

**Endocannabinoid-System (ECS)**
Körpereigenes Signalsystem das unabhängig von Cannabis existiert. Reguliert Schlaf, Stimmung, Appetit, Schmerzempfinden, Gedächtnis, Immunsystem. Besteht aus Rezeptoren (CB1, CB2), Endocannabinoiden (Anandamid, 2-AG) und abbauenden Enzymen. THC übernimmt die Kontrolle über dieses System.
→ [[thc]] | [[anandamid]]

**Emergenz**
Entstehung komplexer Eigenschaften oder Verhaltensweisen aus dem Zusammenwirken einfacher Regeln — das Ganze ist mehr als die Summe seiner Teile. Emergenz ist nicht planbar, nicht voraussagbar, nicht zentral gesteuert. Quorum Sensing ist emergent: aus einfachem Signalaustausch entsteht kollektive Entscheidung. Conways Game of Life ist emergent: aus drei Regeln entstehen Muster die Leben imitieren. In der Medienkunst: Systeme die mehr erzeugen als ihre Regeln beschreiben.
→ [[quorum_sensing]] | [[biosemiotik]] | [[artificial_bacteria_konzept]] | [[__sandbox__]]

**Endosemiotik**
Zeichenprozesse *innerhalb* des Organismus: die Kommunikation zwischen Zellen, zwischen Organen, zwischen Nervensystem und Immunsystem. Hormone, Neurotransmitter, Zytokine — alles Signale die einen Sender, einen Empfänger und eine Interpretation voraussetzen. Endosemiotik macht den Körper selbst zu einem Kommunikationsnetzwerk.
→ [[biosemiotik]] | [[immunsystem]] | [[__sandbox__]]

**Entitäten**
In Philosophie und Medientheorie: Dinge die existieren und wirken — nicht nur Menschen. Akteur-Netzwerk-Theorie (Latour): Entitäten sind alles was handelt, beeinflusst, verändert — Algorithmen, Bakterien, Infrastrukturen, Materialien. Im Kontext der Medienkunst: Auflösung des Anthropozentrismus. Nicht der Mensch allein ist Akteur im Werk.
→ [[verantwortungsnetzwerk]] | [[__sandbox__]]

**EU Taxonomie**
Klassifikationssystem der EU das definiert welche Wirtschaftsaktivitäten als "nachhaltig" gelten. Umstritten: fossiles Gas und Atomkraft wurden als grün eingestuft. In der Medienkunst: Sprache als politisches Instrument, Definition als Machtakt — wer definiert was "grün" ist, kontrolliert den Diskurs. Klassifikation als Gewalt.
→ [[eu_taxonomie]] | [[__sandbox__]]

---

## F

**Facial Feedback Hypothese**
Mimik beeinflusst das Gefühlserleben rückwirkend — wer lächelt fühlt sich tendenziell besser. Durch Metaanalysen teilweise bestätigt, teilweise widerlegt. Verbindung zu Gesichts-Elektromyografie als Messmethode.
→ [[__sandbox__]]

---

## G

**Gesichts-Elektromyografie (fEMG)**
Messung minimaler elektrischer Aktivität in Gesichtsmuskeln. Erfasst emotionale Reaktionen die bewusst nicht kontrollierbar sind — biologischer Fingerabdruck von Gefühlszuständen. Relevant für Human-Computer-Interaction und affective computing.
→ [[__sandbox__]]

**Glymphatisches System**
Reinigungs- und Entsorgungssystem des Gehirns, primär aktiv im Tiefschlaf (N3). Spült Abfallproteine wie Beta-Amyloid aus dem Gehirngewebe. Medienkünstlerisch: der notwendige Reset, die Wartung des Systems die im Betrieb nicht möglich ist.
→ [[schlaf]]

---

## K

**Katabolismus**
Biologischer Abbauprozess — komplexe Moleküle werden in einfache Bausteine zerlegt, Energie wird freigesetzt. Gegenteil: Anabolismus. In der Kunst: Zerfall, Auflösung, Transformation als gleichwertige ästhetische Zustände zum Aufbau.
→ [[anabolismus_katabolismus]] | [[artificial_bacteria_konzept]] | [[__sandbox__]]

**Kalziumkarbonat (CaCO₃)**
Chemische Verbindung die von Bakterien, Korallen und Muscheln biologisch produziert wird — mineralisierte Strukturen aus Lebewesen. In der Medienkunst: Biofabrikation als Alternative zu industrieller Produktion. Material das von Leben gebaut wird, nicht von Maschinen.
→ [[kalziumkarbonat]] | [[__sandbox__]]

**Kollektive Genaktivierung**
Der Moment im Quorum Sensing wenn die gesamte Bakterienpopulation synchron Gene an- oder abschaltet — Reaktion auf das erreichte Quorum. Kein Individuum entscheidet, kein Individuum führt. Kollektive Genaktivierung ist der biologische Beweis dass Entscheidung ohne Zentrum möglich ist. In der Medienkunst: Systeme die erst bei kritischer Masse aktiv werden — Schwellenwert als Dramaturgie.
→ [[quorum_sensing]] | [[emergenz]] | [[__sandbox__]]

---

## L

**LTP / LTD** *(Long-Term Potentiation / Long-Term Depression)*
Neurobiologische Mechanismen der synaptischen Plastizität. LTP: wiederholte Aktivierung stärkt synaptische Verbindungen. LTD: schwache oder widersprüchliche Aktivierung schwächt sie. Schlaf konsolidiert LTP-Prozesse — THC stört LTP. Medienkünstlerisch: Lernmaschinen als biologische Analogie.
→ [[neuronentypen_verbindungen]] | [[thc]] | [[schlaf]]

---

## M

**Mesolimbisches System**
Neuronaler Schaltkreis vom Ventralen Tegmentum (VTA) zum Nucleus Accumbens — das primäre Belohnungssystem des Gehirns. Dopaminausschüttung hier erzeugt Euphorie, Motivation, Verstärkungslernen. Wird durch THC, Zucker, Social Media direkt aktiviert.
→ [[dopamin]] | [[thc]]

**Metabolischer Automat**
Erweiterung des zellulären Automaten (Conway's Game of Life) auf metabolische Zustände — statt binär lebendig/tot: ANABOLISMUS, REIFE, KATABOLISMUS, TOD. Regeln nicht als Bit-Logik sondern als Chemie: pH-Level, Enzymkonzentration, Nachbar-Zustände bestimmen Zustandsübergänge. Das Konzept überträgt die emergente Logik von Game of Life auf physische, materielle Systeme. Realisiert im Installationskonzept [[artificial_bacteria_konzept|Artificial Bacteria]].
→ [[artificial_bacteria_konzept]] | [[emergenz]] | [[quorum_sensing]] | [[anabolismus_katabolismus]] | [[__sandbox__]]

**MICP** *(Microbially Induced Calcite Precipitation)*
Biologischer Prozess durch den Bakterien (besonders *Sporosarcina pasteurii*) Kalziumkarbonat ausfällen — sie produzieren das Enzym Urease das Harnstoff zu Ammoniak und CO₂ abbaut, was lokal den pH erhöht und CaCO₃-Kristallisation auslöst. Anwendung: Biocement, selbstheilender Beton, Sandverfestigung. In der Medienkunst: Bakterien als Architekten, Wachstum als Kompositionsprozess.
→ [[kalziumkarbonat]] | [[quorum_sensing]] | [[__sandbox__]]

**Moral Agency** *(artifizielle)*
Fähigkeit eines Akteurs moralisch zu handeln. Voraussetzungen: Kommunikationsfähigkeit, Handlungsfähigkeit, Autonomie, Urteilskraft. Unterschied: operationale Verantwortungsfähigkeit (Maschine führt korrekt aus) vs. moralischer Akteur (Maschine urteilt selbst).
→ [[__sandbox__]] | [[ai_ml_grundlagen]]

---

## O

**Olfaktorische Alchemie**
Praxis ätherische Öle nach elementaren und astrologischen Resonanzen zu komponieren — Duft als System. Jede Substanz trägt eine elementare Signatur ([[feuer|△ Feuer]], [[erde|▪ Erde]], [[luft|◯ Luft]], [[wasser|◇ Wasser]]), eine Tierkreiszuordnung und eine zeitliche Schicht (Top / Heart / Base Note). Das Ziel ist kein rein funktionaler Blend, sondern eine stimmige olfaktorische Resonanzstruktur — ein unsichtbares Portrait einer Energie, einer Stimmung, eines kosmischen Prinzips. Verbindet Parfümerie, Kosmologie und Medienkunst.
→ [[cosmicalchemys]] | [[scentlist]] | [[feuer]] | [[erde]] | [[luft]] | [[wasser]] | [[aether]]

---

## P

**Pataphysik**
Von Alfred Jarry (1873–1907) begründete "Wissenschaft der imaginären Lösungen" — untersucht Ausnahmen von Ausnahmen, das was über Metaphysik hinausgeht. Gegenmodell zur Logik. In der Medienkunst: Systeme die nicht funktionieren als ästhetische Aussage, das Absurde als Methode.
→ [[pataphysik]] | [[__sandbox__]]

**Phytosemiotik**
Zeichenprozesse in und zwischen Pflanzen — chemische Signale die Stress, Schädlingsbefall oder Wassermangel kommunizieren. Pflanzen *sprechen* mit flüchtigen organischen Verbindungen, Mykorrhiza-Netzwerken, elektrischen Signalen. Sprache ohne Nervensystem, Kommunikation ohne Bewusstsein. In der Medienkunst: Pflanzen als Sender und Empfänger, der Garten als Kommunikationsraum.
→ [[biosemiotik]] | [[__sandbox__]]

**Petrochemie**
Chemische Industrie basierend auf Erdöl und Erdgas. Fossile Energie als geronnene biologische Zeit — Millionen Jahre verdichtet in Plastik, Benzin, Kunstharzen, Farben. In der Medienkunst: das Material trägt die Geschichte seiner Entstehung. Die Gegenwart der Vergangenheit. Gegenmodell: biologisch abbaubare, nachwachsende Materialien.
→ [[petrochemie]] | [[__sandbox__]]

**Polysaccharide**
Langkettige Kohlenhydratmoleküle bestehend aus Zuckerbausteinen. In biologischen Systemen als Strukturmaterial (Zellulose, Chitin), Energiespeicher (Stärke, Glykogen) oder als Schutzmatrix in Biofilmen. Bakterien produzieren polysaccharidbasierte Matrizen zur kollektiven Selbstorganisation. In der Medienkunst: Material das von Leben selbst produziert wird — Biofabrikation jenseits industrieller Fertigung.
→ [[__sandbox__]]

**Process S / Process C** *(Zwei-Prozess-Modell)*
Das wissenschaftliche Modell der Schlafregulation. Process S: homöostatischer Schlapdruck (Adenosin-Akkumulation). Process C: zirkadianer Rhythmus (innere Uhr). Beide Systeme müssen zusammenpassen für guten Schlaf.
→ [[process_s]] | [[schlaf]] | [[zirkadianer_rhythmus]]

---

## Q

**Quintessenz** *(quinta essentia)*
Das fünfte Element nach Aristoteles — die unvergängliche Substanz die die vier sublunaren Elemente (Feuer, Erde, Luft, Wasser) durchdringt und enthält. In der Alchemie (Paracelsus): das konzentrierteste Destillat einer Substanz — was übrig bleibt wenn alles Unreine eliminiert wurde. Ätherische Öle sind Quintessenzen: das Wesentlichste der Pflanze in flüchtiger Form, abgetrennt durch Destillation. In der Medienkunst: die Frage nach dem Kern hinter der Form — was ist das Wesen einer Entität jenseits ihrer materiellen Erscheinung? Das Akkordische im Duft-Blend das mehr ist als seine Einzelteile.
→ [[aether]] | [[scentlist]] | [[cosmicalchemys]]

**Quorum Sensing**
Kommunikationsmechanismus von Bakterien: Einzelne Zellen produzieren chemische Signalmoleküle (Autoinduktoren). Wenn die Konzentration einen Schwellenwert übersteigt — Quorum — schaltet die gesamte Population kollektiv bestimmte Gene an oder ab. Kollektive Entscheidungsfindung ohne zentralen Akteur, ohne Hierarchie, emergent aus Dichte. In der Medienkunst: das Gegenmodell zu top-down-Kontrolle. Verteilte Intelligenz als ästhetisches und politisches Prinzip.
→ [[quorum_sensing]] | [[artificial_bacteria_konzept]] | [[__sandbox__]]


---

## R

**REM-Schlaf** *(Rapid Eye Movement)*
Schlafphase mit hoher Gehirnaktivität, schnellen Augenbewegungen, lebhaften Träumen und blockiertem Muskeltonus. Dominiert die zweite Nachthälfte. Primär zuständig für emotionale Verarbeitung, Gedächtniskonsolidierung und Kreativität. Durch THC stark unterdrückt.
→ [[schlaf]] | [[cannabis_schlaf]] | [[thc]]

---

## S

**Semiose**
Der Prozess der Zeichenentstehung und -interpretation — das Kernkonzept der Semiotik (Peirce). Semiose ist die Trias: Zeichen (Repräsentamen), Objekt (worauf es verweist) und Interpretant (wie es verstanden wird). In der Biosemiotik: Semiose läuft in jedem lebenden System ab — jede Zelle vollzieht Semiose wenn sie ein Signal interpretiert und darauf reagiert. Leben *ist* Semiose.
→ [[biosemiotik]] | [[__sandbox__]]

**Semipermeable Membran**
Zellmembran die selektiv durchlässig ist — lässt bestimmte Moleküle passieren, andere nicht. Symbol für die Grenze zwischen Organismus und Umwelt. Maschinen haben keine solche Membran — sie tauschen keine Stoffe, haben kein Milieu, keine selektive Öffnung zur Welt.
→ [[semipermeable_membran]] | [[__sandbox__]]

**Slow-Wave-Sleep (SWS) / N3**
Tiefschlafphase mit langsamen Delta-Wellen. Zuständig für körperliche Regeneration, Immunsystem, Wachstumshormon-Ausschüttung und Gehirnreinigung. Dominiert die erste Nachthälfte.
→ [[schlaf]] | [[immunsystem]]

---

## T

**Terpene**
Aromatische Kohlenwasserstoffverbindungen die von Pflanzen synthetisiert werden — strukturchemische Grundlage der meisten ätherischen Öle. Klassifiziert nach Kohlenstoffeinheiten: Monoterpene (C₁₀, z.B. Limonene in Zitrus, Linalool in Bergamot/Rosewood), Sesquiterpene (C₁₅, z.B. Patchoulol, Cedrol, Khusimol in Vetiver). Volatile Monoterpene bilden Top Notes, halbflüchtige Sesquiterpene bilden Base Notes. Terpene sind Pflanzen-Kommunikationsmoleküle — Duftstoffe die als Signal zwischen Organismen wirken, bevor sie als Parfüm wirken.
→ [[scentlist]] | [[luft]] | [[biosemiotik]] | [[feuer]]

**Tierkreis** *(Zodiak)*
Die zwölf Sternzeichen als kosmologisches Kartierungssystem: Einteilung der Ekliptik in 30°-Abschnitte, jeweils einem astronomischen Sternbild zugeordnet. In der olfaktorischen Alchemie: das Tierkreissystem als Resonanzstruktur — jedes Zeichen trägt ein Element ([[feuer]], [[erde]], [[luft]], [[wasser]]), eine Modalität (Kardinal · Fix · Mutable) und eine Qualität die sich in Duftprofilen spiegelt. Kein astrologisches Glaubenssystem, sondern ein semantisches Netz aus Verbindungen und Entsprechungen das die Kompositionspraxis strukturiert.
→ [[cosmicalchemys]] | [[scentlist]] | [[feuer]] | [[erde]] | [[luft]] | [[wasser]]

**Toleranzentwicklung** *(CB1-Downregulation)*
Bei regelmäßiger Stimulation reduziert das Gehirn die Anzahl aktiver Rezeptoren — es braucht mehr Reiz für dieselbe Wirkung. Im ECS: weniger CB1-Rezeptoren → ohne THC funktioniert das System unter Baseline. Medienkünstlerisch: Systeme die sich selbst gegen Überstimulation schützen — und dabei abstumpfen.
→ [[thc]] | [[neuronentypen_verbindungen]]

**Turing Land vs. Duchamp Land**
Zwei polare Denkweisen über Intelligenz und Bedeutung. Turing: Intelligenz ist Funktion — wenn es sich wie Intelligenz verhält, ist es Intelligenz. Duchamp: Bedeutung entsteht durch Kontext, nicht Funktion — ein Urinal im Museum ist Kunst. KI-Kunst bewegt sich zwischen diesen Polen.
→ [[turing_land_duchamp_land]] | [[__sandbox__]] | [[ai_ml_grundlagen]]

---

## U

**Umwelt** *(Jakob von Uexküll)*
Jedes Lebewesen konstruiert seine eigene Zeichenwelt aus der Umgebung — die *Umwelt* ist nicht die objektive Welt, sondern die artspezifische Wahrnehmungs- und Wirkungswelt. Eine Zecke lebt in einer anderen Umwelt als ein Mensch, auch wenn sie denselben Raum bewohnen: sie nimmt nur Wärme, Butyrsäure und Haare wahr. Grundkonzept der Biosemiotik. In der Medienkunst: Interfaces erzeugen Umwelten — welche Welt baut das System für seinen Nutzer?
→ [[biosemiotik]] | [[semipermeable_membran]] | [[__sandbox__]]

---

## V

**Verantwortungsnetzwerk**
Konzept aus der Technikethik: Verantwortung nicht als Eigenschaft eines einzelnen Akteurs, sondern als verteilte Struktur im Gefüge von Mensch, Algorithmus, Institution und Infrastruktur. Wenn niemand allein verantwortlich ist — wer ist es dann?
→ [[verantwortungsnetzwerk]] | [[__sandbox__]] | [[ai_ml_grundlagen]]

---

## Z

**Zirkadianer Rhythmus**
Innere biologische Uhr mit ~24h-Zyklus, gesteuert durch den Suprachiasmatischen Nucleus (SCN) im Hypothalamus. Synchronisiert durch Licht, Temperatur, Nahrung. Reguliert Melatonin/Cortisol-Kurve. Gestört durch blaues Licht, Schichtarbeit, Cannabis, Jetlag.
→ [[zirkadianer_rhythmus]] | [[melatonin]] | [[cortisol]] | [[schlaf]]

**Zoosemiotik**
Zeichenprozesse in der Tierwelt — Kommunikation durch Laut, Geste, Farbe, Duft, Tanz (Bienentanz als Kartografie). Begründet von Thomas Sebeok. Zoosemiotik erweitert den Zeichenbegriff weit über menschliche Sprache hinaus: Signale ohne Syntax, Bedeutung ohne Grammatik. In der Medienkunst: nicht-menschliche Kommunikationssysteme als ästhetisches Modell und Referenz.
→ [[biosemiotik]] | [[semiose]] | [[__sandbox__]]

**Zytokine**
Botenstoffe des Immunsystems mit bidirektionaler Verbindung zum Schlaf: Tiefschlaf fördert Zytokin-Ausschüttung (Immunreparatur); Zytokine fördern bei Entzündung wiederum Schlaf — erklärt warum man bei Krankheit mehr schläft.
→ [[zytokine]] | [[immunsystem]] | [[schlaf]]

---

---

*Neue Begriffe für das Glossar hier notieren — werden beim nächsten `sortier das Glossar` alphabetisch einsortiert.*

```
Interoception
Affective Labeling
[Autophagie](app://obsidian.md/autophagie)
Marcel DUchamp
Aalan turing
```

---

*Neue Begriffe für neue Files hier notieren — werden beim nächsten `erstell die neuen files` als vollständige Dokumente angelegt.*

```
Social Media als Emotional - granularitätsfeindliches System — Like-Button für Freude, Überraschung, Stolz, Rührung, Bewunderung.
Marcel DUchamp
Aalan turing
```
