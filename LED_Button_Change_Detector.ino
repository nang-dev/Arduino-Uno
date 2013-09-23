const int  buttonPin = 2;  
const int ledPin1 = 13;    
const int ledPin2 = 12;    
const int ledPin3 = 11;    
const int ledPin4 = 10;    
const int ledPin5 = 9;    

int buttonPushCounter = 0;  
int buttonState = 0;      
int lastButtonState = 0;  

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  Serial.begin(9600);
  Serial.println(" ");
  Serial.println("number of LED's on: 0 ");
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState)
  {
    if (buttonState == HIGH)
    {
      buttonPushCounter++;
      if (buttonPushCounter > 5)
          {
            buttonPushCounter = 0; 
          }
      Serial.print("number of LED's on:  ");
      Serial.println(buttonPushCounter);
    } 
  }
  lastButtonState = buttonState;
      if (buttonPushCounter == 0)
      {
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin4, LOW);
        digitalWrite(ledPin5, LOW);
      }
      if (buttonPushCounter == 1) 
      {
        digitalWrite(ledPin1, HIGH);
      }
      if (buttonPushCounter == 2)
      {
        digitalWrite(ledPin2, HIGH);
    
      }
        if (buttonPushCounter == 3)
      {
        digitalWrite(ledPin3, HIGH);
      }
        if (buttonPushCounter == 4)
      {
        digitalWrite(ledPin4, HIGH);
      }
        if (buttonPushCounter == 5)
      {
        digitalWrite(ledPin5, HIGH);
      }
        if (buttonPushCounter > 5)
        {
            buttonPushCounter = 0; 
        }
}
