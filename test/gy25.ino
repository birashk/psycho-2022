void gy25_init(){
  delay(500);
  Serial1.begin(115200);
  Serial1.write(0XA5);
  Serial1.write(0X54);
  delay(500);
  Serial1.write(0XA5);
  Serial1.write(0X51);
}

void gy25_read(){
  Serial1.write(0XA5);
  Serial1.write(0X51);
  while (true) { 
    buff[counter] = Serial1.read();
    if(counter == 0 && buff[0] != 0xAA) break;
    counter++;       
    if(counter==8)
    {                                       // kln 8 bar anjm mishe bra gy kln
    counter=0;                 
    if(buff[0]==0xAA && buff[7]==0x55)
      {         
       GY=(int16_t)(buff[1]<<8|buff[2])/100.00; 
      } 
    }    
  }
}
void gy25_print()
{
  display.setCursor(40,0);
  display.print("GY:");
  display.print(GY);
  ///////////////////-----GY-25 Compass
//  display.drawCircle(90,32,19,WHITE);
  cx1 = 90 + sin(-GY*PI/180)*10;
  cx2 = 90 - sin(-GY*PI/180)*10;
  cy1 = 32  + cos(-GY*PI/180)*10;
  cy2 = 32  - cos(-GY*PI/180)*10;
  display.drawLine(cx1,cy1,cx2,cy2,WHITE);   // khate ba noghte thsh
  display.fillCircle(cx1,cy1,2,WHITE);
  
}
