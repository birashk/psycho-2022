#include <EEPROM.h>
#include <Wire.h>
#include <PixyI2C.h>
PixyI2C pixy;
#include <Adafruit_SH1106_STM32.h>
Adafruit_SH1106 display(-1);
#include <math.h>
#define Gareath 0
#define GareathE 1
int robotName = Gareath;
uint16_t blocks;   // bra penalty ba oon yeki robot (gareathE) brim va sorat nesbat be gareath kamtar bshe va khb bra penalty michrkhonim mizarim 
int sensor[7];
int buff[8];
int counter = 0;
int GY;
int cx1,cy1,cx2,cy2;
int bx,by;
int v = 120;
int ball_x, ball_y, ball_distance, ball_angle, ball_direction, ball;
int goal_x, goal_y, goal_distance, goal_angle, goal_direction, goal;
int shb, shr, shl, shf;
int printMode = 2;
int ROBOTX, ROBOTY;
bool is_ball, is_goal;
bool kaf_f, kaf_r, kaf_b, kaf_l;
int kaf_f_min, kaf_r_min, kaf_b_min, kaf_l_min;
int out_cnt, kaf;                   ////// kaf mal out bella bella 
bool arrived = false;
bool ball_catched;
bool printBall = true;
int crazy_cnt = 0;
uint16 playMode = 0;
uint16 AddressWrite = 0x10;
uint16 Status;

void setup() {
  set_robotXY();
  init_all();
  // delay (6000); bra penalty
}

void loop() {
  read_all();
  print_all();
  if(ball_catched){
    spin(true);
    if(is_goal){
      GY = 0;
      int angle = goal_angle;
      if(angle > 180) angle -= 360;
      if(angle < 5 && angle > -5) shoot();
      else if(angle < 0) motor(40 , -50, -50, -40);
      else if(angle > 0) motor(40 , 50, 50, -40);
      
    }
    else move(0);
  }
  else if(is_ball){
    spin(true);
    if(ball_distance <50) {v=100;shift_near();}
    else                  {v=150;shift_far();}
  }
  else {
    stop();
    spin(false);
  }
  
}
