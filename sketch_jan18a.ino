int E2 = 5;
int M2 = 4;

int motorSpeed;


void setup() {
  pinMode(M2, OUTPUT);
}

void loop() {
  for(motorSpeed = 0; motorSpeed <= 255; motorSpeed += 5) {
    digitalWrite(M2, HIGH);
    //Temps où le moteur atteint la vitesse max
    delay(500);
    analogWrite(E2, motorSpeed);
   }
   delay(5000);
}
