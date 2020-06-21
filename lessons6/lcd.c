#include <LiquidCrystal.h>
String str="";
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()>0)
  {
    str+=char(Serial.read());
    delay(2);
  }
  if(str.length()>0)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(str);
  }
  delay(20);
  str="";
}
