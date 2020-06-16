void setup()
{
  for(i=0;i<=7;i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for(i=0;i<=6;i+=2)
  {
    digitalWrite(i, HIGH);
    digitalWrite(i+1, HIGH);
    delay(500); // Wait for 1000 millisecond(s)
    digitalWrite(i, LOW);
    digitalWrite(i+1, LOW);
    delay(500); // Wait for 1000 millisecond(s)
  }
  for(i=0;i<=5;i++)
  {
    digitalWrite(i, HIGH);
    digitalWrite(i+2, HIGH);
    delay(500); // Wait for 1000 millisecond(s)
    digitalWrite(i, LOW);
    digitalWrite(i+2, LOW);
    delay(500); // Wait for 1000 millisecond(s)
  }
}
