double ForwardSpeed = 150.0;
double RotateSpeed = 150.0;
double BackwardSpeed = 150.0;
long duration;
long distance;
long cm;
int echoPin=2;
int trigPin=4; 
int ledGreen = 13;
int ledRed = 12;
#include <Servo.h> 
 
Servo LeftWheel;  // create servo object to control a servo 
Servo RightWheel;  // create servo object to control a servo 

// Note: a maximum of eight servo objects can be created 

int LWPin = 10; //set the pin number for your left servo-motors (just change the number if not pin 9)
int RWPin = 11; //right-wheel control pin
int sensorRead;



void setup() 
{ 
  LeftWheel.attach( LWPin );  //  Connects LeftWheel to the pin LWPin
  RightWheel.attach( RWPin );  // Connects another wheel to be controlled by the pin RWPin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode (ledRed, OUTPUT);
  Serial.begin(9600); //9600 = baud rate
} 
 
 
void loop() 
{ 
  sensorRead = analogRead(A0);
  Serial.println(sensorRead);
  distance = getDistance();
  if(distance>21 || distance == 0)
 {
   digitalWrite (ledGreen, HIGH);
    Serial.println("Too far! Move Forward!");
    Forward(1);
    digitalWrite (ledGreen, LOW);
 }
if (distance < 20) 
{
  digitalWrite (ledGreen, HIGH);
  Serial.println("Too close!");
  Backward (1);          
  RotateLeft(1);
  digitalWrite (ledGreen, LOW);
}  

if (sensorRead >55) 
{
  digitalWrite (ledRed, HIGH);
  Serial.println("IM STUCK!");
  Backward (3);
  RotateRight (2);
  digitalWrite (ledRed, LOW);
}

 delay(10);
}


void Forward(double seconds)
{
    double speed = ForwardSpeed;

     attachServos(); //in case we disconnected them

     //The CRS thinks it is always at 90 degrees
     //if you tell it to go to 180 degrees it will go really fast clock-wise
     //0 degrees really quickly counterclockwise
     // 95 really slowly clockwise
     
    double leftspeed = (-speed/100.0*90.0 + 90) ;
    double rightspeed = (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    
    LeftWheel.write( (int) leftspeed);             
    RightWheel.write((int) rightspeed); // Right wheel is backwards
 
   //delay wants an integer number of milliseconds, we turn seconds to milliseconds
   //then we turn the result into an int
   delay((int) (seconds*1000)); 
}



void Backward ( double seconds)
{
    double speed = BackwardSpeed; 

    attachServos(); //in case we disconnected them

    double leftspeed = (speed/100.0*90.0 + 90) ;
    double rightspeed = (-speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    
    LeftWheel.write( (int) leftspeed);             
    RightWheel.write((int) rightspeed);
    
    delay((int) (seconds*1000));
}



void RotateLeft (double seconds)
{
    double speed = RotateSpeed;

    attachServos(); //in case we disconnected them

    double leftspeed = (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    double rightspeed = (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    
    LeftWheel.write((int) leftspeed);             
    RightWheel.write((int) rightspeed);
    delay((int) (seconds*1000));
}

void RotateRight (double seconds)
{
    double speed = RotateSpeed;
    
    attachServos(); //in case we disconnected them
     
    double leftspeed =  (-speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    double rightspeed =  (-speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    
    LeftWheel.write((int) leftspeed);             
    RightWheel.write((int) rightspeed); 

    delay((int) (seconds*1000));
}


void Stop( double seconds)
{
  LeftWheel.detach();  //to stop the motors, we have the Arduino stop sending signals entirely
  RightWheel.detach();

  delay((int) (seconds*1000));
}


void attachServos()
{
   LeftWheel.attach(LWPin);
   RightWheel.attach(RWPin);
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
