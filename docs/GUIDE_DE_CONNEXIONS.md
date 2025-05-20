📌 Projet : Robot suiveur de ligne avec évitement d'obstacles (capteur ultrason)
✍️ Auteur : Ahmed Jendoubi  
🔗 GitHub : https://github.com/AhmedGhost24  

======================================
🔧 Composants nécessaires (BOM)
======================================

- 1x Carte Arduino Uno (ou compatible)
- 2x Moteurs DC avec module de contrôle (L298N ou pont en H)
- 1x Capteur suiveur de ligne à 3 capteurs IR (gauche, milieu, droite)
- 1x Capteur ultrason HC-SR04
- Câbles de connexion (jumper wires)
- Alimentation externe (batterie 7.4V à 12V)

======================================
🔌 Connexions (entre Arduino et modules)
======================================

📍 Capteur infrarouge (suiveur de ligne)
----------------------------------------
- Capteur gauche (CI_L)   → D6
- Capteur milieu (CI_M)   → D4
- Capteur droit (CI_R)    → D2

📍 Capteur ultrason (HC-SR04)
------------------------------
- Trig (émission)         → D13
- Echo (réception)        → D12

📍 Moteurs DC (via pont en H)
------------------------------
🛞 Moteur droit
- Avant (RF)              → D7
- Arrière (RB)            → D9
- Vitesse PWM             → D5

🛞 Moteur gauche
- Avant (LF)              → D11
- Arrière (LB)            → D10
- Vitesse PWM             → D3

📍 Alimentation
------------------------------
- Arduino : via USB ou VIN (avec batterie)
- Pont en H : connecter GND commun + alimentation moteur (7.4V à 12V)
- Attention : GND de tous les modules doit être connecté ensemble.

======================================
⚠️ Remarques importantes
======================================
- Vérifiez que toutes les masses (GND) sont bien communes.
- Les moteurs DC doivent être compatibles avec le module utilisé (L298N ou autre).
- Si vous utilisez un L298N :
  - ENA = D3 (PWM moteur gauche)
  - ENB = D5 (PWM moteur droit)

======================================
▶️ Fonctionnement du robot
======================================
1. Démarrage : les capteurs IR suivent une ligne noire.
2. Si un obstacle est détecté à moins de 10 cm via l’ultrason, le robot s'arrête.

======================================
📎 Lien vers le code :
======================================
> À compléter avec le lien GitHub ou fichier `.ino`

