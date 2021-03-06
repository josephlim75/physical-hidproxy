#include <SoftwareSerial.h>

#define USE_SOFTSERIAL
#define SS_RX 14
#define SS_TX 16

SoftwareSerial toAndroid(SS_RX, SS_TX);

void setup() {
  Keyboard.begin();
  
  toAndroid.begin(19200);
}

void loop() {
	if (toAndroid.available() > 0) {
		char key = toAndroid.read();
		Keyboard.press(key);
		delay(25);
		Keyboard.release(key);
	}
}
