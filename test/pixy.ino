void pixy_read(){
  blocks = pixy.getBlocks();
  if (blocks)
  {
    for (int i=0; i<blocks; i++)
    {
      if(pixy.blocks[i].signature == 1){
        ball_x = pixy.blocks[i].x;
        ball_y = pixy.blocks[i].y;
        ball_angle = get_angle(ball_x, ball_y);
        ball_direction = get_direction(ball_angle);
        ball_distance = sqrt(pow(ball_x - ROBOTX, 2) + pow(ball_y - ROBOTY, 2));
        ball = ball_direction;
        is_ball = true;
      }
      else if(pixy.blocks[i].signature == 2){
        goal_x = pixy.blocks[i].x;
        goal_y = pixy.blocks[i].y;
        goal_angle = get_angle(goal_x, goal_y);
        goal_direction = get_direction(goal_angle);
        goal_distance = sqrt(pow(goal_x - ROBOTX, 2) + pow(goal_y - ROBOTY, 2));
        goal = goal_direction;
        is_goal = true;
        is_ball = false;
      }
    }
  }  
  else {
    is_ball = false;
  }
}
int get_angle(int x, int y)
{
  int angle = atan2(y - ROBOTY, x - ROBOTX)*180/PI;
  angle += 180;
  if(angle < 0) angle += 360;
  if(angle > 360) angle -= 360;
  return 360 - angle;           ///?
}
int get_direction(int angle)
{
  int direction;
  for(int i = 0; i < 16; i++)
  {         
    if(angle <= 11.25) direction = 0; 
    else if(angle >= 348.5) direction = 0;
    else if((angle - 11.25 >= i * 22.5) && (angle-11.25 < (i+1) * 22.5))  direction = i + 1;
  }
  return direction;
}
void pixy_print(){
  display.drawCircle(90,32,19,WHITE);
  display.drawCircle(90, 10, 12, WHITE);
  display.fillRect(75, 0, 105, 17, BLACK);
  bx = 90 + sin(ball_angle*PI/180)*24;
  by = 32 - cos(ball_angle*PI/180)*24;
  if(is_ball) display.fillCircle(bx,by,4,WHITE);
  if(ball_catched) display.fillCircle(90, 17, 4, WHITE);
  bx = 90 + sin(goal_angle*PI/180)*24;
  by = 32 - cos(goal_angle*PI/180)*24;
  if(is_goal) display.drawRect(bx - 4, by - 4, 8, 8, WHITE);
  
}                                                         
void pixy_printData(){
  if(printBall){
    display.setCursor(0,0);
    display.print("Ball:");
    display.setCursor(0,24);
    display.print("x:");
    display.print(ball_x);
    display.setCursor(0,32);
    display.print("y:");
    display.print(ball_y);
    display.setCursor(0,40);
    display.print("a:");
    display.print(ball_angle);
    display.setCursor(0,48);
    display.print("b:");
    display.print(ball_direction); 
    display.setCursor(0,56);
    display.print("d:");
    display.print(ball_distance);
  }else{
    display.setCursor(0,0);
    display.print("Goal:");
    display.setCursor(0,24);
    display.print("x:");
    display.print(goal_x);
    display.setCursor(0,32);
    display.print("y:");
    display.print(goal_y);
    display.setCursor(0,40);
    display.print("a:");
    display.print(goal_angle);
    display.setCursor(0,48);
    display.print("b:");
    display.print(goal_direction); 
    display.setCursor(0,56);
    display.print("d:");
    display.print(goal_distance);
  }
}
