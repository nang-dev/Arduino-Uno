//PRESS 78A To unlock
int row[] = {0, 0, 0, 0};
int column[] = {0, 0, 0, 0};
int rowPass[] = {1,0,1,0};
int colPass[] = {0,1,1,1};
int correct = 0;
int ledTrue=13;
int ledFalse=12;
boolean locked = false;
#include <Servo.h>
Servo greg;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  greg.attach(11);
  greg.write(0);
  for (int i= 2; i < 6; i++)
  {
    digitalWrite(i,LOW);
  }
  Serial.begin(9600);
}
void loop()
{
  ReadRows();
  ReadColumns();
  
  //58B# =01110111
 for (int i = 0; i< 4; i++)
 {
   if(row[i]==rowPass[i] && column[i]==colPass[i])
     {
        correct++;
      }
 }
   if(correct == 4)
   {
     if(locked == false)
      {
       digitalWrite(ledTrue, HIGH);
       greg.write(0);
       delay(50);
       digitalWrite(ledTrue, LOW);
       locked = true;

     }
     else
     {
       digitalWrite(ledTrue, HIGH);
       greg.write(180);
       delay(100);
       digitalWrite(ledTrue, LOW);
       locked = false;

     }
   }
   
    else
    {
      correct = 0;
      digitalWrite(ledFalse,HIGH);
      delay(50);
      digitalWrite(ledFalse, LOW);
    }
}




void ReadRows()
{
 //Make Them Into Inputs 

   for (int i= 2; i < 6; i++)
  {
    pinMode(i,INPUT);
    digitalWrite(i,LOW);
  }
  
  //Reading
  for (int i= 2; i < 6; i++)
  {
    Serial.print(digitalRead(i));    
    row[i - 2] = digitalRead(i);
  }
 
//Drain 
   for (int i= 2; i < 6; i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
  delay(100);
}
 void ReadColumns()
{
   //Make Them Into Inputs 

   for (int i= 6; i <= 9; i++)
  {
    pinMode(i,INPUT);
    digitalWrite(i, LOW);
  }
//Reading
  for (int i= 6; i <= 9; i++)
  {
    Serial.print(!digitalRead(i));
    column [i-6] = !digitalRead(i); 
  }
   Serial.println("");
 
//Drain 
   for (int i= 6; i <= 9; i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,HIGH);
  }
  delay(100);
} 

