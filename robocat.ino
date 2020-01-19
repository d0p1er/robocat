#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();   // Initiates library.

#define SERVOMIN  110  // Minimum pulse length count out of 4096.
#define SERVOMAX  510 // Maximum pulse length count out of 4096.

int servoNo = 0; // Defines a counter for servos.

//правая верхняя
int time_to_do_0 = millis();
bool do_rev_0 = false;
int pos_0 = 390;

int time_to_do_1 = millis();
bool do_rev_1 = false;
int pos_1 = 300;

//правая нижняя
int time_to_do_4 = millis();
bool do_rev_4 = true;
int pos_4 = 355;

int time_to_do_5 = millis();
bool do_rev_5 = true;
int pos_5 = 370;

//левая верхняя
int time_to_do_8 = millis();
bool do_rev_8 = true;
int pos_8 = 375;

int time_to_do_9 = millis();
bool do_rev_9 = true;
int pos_9 = 360;

//левая нижняя
int time_to_do_12 = millis();
bool do_rev_12 = false;
int pos_12 = 340;

int time_to_do_13 = millis();
bool do_rev_13 = false;
int pos_13 = 490;


void setup() 
{
  Serial.begin(9600);       // Starts serial connecton at 9600 baud rate.
  
  pwm.begin();         // Sends PWM signals.
  pwm.setPWMFreq(60);  // Makes servos run at 60 Hz rate.

//pwm.setPWM(2, 0, 350);
//pwm.setPWM(6, 0, 330);
//pwm.setPWM(10, 0, 350);
//pwm.setPWM(14, 0, 370);

//занять прямое положение
  pwm.setPWM(0, 0, 390);
  pwm.setPWM(1, 0, 300);
  pwm.setPWM(2, 0, 390);

  pwm.setPWM(4, 0, 390);
  pwm.setPWM(5, 0, 220);
  pwm.setPWM(6, 0, 350);

  pwm.setPWM(8, 0, 340);
  pwm.setPWM(9, 0, 430);
  pwm.setPWM(10, 0, 350);

  pwm.setPWM(12, 0, 340);
  pwm.setPWM(13, 0, 500);
  pwm.setPWM(14, 0, 370);

  delay(1000);

//занять положение полуприсяд
  pwm.setPWM(0, 0, 355);
  pwm.setPWM(1, 0, 370);
  pwm.setPWM(2, 0, 390);

  pwm.setPWM(4, 0, 355);
  pwm.setPWM(5, 0, 290);
  pwm.setPWM(6, 0, 350);

  pwm.setPWM(8, 0, 375);
  pwm.setPWM(9, 0, 360);
  pwm.setPWM(10, 0, 350);

  pwm.setPWM(12, 0, 375);
  pwm.setPWM(13, 0, 430);
  pwm.setPWM(14, 0, 370);

  delay(1000);

//готовность к ходу
  pwm.setPWM(0, 0, 390);
  pwm.setPWM(1, 0, 300);
  pwm.setPWM(2, 0, 390);

  pwm.setPWM(4, 0, 355);
  pwm.setPWM(5, 0, 290);
  pwm.setPWM(6, 0, 350);

  pwm.setPWM(8, 0, 375);
  pwm.setPWM(9, 0, 360);
  pwm.setPWM(10, 0, 350);

  pwm.setPWM(12, 0, 340);
  pwm.setPWM(13, 0, 500);
  pwm.setPWM(14, 0, 370);

  delay(1000);
  
  time_to_do_0 = millis();
  time_to_do_1 = millis();
  time_to_do_4 = millis();
  time_to_do_5 = millis();
  time_to_do_8 = millis();
  time_to_do_9 = millis();
  time_to_do_12 = millis();
  time_to_do_13 = millis();
    
}


