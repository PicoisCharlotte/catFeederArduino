
/**
 * Le TC4429 est un driver INVERSEUR. Le moteur tournera donc à l'inverse du rapport cyclique.
 * 255 => le moteur ne tourne pas
 * 0   => le moteur tourne à plein régime
 */

// Déclaration des variables globales
//pinMot
int E2               = 5;     // Broche de sortie du signal de contrôle moteur
int bp                   = 2;     // Broche d'entrée du bouton poussoir
//duty
int M2                 = 4;     // Rapport cyclique du signal de contrôle du moteur
int duree                = 7;     // Nombre de sec pendant lesquelles le moteur va tourner pour une distribution : à adapter selon la longueur du tube et la vitesse de rotation du moteur
unsigned long dureeCycle = 10; // Nombre de sec séparant 2 distributions, équivaut ici à 4h
int buttonState = 0;

/**
 * Fonction d'initialisation
 */
void setup(void)
{
    pinMode(bp, INPUT_PULLUP);
    pinMode(M2, OUTPUT);
  
    // L'interruption int.0 écoute la broche 2 de l'Arduino Uno
    // Déclenche une interruption lorsque le signal bp est à l'état BAS (bouton poussoir appuyé)
    //attachInterrupt(0, startMoteur, LOW);

    // Initialise la commande moteur
    //analogWrite(E2, 255);
}


/**
 * Boucle principale
 */
void loop(){
  buttonState = digitalRead(bp);

  if(buttonState == LOW) {
    actionnerMoteur();
    Serial.print(buttonState);
    Serial.print(" pouet              ");

  }
    // Attente jusqu'au prochain cycle de distribution (ici 4h)
    //delay(50);
    //attendre(dureeCycle);
    
}

/**
 * Fait tourner le moteur pendant 'duree' millisecondes
 */
void actionnerMoteur()
{
  int value;
  for(value = 0; value <= 255; value += 5) {
    Serial.print("               pouet2           ");
    Serial.println(value);
    digitalWrite(M2, HIGH);
    analogWrite(E2, value);
        delay(30);

    }
     analogWrite(E2, 0);
}

/**
 * Actionne le moteur et l'arrête si le bouton poussoir est relâché
 */
/*void startMoteur()
{
    analogWrite(pinMot, duty);

    // Si on arrête d'appuyer sur le bouton
    if (digitalRead(bp) == HIGH) {
        digitalWrite(pinMot, HIGH);
    }
}*/

/**
 * Attendre n secondes
 * @param unsigned long duree : nombre de secondes à attendre
 * @return void
 */
/*void attendre(int duree)
{
    int loops;
    int count = 30;
    int reste = (duree%count);

    loops = floor(duree/count);

    for (int i=0; i < loops; i++) {
       delay(count*1000);
    }

    delay(reste*1000);
}*/
