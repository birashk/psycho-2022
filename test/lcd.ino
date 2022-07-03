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
