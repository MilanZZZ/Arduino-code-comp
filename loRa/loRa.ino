/*
* LoRa E32-TTL-100
* Write on serial to transfer a message to other device
* https://www.mischianti.org/2019/10/15/lora-e32-device-for-arduino-esp32-or-esp8266-specs-and-basic-usage-part-1/
*
* E32-TTL-100----- Arduino UNO
* M0         ----- GND
* M1         ----- GND
* RX         ----- PIN 2 (PullUP &amp; Voltage divider)
* TX         ----- PIN 3 (PullUP)
* AUX        ----- Not connected
* VCC        ----- 3.3v/5v
* GND        ----- GND
*
*/
#include "Arduino.h"
#include "LoRa_E32.h"
LoRa_E32 e32ttl100(2, 3); // RX, TX
void setup() {
Serial.begin(9600);
delay(500);
Serial.println("Hi, I'm going to send message!");
// Startup all pins and UART
e32ttl100.begin();
// Send message
ResponseStatus rs = e32ttl100.sendMessage("Hello, world?");
// Check If there is some problem of succesfully send
Serial.println(rs.getResponseDescription());
}
void loop() {
// If something available
if (e32ttl100.available()>1) {
// read the String message
ResponseContainer rc = e32ttl100.receiveMessage();
// Is something goes wrong print error
if (rc.status.code!=1){
rc.status.getResponseDescription();
}else{
// Print the data received
Serial.println(rc.data);
}
}
if (Serial.available()) {
String input = Serial.readString();
e32ttl100.sendMessage(input);
}
}
