void motor(int L1, int L2, int R2, int R1)
{
  if (robotName == Gareath){
  L1 = (float) L1 * 0.86;
  R1 = (float) R1 * 0.86;
  }
  else   {
     L1 = (float) L1 * 0.9;
     R1 = (float) R1 * 0.9;
    
  }
  int GY2 = GY;
  if(GY2 < 20 && GY2 > -20) GY2 *= 1;
  else GY2 /= 2; 
  L1 += GY2;
  L2 += GY2;
  R1 += GY2;
  R2 += GY2;

  L1 = L1*65535/255;
  L2 = L2*65535/255;
  R1 = R1*65535/255;
  R2 = R2*65535/255;
  if(L1 > 65535) L1 = 65535;
  if(L2 > 65535) L2 = 65535;
  if(R1 > 65535) R1 = 65535;
  if(R2 > 65535) R2 = 65535;
  if(L1 < -65535) L1 = -65535;
  if(L2 < -65535) L2 = -65535;
  if(R1 < -65535) R1 = -65535;
  if(R2 < -65535) R2 = -65535;
  
  if(L1 >= 0){
    digitalWrite(PB15,0);
    pwmWrite(PA8,L1);
  }
  else{
    digitalWrite(PB15,1);
    pwmWrite(PA8,L1+65535);
  }
  if(L2 >= 0){
    digitalWrite(PB14,0);
    pwmWrite(PB8,L2);
  }
  else{
    digitalWrite(PB14,1);
    pwmWrite(PB8,L2+65535);
  }
  if(R2 >= 0){
    digitalWrite(PB13,0);
    pwmWrite(PB7,R2);
  }
  else{
    digitalWrite(PB13,1);
    pwmWrite(PB7,R2+65535);
  }
  if(R1 >= 0){
    digitalWrite(PB12,0);
    pwmWrite(PB6,R1);
  }
  else{
    digitalWrite(PB12,1);
    pwmWrite(PB6,R1+65535);
  }
}
void move(int d){
  if     (d == 0 )  motor(v, v, -v, -v);     //0
  else if(d == 1 )  motor(v, v/2, -v, -v/2); //1
  else if(d == 2 )  motor(v, 0, -v, 0);      //2
  else if(d == 3 )  motor(v, -v/2, -v, v/2); //3
  else if(d == 4 )  motor(v, -v, -v, v);     //4
  else if(d == 5 )  motor(v/2, -v, -v/2, v); //5
  else if(d == 6 )  motor(0, -v, 0, v);      //6
  else if(d == 7 )  motor(-v/2, -v, v/2, v); //7
  else if(d == 8 )  motor(-v, -v, v, v);     //8
  else if(d == 9 )  motor(-v, -v/2, v, v/2); //9
  else if(d == 10)  motor(-v, 0, v, 0);      //10
  else if(d == 11)  motor(-v, v/2, v, -v/2); //11
  else if(d == 12)  motor(-v, v, v, -v);     //12
  else if(d == 13)  motor(-v/2, v, v/2, -v); //13
  else if(d == 14)  motor(0, v, 0, -v);      //14
  else if(d == 15)  motor(v/2, v, -v/2, -v); //15
}
void stop(){
  motor(0,0,0,0);
}
void moveForSeconds(int direction, int seconds){
  for(int j=0; j<seconds*8; j++){
    read_all();
    print_all();
    move(direction);
  }
}
void fastStop(){
  motor(GY, GY, GY, GY);
}
void waitForBall(){  
  out_cnt = 0;
  while(is_ball && out_cnt < 60 && ball <= (kaf+3)%16 && ball >= (kaf-3)%16){
    read_all();
    print_all();
    stop();
    spin(false);
    out_cnt++;
  }
}
void out(){
  if( kaf_f || kaf_r || kaf_b || kaf_l){
    v = 130;
    moveForSeconds((kaf+8)%16, 2);
    waitForBall();
  }
  /*
  out_cnt = 0;
  arrived = false;
  v = 150;
  // Out Right
  if(kaf_r &&  shr > 150 ){
    moveForSeconds(12, 1);
    while(is_ball && ball<8 && out_cnt < 60){
      read_all();
      print_all();
      if ( ball < 3)  move(0);
      else if ( ball > 5)  move(8); 
      else stop();
//      out_cnt++;
    }
  }
  // Out Left
  if(kaf_l &&  shl > 150 ){
    moveForSeconds(4, 1);
    while(is_ball && ball > 8 && out_cnt < 60){
      read_all();
      print_all();
      if ( ball > 13)  move(0);
      else if ( ball < 11)  move(8); 
      else stop();
//      out_cnt++;
    }         
  }
  // Out Back
  if(kaf_b){
    moveForSeconds(0, 2);
    waitForBall();  
  }
  // Out Forward
  if(kaf_f){
    moveForSeconds(8, 2);
    waitForBall();  
  }
   */
}    
void shoot(){
  stop();
  digitalWrite(PC15,1);
  delay (300);
  digitalWrite(PC15,0);
  delay (300);
}
void spin(bool state){
  if ( state )
    digitalWrite(PC14,1);
   else 
    digitalWrite(PC14,0);
}
