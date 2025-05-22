# 🤖 Robot Suiveur de Ligne avec Capteur Ultrason

Ce projet Arduino met en œuvre un robot autonome capable de suivre une ligne noire à l’aide de capteurs infrarouges tout en évitant les obstacles grâce à un capteur à ultrasons.

---

## 👨‍💻 Développé par
- **Auteur** : [Ahmed Jendoubi](https://www.instagram.com/volk._.00011000/)
- **GitHub** : [Ahmed Jendoubi](https://github.com/AhmedGhost24)
- **Code source** : [Code source](https://github.com/AhmedGhost24/robot-suiveur-ligne)
- **Équipe projet** : 
      - Ahmed Jendoubi
      - Ahmed Yassin Trabelsi
      - Yassin Ben Hassen
      - Arij Melliti
      - Alaa Ben Hamouda
      - Emna Soltani
      - Yassin Dorii

---

## 📌 Description

Le robot utilise :
- **Trois capteurs infrarouges** pour détecter la position de la ligne (gauche, milieu, droite).
- **Un capteur à ultrasons** (HC-SR04) pour mesurer la distance devant le robot.
- **Deux moteurs DC** contrôlés par des broches directionnelles et PWM pour ajuster la vitesse et la direction.

Lorsque la distance devant le robot est supérieure à 10 cm, il suit la ligne. Si un obstacle est détecté à moins de 10 cm, il s'arrête automatiquement.

---

## ⚙️ Matériel utilisé

- Carte Arduino (Uno ou compatible)
- 3 capteurs infrarouges (CI_L, CI_M, CI_R)
- 1 capteur ultrason (trig, echo)
- 2 moteurs DC
- L298N ou pont en H similaire
- Fils de connexion, châssis, roues, alimentation

---

## 🧠 Fonctionnalités principales

- Suivi intelligent de ligne avec correction de trajectoire
- Détection d'obstacle en temps réel
- Contrôle différentiel de vitesse pour tourner en douceur
- Test individuel des moteurs

---

## 🛠️ Fonctions du programme

- `FollowLine()` : suit la ligne selon les valeurs des capteurs IR.
- `Moteur_controller()` : gère direction et vitesse des moteurs.
- `mesurerDistanceCM()` : mesure la distance avec le capteur ultrasonique.
- `Moteur_stop()` : arrête tous les moteurs.
- `Moteur_Move()` : avance en ligne droite.
- `Test_Moteurs()` : vérifie le bon fonctionnement des moteurs.

---

## 📂 Structure du code

```c
loop()                         → Boucle principale
FollowLine()                   → Suivi de ligne
Moteur_controller()            → Contrôle des moteurs (direction/vitesse)
mesurerDistanceCM()            → Mesure de distance avec HC-SR04
Moteur_stop(), Moteur_Move()   → Contrôles basiques de mouvement
Test_Moteurs()                 → Auto-test moteur

## Installation
1. Clonez ce projet sur votre machine
2. Ouvrez le fichier `robot.ino` dans l'IDE Arduino
3. Téléchargez le code sur votre Arduino
4. Connectez les composants comme indiqué dans le schéma
5. Lancez le robot!

## Licence
Ce projet est sous licence MIT - voir le fichier [LICENSE](LICENSE)
