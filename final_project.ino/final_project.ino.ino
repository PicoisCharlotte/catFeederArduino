
/**
 * Le TC4429 est un driver INVERSEUR. Le moteur tournera donc à l'inverse du rapport cyclique.
 * 255 => le moteur ne tourne pas
 * 0   => le moteur tourne à plein régime
 */

// Déclaration des variables globales
//pinMot
int E2               = 5;     // Broche de sortie du signal de contrôle moteur
int bp                   = 2;     // Broche d'entrée du bouton poussoir
int M2                 = 4;     // Rapport cyclique du signal de contrôle du moteur
unsigned long timeCycle = 10000; // Nombre de sec séparant 2 distributions, équivaut ici à 4h
int buttonState = 0;

unsigned long previousMillis = 0;

/**
 * Fonction d'initialisation
 */
void setup(void)
{
    pinMode(bp, INPUT_PULLUP);
    pinMode(M2, OUTPUT);
    Serial.begin(9600);      // open the serial port at 9600 bps:

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

  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= timeCycle) {
    
    
    actionMotorPeriod();
    Serial.println(currentMillis);
    Serial.println(previousMillis);

    previousMillis = millis();

    Serial.println("2");
    Serial.println(currentMillis);
    Serial.println(previousMillis);
    
  }
  if(buttonState == LOW) {
      actionMotor();
          previousMillis = millis();


    }
  
}

void actionMotorPeriod() {
  int i;
  
  for(i = 0; i <= 20; i++){
    actionMotor();
  }
}

/**
 * Fait tourner le moteur pendant 'duree' millisecondes
 */
void actionMotor()
{
  int value;
  for(value = 0; value <= 255; value += 5) {
      digitalWrite(M2, HIGH);
      analogWrite(E2, value);
      delay(30);

    }
     analogWrite(E2, 0);
}
