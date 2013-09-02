int lightRead = 0;
int ledPin = 11;
int ledPin2 = 10;
int ledPin3 = 5;
int ledPin4 = 3;
void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  Serial.begin(9600);
}
void loop()
{
  lightRead = analogRead(A0);
  Serial.println(lightRead);
  if(lightRead < 255)
  {
    int brightness = 255 - lightRead;
    analogWrite(ledPin, brightness);
    analogWrite(ledPin2, brightness);
    analogWrite(ledPin3, brightness);
    analogWrite(ledPin4, brightness);
  }

    
  else
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }

}
