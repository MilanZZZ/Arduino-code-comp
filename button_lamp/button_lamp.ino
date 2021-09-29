const int buttonPin = 12;
int counter = 0;
int pin = 13;
void setup() {
  // put your setup code here, to run once:
pinMode(buttonPin, INPUT);
pinMode(pin, OUTPUT);
}

void loop() {
  int buttonState;
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) // light the LED
  {
    counter++;
    delay(150);
  }

  if (counter == 0)
  {
    digitalWrite(pin, HIGH);
    
  }
  
  else if (counter == 1)
  {
    digitalWrite(pin, LOW);
  }

  else if (counter == 2)
  {
    digitalWrite(pin, HIGH);
  }

  else if (counter == 3)
  {
    digitalWrite(pin, LOW);
  }

  else
  {
    counter = 0;
  }

}
