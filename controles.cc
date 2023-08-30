// Motores
int IN1 = 4 ;
int IN2 = 5 ;
int IN3 = 6 ;
int IN4 = 7 ;
void  setup () {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin( 9600 );

}
void  loop () {

    frente()
    delay(2000)
    re()
    delay(2000)
 
}
void frente(){
  //Roda direita
  digitalWrite (IN1, 1);
  digitalWrite (IN2, 0 );
  //Roda Esquerda
  digitalWrite (IN3, 1);
  digitalWrite (IN4, 0);
}
void re(){
  //Roda direita
  digitalWrite (IN1, 0);
  digitalWrite (IN2, 1 );
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
  digitalWrite (IN4, 0);
}
  
void viraEsquerda(){
  //Roda direita
  digitalWrite (IN1, 0);
  digitalWrite (IN2, 0 );
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