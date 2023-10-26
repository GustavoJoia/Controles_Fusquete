#include <SoftwareSerial.h>
#include <Wire.h>

// Bluetooth
SoftwareSerial BT(8,9); // RX, TX
String command = "";

// Motores
int IN1 = 4 ;
int IN2 = 5 ;
int IN3 = 6 ;
int IN4 = 7 ;

//echo - 10, trigger - 11
void  setup () {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
 

}
void loop()
{
  if (BT.available()){
    while(BT.available()){
     delay(15); 
     char c = BT.read(); 
     command = c; 
    }
    Serial.println(command);
    if(command=="F"){
      frente();
    }else if(command=="S"){
      viraParar();
    }else if(command=="B"){
      re();
    }else if(command=="L"){
      viraEsquerda();
    }else if(command=="R"){
      viraDireita();
    }else if(command=="X"){
//     parar(); 
    }else if(command=="x"){
//     parar(); 
    }else{
      viraParar();
    }
    command = ""; 
  }
}


void frente(){
  //Roda direita
  digitalWrite (IN1, 0);
  digitalWrite (IN2, 1);
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
