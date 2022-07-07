void oled_init(){
  display.begin(0x2, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(15,20);
  if(robotName == Gareath)
    display.print("Gareth");
  else
    display.print("GarethE");
  display.display();
  delay(1000);
  display.setTextSize(1);
  display.clearDisplay();
  display.display();
}
void print_playModes(){
  if(playMode == 0){
    display.fillRect(10, 10, 108, 12, WHITE);
    display.setTextColor(BLACK);
    display.setCursor(15, 11);
    display.print("Main");
  }
  else{
    display.setTextColor(WHITE);
    display.setCursor(15, 11);
    display.print("Main");
  }
  if(playMode == 1){
    display.fillRect(10, 22, 108, 12, WHITE);
    display.setTextColor(BLACK);
    display.setCursor(15, 23);
    display.print("Simple");
  }
  else{
    display.setTextColor(WHITE);
    display.setCursor(15, 23);
    display.print("Simple");
  }
  if(playMode == 2){
    display.fillRect(10, 33, 108, 12, WHITE);
    display.setTextColor(BLACK);
    display.setCursor(15, 34);
    display.print("Goal Keeper");
  }
  else{
    display.setTextColor(WHITE);
    display.setCursor(15, 34);
    display.print("Goal Keeper");
  }
  display.setTextColor(WHITE);
}
