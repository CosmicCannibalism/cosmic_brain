# Agent-System — stellar design und engineering

---

## Die Arbeit, wie sie heute ist

stellar gestaltet Interaktion für Systeme die Menschen in kritischen Momenten begleiten — im Auto, in der Fabrik, im Cockpit. Die Arbeit ist komplex: viele Zustände, viele Zielgruppen, viele Targets. Ein Interface für ein Fahrzeug-HMI hat nicht eine Ansicht — es hat hunderte.

Die eigentliche Herausforderung ist nicht das Entwerfen. Es ist die Übersetzung.

Ein Designer trifft eine Entscheidung in Figma. Diese Entscheidung muss von einem Entwickler interpretiert, in Code übersetzt, auf ein Embedded-Target portiert und gegen die CI geprüft werden. An jedem dieser Schritte kann etwas verloren gehen — Nuance, Timing, Absicht.

Das ist nicht ein Problem schlechter Arbeit. Es ist ein strukturelles Problem des Prozesses.

---

## Was sich gerade verändert

Tools werden besser. Das ist keine neue Beobachtung — Tools werden immer besser. Aber was gerade passiert ist qualitativ anders.

Bisher haben bessere Tools schnellere Ausführung ermöglicht. Ein besserer Grafikeditor. Eine schnellere Build-Pipeline. Mehr Rechenleistung auf dem Target.

Was sich jetzt verändert ist nicht die Geschwindigkeit der Ausführung — sondern **wer ausführt**.

Ein Werkzeug das Code versteht, Figma-Strukturen liest, Designentscheidungen in Komponenten übersetzt und dabei stellars Gestaltungssprache kennt, ist kein Tool mehr im klassischen Sinn. Es ist etwas dazwischen. Noch kein Kollege — aber auch kein Hammer mehr.

Die Frage ist nicht ob man das einsetzt. Die Frage ist: **wie denkt man darüber nach?**

---

## Eine andere Sprache für das Neue

Wer über KI-Tools spricht, denkt in Automatisierung. In Zeitersparnis. In Effizienz.

Das ist nicht falsch — aber es greift zu kurz.

Eine nützlichere Vorstellung: **Mitarbeiter, nicht Maschinen.**

Ein Mitarbeiter bekommt eine Einarbeitung. Er versteht den Kontext des Büros, die Erwartungen, die Qualitätsstandards. Er arbeitet selbstständig — aber er berichtet zurück. Er macht Fehler, bekommt Feedback, wird besser. Und er trägt Wissen das sich über Projekte hinweg aufbaut.

Ein Agent-System funktioniert genauso. Der Unterschied: man schult ihn mit Dokumenten statt mit Gesprächen. Man gibt ihm Aufträge in Textform. Und er vergisst nie, was man ihm beigebracht hat.

Das bedeutet: stellars Designauffassung, stellars Qualitätsstandards, stellars Art zu denken — können als Schulungsmaterial existieren. Maschinenlesbar. Dauerhaft. Anwendbar auf jeden Output.

Der nächste Schritt ist nicht ein einzelner besser geschulter Agent — es ist das koordinierte Zusammenspiel mehrerer. Ein Agent der Figma ausliest, gibt sein Ergebnis weiter an einen der Code generiert, der wiederum von einem dritten gegen die Principles geprüft wird. Wer entscheidet, wer was bekommt, in welcher Reihenfolge, mit welchen Abhängigkeiten — das ist **Orchestrierung**.

Orchestrierung kann manuell sein: man selbst verteilt die Aufträge, reviewt Zwischenergebnisse, gibt weiter. Oder sie kann automatisiert sein: ein übergeordneter Agent zerlegt eine Aufgabe selbst in Teilschritte, delegiert sie und synthetisiert das Ergebnis. In beiden Fällen verschiebt sich die Denkweise — nicht mehr in einzelnen Prompts, sondern in Workflows. Welche Teilaufgaben gibt es? Was kann parallel laufen? Was braucht das Ergebnis von was?

Das ist die eigentliche Lernkurve. Nicht die Technologie — das Denken in Systemen statt in Einzelaufträgen.

---

## Was das für den Designer bedeutet

Der Bruch zwischen Figma und Code war immer da. Design sieht anders aus als Implementierung — andere Timing-Charakteristik, andere Performance, andere Eigenheiten des Targets. Designer haben das oft erst im Review gesehen. Zu spät, um es ohne Aufwand zu korrigieren.

Mit einem Agent der Figma direkt ausliest und QML-Code generiert, der auf echtem Hardware läuft, **rückt die Realität näher an die Entstehung**.

