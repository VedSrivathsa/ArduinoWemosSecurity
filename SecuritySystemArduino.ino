#include <LiquidCrystal.h>
#include <Keypad.h>


#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int redPin = 10;
int greenPin = 11;



char* code = "4321";
int digit = 0;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8,9};


Keypad mainKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  passwordLocked(true);
}

void loop() {
  char pressedKey = mainKeypad.getKey();
  display.setCursor(0,0);
  display.print("Enter Password");
  Serial.println("Enter Password");

  if(pressedKey == '*' || pressedKey == 'A' || pressedKey == 'B' ||
     pressedKey == 'C' || pressedKey == 'D' || pressedKey == '#')
  { 
    digit = 0;
    passwordLocked(true);
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("Password Incorrect");
    Serial.println("Password Incorret");
    delay(1000);
    display.clearDisplay();
  }

  if(pressedKey == code[digit])
  {
    digit++;
  }

  if(digit == 4)
  {
    passwordLocked(false);
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("Correct");
    Serial.println("Correct");
    delay(8000);
    display.clearDisplay();
  }

  delay(100);

}

void passwordLocked(int locked)
{
  if(locked)
  {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
  }

  else
  {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
  }
}
  

  
       
