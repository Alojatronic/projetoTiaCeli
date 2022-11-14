#include <LiquidCrystal.h>;

// Configurando a pinagem
#define pin_RS 12
#define pin_Enable 11
#define pin_D4 5
#define pin_D5 4
#define pin_D6 3
#define pin_D7 2

// Configurando a biblioteca
LiquidCrystal lcd(pin_RS, pin_Enable, pin_D4, pin_D5, pin_D6, pin_D7);

void setup(){
  lcd.begin(16, 2);
  pinMode(6,OUTPUT); 
  analogWrite(6,50); ;
}

void loop()
{
  lcd.clear();
  lcd.setCursor(16,0);
  lcd.print("COLOQUE DINHEIROS HUMANO");
  lcd.setCursor(30,1);
  lcd.print("PRECISAMOS! Assinado: Miau");

  for (int col = 0; col < 50; col++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
}
