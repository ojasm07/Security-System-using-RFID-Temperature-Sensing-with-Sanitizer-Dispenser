int IR = 12;
int motor = 3;
int LED = 2;
int z = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(motor, OUTPUT);

}

void loop()
{
   int z = digitalRead(IR);
   if (z == HIGH)
   {
     digitalWrite(motor, HIGH);
     digitalWrite(LED, HIGH);
     delay(2000);
    }
   else
   {
    digitalWrite(motor, LOW);
    digitalWrite(LED, LOW);
   }
}
