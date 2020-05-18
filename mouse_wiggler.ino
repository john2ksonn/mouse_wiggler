#include <Mouse.h>

void setup() {
  int dela=5;
  int x = 50;
  
  Mouse.begin();
  delay(1000);
  
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

void loop() {
  // move the mouse every 10 seconds
  Mouse.move(3, 0, 0);
  delay(100);
  Mouse.move(-3, 0, 0);
  delay(10000);
}
