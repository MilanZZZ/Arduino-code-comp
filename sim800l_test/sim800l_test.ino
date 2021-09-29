#include

#include

#define TIMEOUT 5000

#define ACTIVE LOW

#define OFF HIGH

byte Relay[] = {A0,A1,A2,A3};

byte StatRelay[4];

char buffNumber[20];

char currentLine[500] = "";

int currentLineIndex = 0;

bool nextLineIsMessage = false;

String replyNumber = "089510863958";

GPRS gprs;

void setup() {

for(int i=0; i < 4; i++) {

pinMode (Relay[i] , OUTPUT);

digitalWrite (Relay[i], MATI);

StatRelay[i] = MATI;

}

Serial.begin(9600);

while (!Serial);

Serial.println("Activate SIM800L V2 >>> Automatically Read SMS");

gprs.preInit();

delay(1000);

while (0 != gprs.init()) {

delay(1000);

Serial.print("init errorrn");

}

// Manage message to mode ASCII

if (0 != gprs.sendCmdAndWaitForResp("AT+CMGF=1rn", "OK", TIMEOUT)) {

ERROR("ERROR:CNMI");

return;

}

// Read Incoming SMS

if (0 != gprs.sendCmdAndWaitForResp("AT+CNMI=1,2,0,0,0rn", "OK", TIMEOUT)) {

ERROR("ERROR:CNMI");

return;

}

int pjg = replyNumber.length() + 1;

buffNumber[pjg];

replyNumber.toCharArray(buffNumber,pjg);

Serial.print("Send reply to number = > ");

Serial.println(buffNumber);

Serial.println("Initialization Done");

Serial.println("=============================================================");

}

void loop() {

// Change status Relay ON / OFF

for(int i=0; i < 4; i++) {

digitalWrite(Relay[i], StatRelay[i]);

}

// If there is input data from SIM800

if (gprs.serialSIM800.available()) {

char lastCharRead = gprs.serialSIM800.read();

// Save all data on lastCharRead, then if there is r or n, as a final signal of incoming message

if (lastCharRead == 'r' || lastCharRead == 'n') {

String lastLine = String(currentLine);

// If the last message +CMT indicates new message arrive

if (lastLine.startsWith("+CMT:")) {

Serial.println(lastLine);

nextLineIsMessage = true;

} else if (lastLine.length() > 0) {

if (nextLineIsMessage) {

Serial.println(lastLine);

// ================================================================>> Function of Relay Controller

//Relay 1 Controller

if (lastLine.indexOf("Relay 1 ON") >= 0) {

StatRelay[0] = AKTIF;

Serial.print("Reply====>>>> ");

Serial.println("Relay 1 Status Active");

gprs.sendSMS (buffNumber, "Relay 1 Status Active");

}

else if (lastLine.indexOf("Relay 1 OFF") >= 0) {

StatRelay[0] = MATI;

Serial.print("Reply====>>>> ");

Serial.println("Relay 1 Status Off");

gprs.sendSMS (buffNumber, "Relay 1 Status Off");

}

//Relay 2 Controller

if (lastLine.indexOf("Relay 2 ON") >= 0) {

StatRelay[1] = AKTIF;

Serial.print("Reply====>>>> ");

Serial.println("Relay 2 Status Active");

gprs.sendSMS (buffNumber, "Relay 2 Status Active");

}

else if (lastLine.indexOf("Relay 2 OFF") >= 0) {

StatRelay[1] = MATI;

Serial.print("Reply====>>>> ");

Serial.println("Relay 2 Status Off");

gprs.sendSMS (buffNumber, "Relay 2 Status Off");

}

//Relay 3 Controller

if (lastLine.indexOf("Relay 3 ON") >= 0) {

StatRelay[2] = AKTIF;

Serial.print("Reply====>>>> ");

Serial.println("Relay 3 Status Active");

gprs.sendSMS (buffNumber, "Relay 3 Status Active");

}

else if (lastLine.indexOf("Relay 3 OFF") >= 0) {

StatRelay[2] = MATI;

Serial.print("Reply====>>>> ");

Serial.println("Relay 3 Status Off");

gprs.sendSMS (buffNumber, "Relay 3 Status Off");

}

//Relay 4 Controller

if (lastLine.indexOf("Relay 4 ON") >= 0) {

StatRelay[3] = AKTIF;

Serial.print("Reply====>>>> ");

Serial.println("Relay 4 Status Active");

gprs.sendSMS (buffNumber, "Relay 1 Status Active");

}

else if (lastLine.indexOf("Relay 4 OFF") >= 0) {

StatRelay[3] = MATI;

Serial.print("Reply====>>>> ");

Serial.println("Relay 4 Status Off");

gprs.sendSMS (buffNumber, "Relay 4 Status Off");

}

nextLineIsMessage = false;

}

// ==================================================================>>

}

//Clear char array for next line of read

for ( int i = 0; i < sizeof(currentLine); ++i ) {

currentLine[i] = (char)0;

}

currentLineIndex = 0;

}

else {

currentLine[currentLineIndex++] = lastCharRead;

}

}

}
