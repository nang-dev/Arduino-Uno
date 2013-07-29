int brightness;

void setup()
{
  pinMode(9, OUTPUT);
}
void loop()
{
  for (brightness = 0; brightness <= 255; brightness ++)
{
  analogWrite(9,brightness);
  delay(10);
 }
  for (brightness = 255; brightness >= 0; brightness--)
{
  analogWrite(9,brightness);
  delay(10);
}
}
  
