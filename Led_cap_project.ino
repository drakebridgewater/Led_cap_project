// By Drake Bridgewater

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include <NewSoftSerial.h>

//pinout for the led array
#define CLK 8  
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

/* Global Variables */
byte byteRead; //Used to receive data from computer.
int ledPin=13; //LED connected to pin 13 on Arduino UNO.

NewSoftSerial mySerial(0, 1);
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup() {
  pinMode(ledPin, OUTPUT);      //Set pin 13 (ledPin) as an output 
  mySerial.begin(9600);
  matrix.begin();
  start_sequence();
}

void loop() {
 /* check if data has been sent from the computer: */
 write_text("test", 3,3,3);
 if (mySerial.available()) {
   /* read the most recent byte */
   byteRead = mySerial.read();
 }
}

void start_sequence() {
  matrix.fillRect(0, 0, 32, 32, matrix.Color333(7, 0, 0));
  delay(500);
  clear_display();
  matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 7, 0));
  delay(500);
  clear_display();
  matrix.fillRect(0, 0, 32, 32, matrix.Color333(0, 0, 7));
  delay(500);
  clear_display();
}

void clear_display(){
 // fill the screen with 'black'
 matrix.fillScreen(matrix.Color333(0, 0, 0)); 
}

void write_text(char text[], int r, int g, int b) {
  matrix.setTextColor(matrix.Color333(r, g, b));
  matrix.println(text);
}
