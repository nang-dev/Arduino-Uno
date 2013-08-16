//feel free to edit patterns
//red = bottom to right  2-10
//black= left=11
//black= middle=12
//black= right=13
void setup()
{
 for( int i = 2; i <= 13; i++)
  {
   pinMode(i, OUTPUT); 
  } 
}


void loop()
{
  
  turnOff();
   for( int i = 11; i <= 13; i++)
  {
   digitalWrite(i, HIGH); 
   delay(2000);
    digitalWrite(i, LOW);
  } 
   for( int i = 13; i >= 11; i--)
  {
   digitalWrite(i, HIGH); 
   delay(2000); 
   digitalWrite(i, LOW);
  } 
  turnOn();
  delay(1000);
  for(int i=2; i < 11; i++)
  {
    if(i==2)
      {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        delay(1000);
       }
    if(i==5)
      {
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        delay(1000);
       }
     if(i==8)
      {
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        delay(1000);
  }
  }
  turnOff();
  turnOn();
  delay(1000);
  for (int i = 2; i < 11; i++)
  {
    digitalWrite(i, HIGH);
    delay(1000);
  }
  
  //---> crazyyy <--
 turnOff();
    for( int i = 11; i <= 13; i++)
  {
   digitalWrite(i, HIGH); 
   delay(50);
    digitalWrite(i, LOW);
  } 
   for( int i = 13; i >= 11; i--)
  {
   digitalWrite(i, HIGH); 
   delay(50); 
   digitalWrite(i, LOW);
  } 
  turnOn();
  delay(30);
  turnOff();
  delay(100);
    turnOn();
  delay(30);
  turnOff();
  delay(100);
    turnOn();
  delay(30);
  turnOff();
  delay(100);
  turnOn();
  delay(100);
  turnOn();
  delay(30);
  turnOff();
  delay(100);
    turnOn();
  delay(30);
  turnOff();
  delay(100);
    turnOn();
  delay(30);
  turnOff();
  delay(100);
  turnOn();
  turnOff();
  
  //---> end of crazy :( <--------


}
void turnOff()
{
  for( int i = 2; i <= 13; i++)
  {
   digitalWrite(i, LOW); 
  } 
}
void turnOn()
{
   for( int i = 11; i <= 13; i++)
  {
   digitalWrite(i, HIGH); 
  } 
}
