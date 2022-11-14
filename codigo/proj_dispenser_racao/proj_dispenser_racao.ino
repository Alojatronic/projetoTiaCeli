
// Carregando as bibliotecas
#include <Ultrasonic.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// Configurando a pinagem
// Sensor ultrassônico 
#define pino_trigger 8
#define pino_echo 9
// Display LCD
#define pin_RS 12
#define pin_Enable 11
#define pin_D4 5
#define pin_D5 4
#define pin_D6 3
#define pin_D7 2
// Servo motor
#define SERVO 52 // Porta Digital 6 PWM

// Iniciando os objetos
Ultrasonic ultrasonic(pino_trigger, pino_echo);
LiquidCrystal lcd(pin_RS, pin_Enable, pin_D4, pin_D5, pin_D6, pin_D7);
Servo s; 

int cont = 0;     // contador 
int carga = 15;   // quantidade de carga disponível

void setup()
{
  lcd.begin(16, 2);   //Define o número de colunas e linhas do LCD
  s.attach(SERVO);
  s.write(0);
  Serial.begin(9600); // porta serial 
}
 
void loop()
{
  delay(2000);
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  if(cmMsec <= 5){
      cont = cont + 1;
      carga = carga - 1;
      
      //Limpa a tela
      lcd.clear();
      //Posiciona o cursor na coluna 3, linha 0;
      lcd.setCursor(0, 0);
      
      //Envia o texto entre aspas para o LCD
      lcd.print("Contagem:");
      lcd.print(cont);
      lcd.setCursor(0, 1);
      lcd.print("Carga restante");
      lcd.print(carga);
      s.write(90);
      delay(15000);
      s.write(0);     
  }
}
