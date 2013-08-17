//RGB Led  Common Cathode
//10K potentiometer
int lightRead = 0;

void setup()
{
 Serial.begin(9600);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(11, OUTPUT);

}

void loop()
{
  lightRead = analogRead(A0);
  Serial.println(lightRead);
  if(lightRead < 550)
  {
    digitalWrite(9, HIGH);
    delay(100);
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(11, HIGH);
    delay(100);
    digitalWrite(11, LOW);
    delay(100);
    digitalWrite(10, LOW);
    delay(100);
    digitalWrite(9, LOW);
  delay(10);
  }
}
