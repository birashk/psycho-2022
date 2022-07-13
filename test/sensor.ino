void sensor_read(){
  sensor[0] = analogRead(PA0);
  sensor[1] = analogRead(PA1);
  sensor[2] = analogRead(PA2);
  sensor[3] = analogRead(PA3);
  sensor[4] = analogRead(PA4);
  sensor[5] = analogRead(PA5);
  sensor[6] = analogRead(PA6);
  sensor[7] = analogRead(PA7);
  sensor[8] = analogRead(PB0);
  for(int i = 0; i<3; i++) sensor[i] /= 10;
  shb = sensor[0];
  shr = sensor[1];
  shl = sensor[2];
  sensor[4] -= kaf_f_min;
  sensor[5] -= kaf_r_min;
  sensor[6] -= kaf_b_min;
  sensor[7] -= kaf_l_min;
  if(sensor[4] > 100) kaf_f = true ;
  else                kaf_f = false;
  if(sensor[5] > 100) kaf_r = true ;
  else                kaf_r = false;
  if(sensor[6] > 100) kaf_b = true ;
  else                kaf_b = false;
  if(sensor[7] > 100) kaf_l = true ;
  else                kaf_l = false;
  if ( sensor [3]>500)
  ball_catched = true;
  else 
  ball_catched = false ;
  
       if(kaf_f  && !kaf_r && !kaf_b && !kaf_l) kaf =  0;
  else if(kaf_f  &&  kaf_r && !kaf_b && !kaf_l) kaf =  2;
  else if(!kaf_f && kaf_r &&  !kaf_b && !kaf_l) kaf =  4;
  else if(!kaf_f && kaf_r &&  kaf_b  && !kaf_l) kaf =  6;
  else if(!kaf_f && !kaf_r && kaf_b  && !kaf_l) kaf =  8;
  else if(!kaf_f && !kaf_r && kaf_b  && kaf_l ) kaf = 10;
  else if(!kaf_f && !kaf_r && !kaf_b && kaf_l ) kaf = 12;
  else if(kaf_f  && !kaf_r && !kaf_b && kaf_l ) kaf = 14;

}
void sensor_print(){
  for(int i = 0; i<7 ; i++){
    display.setCursor(0,i*9);
    display.print(i);
    display.print(":");
    display.print(sensor[i]);
  } 

}
void sharp_and_kaf_print(){
  display.drawCircle(64, 32, 15, WHITE);
  display.drawCircle(64, 15, 10, WHITE);
  display.fillRect(50, 0, 80, 20, BLACK);
  display.setCursor(30, 30);
  display.print(shl);
  display.setCursor(82, 30);
  display.print(shr);
  display.setCursor(55, 50);
  display.print(shb);
  if(kaf_f) display.fillRect(62, 25, 4, 8, WHITE);
  if(kaf_r) display.fillRect(69, 32, 8, 4, WHITE);
  if(kaf_b) display.fillRect(62, 38, 4, 8, WHITE);
  if(kaf_l) display.fillRect(51, 32, 8, 4, WHITE);
  
}
void push_button_read(){
  if(digitalRead(PB4) || digitalRead(PB5) || digitalRead(PA15))  {
    digitalWrite(PC13,0);
    if(digitalRead(PB5)){ //Set GY-25
      if(printMode == 3){
        if(playMode > 0) {
          playMode--;
          EEPROM.write(AddressWrite, playMode);
        }
      }
      else{
        Serial1.write(0XA5);
        Serial1.write(0X55);
      }
      while(digitalRead(PB5));
    }
    if(digitalRead(PB4)){
      printMode++;
      printMode%=4;
      while(digitalRead(PB4));
    }
    if(digitalRead(PA15)){
      if     (printMode == 0)  {
//     move (0);
//    digitalWrite(PC15,1);
//    delay (50);                                                                      
//    digitalWrite(PC15,0);
//    delay (300);
       shoot();
      }
      else if(printMode == 1) printBall = !printBall;
      else if(printMode == 2){
        kaf_f_min = analogRead(PA4);
        kaf_r_min = analogRead(PA5);
        kaf_b_min = analogRead(PA6);
        kaf_l_min = analogRead(PA7);
      }
      else if(printMode == 3) {
        if(playMode < 2) {
          playMode++;
          EEPROM.write(AddressWrite, playMode);
        }
      }
      
      while(digitalRead(PA15));
    }
  }
  else digitalWrite(PC13,1);
}
