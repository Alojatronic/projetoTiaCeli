
#include <Ultrasonic.h>
#define pino_trigger 8
#define pino_echo 9
Ultrasonic ultrasonic(pino_trigger, pino_echo);

//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int n = 0;
int carga = 15;

#include <Servo.h>
#define SERVO 52 // Porta Digital 6 PWM
Servo s; // Variável Servo

void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  s.attach(SERVO);
  s.write(0);
  Serial.begin(9600);

}
 
void loop()
{
  delay(2000);
  //Le as informacoes do sensor, em cm e pol
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  if(cmMsec <= 5){

      //Limpa a tela
      n = n + 1;
      carga = carga - 1;
      lcd.clear();
      //Posiciona o cursor na coluna 3, linha 0;
      lcd.setCursor(0, 0);
      //Envia o texto entre aspas para o LCD
      lcd.print("Ativacoes:");
      lcd.print(n);
      lcd.setCursor(0, 1);
      lcd.print("Carga restante");
      lcd.print(carga);
      s.write(90);
      delay(15000);
      s.write(0);
      
  }

}
