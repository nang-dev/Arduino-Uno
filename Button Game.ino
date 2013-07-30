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
    delay (35);
    if (digitalRead(13)==HIGH)
    {
     if(i==7)
     {
       for(int j=2; j<=12; j++)
        {
         digitalWrite(j,HIGH);
         delay(100);
        }
         for(int j=2; j<=12; j++)
        {
         digitalWrite(j,LOW);
         delay(100);
        }
     }
     else
     {
      break;
     }
    }
    digitalWrite(i,LOW);
  }
}