Das ist ein Gewinn. Es ist aber auch eine Zumutung.

Weil es bedeutet: Figma muss vollständig sein. Alle States, alle Varianten, alle Edge Cases — bevor Code entsteht, nicht danach. Die Unschärfe die im Prozess immer Raum für Interpretation gelassen hat, verschwindet. Was nicht definiert ist, existiert nicht.

Das klingt nach Mehrarbeit. Es ist in Wirklichkeit eine Verschiebung: **von implizitem Wissen zu explizitem Wissen**. Was bisher im Kopf des Designers war und im Gespräch mit dem Entwickler ausgehandelt wurde, muss jetzt in der Spec stehen.

Wer das kann — wer systemisch denkt, wer Entscheidungen explizit macht — arbeitet mit dieser Verschiebung. Wer das nicht kann, wird schneller mit den Konsequenzen konfrontiert.

---

## Was das für den Entwickler bedeutet

Ein erheblicher Teil der Entwicklerarbeit bei HMI-Projekten ist Übersetzung: Token-Werte nachschlagen, States ableiten, Figma-Intentionen in Property-Bindings überführen. Das ist notwendig — aber es ist nicht die Ingenieursarbeit.

Die Ingenieursarbeit ist: Systemarchitektur. Performance auf Embedded-Targets. Plattform-Integration. Safety. Die wirklich schwierigen Interaction-Probleme, die keine generische Lösung haben.

Wenn der Übersetzungsanteil kleiner wird, bekommt die eigentliche Arbeit mehr Raum.

Das klingt angenehm. Es ist aber auch eine Verschiebung der Erwartung. Ein Entwickler der hauptsächlich übersetzt hat, wird nicht dadurch weniger beschäftigt dass das Werkzeug übersetzt — er wird an anderem gemessen. An Architekturentscheidungen. An Urteilsvermögen.

Das verändert, welche Fähigkeiten zählen.

---

## Die Skills die wichtiger werden

Auf beiden Seiten — Design und Entwicklung — verschiebt sich was gefragt ist.

**Für Designer:** nicht schneller skizzieren, sondern präziser spezifizieren. Nicht mehr Screens, sondern vollständigere Systeme. Das Handwerk bleibt — aber das Denken in Systemen, in Regeln, in Konsequenzen wird wichtiger.

**Für Entwickler:** nicht weniger Tiefe, sondern andere Tiefe. Weniger Übersetzung, mehr Architektur. Die Fähigkeit, einem Agent die richtigen Constraints zu geben — zu wissen, was man nicht delegieren sollte — ist keine triviale Fähigkeit.

**Für beide:** Feedback geben können. Einen schlechten Output präzise benennen — nicht nur „das stimmt nicht" sondern „das stimmt nicht weil". Das ist die Fähigkeit die darüber entscheidet, ob ein Agent besser wird oder nicht.

Und es gibt eine Rolle die gerade entsteht: jemand der das System pflegt. Der Schulungsmaterial schreibt. Der Regeln explizit macht. Der die Qualität der Agent-Outputs beobachtet und den Regelkreis schließt. **Agent Architect** ist ein möglicher Name — im Kern eine Mischung aus System-Denken und Redaktion.

---

## Neue Räume

Stellars Automotive-Kern steht unter Druck. Das ist keine Neuigkeit. Was weniger oft besprochen wird: die Fähigkeiten die stellar für Automotive aufgebaut hat, sind in anderen Branchen genauso gefragt — und dort weit weniger verbreitet.

Medizintechnik. Schienenfahrzeuge. Industrieautomation. Energiemanagement. Baumaschinen. Material Handling.

Alle haben dieselbe Grundstruktur: komplexe Systeme, kritische Kontexte, Nutzer die keine Fehler machen dürfen. Und alle haben ein massives Defizit an Interaction Design das diese Anforderungen wirklich ernst nimmt.

Material Handling ist kein fremdes Terrain — stellar hat hier bereits Expertise. Steuerungssysteme für Logistik und Lagertechnik, Bedienpanels für vollautomatisierte Fördersysteme: die Anforderungen sind vertraut. Was fehlt, ist nicht die Kompetenz — es ist die Kapazität, diese Expertise schneller auf neue Kunden und Systemarchitekturen zu übertragen.

Baumaschinen sind ein Schritt weiter, aber strukturell nah dran. Kabinen-HMI unter extremen Bedingungen: Staub, Vibration, grobe Handschuhe, direkte Sonneneinstrahlung. Die Nutzer sind Profis die auf ihre Maschine angewiesen sind und keine Toleranz für schlechte Bedienbarkeit haben. Europäische Hersteller wie Liebherr, Zeppelin/Cat und Wacker Neuson investieren zunehmend in moderne HMI — und suchen Partner die beides können: Design und technische Umsetzung auf embedded Targets.

