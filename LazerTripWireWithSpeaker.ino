//10K Potentiometer
//8 ohm 4 watt speaker
int lightRead = 0;
int speaker=6;
int intruder=0;
void setup()
{
 Serial.begin(9600);
 pinMode(speaker, OUTPUT);

}

void loop()
{
  lightRead = analogRead(A0);
  Serial.println(lightRead);
  if(lightRead < 550 || intruder==1)
  {
    intruder=1;
    tone(speaker, 470*4/3, 400);
    delay(400);
    tone(speaker, 470, 400);
    delay(400);
  }
}
