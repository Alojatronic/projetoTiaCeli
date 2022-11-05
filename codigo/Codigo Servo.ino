#include <Servo.h>
#include <HCSR04.h>
#include <Ultrasonic.h>
#define TRIGGER   11
#define ECHO      12
Servo myservo; 
Ultrasonic ultrasonic(TRIGGER, ECHO);
void setup () {
  //Inicializa a porta serial do Arduino com 9600 de baud rate
    Serial.begin(9600);  
    myservo.attach(7);  // Diz que o objeto "myservo" está ligado ao pino 9
}

void loop () {
  float distancia;
  long microsec = ultrasonic.timing();
  distancia = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("Distancia em cm: ");
  Serial.println(distancia);
        //if(distancia<=20){
       // myservo.write(0); // Comando para mandar o servo para posição 180
  //delay(500); // Espera de 500 ms
  myservo.write(180); // Comando para mandar o servo para posição 0
  //delay(500); // Espera de 500 ms
  myservo.write(45); // Comando para mandar o servo para posição 90
  delay(1000);  // Espera de 500 ms
       // }
    
    //Espera 1 segundo
    //delay(1000);
}
