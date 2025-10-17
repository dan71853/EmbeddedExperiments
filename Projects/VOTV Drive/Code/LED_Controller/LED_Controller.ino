

#include <Adafruit_NeoPixel.h>

#define PIN 13

#define NUMPIXELS 4  // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 1000  // Time (in milliseconds) to pause between pixels

const uint8_t RED_BRT = 10;
const uint8_t GREEN_BRT = 10;
const uint8_t BLUE_BRT = 10;

uint32_t colourArray[4];

void setup() {


  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(255);
}

void setLEDs() {
  for (int i = 0; i < 4; i++) {
    pixels.setPixelColor(i, colourArray[i]);
  }
  pixels.show();
}

void loop() {
  pixels.clear();  // Set all pixel colors to 'off'


  colourArray[0] = 0;
  colourArray[1] = 0;
  colourArray[2] = 0;
  colourArray[3] = pixels.Color(RED_BRT, 0, 0);
  setLEDs();
  delay(DELAYVAL);

  colourArray[0] = 0;
  colourArray[1] = 0;
  colourArray[2] = 0;
  colourArray[3] = pixels.Color(0, GREEN_BRT, 0);
  setLEDs();
  delay(DELAYVAL);

  colourArray[0] = pixels.Color(0, 0, BLUE_BRT);
  colourArray[1] = 0;
  colourArray[2] = 0;
  colourArray[3] = pixels.Color(0, GREEN_BRT, 0);
  setLEDs();
  delay(DELAYVAL);

  colourArray[0] = pixels.Color(0, 0, BLUE_BRT);
  colourArray[1] = pixels.Color(0, 0, BLUE_BRT);
  colourArray[2] = 0;
  colourArray[3] = pixels.Color(0, GREEN_BRT, 0);
  setLEDs();
  delay(DELAYVAL);

  colourArray[0] = pixels.Color(0, 0, BLUE_BRT);
  colourArray[1] = pixels.Color(0, 0, BLUE_BRT);
  colourArray[2] = pixels.Color(0, 0, BLUE_BRT);
  colourArray[3] = pixels.Color(0, GREEN_BRT, 0);
  setLEDs();
  delay(DELAYVAL);
}