Das Problem war bisher: in jede neue Branche einzusteigen bedeutet von vorne zu beginnen. Neue Regularien lernen. Neue Nutzergruppen verstehen. Neue Normen recherchieren.

Ein branchenspezifischer Agent ändert diese Kalkulation. Nicht weil er die Expertise ersetzt, sondern weil er sie komprimiert. Regulatorik, Nutzerprofile, Fehlermuster einer Branche als strukturiertes Wissen — abrufbar während der Designarbeit, nicht als vorgelagertes Recherche-Projekt. Nach dem ersten Projekt ist dieser Agent spezifischer. Nach dem zweiten noch mehr. Das akkumulierte Wissen bleibt im System — nicht nur im Kopf des Seniors der das Projekt gemacht hat.

---

## Hardware, Software und das Physische

Es gibt eine Dimension die in der Diskussion über digitale Interfaces oft fehlt: die Hand, die das Gerät bedient, berührt nicht nur einen Screen.

Gerade in den Branchen die stellar interessieren — Baumaschinen, Medizintechnik, Industrieautomation — ist die physische Eingabe oft genauso wichtig wie das Display dahinter. Ein Joystick im Baggerfahrerstand. Ein Drehregler am OP-Tisch. Ein taktiles Bedienelement an einer CNC-Maschine. Diese Elemente sind keine Peripherie — sie sind Teil des Interaction Designs.

Stellars Kompetenz als Büro das sowohl gestalterisch als auch technisch arbeitet, macht genau diesen Übergang möglich: von der Gestaltung des Eingabeelements über die Firmware-Anbindung bis zur Darstellung auf dem Display. Hardware und Software nicht als getrennte Gewerke, sondern als ein zusammenhängendes System.

Das ist Physical Computing — nicht als Bastelprojekt, sondern als professionelle Disziplin. Prototypen mit echten Encodern, Drucktasten und Haptik-Feedback die früh zeigen wie sich eine Interaktion *anfühlt*, nicht nur wie sie aussieht. Materialwahl, Kraftpunkt, Rückmeldung — Entscheidungen die das Agent-System nicht trifft, aber für die es Kontext liefern kann: Normen für Bedienkräfte, ergonomische Richtwerte, bekannte Fehlermuster aus der Nutzungsforschung.

Das Physische macht die Arbeit komplexer. Es macht sie aber auch konkreter — und für Auftraggeber sichtbarer.

---

## Was das von stellar verlangt

Ein Agent-System funktioniert nicht ohne Investition. Nicht in Software — in Klarheit.

Stellars Gestaltungsauffassung muss explizit gemacht werden. Nicht als PDF-Guideline, sondern als Regelwerk das ein Agent anwenden kann. Was ist stellars Qualitätsstandard, konkret? Was ist der Unterschied zwischen einem guten und einem schlechten Output, in Worten die überprüfbar sind?

Das ist keine kleine Aufgabe. Es ist im Grunde die Aufgabe, das implizite Wissen des Büros — was in 30 Jahren Projekterfahrung akkumuliert wurde — in eine Form zu bringen die übertragbar ist.

Der Gewinn: dieses Wissen ist dann nicht mehr an einzelne Personen gebunden. Es skaliert. Es gilt für Junior und Senior. Es gilt für das erste MedTech-Projekt und das zehnte.

Und es verändert, was stellar gegenüber neuen Kunden zeigen kann. Neue Kunden kaufen selten ein Konzept — sie kaufen das Vertrauen, dass jemand ihr Problem wirklich versteht und umsetzen kann. Mit einem Domain-Agent der die Branche kennt, einer bestehenden Komponentenbibliothek und einer Pipeline die aus Figma direkt lauffähigen Code erzeugt, ist der erste Eindruck kein Mock mehr — sondern ein Stück echtes Produkt. Was heute Wochen braucht, komprimiert sich. Kein Bruch zwischen Demo und Realität im Projekt.

---

## Das Bild

Die Art wie Büros wie stellar arbeiten wird sich in den nächsten Jahren verändern. Nicht weil KI alles übernimmt — sondern weil sich verschiebt, was menschliche Arbeit leistet und was Werkzeuge leisten.

Die Frage ist nicht, ob man sich damit beschäftigt. Die Frage ist: **wann und wie**.

