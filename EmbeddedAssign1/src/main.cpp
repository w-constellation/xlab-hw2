#include <Arduino.h>

int pin_list[5]={12,14,27,26,25};
int num=sizeof(pin_list)/sizeof(pin_list[0]);
void setup() {
  // 设定主角（程序里的变量对应硬件的引脚），引脚功能/作用（输入/输出）
  for(int i = 0; i < num; i++)
  pinMode(pin_list[i],OUTPUT);
}

void loop() {
  //来回for循环，设置好起止点
  for(int i = 0; i < num; i++ )
  {
    digitalWrite(pin_list[i] , HIGH);
    delay(500);
    digitalWrite(pin_list[i] , LOW);
  }
  for(int i = num-2;i >= 1;i--)
  {
    digitalWrite(pin_list[i] , HIGH);
    delay(500);
    digitalWrite(pin_list[i] , LOW);
  }
}
