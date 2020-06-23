#include<MsTimer2.h>
byte tick[10];
int i,pinInterrupt=2;
void onTimer()//循环计数函数
{
  if(i==10)
  {
    i=0;
  }
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,tick[i]&0x1);
  digitalWrite(3,(tick[i]>>1)&0x1);
  digitalWrite(4,(tick[i]>>2)&0x1);
  digitalWrite(5,(tick[i]>>3)&0x1);
  i++;
}
void onchange()//归零函数
{
  i=0;
}
void setup()
{
  for(i=0;i<10;i++)
  {
    tick[i]=i;
    tick[i]=tick[i]-'0';
  }//将数字转化成字节
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
  pinMode(pinInterrupt,INPUT);
  attachInterrupt(digitalPinToInterrupt(pinInterrupt),onchange,CHANGE);
  //按钮控制归零
  MsTimer2::set(1000,onTimer);
  MsTimer2::start();//每一秒增加1
}
void loop()
{
  
}
