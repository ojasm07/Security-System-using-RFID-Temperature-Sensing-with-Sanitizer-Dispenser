#include<LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, rf = 6, IR = 9, door = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte temp_cel = 0;
float temp;
bool rf_value, IR_value; 
void setup()
{
  Serial.begin(9600);
  pinMode(rf, INPUT);
  pinMode(IR, INPUT);
  pinMode(door, OUTPUT);
  lcd.begin(16, 2);
  delay(500);
  digitalWrite(door, LOW);
  lcd.setCursor(0, 0);
  lcd.print("----WELCOME----"); 
  lcd.setCursor(0, 1);
  lcd.print("---SCAN CARD---");
  delay(1500);
  lcd.clear();
  rf_value = digitalRead(rf);
  IR_value = digitalRead(IR);
  if (rf_value == 1)
  {
    lcd.setCursor(0,0);
    lcd.print("HI USER_BOT");
    lcd.setCursor(0,1);
    lcd.print("AUTHORISED");
    delay(1500);
    lcd.clear();
  }
  else if ( rf_value == 0 )
  {
    lcd.setCursor(0,0);
    lcd.print("UNAUTHORISED");
    delay(1500);
  }
}
void loop()
{
  rf_value = digitalRead(rf);
  IR_value = digitalRead(IR);
  if (rf_value == 1)
  {
    if ( Serial.available())
    {
      temp_cel = Serial.read();
    }
    temp = map(temp_cel, 0, 200, 25.0, 45.0);
    lcd.setCursor(0,0);
    lcd.print("Temperature:");
    lcd.setCursor(12,0);
    lcd.print(temp);
    lcd.setCursor(0,1); 
    if (temp <= 37.00)
    {
      lcd.setCursor(0, 1);
      lcd.print("----WELCOME----");
      if (IR_value == 1)
      {
        digitalWrite(door, HIGH);
        delay(10000);
      }
      
    }
    else
    {
      lcd.setCursor(0, 1);
      lcd.print("-----Alert!-----");
    }
    
  }
  
}
