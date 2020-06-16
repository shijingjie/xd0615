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
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(i, LOW);
    digitalWrite(i+1, LOW);
    delay(500); // Wait for 500 millisecond(s)
  }//两个两个地亮，如0、1亮，2、3亮、4、5亮以此类推
  for(i=0;i<=5;i++)
  {
    digitalWrite(i, HIGH);
    digitalWrite(i+2, HIGH);
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(i, LOW);
    digitalWrite(i+2, LOW);
    delay(500); // Wait for 500 millisecond(s)
  }//交替着亮，如0、2亮，1、3亮、2、4亮以此类推
}
