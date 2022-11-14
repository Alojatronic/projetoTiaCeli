#include <Servo.h>

// configurando a pinagem
#define pin_servo 7

Servo myservo; 
Ultrasonic ultrasonic(pin_TRIGGER, pin_ECHO);


void setup () {
    myservo.attach(pin_servo);  
}

void loop () {
  myservo.write(180); // Comando para mandar o servo para posição 0
  delay(500);         // Espera de 500 ms
  myservo.write(45);  // Comando para mandar o servo para posição 90
  delay(1000);  // Espera de 1000 ms
}
