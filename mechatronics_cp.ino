#include<LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float temp = 37.01;

void setup()
{
  lcd.begin(16, 2);
  delay(500);
  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("----WELCOME----"); 
  lcd.setCursor(0, 1);
  lcd.print("---SCAN CARD---");

}
void loop()
{
  delay(1500);
  if ( temp <= 37.00)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperature:OK");
    lcd.setCursor(0, 1);
    lcd.print("----WELCOME----");
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperature:High");
    lcd.setCursor(0, 1);
    lcd.print("-----Alert!-----");
  }

}
