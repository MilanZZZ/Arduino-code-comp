int groundpin = 8;

void setup() {
  // put your setup code here, to run once:

pinMode(groundpin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
groundpin.write(60);
}
