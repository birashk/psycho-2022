#include <Wire.h>
#include <PixyI2C.h>
PixyI2C pixy;
#include <Adafruit_SH1106_STM32.h>
Adafruit_SH1106 display(-1);
#include <math.h>
#define Gareath 0
#define GareathE 1
int robotName = GareathE;
uint16_t blocks;
int sensor[7];
int buff[8];
int counter = 0;
int GY;
int cx1,cy1,cx2,cy2;
int bx,by;
int v = 150;
int ball_x, ball_y, ball_distance, ball_angle, ball_direction, ball;
int goal_x, goal_y, goal_distance, goal_angle, goal_direction, goal;
int shb, shr, shl, shf;
int printMode = 2;
int ROBOTX, ROBOTY;
bool is_ball, is_goal;
bool kaf_f, kaf_r, kaf_b, kaf_l;
int kaf_f_min, kaf_r_min, kaf_b_min, kaf_l_min;
int out_cnt, kaf;
bool arrived = false;
bool ball_catched;
bool printBall = true;
void setup() {
  set_robotXY();
  init_all();
}

void loop() {
//  Yeki az in dota uncomment mishe (Joftesho ba ham nazari!!!) 
//  main_gamePlay();
  simple_gamePlay();
}
