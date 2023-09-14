// Motores
int IN1 = 4 ;
int IN2 = 5 ;
int IN3 = 6 ;
int IN4 = 7 ;
int distancia = 0;

//echo - 10, trigger - 11
void  setup () {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin( 9600 );

}
void  loop () {
  distanciaSensor();
 
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void distanciaSensor()
{
  Serial.println(0.01723 * readUltrasonicDistance(8, 9));
  double distanciaDireita = 0.01723 * readUltrasonicDistance(8, 9);
  double distanciaEsquerda = 0.01723 * readUltrasonicDistance(11, 10);
  if (distanciaDireita <= 15 && distanciaEsquerda > 15) {
    viraParar();
    delay(1000);
    re();
    delay(250);
    viraParar();
    delay(1000);
    viraDireita();
    delay(900);
  } else if(distanciaDireita > 15 && distanciaEsquerda <= 15){
    
    viraParar();
    delay(1000);
    re();
    delay(250);
    viraParar();
    delay(1000);
    viraEsquerda();
    delay(900);
    
    } else {
    frente();
  }
  delay(10); // Delay a little bit to improve simulation performance
}


void frente(){
  //Roda direita
  digitalWrite (IN1, 1);
  digitalWrite (IN2, 0);
  //Roda Esquerda
  digitalWrite (IN3, 1);
  digitalWrite (IN4, 0);
}
void re(){
  //Roda direita
  digitalWrite (IN1, 0);
  digitalWrite (IN2, 1);
  //Roda Esquerda
  digitalWrite (IN3, 0);
  digitalWrite (IN4, 1);
}
void viraDireita(){
  //Roda direita
  digitalWrite (IN1, 1);
  digitalWrite (IN2, 0 );
  //Roda Esquerda
  digitalWrite (IN3, 0);
  digitalWrite (IN4, 1);
}
  
void viraEsquerda(){
  //Roda direita
  digitalWrite (IN1, 0);
  digitalWrite (IN2, 1);
  //Roda Esquerda
  digitalWrite (IN3, 1);
  digitalWrite (IN4, 0);
}
  
void viraParar(){
  //Roda direita
  digitalWrite (IN1, 0);
  digitalWrite (IN2, 0 );
  //Roda Esquerda
  digitalWrite (IN3, 0);
  digitalWrite (IN4, 0);
}
