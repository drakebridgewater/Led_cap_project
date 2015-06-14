// By Drake Bridgewater

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

//pinout for the led array
#define CLK 8
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

#define BYTE_LENGTH 10

/* Global Variables */

int ledPin = 13; //LED connected to pin 13 on Arduino UNO.
  
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup() {
  pinMode(ledPin, OUTPUT);
  matrix.begin();
  start_sequence();
  matrix.setTextWrap(false);
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
  delay(500);
  clear_display();
}

void clear_display() {
  // fill the screen with 'black'
  matrix.fillScreen(matrix.Color333(0, 0, 0));
}

void write_text(String text, int r, int g, int b) {
  matrix.setTextColor(matrix.Color333(r, g, b));
  matrix.println(text);
}

void loop() {
  matrix.setTextSize(1);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setTextColor(matrix.Color333(7,0,0)); 
  matrix.setCursor(7, 4); 
  matrix.println("OSU");
  matrix.setCursor(4, 14); 
  matrix.println("EECS");
  delay(2100);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  
  
  matrix.setTextColor(matrix.Color333(0,7,0)); 
  matrix.setCursor(1, 0); 
  matrix.setTextSize(1);
  matrix.println(" Thx");
  matrix.println(" MOM");
  matrix.println("  &");
  matrix.println(" DAD");
  delay(2000);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  

  
  
  matrix.setTextSize(4);
  matrix.setCursor(5, 0); 
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setTextColor(matrix.Color333(7,1,1)); 
  matrix.println("O");
  delay(500);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setTextColor(matrix.Color333(7,1,1)); 
  matrix.setCursor(5, 0); 
  matrix.println("S");
  delay(500);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setTextColor(matrix.Color333(7,1,1)); 
  matrix.setCursor(5, 0); 
  matrix.println("U");
  delay(500);
  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(5, 0); 
  start_sequence();
  matrix.fillScreen(matrix.Color333(0, 0, 0));

}
