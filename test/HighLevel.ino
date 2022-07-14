void init_all(){
  delay(100);
  pinMode(PA11,INPUT_PULLUP);
  pinMode(PA12,OUTPUT);  
  pinMode(PC13,OUTPUT);  
  pinMode(PC15,OUTPUT);  
  pinMode(PC14,OUTPUT);  
  pinMode(PB0,OUTPUT);  
  pinMode(PB1,OUTPUT);  

  pinMode(PB12,OUTPUT);
  pinMode(PB13,OUTPUT);
  pinMode(PB14,OUTPUT);
  pinMode(PB15,OUTPUT);

  pinMode(PA8,PWM);
  pinMode(PB8,PWM);
  pinMode(PB7,PWM);
  pinMode(PB6,PWM);
  
  digitalWrite(PC13,1);
  pinMode(PB5,INPUT);  
  pinMode(PB4,INPUT);  
  pinMode(PA15,INPUT);  

  pinMode(PA0, INPUT_ANALOG);
  pinMode(PA1, INPUT_ANALOG);
  pinMode(PA2, INPUT_ANALOG);
  pinMode(PA3, INPUT_ANALOG);
  pinMode(PA4, INPUT_ANALOG);
  pinMode(PA5, INPUT_ANALOG);
  pinMode(PA6, INPUT_ANALOG);
  pinMode(PA7, INPUT_ANALOG);
//  pinMode(PB0, INPUT_ANALOG);
  kaf_f_min = analogRead(PA4);
  kaf_r_min = analogRead(PA5);
  kaf_b_min = analogRead(PA6);
  kaf_l_min = analogRead(PA7);
  motor(0,0,0,0);
  oled_init();
  gy25_init();
  pixy.init();
  EEPROM.init();
  Status = EEPROM.read(AddressWrite, &playMode);
  if(playMode == 65535 || playMode == 5) playMode = 0;  
}
void main_gamePlay(){  // spin + shoot 
  read_all();
  print_all();
  if (  ball_catched){
      spin (true);
      v= 80;
      if(!is_goal) {
        v = 150; //////200
        move(0);
      }
      else if( (goal_distance > 120 && robotName == GareathE) || (goal_distance > 110 && robotName == Gareath)) move(goal);
      else{
        GY = 0;
        if ( goal == 0) shoot ();
        else if  ( goal < 8)   motor ( 50, 50, 50, 50);
        else                   motor ( -50,-50,-50,-50);
        
      }
      
    }
  else if(is_ball) {    // ball shmare toop 
   out();  
    if ( ball_distance < 55 ){ // 50
      v=110; ////// 120
      if (ball <= 2 || ball >=14) spin (true );
      else spin(false);       
      shift_near();
    }
    else if ( ball_distance <80) { //75
      v= 130;     // 160
      spin ( false );
      shift_far();
    }
    else{
      v= 170;
      spin ( false );
      move(ball);
    }
    
  }
  else {
    come_back();
    out();
  }
}
void simple_gamePlay(){
  spin (false);
  read_all();
  print_all();
  if (  ball_catched) shoot();
  else if(is_ball) {
    out();  
    if ( ball_distance < 50 ){
      v=120;
      if (ball <= 2 || ball >=14) spin (true );
      else ;       
      shift_near();
    }
    else if ( ball_distance < 75) {
      v= 160;
      spin ( false );
      shift_far();
    }
    else{
      v= 250;
      spin ( false );
      move(ball);
    }
  }
  else {
    come_back();
    out();
  }
  
}
void goal_keeper(){
  read_all();
  print_all();
  if (ball_catched) shoot();
  else if( is_ball && ball_distance < 50 ){
    shift_near();
  }
  else if(shb < 90) {            //////////// 80 boood 
    v = 100;
    int k = (shl - shr);
    motor(-v + k, -v - k, v - k, v + k);
  }
  else if(shb > 170){      // 150 bood 
    v = 100;
    int k = (shl - shr);
    motor(v + k, v - k, -v - k, -v + k);
  }
  else{
    if( is_ball){
      
      if ( ball_distance >50) {  /////////// >50 bood 
        v = 200; 
        spin (false );
      }
      else    {
        spin ( true );
        v = 250;
      }
      int angle = ball_angle;
      if(angle > 180) angle -= 360;
      angle *= 4;
      if ( angle >200 ) angle = 200;
      if ( angle < -200 ) angle = -200;
      
      if     ( ball > 4 && ball < 8)   shift_near(); 
      else if( ball < 12 && ball >= 8) shift_near();
      else if(shr < 150 && angle > 0)  motor(angle, -angle, -angle, angle);
      else if(shl < 150 && angle < 0)  motor(angle, -angle, -angle, angle);
      else {    
        stop();
        spin (false ); 
      }   
    }
    else {     
//      if(crazy_cnt < 20)      move(4);
//      else if(crazy_cnt < 40) move(12);
//      else crazy_cnt = 0;
//      crazy_cnt++;             /////////////////////////////////
      stop(); 
      spin(false);
    }
  }
}
void shift_near(){
    if(robotName == Gareath){
           if(ball == 0 ) move(ball); 
      else if(ball == 1 ) move(ball + 1);
      else if(ball == 2 ) move(ball + 1);
      else if(ball == 3 ) move(ball + 2);
      else if(ball == 4 ) move(ball + 2);
      else if(ball == 5 ) move(ball + 2);
      else if(ball == 6 ) move(ball + 3);
      else if(ball == 7 ) move(ball + 4);
      else if(ball == 8 ) move(ball + 4);
      else if(ball == 9 ) move(ball - 4);
      else if(ball == 10) move(ball - 3);
      else if(ball == 11) move(ball - 2);
      else if(ball == 12) move(ball - 2);
      else if(ball == 13) move(ball - 2);
      else if(ball == 14) move(ball - 1);
      else if(ball == 15) move(ball - 1);
    }
    else{
      if(ball == 0 ) move(ball); 
      else if(ball == 1 ) move(ball );
      else if(ball == 2 ) move(ball + 1);
      else if(ball == 3 ) move(ball + 2);
      else if(ball == 4 ) move(ball + 2);
      else if(ball == 5 ) move(ball + 2);
      else if(ball == 6 ) move(ball + 3);
      else if(ball == 7 ) move(ball + 4);
      else if(ball == 8 ) move(ball + 4);
      else if(ball == 9 ) move(ball - 4);
      else if(ball == 10) move(ball - 3);
      else if(ball == 11) move(ball - 2);
      else if(ball == 12) move(ball - 2);
      else if(ball == 13) move(ball - 2);
      else if(ball == 14) move(ball - 1);
      else if(ball == 15) move(ball );
    }
}
void shift_far(){
       if(ball == 0 ) move(ball); 
  else if(ball == 1 ) move(ball +1 );
  else if(ball == 2 ) move(ball +1  );
  else if(ball == 3 ) move(ball + 2);
  else if(ball == 4 ) move(ball + 2);
  else if(ball == 5 ) move(ball + 2);
  else if(ball == 6 ) move(ball + 2);
  else if(ball == 7 ) move(ball + 2);
  else if(ball == 8 ) move(ball + 2);
  else if(ball == 9 ) move(ball - 2);
  else if(ball == 10) move(ball - 2);
  else if(ball == 11) move(ball - 2);
  else if(ball == 12) move(ball - 2);
  else if(ball == 13) move(ball - 2);
  else if(ball == 14) move(ball - 1);
  else if(ball == 15) move(ball - 1);
}
void come_back(){
  int k = (shl - shr);
  v = 100;
  spin(false);
  if(shb < 70) motor(-v + k, -v - k, v - k, v + k);
  else stop();
}
void set_robotXY(){
  if(robotName == Gareath){
    ROBOTX = 167; // 162
    ROBOTY = 110; // 108
  }
  else{
    ROBOTX = 185; //180
    ROBOTY = 100;// 97
  }
}
