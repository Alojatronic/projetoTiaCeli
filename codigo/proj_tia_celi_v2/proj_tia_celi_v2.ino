
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
#include <Servo.h>

//Define os pinos para o trigger e echo
#define pino_trigger 11
#define pino_echo 10
#define pin_servo 9


//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
Servo myservo;  // Cria um objeto baseado na biblioteca Servo
int angulo_abre = 50;
int angulo_fecha = 80;
int tempo_aberto = 5000;
int tempo_prox_gato = 500;
int dist_gato = 15;
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  myservo.attach(pin_servo);  // Diz que o objeto "myservo" está ligado ao pino 9

}
 
void loop(){
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);

  if (cmMsec<dist_gato and cmMsec != 0){
    Serial.println("Gatoooooooo");
    myservo.write(angulo_abre);
    delay(tempo_aberto);
    myservo.write(angulo_fecha);    
    }
   delay(tempo_prox_gato);
}
