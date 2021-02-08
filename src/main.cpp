#include <Arduino.h>
#include <ezButton.h>
#include "MorsDuino.h"

// MorsDuino led(13, 1); // Make new instance of MarsDuinoLed class with name 'led'
// ezButton button(8);  // create ezButton object that attach to pin 7;
// ezButton button2(9);  // create ezButton object that attach to pin 7;
// bool s = false;
// void setup() {
//   Serial.begin(9600); // Start serial on 9600 baud rate
//   Serial.println("Morse Code sender");
//   Serial.println("--------------");
//   button.setDebounceTime(50);
//   button2.setDebounceTime(50);
//   pinMode(13, OUTPUT);
//   digitalWrite(13, HIGH);
//   for (int i = 0;  ; i++)
//   {
//     led.displayString("hello world");
//   }

//   digitalWrite(13, HIGH);

// }

// void loop() {
//   //  while(!Serial.available()); // Wait until serial has some data
//   //  char data = Serial.read(); // Read data
//   //  led.displayChar(data); // Draw morse on 13 LED
//   button.loop(); // MUST call the loop() function first
//   button2.loop(); // MUST call the loop() function first

//   if (button.isPressed()) {
//     //    Serial.println("The button is pressed");
//     led.displayString("hello world");

//   }
//   if (button2.isPressed()) {
//     // Serial.println("The button is pressed");
//     s = !s;
//     if (s) {
//       digitalWrite(13, HIGH);
//     } else {
//       digitalWrite(13, LOW);
//     }
//     //led.displayChar("sos");
//   }
//   //  if(button.isReleased())
//   //    Serial.println("The button is released");
// }

const char *MorseTable[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    // space, !, ", #, $, %, &, '
    NULL,
    "-.-.--",
    ".-..-.",
    NULL,
    NULL,
    NULL,
    NULL,
    ".----.",
    // ( ) * + , - . /
    "-.--.",
    "-.--.-",
    NULL,
    ".-.-.",
    "--..--",
    "-....-",
    ".-.-.-",
    "-..-.",
    // 0 1 2 3 4 5 6 7
    "-----",
    ".----",
    "..---",
    "...--",
    "....-",
    ".....",
    "-....",
    "--...",
    // 8 9 : ; < = > ?
    "---..",
    "----.",
    "---...",
    "-.-.-.",
    NULL,
    "-...-",
    NULL,
    "..--..",
    // @ A B C D E F G
    ".--.-.",
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    // H I J K L M N O
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    // P Q R S T U V W
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    // X Y Z [ \ ] ^ _
    "-..-",
    "-.--",
    "--..",
    NULL,
    NULL,
    NULL,
    NULL,
    "..--.-",
    // ' a b c d e f g
    NULL,
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    // h i j k l m n o
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    // p q r s t u v w
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    // x y z { | } ~ DEL
    "-..-",
    "-.--",
    "--..",
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};
void dash();
void dot();
void flashDashDot(const char *);
void displayString(String);

int dotLength = 100;
int dashLength = dotLength * 3;

void setup()
{
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
void loop()
{

  displayString(F("_hello_world_"));

  delay(dotLength * 2);
}

void displayString(String text)
{
  for (int i = 0; i <= text.length(); i++)
  {

    flashDashDot(MorseTable[(char)text[i]]);
    delay(dotLength * 2);
  }
  delay(dotLength * 2);
}
void flashDashDot(const char *morseCode)
{
  int i = 0;
  while (morseCode[i] != 0)
  {
    if (morseCode[i] == '.')
    {
      dot();
    }
    else if (morseCode[i] == '-')
    {
      dash();
    }
    i++;
  }
}
void dot()
{
  digitalWrite(13, HIGH);
  delay(dotLength);
  digitalWrite(13, LOW);
  delay(dotLength);
}
void dash()
{
  digitalWrite(13, HIGH);
  delay(dashLength);
  digitalWrite(13, LOW);
  delay(dotLength);
}