Wer früh anfängt, baut etwas auf. Wissen über das System. Schulungsmaterial das besser wird. Agents die stellars Sprache sprechen und nicht die eines generischen Modells. Das ist kein Vorteil der sich kaufen lässt — er entsteht durch Arbeit, durch Feedback, durch Zeit.

Wer später anfängt, beginnt von vorne.

---

## Was man nicht verdrängen sollte

Das alles klingt nach Gewinn. Es ist auch Gewinn. Aber ein System das man nicht versteht, dem man nicht misstraut, und das man nicht kontrollieren kann, ist kein Werkzeug — es ist eine Abhängigkeit.

### Wo gehen die Daten hin?

Wenn ein Agent eine Figma-Datei liest, einen Designentwurf analysiert, Kundenbriefings verarbeitet — dann landet dieser Inhalt irgendwo. Bei welchem Anbieter, auf welchem Server, in welchem Land.

Für stellar ist das keine abstrakte Frage. Automotive-Kunden haben NDAs. Medizintechnik-Daten haben Regulatorik. Interne Designentscheidungen sind IP.

Die meisten kommerziellen Sprachmodelle laufen auf Servern in den USA. Was genau mit den gesendeten Daten passiert, hängt von Nutzungsbedingungen ab die sich ändern. Das ist kein Argument dagegen — es ist ein Argument für Bewusstsein. Wer weiß was er sendet, kann entscheiden was er sendet.

Praktisch bedeutet das: Datenkategorien trennen. Was darf das Modell sehen? Was bleibt lokal? Eine klare Antwort auf diese Frage ist die Voraussetzung für verantwortungsvollen Einsatz — und in manchen Projekten die Voraussetzung für einen Einsatz überhaupt.

### Wie abhängig ist man?

Ein Agent-System das auf einem einzigen kommerziellen Anbieter basiert, ist exponiert. Preise ändern sich. APIs ändern sich. Was heute funktioniert, ist morgen möglicherweise teurer, anders, oder weg.

Das eigentliche Kapital ist nicht die API — es ist das Schulungsmaterial. Die Principles, die Instructions, die Prompt-Struktur. Wenn das sauber dokumentiert ist, lässt es sich auf ein anderes Modell portieren. Wenn es implizit ist, verliert man es.

Portabilität ist eine Designentscheidung, die man am Anfang trifft oder nachher schmerzhaft nachholt.

### Wie baut man ein unabhängiges System?

Unabhängigkeit ist kein binärer Zustand. Es gibt Grade.

Architektonische Unabhängigkeit bedeutet: die Logik — Regeln, Prompts, Strukturen — ist außerhalb des Modells dokumentiert und austauschbar. Wer das Modell wechselt, wechselt den Lieferanten, nicht das System.

Datensouveränität bedeutet: sensible Daten bleiben dort wo man die Kontrolle hat. Lokale Modelle wie Llama, Mistral oder Phi laufen auf eigener Hardware, senden nichts nach außen. Kleiner, langsamer, weniger fähig als die großen kommerziellen Modelle — aber für viele Aufgaben ausreichend, und ohne Datenschutzrisiko.

Eine sinnvolle Architektur:

```
Öffentliche Informationen, allgemeine Fragen
→  kommerzielles Modell

Projektspezifisches, Kundendaten, NDAs
→  lokales Modell auf eigenem Server

Schulungsmaterial, Principles Layer, Prompt-Struktur
→  eigenes Repository, versioniert, modellunabhängig
```

### Ein Argument gegenüber Kunden

Wer das alles ernst nimmt, hat gegenüber Kunden etwas zu sagen das über „wir passen auf" hinausgeht.

Gerade in den Branchen die stellar interessieren — Medizintechnik, Automotive, Rail — sind Kunden gewohnt, Prozesse zu auditieren. Qualitätsmanagementsysteme, Dokumentationspflichten, Nachweisbarkeit von Entscheidungen. Ein Dienstleister der auf die Frage „wie setzt ihr KI-Werkzeuge ein und was passiert mit unseren Daten?" eine strukturierte Antwort hat, ist ein anderer Gesprächspartner als einer der das Thema wegwischt.

Das ist kein Selbstzweck. Es ist ein Vertrauenssignal — und in manchen Projekten eine Voraussetzung für den Auftrag überhaupt. Ein Kunde der ein NDA-geschütztes Entwicklungsprojekt vergibt, will wissen ob seine Designentscheidungen auf einem externen Server landen. Wenn stellar das beantworten kann — mit konkreten Prozessen, nicht mit Beruhigungen — ist das ein Wettbewerbsvorteil der nichts mit Technologie zu tun hat. Sondern mit Haltung.