void loop() 
{

//правая верхняя нога
  if(pos_0 < 390 and do_rev_0 == true and millis() - time_to_do_0 >= 500){
    pos_0++;
    if(pos_0 >= 390){
      do_rev_0 = false;
      time_to_do_0 = millis();
    }
  }
  else if(pos_0 > 355 and do_rev_0 == false and millis() - time_to_do_0 >= 500){
    pos_0--;
    if(pos_0 <= 355){
      do_rev_0 = true;
      time_to_do_0 = millis();
    }
  }

  pwm.setPWM(0, 0, pos_0);


  if(pos_1 > 300 and do_rev_1 == true and millis() - time_to_do_1 >= 500){
    pos_1 -= 2;
    if(pos_1 <= 300){
      do_rev_1 = false;
      time_to_do_1 = millis();
    }
  }
  else if(pos_1 < 370 and do_rev_1 == false and millis() - time_to_do_1 >= 500){
    pos_1 += 2;
    if(pos_1 >= 370){
      do_rev_1 = true;
      time_to_do_1 = millis();
    }
  }

  pwm.setPWM(1, 0, pos_1);


//правая нижняя нога
  if(pos_4 < 390 and do_rev_4 == true and millis() - time_to_do_4 >= 500){
    pos_4++;
    if(pos_4 >= 390){
      do_rev_4 = false;
      time_to_do_4 = millis();
    }
  }
  else if(pos_4 > 355 and do_rev_4 == false and millis() - time_to_do_4 >= 500){
    pos_4--;
    if(pos_4 <= 355){
      do_rev_4 = true;
      time_to_do_4 = millis();
    }
  }

  pwm.setPWM(4, 0, pos_4);


  if(pos_5 > 220 and do_rev_5 == true and millis() - time_to_do_5 >= 500){
    pos_5 -= 2;
    if(pos_5 <= 220){
      do_rev_5 = false;
      time_to_do_5 = millis();
    }
  }
  else if(pos_5 < 290 and do_rev_5 == false and millis() - time_to_do_5 >= 500){
    pos_5 += 2;
    if(pos_5 >= 290){
      do_rev_5 = true;
      time_to_do_5 = millis();
    }
  }

  pwm.setPWM(5, 0, pos_5);



//левая верхняя нога
  if(pos_8 < 375 and do_rev_8 == false and millis() - time_to_do_8 >= 500){
    pos_8++;
    if(pos_8 >= 375){
      do_rev_8 = true;
      time_to_do_8 = millis();
    }
  }
  else if(pos_8 > 340 and do_rev_8 == true and millis() - time_to_do_8 >= 500){
    pos_8--;
    if(pos_8 <= 340){
      do_rev_8 = false;
      time_to_do_8 = millis();
    }
  }

  pwm.setPWM(8, 0, pos_8);


  if(pos_9 > 360 and do_rev_9 == false and millis() - time_to_do_9 >= 500){
    pos_9 -= 2;
    if(pos_9 <= 360){
      do_rev_9 = true;
      time_to_do_9 = millis();
    }
  }
  else if(pos_9 < 430 and do_rev_9 == true and millis() - time_to_do_9 >= 500){
    pos_9 += 2;
    if(pos_9 >= 430){
      do_rev_9 = false;
      time_to_do_9 = millis();
    }
  }

  pwm.setPWM(9, 0, pos_9);


//левая нижняя нога
  if(pos_12 < 375 and do_rev_12 == false and millis() - time_to_do_12 >= 500){
    pos_12++;
    if(pos_12 >= 375){
      do_rev_12 = true;
      time_to_do_12 = millis();
    }
  }
  else if(pos_12 > 340 and do_rev_12 == true and millis() - time_to_do_4 >= 500){
    pos_12--;
    if(pos_12 <= 340){
      do_rev_12 = false;
      time_to_do_12 = millis();
    }
  }

  pwm.setPWM(12, 0, pos_12);


  if(pos_13 > 430 and do_rev_13 == false and millis() - time_to_do_13 >= 500){
    pos_13 -= 2;
    if(pos_13 <= 430){
      do_rev_13 = true;
      time_to_do_13 = millis();
    }
  }
  else if(pos_13 < 500 and do_rev_13 == true and millis() - time_to_do_13 >= 500){
    pos_13 += 2;
    if(pos_13 >= 500){
      do_rev_13 = false;
      time_to_do_13 = millis();
    }
  }

  pwm.setPWM(13, 0, pos_13);
} 
