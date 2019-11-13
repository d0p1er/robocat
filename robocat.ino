#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();   // Initiates library.

#define SERVOMIN  110  // Minimum pulse length count out of 4096.
#define SERVOMAX  510 // Maximum pulse length count out of 4096.

int servoNo = 0; // Defines a counter for servos.

int time_to_do_0 = millis();
bool do_rev_0 = false;
int pos_0 = 260;

int time_to_do_1 = millis();
bool do_rev_1 = false;
int pos_1 = 360;

int time_to_do_4 = millis() + 1000;
bool do_rev_4 = false;
int pos_4 = 260;

int time_to_do_5 = millis() + 1000;
bool do_rev_5 = false;
int pos_5 = 360;

int time_to_do_8 = millis() + 1000;
bool do_rev_8 = false;
int pos_8 = 450;

int time_to_do_9 = millis() + 1000;
bool do_rev_9 = false;
int pos_9 = 350;

int time_to_do_12 = millis();
bool do_rev_12 = false;
int pos_12 = 450;

int time_to_do_13 = millis();
bool do_rev_13 = false;
int pos_13 = 350;


void setup() 
{
  Serial.begin(9600);       // Starts serial connecton at 9600 baud rate.
  
  pwm.begin();         // Sends PWM signals.
  pwm.setPWMFreq(60);  // Makes servos run at 60 Hz rate.
  
//занять прямое положение

  pwm.setPWM(2, 0, 310);
  pwm.setPWM(6, 0, 310);
  pwm.setPWM(10, 0, 400);
  pwm.setPWM(14, 0, 400);
}


void loop() 
{
//правая верхняя нога
  if(pos_1 < 460 and do_rev_1 == false and millis() - time_to_do_1 >= 500){
    pos_1++;
    if(pos_1 >= 460){
      do_rev_1 = true;
      time_to_do_1 = millis();
    }
  }
  else{
    if(pos_1 > 360 and do_rev_1 == true and millis() - time_to_do_1 >= 500){
      pos_1--;
      if(pos_1 <= 360){
        do_rev_1 = false;
        time_to_do_1 = millis();
      }
    }
  }
  pwm.setPWM(1, 0, pos_1);

  if(pos_0 < 360 and do_rev_0 == false and millis() - time_to_do_0 >= 500){
    pos_0++;
    if(pos_0 >= 360){
      do_rev_0 = true;
      time_to_do_0 = millis();
    }
  }
  else{
    if(pos_0 > 260 and do_rev_0 == true and millis() - time_to_do_0 >= 500){
      pos_0--;
      if(pos_0 <= 260){
        do_rev_0 = false;
        time_to_do_0 = millis();
      }
    }
  }
  pwm.setPWM(0, 0, pos_0);

//правая нижняя нога
  if(pos_5 < 460 and do_rev_5 == false and millis() - time_to_do_5 >= 500){
    pos_5++;
    if(pos_5 >= 460){
      do_rev_5 = true;
      time_to_do_5 = millis();
    }
  }
  else{
    if(pos_5 > 360 and do_rev_5 == true and millis() - time_to_do_5 >= 500){
      pos_5--;
      if(pos_5 <= 360){
        do_rev_5 = false;
        time_to_do_5 = millis();
      }
    }
  }
  pwm.setPWM(5, 0, pos_5);

  if(pos_4 < 360 and do_rev_4 == false and millis() - time_to_do_4 >= 500){
    pos_4++;
    if(pos_4 >= 360){
      do_rev_4 = true;
      time_to_do_4 = millis();
    }
  }
  else{
    if(pos_4 > 260 and do_rev_4 == true and millis() - time_to_do_4 >= 500){
      pos_4--;
      if(pos_4 <= 260){
        do_rev_4 = false;
        time_to_do_4 = millis();
      }
    }
  }
  pwm.setPWM(4, 0, pos_4);

//левая верхняя
  if(pos_9 > 250 and do_rev_9 == false and millis() - time_to_do_9 >= 500){
    pos_9--;
    if(pos_9 <= 250){
      do_rev_9 = true;
      time_to_do_9 = millis();
    }
  }
  else{
    if(pos_9 < 350 and do_rev_9 == true and millis() - time_to_do_9 >= 500){
      pos_9++;
      if(pos_9 >= 350){
        do_rev_9 = false;
        time_to_do_9 = millis();
      }
    }
  }
  pwm.setPWM(9, 0, pos_9);

  if(pos_8 > 350 and do_rev_8 == false and millis() - time_to_do_8 >= 500){
    pos_8--;
    if(pos_8 <= 350){
      do_rev_8 = true;
      time_to_do_8 = millis();
    }
  }
  else{
    if(pos_8 < 450 and do_rev_8 == true and millis() - time_to_do_8 >= 500){
      pos_8++;
      if(pos_8 >= 450){
        do_rev_8 = false;
        time_to_do_8 = millis();
      }
    }
  }
  pwm.setPWM(8, 0, pos_8);

  if(pos_13 > 250 and do_rev_13 == false and millis() - time_to_do_13 >= 500){
    pos_13--;
    if(pos_13 <= 250){
      do_rev_13 = true;
      time_to_do_13 = millis();
    }
  }
  else{
    if(pos_13 < 350 and do_rev_13 == true and millis() - time_to_do_13 >= 500){
      pos_13++;
      if(pos_13 >= 350){
        do_rev_13 = false;
        time_to_do_13 = millis();
      }
    }
  }
  pwm.setPWM(13, 0, pos_13);

//левая нижняя
  if(pos_12 > 350 and do_rev_12 == false and millis() - time_to_do_12 >= 500){
    pos_12--;
    if(pos_12 <= 350){
      do_rev_12 = true;
      time_to_do_12 = millis();
    }
  }
  else{
    if(pos_12 < 450 and do_rev_12 == true and millis() - time_to_do_12 >= 500){
      pos_12++;
      if(pos_12 >= 450){
        do_rev_12 = false;
        time_to_do_12 = millis();
      }
    }
  }
  pwm.setPWM(12, 0, pos_12);

//  pwm.setPWM(1, 0, 360);
//  delay(1000);
//  pwm.setPWM(1, 0, 110);
//  delay(1000);
//  pwm.setPWM(1, 0, 210);
//  delay(1000);
//  pwm.setPWM(1, 0, 310);
//  delay(1000);
//  pwm.setPWM(1, 0, 410);
//  delay(1000);
//  pwm.setPWM(1, 0, 510);
//  delay(1000);
//  pwm.setPWM(1, 0, 610);
//  delay(1000);
} 
