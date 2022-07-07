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
void shift_near(){
    if(robotName == Gareath){
           if(ball == 0 ) move(ball); 
      else if(ball == 1 ) move(ball + 2);
      else if(ball == 2 ) move(ball + 3);
      else if(ball == 3 ) move(ball + 3);
      else if(ball == 4 ) move(ball + 3);
      else if(ball == 5 ) move(ball + 3);
      else if(ball == 6 ) move(ball + 3);
      else if(ball == 7 ) move(ball + 4);
      else if(ball == 8 ) move(ball + 4);
      else if(ball == 9 ) move(ball - 4);
      else if(ball == 10) move(ball - 3);
      else if(ball == 11) move(ball - 3);
      else if(ball == 12) move(ball - 3);
      else if(ball == 13) move(ball - 3);
      else if(ball == 14) move(ball - 3);
      else if(ball == 15) move(ball - 2);
    }
    else{
      if(ball == 0 ) move(ball); 
      else if(ball == 1 ) move(ball + 2);
      else if(ball == 2 ) move(ball + 2);
      else if(ball == 3 ) move(ball + 3);
      else if(ball == 4 ) move(ball + 2);
      else if(ball == 5 ) move(ball + 2);
      else if(ball == 6 ) move(ball + 3);
      else if(ball == 7 ) move(ball + 4);
      else if(ball == 8 ) move(ball + 4);
      else if(ball == 9 ) move(ball - 4);
      else if(ball == 10) move(ball - 3);
      else if(ball == 11) move(ball - 3);
      else if(ball == 12) move(ball - 3);
      else if(ball == 13) move(ball - 3);
      else if(ball == 14) move(ball - 2);
      else if(ball == 15) move(ball - 2);
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
    ROBOTX = 162;
    ROBOTY = 108;
  }
  else{
    ROBOTX = 180;
    ROBOTY = 97;
  }
}
