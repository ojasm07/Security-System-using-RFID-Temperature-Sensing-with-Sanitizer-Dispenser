
#define SS_PIN 4  //D2
#define RST_PIN 5 //D1
#define rf_pin 10

#include <SPI.h>
#include <MFRC522.h>

MFRC522 mfrc522(SS_PIN, RST_PIN);
int statuss = 0;
int out = 0;

const int temp_read = A0;
byte temp_cel;
float temp;
float vout;
int IR = 12;
int motor = 3;
int LED = 2;
int z = 0;

void setup() 
{
 pinMode(temp_read, INPUT);
 Serial.begin(9600);
 pinMode(IR, INPUT);
 pinMode(LED, OUTPUT);
 pinMode(motor, OUTPUT);

 SPI.begin();      // Initiate  SPI bus
 mfrc522.PCD_Init();   // Initiate MFRC522 RFID reader
}

void loop() 
{
 // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.println();
  Serial.print(" UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();
  if (content.substring(1) == "8E 39 32 50") //change UID of the card that you want to give access
  {
    Serial.println(" Access Granted ");
    Serial.println(" Welcome Mr.Circuit ");
    delay(1000);
    Serial.println(" Have FUN ");
    Serial.println();
    statuss = 1;
    digitalWrite(rf_pin, HIGH);
  }
  
  else   {
    Serial.println(" Access Denied ");
    delay(3000);
    digitalWrite(rf_pin,LOW);  
  }
  
 vout = analogRead(temp_read);
 temp = (vout*500)/1024.00;
 temp_cel = map(temp, 25.0, 45.0, 0, 200);
 Serial.write(temp_cel);
 delay(1500);
 int z = digitalRead(IR);
 if (z == HIGH)
 {
   digitalWrite(motor, HIGH);
   digitalWrite(LED, HIGH);
   delay(1000);
   digitalWrite(motor, LOW);
   digitalWrite(LED, LOW);
  }
 else
 {
  digitalWrite(motor, LOW);
  digitalWrite(LED, LOW);
 }

}
