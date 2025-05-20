Algorithmes du robot suiveur de ligne avec capteur ultrason
============================================================

1. loop()
----------
Algorithme :
1. Mesurer la distance à l’aide du capteur à ultrasons.
2. Si la distance est supérieure à 10 cm :
   → Suivre la ligne (FollowLine).
3. Sinon :
   → Arrêter les moteurs (Moteur_stop).

2. Moteur_controller(direction_AA _AA, direction_LR _LR)
---------------------------------------------------------
Algorithme :
1. Définir la vitesse de base et l’offset de virage.
2. En fonction de la direction gauche/droite (_LR) :
   - Right   → vitesse_L = base + offset, vitesse_R = base - offset
   - Left    → vitesse_L = base - offset, vitesse_R = base + offset
   - All     → vitesse_L = base, vitesse_R = base
   - Default → vitesse_L = 0, vitesse_R = 0
3. Appliquer les vitesses sur les broches PWM.
4. En fonction de la direction avant/arrière (_AA) :
   - Forward   → activer RF et LF, désactiver RB et LB
   - Backward  → activer RB et LB, désactiver RF et LF
   - Default   → désactiver toutes les broches moteurs

3. Moteur_stop()
----------------
Algorithme :
1. Mettre toutes les broches de contrôle moteurs (RF, RB, LF, LB) à LOW pour arrêter le robot.

4. Moteur_Move()
-----------------
Algorithme :
1. Activer les broches RF et LF pour avancer tout droit.
2. Désactiver les broches RB et LB.

5. FollowLine()
----------------
Algorithme :
1. Lire les valeurs des capteurs infrarouges CI_L, CI_M, CI_R.
2. Vérifier les cas suivants :
   - CI_L = 0, CI_M = 1, CI_R = 0 → Avancer tout droit
   - CI_L = 1, CI_M = 1, CI_R = 0 ou CI_L = 1, CI_M = 0, CI_R = 0 → Tourner à gauche
   - CI_L = 0, CI_M = 1, CI_R = 1 ou CI_L = 0, CI_M = 0, CI_R = 1 → Tourner à droite
   - Tout autre cas → Arrêter les moteurs

6. Test_Moteurs()
------------------
Algorithme :
1. Arrêter tous les moteurs.
2. Tester chaque broche individuellement avec délai :
   - RF, puis RB, puis LF, puis LB
3. Tester les deux moteurs en marche avant
4. Tester les deux moteurs en marche arrière

7. mesurerDistanceCM()
------------------------
Algorithme :
1. Envoyer une impulsion LOW sur trig pendant 2 microsecondes.
2. Envoyer une impulsion HIGH sur trig pendant 10 microsecondes.
3. Revenir à LOW.
4. Lire la durée du retour d’écho sur la broche echo.
5. Calculer la distance avec la formule :
   distance = (durée × 0.0343) / 2
6. Retourner la distance.
