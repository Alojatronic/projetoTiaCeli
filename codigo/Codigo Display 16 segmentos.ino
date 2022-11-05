#include <LiquidCrystal.h>;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

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
  lcd.print("PRECISAMOS");

  for (int col = 0; col < 50; col++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
}
