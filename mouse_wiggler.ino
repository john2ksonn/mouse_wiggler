#include "HID-Project.h"

boolean wiggleMouse = true;

void setup() {
  int dela=5;
  int x = 50;
  
  Mouse.begin();
  BootKeyboard.begin();
  delay(1000);

  wiggleMouse = !(BootKeyboard.getLeds() & LED_CAPS_LOCK);

  if(wiggleMouse){
    // Let the mouse pointer dance a bit in the beginning
    for(int j = x; j > 0; j-=10){
      for(int i = 0; i < j/2; i++){
        Mouse.move(1, -1, 0);
        delay(dela);
      }
      for(int i = 0; i < j/2; i++){
        Mouse.move(-1, -1, 0);
        delay(dela);
      }
      for(int i = 0; i < j/2; i++){
        Mouse.move(-1, 1, 0);
        delay(dela);
      }
      for(int i = 0; i < j/2; i++){
        Mouse.move(1, 1, 0);
        delay(dela);
      }
    }
  }
}

void loop() {
  for(unsigned int i = 0; i < 1000; i++){
    if (BootKeyboard.getLeds() & LED_CAPS_LOCK){
      BootKeyboard.write(KEY_CAPS_LOCK);
      BootKeyboard.write(KEY_ESC);
    }
    delay(1);
  }
  if(wiggleMouse){
    Mouse.move(1, 0, 0);
    delay(1);
    Mouse.move(-1, 0, 0);
  }
}
