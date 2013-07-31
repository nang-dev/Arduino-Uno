void setup ()
{
  for (int i = 2; i <=12; i++)
  {
  pinMode(i, OUTPUT);
  }
  pinMode(13, INPUT);
  
}

void loop ()
{
  for (int i = 2; i <= 12; i++)
  {
    digitalWrite(i, HIGH) ;
    delay(40);
    if (digitalRead(13)==HIGH)
    {
      break;
    }
    digitalWrite(i, LOW);
    
  }
}
//try to get all leds lit up
