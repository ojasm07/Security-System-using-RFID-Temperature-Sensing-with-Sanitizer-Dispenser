const int temp_read = A0;
byte temp_cel;
float temp;
float vout;
void setup() 
{
 pinMode(temp_read, INPUT);
 Serial.begin(9600);
 
}

void loop() 
{
 vout = analogRead(temp_read);
 temp = (vout*500)/1024.00;
 temp_cel = map(temp, 25.0, 45.0, 0, 200);
 Serial.write(temp_cel);

}
