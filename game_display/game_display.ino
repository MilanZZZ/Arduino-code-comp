
#include <Adafruit_GFX.h>  // Include core graphics library for the display
#include <Adafruit_SSD1306.h>  // Include Adafruit_SSD1306 library to drive the display


Adafruit_SSD1306 display(128, 64);  // Create display


#include <Fonts/FreeMonoBold12pt7b.h>  // Add a custom font
#include <Fonts/FreeMono9pt7b.h>  // Add a custom font

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
 
const int buzzerPin = 9 ;
const int ledPin1 = 12;
const int ledPin2 = 13;
 
int counter = 0;
int randNum = random(0,128);
int x = 64;
int potpin = 1;
int val;
int val2;
int counters = 5;
const int buttonPin = 6;
int score = 0;





void setup()  // Start of setup
{      
  pinMode(buzzerPin, OUTPUT);          

  delay(100);  // This delay is needed to let the display to initialize

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
 
  display.clearDisplay();  // Clear the buffer

  display.setTextColor(WHITE);  // Set color of the text

  display.setRotation(0);  // Set orientation. Goes from 0, 1, 2 or 3

  display.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.
                               // To override this behavior (so text will run off the right side of the display - useful for
                               // scrolling marquee effects), use setTextWrap(false). The normal wrapping behavior is restored
                               // with setTextWrap(true).

  display.dim(0);  //Set brightness (0 is maximun and 1 is a little dim)

  pinMode(buttonPin, INPUT);
}  // End of setup






void loop()  // Start of loop
{
  display.setCursor(20, 30); 
  display.setTextSize(2);
  display.println("PING PONG");
  
  display.display();
  
  display.clearDisplay();
  //Play first section
  firstSection();
 
  //Play second section
  secondSection();
 
  //Variant 1
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 350);  
  beep(a, 125);
  beep(cH, 500);
  beep(a, 375);  
  beep(cH, 125);
  beep(eH, 650);
 
  delay(500);
 
  //Repeat second section
  secondSection();
 
  //Variant 2
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 650);  
 
  delay(650);
  int buttonState;
  buttonState = digitalRead(buttonPin);
  //button control
if (buttonState == LOW) 
  {
    counters++;
    delay(150);
  }

 // val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  //val = map(val, 0, 1023, 0, 102);
 // val2 = val+20;
 // val2 = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
 // val2 = map(val2, 0, 1023, 0, 63);


//falling ball
while (1)
{ 
  display.setCursor(105, 15); 
  display.println(score);
   display.setFont(&FreeMono9pt7b);  // Set a custom font
     display.setTextSize(1); 
     display.setCursor(24, 30);  // (x,y)
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 102);
  val2 = val+20;
  counters++;
  delay(1);
  display.drawCircle(x, counters, 5, WHITE);

  display.display();
  display.clearDisplay();
  display.drawLine(val,60, val2, 60, WHITE);
  if (counters == 55 && ((val <= x)&& (val>=x-20)))
  {
    score++;
    //counters = 10;
    beep(f, 250);
    
    while(counters>=0)
    {
      val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
      val = map(val, 0, 1023, 0, 102);
      val2 = val+20;
      
      counters--;
      display.drawCircle(x, counters, 5, WHITE);
      display.drawLine(val,60, val2, 60, WHITE);
      display.display();
      display.clearDisplay();
    }
    x = random(5,120);
  }
  else if (counters == 55 && (( val > x) || (val<x-20)))
  {  
    score = 0;
    
     display.println("YOU LOSE!!!");
  
     display.setCursor(24, 50);  // (x,y)
      display.display();
     delay(500);
     firstSection();
     display.println("CUNT!");
    display.display();
     delay(5000);
     display.clearDisplay();
     display.setCursor(4, 30); 
     display.println("PLAY AGAIN?");
     display.display();
     delay(500000);
  }
    
}


  display.clearDisplay();  // Clear the display so we can refresh


  display.setFont(&FreeMono9pt7b);  // Set a custom font
  display.setTextSize(0);  // Set text size. We are using a custom font so you should always use the text size of 0


  // Print text:
 // display.setCursor(0, 10);  // (x,y)
 // display.println("TEST");  // Text or value to print
 // display.setCursor(0, 30);  // (x,y)
 // display.println("TESTIS");

  // Draw triangle:
  //display.drawTriangle(0,0,   0,63,   128,63, WHITE);  // Draw triangle. X, Y coordinates for three corner points defining the triangle, followed by a color

  // Draw filled triangle:
 // display.fillTriangle(0,63,   15,45,   30,63, WHITE);  // Draw filled triangle. X, Y coordinates for three corner points defining the triangle, followed by a color

  // Draw line:
 // display.drawLine(val,60, val2, 60, WHITE);  // Draw line (x0,y0,x1,y1,color)
  
 //display.drawCircle(64, counters, val, WHITE);  //  Draw circle (x,y,radius,color). X and Y are the coordinates for the center point
//  display.display();
  // Draw a filled circle:
 // display.fillCircle(64, 32, 30, WHITE);  // Draw filled circle (x,y,radius,color). X and Y are the coordinates for the center point
 // delay(1000);
 // display.display();
 // Draw rounded rectangle and fill:
  //display.fillRoundRect(58, 0, 18, 18, 5, WHITE);  // Draw filled rounded rectangle (x,y,width,height,color)
                                                   // It draws from the location to down-right


  
  
  
  // Draw rectangle:
 // display.drawRect(79, 0, 49, 27, WHITE);  // Draw rectangle (x,y,width,height,color)
                                           // It draws from the location to down-right
   
  display.setFont(&FreeMonoBold12pt7b);  // Set a custom font
  
  // Print variable with left alignment:
 // display.setCursor(83, 20);  // (x,y)
 // display.println(Variable1);  // Text or value to print



  

  // Draw rounded rectangle:
 // display.drawRoundRect(79, 37, 49, 27, 8, WHITE);  // Draw rounded rectangle (x,y,width,height,radius,color)
                                                    // It draws from the location to down-right

  // Print variable with right alignment:
 // display.setCursor(83, 57);  // (x,y)
 // display.println(string);  // Text or value to print




  
  display.display();  // Print everything we set previously



  

}  // End of loop

void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
 
  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }else
  {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }
 
  //Stop tone on buzzerPin
  noTone(buzzerPin);
 
  delay(50);
 
  //Increment counter
  counter++;
}
 
void firstSection()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(350);
 
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(350);
}
 
void secondSection()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
 
  delay(325);
 
  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  
 
  delay(350);
}
