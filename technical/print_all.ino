void print_all(){
  display.clearDisplay();
  if(printMode == 0){
    sensor_print();
    gy25_print();
    pixy_print();
  }
  else if(printMode == 1){
    pixy_printData();
    pixy_print();
  }
  else if(printMode == 2){
    sharp_and_kaf_print();
  }
  else if(printMode == 3){
    print_playModes();
  }
  display.display();
}
