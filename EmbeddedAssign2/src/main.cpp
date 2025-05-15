#include <Arduino.h>

// 定义LED引脚
const int led1Pin = 2;  // 假设LED1连接到GPIO2，需根据实际硬件连接调整
const int led2Pin = 4;  // 假设LED2连接到GPIO4，需根据实际硬件连接调整

// 初始化LED引脚
void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  Serial.begin(115200);  // 初始化串口通信，波特率设为115200
}

// 主循环
void loop() {
  if (Serial.available() > 0) {  // 检查串口是否有数据可读
    char receivedChar = Serial.read();  // 读取串口数据
    switch (receivedChar) {
      case '1':
        digitalWrite(led1Pin,!digitalRead(led1Pin));  // 切换LED1状态
        Serial.print("LED1");  // 发送反馈
        Serial.println(digitalRead(led1Pin)? "亮" : "灭");
        break;
      case '2':
        digitalWrite(led2Pin,!digitalRead(led2Pin));  // 切换LED2状态
        Serial.print("LED2");
        Serial.println(digitalRead(led2Pin)? "亮" : "灭");
        break;
      default:
        break;  // 无对应指令，不执行动作
    }
  }
  delay(1000);  // 适当延时，避免资源占用过高
}