#include "Arduino.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
void setup() {
Serial.begin(9600);
delay(500);
Serial.println("I'm going to send a message!");
mySerial.begin(9600);
mySerial.println("Hello world?");
}
void loop() {
if (mySerial.available()) {
Serial.write(mySerial.read());
}
if (Serial.available()) {
mySerial.write(Serial.read());
}
}
