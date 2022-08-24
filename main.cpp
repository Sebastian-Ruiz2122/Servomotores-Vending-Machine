#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);
unsigned int pos0=204;
unsigned  int pos180=409;
void setServo(uint8_t n_servo, int angulo);


void setup() {
  // put your setup code here, to run once:
  servos.begin();
  servos.setPWMFreq(50);
  setServo(0,90);
}


void setServo(uint8_t n_servo, int angulo){
  int duty;
  duty = map(angulo,0,180,pos0,pos180);
  servos.setPWM(n_servo, 0, duty);
}


void correccion360();

void loop() {
  correccion360();
}

void correccion360(){
  setServo(0,0);
  delay(1680);
  setServo(0,90);
  delay(10000);
}
