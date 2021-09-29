static const uint8_t led1 = 14;
int led12 = 16;

void setup() {
  // put your setup code here, to run once:
pinMode(led1, OUTPUT);
pinMode(led12, OUTPUT);
Serial.begin(115200);
}

void loop() {
  digitalWrite(led1, HIGH);
  Serial.print("1");
  delay (1000);
  Serial.print("0");
  digitalWrite(led1, LOW);
  
 
  // put your main code here, to run repeatedly:

}
