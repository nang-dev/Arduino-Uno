// sound travels 34200 per second
//serial means one after another

long duration;
long distance;
long cm;
int echoPin=2;
int trigPin=4;
void setup ()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); //9600 = baud rate
}
void loop()
{
  distance = getDistance();
  if(distance>30 || distance == 0)
 {
    Serial.println("Too far! Move Forward!");
 }
  
if (distance < 15) 
{
  Serial.println("Too close!");
}   
}
    long getDistance()
    {
   digitalWrite(trigPin, LOW);
 delayMicroseconds(5);
 digitalWrite (trigPin, HIGH);
 delayMicroseconds(5);
 //reset the trigger pin
 digitalWrite (trigPin,LOW);
 //store the microseconds
 duration = pulseIn(echoPin, HIGH);
 //27 microseconds per cm travelled, and it travels to and fro
 cm = duration/54;
 Serial.println (cm);
  delay (100);
 return cm;
    }
