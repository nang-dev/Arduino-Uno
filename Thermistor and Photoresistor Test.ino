int photoresistor=A1;
int thermistor =A0;
int sensorVoltage = 0;
int sensor2Voltage = 0;
int outputValue = 0;

void setup ()
{
  Serial.begin (9600);
}

void loop ()
{
  sensorVoltage = analogRead(photoresistor);
  outputValue = map(sensorVoltage, 0, 1023, 0, 255);  
  Serial.print("photoresistor= ");
  Serial.println (sensorVoltage);
  delay(1000);
    sensor2Voltage = analogRead(thermistor);
      outputValue = map(sensor2Voltage, 0, 1023, 0, 255);
    Serial.print ("thermistor= ");
  Serial.println (sensor2Voltage);
  delay (1000);
}
  
  
