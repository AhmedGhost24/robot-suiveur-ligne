/*******************************************************
 * Projet        : Robot Suiveur de Ligne avec Ultrason
 * Auteur        : Ahmed Jendoubi
 * Équipe projet : 
 *    - Ahmed Jendoubi
 *    - Ahmed Yassin Trabelsi
 *    - Yassin Ben Hassen
 *    - Arij Melliti
 *    - Alaa Ben Hamouda
 *    - Emna Soltani
 *    - Yassin Dorii
 * 
 * Compte GitHub  : https://github.com/AhmedGhost24
 * Code source    : https://github.com/AhmedGhost24/robot-suiveur-ligne
 * 
 * Description    : Robot autonome qui suit une ligne
 *                  noire et évite les obstacles grâce à 
 *                  un capteur à ultrasons (HC-SR04).
 *******************************************************/



 
const int CI_L = 6, CI_M = 4, CI_R = 2; // Capteurs infrarouges : gauche (CI_L), milieu (CI_M), droite (CI_R)
const int RF = 7, RB = 9, LB = 10, LF = 11; // Broches pour les deux moteurs : RF et RB pour le moteur droit, LF et LB pour le moteur gauche (Forward = avant, Backward = arrière)
const int trig = 13, echo = 12; // Broches pour le capteur à ultrasons : trig (émission), echo (réception)

const int vitesse_L_Pin = 3;  // Broche PWM pour contrôler la vitesse du moteur gauche
const int vitesse_R_Pin = 5;  // Broche PWM pour contrôler la vitesse du moteur droit

int vitesse_L = 50; // Vitesse initiale du moteur gauche (valeur entre 0 et 255)
int vitesse_R = 50; // Vitesse initiale du moteur droit (valeur entre 0 et 255)

enum direction_AA{ Forward, Backward};
enum direction_LR{ Right, Left, All};


void Moteur_controller(direction_AA _AA,direction_LR _LR); // Fonction pour contrôler les moteurs : définit leur direction (avant/arrière) et leur mouvement (gauche/droite)
void FollowLine();  // Fonction pour suivre une ligne noire ou blanche à l’aide des capteurs infrarouges
void Moteur_stop(); // Fonction pour arrêter tous les moteurs du robot
void Test_Moteurs();  // Fonction pour tester individuellement les moteurs gauche et droit
void Moteur_Move(); // Fonction pour faire avancer le robot tout droit
int mesurerDistanceCM();  // Fonction pour mesurer la distance (en centimètres) à l’aide du capteur à ultrasons


void setup()
{
  // les capteurs infrarouge 
  pinMode(CI_L,INPUT);
  pinMode(CI_M,INPUT);
  pinMode(CI_R,INPUT);

  // le capteur ultrason
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  // les moteurs
  pinMode(RF,OUTPUT);
  pinMode(RF,OUTPUT);
  pinMode(RB,OUTPUT);
  pinMode(LF,OUTPUT);
  pinMode(LB,OUTPUT);
}


void loop()
{
  int distance = mesurerDistanceCM();
  if (distance > 10)
    FollowLine();
  else
    Moteur_stop();
}

void Moteur_controller(direction_AA _AA, direction_LR _LR) {


  int baseSpeed = 75; 
  int turnOffset = 35;

  switch (_LR) {
    case Right:
      vitesse_L = baseSpeed + turnOffset;
      vitesse_R = baseSpeed - turnOffset;
      break;

    case Left:
      vitesse_L = baseSpeed - turnOffset;
      vitesse_R = baseSpeed + turnOffset;
      break;

    case All: 
      vitesse_L = baseSpeed;
      vitesse_R = baseSpeed;
      break;

    default:
      vitesse_L = 0;
      vitesse_R = 0;
      break;
  }

  analogWrite(vitesse_L_Pin, vitesse_L);
  analogWrite(vitesse_R_Pin, vitesse_R);

  switch (_AA) {
    case Forward:
      digitalWrite(RB, LOW);
      digitalWrite(LB, LOW);
      digitalWrite(RF, HIGH);
      digitalWrite(LF, HIGH);
      break;

    case Backward:
      digitalWrite(RB, HIGH);
      digitalWrite(LB, HIGH);
      digitalWrite(RF, LOW);
      digitalWrite(LF, LOW);
      break;

    default: 
      digitalWrite(RB, LOW);
      digitalWrite(LB, LOW);
      digitalWrite(RF, LOW);
      digitalWrite(LF, LOW);
      break;
  }
}




void Moteur_stop(){
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(RF, LOW);
  digitalWrite(LF, LOW);
}

void Moteur_Move(){
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(RF, HIGH);
  digitalWrite(LF, HIGH);
}


void FollowLine() {
if (!digitalRead(CI_L) && digitalRead(CI_M) && !digitalRead(CI_R)) {
  Moteur_controller(Forward, All);
}
else if ((digitalRead(CI_L) && digitalRead(CI_M) && !digitalRead(CI_R)) ||
         (digitalRead(CI_L) && !digitalRead(CI_M) && !digitalRead(CI_R))) {
  Moteur_controller(Forward, Left);
}
else if ((!digitalRead(CI_L) && digitalRead(CI_M) && digitalRead(CI_R)) ||
         (!digitalRead(CI_L) && !digitalRead(CI_M) && digitalRead(CI_R))) {
  Moteur_controller(Forward, Right);
}
else {
  Moteur_stop();
}

/*
  | CI_L | CI_M | CI_R | Explication                            | Mouvement                            |
  |------|------|------|----------------------------------------|--------------------------------------|
  |  1   |  0   |  1   | Ligne centrée                          | Avancer tout droit (All)             |
  |  1   |  0   |  0   | Ligne légèrement à droite              | Tourner un peu à gauche              |
  |  1   |  1   |  0   | Ligne fortement à droite               | Tourner fort à gauche                |
  |  0   |  0   |  1   | Ligne légèrement à gauche              | Tourner un peu à droite              |
  |  0   |  1   |  1   | Ligne fortement à gauche               | Tourner fort à droite                |
  |     Autres cas     | Ligne non détectée                     | Arrêt (Moteur_stop)                  |
*/
}

void Test_Moteurs(){
  Moteur_stop();

  digitalWrite(RF, HIGH);
  digitalWrite(RF, LOW);
  delay(1000);

  digitalWrite(RB, HIGH);
  digitalWrite(RB, LOW);
  delay(1000);

  digitalWrite(LF, HIGH);
  digitalWrite(LF, LOW);
  delay(1000);
  
  digitalWrite(LB, HIGH);
  digitalWrite(LB, LOW);
  delay(1000);

  digitalWrite(RF, HIGH);
  digitalWrite(LF, HIGH);
  digitalWrite(RF, LOW);
  digitalWrite(LF, LOW);
  delay(1000);

  digitalWrite(RB, HIGH);
  digitalWrite(LB, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LB, LOW);
  delay(1000);
}

// sonar.ping_cm() effectue les étapes suivantes :
// 1. Envoie une impulsion ultrasonique via le pin "trig" pendant 10 microsecondes
// 2. Attend que l'écho revienne via le pin "echo"
// 3. Mesure le temps de l'aller-retour de l'onde sonore en microsecondes
// 4. Calcule la distance en centimètres avec la formule suivante :
//      distance_cm = (durée_μs × 0.0343) / 2
//    → 0.0343 = vitesse du son en cm/μs (343 m/s)
//    → on divise par 2 car le son fait un aller-retour

int mesurerDistanceCM() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  long duree = pulseIn(echo, HIGH); // durée en microsecondes

  int distance = duree * 0.0343 / 2; // convertir en cm
  return distance;
}
