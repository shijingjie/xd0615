const int sensorPin = A0;    //光敏电阻器的引脚
const int ledPin = 9;        //LED灯的引脚

int sensorValue = 0;         //光敏电阻器的值
int sensorMin = 1023;        //光敏电阻器的最小值
int sensorMax = 0;           //光敏电阻器的最大值


void setup() {
  pinMode(13, OUTPUT);//定义13号引脚为输出引脚
  digitalWrite(13, HIGH);//将13号引脚初始化为高电压
  //同时将UNO板上的LED灯点亮用来指示

  while (millis() < 5000) {//在最初的五秒进行校准
    sensorValue = analogRead(sensorPin);//获取光敏电阻器的值

    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
      //若光敏电阻器的值大于最大值，则该值成为新的最大值
    }
    
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
      //若光敏电阻器的值小于最小值，则该值成为新的最小值
    }
  }

  digitalWrite(13, LOW);
  //校准结束后将13号引脚设为低电压，关闭UNO板上的LED灯
}

void loop() {
  sensorValue = analogRead(sensorPin);//读取光敏电阻器的值

  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
  //通过map()方法，将光敏电阻器的值从最小到最大的范围内，
  //映射到0~255范围内的某个数值

  sensorValue = constrain(sensorValue, 0, 255);
  //通过constrain()方法，将映射后的sensorValue
  //返回值限定在0~255之间

  analogWrite(ledPin, sensorValue);
  //将最终校准后的值设置给LED灯
  //从而实现LED灯的亮度随光敏电阻器的光线强弱变化
}	
