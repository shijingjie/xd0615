void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}
int i;
byte income[4]={0};
void loop()
{
  if(Serial.available()>0)
  {
    digitalWrite(6,HIGH);
  	digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
  	digitalWrite(9,HIGH);   
 	digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    for(i=0;i<4;i++)
    {
      income[i]=Serial.read();
      income[i]=income[i]-'0';
      digitalWrite(i+8,LOW);//将8置低取消锁定
      digitalWrite(2,income[i]&0x1);
   	  digitalWrite(3,(income[i]>>1)&0x1);
      digitalWrite(4,(income[i]>>2)&0x1);
      digitalWrite(5,(income[i]>>3)&0x1);
      delay(10);
      digitalWrite(i+8,HIGH);//重新上锁进行下一个数字显示
    }
  }
}
