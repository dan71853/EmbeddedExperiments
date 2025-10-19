

#include <Adafruit_NeoPixel.h>

#define PIN 13

#define NUMPIXELS 4  // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 1000  // Time (in milliseconds) to pause between pixels

const uint8_t RED_BRT = 255;
const uint8_t GREEN_BRT = 255;
const uint8_t BLUE_BRT = 255;

uint32_t colourArray[4];

const uint8_t BUTTON_MODE_PIN = 23;
const uint8_t BUTTON_BRT_PIN = 22;

uint32_t debounceTimer;  //Will share the debounce timer
const uint16_t DEBOUNCE_TIME = 300;

volatile uint8_t brightnessIndex = 0;
const uint8_t brightnessArray[] = { 5, 50, 128, 200, 255 };

enum Modes {
  NO_DATA,
  LEVEL_0,
  LEVEL_1,
  LEVEL_2,
  LEVEL_3,
  OFF,
  AUTO
};

enum Modes currentMode;
uint8_t autoModeIndex = 0;

void IRAM_ATTR modeButtonISR() {
  if (millis() - debounceTimer > DEBOUNCE_TIME) {
    Serial.printf("MODE: %d, BRT: %d\n", digitalRead(BUTTON_MODE_PIN), digitalRead(BUTTON_BRT_PIN));
    debounceTimer = millis();
    currentMode = (Modes)((currentMode + 1) % 7);
    Serial.println(currentMode);
  }
}

void IRAM_ATTR brtButtonISR() {
  if (millis() - debounceTimer > DEBOUNCE_TIME) {

    brightnessIndex = (brightnessIndex + 1) % sizeof(brightnessArray);

    // Serial.println(brightnessArray[brightnessIndex]);
    pixels.setBrightness(brightnessArray[brightnessIndex]);
    debounceTimer = millis();
  }
}




void setup() {
  Serial.begin(115200);

  pixels.begin();
  pixels.clear();
  pixels.setBrightness(10);

  pinMode(BUTTON_MODE_PIN, INPUT_PULLUP);
  pinMode(BUTTON_BRT_PIN, INPUT_PULLUP);

  attachInterrupt(BUTTON_MODE_PIN, modeButtonISR, FALLING);
  attachInterrupt(BUTTON_BRT_PIN, brtButtonISR, FALLING);
  debounceTimer = millis();
  
  currentMode=AUTO;
}



void setLEDs() {
  for (int i = 0; i < 4; i++) {
    pixels.setPixelColor(i, colourArray[i]);
  }
  pixels.show();
}


void setColour(Modes colourMode) {

  switch (colourMode) {
    case NO_DATA:
      colourArray[0] = 0;
      colourArray[1] = 0;
      colourArray[2] = 0;
      colourArray[3] = pixels.Color(RED_BRT, 0, 0);
      break;
    case LEVEL_0:
      colourArray[0] = 0;
      colourArray[1] = 0;
      colourArray[2] = 0;
      colourArray[3] = pixels.Color(0, GREEN_BRT, 0);
      break;
    case LEVEL_1:
      colourArray[0] = pixels.Color(0, 0, BLUE_BRT);
      colourArray[1] = 0;
      colourArray[2] = 0;
      colourArray[3] = pixels.Color(0, GREEN_BRT, 0);
      break;
    case LEVEL_2:
      colourArray[0] = pixels.Color(0, 0, BLUE_BRT);
      colourArray[1] = pixels.Color(0, 0, BLUE_BRT);
      colourArray[2] = 0;
      colourArray[3] = pixels.Color(0, GREEN_BRT, 0);
      break;
    case LEVEL_3:
      colourArray[0] = pixels.Color(0, 0, BLUE_BRT);
      colourArray[1] = pixels.Color(0, 0, BLUE_BRT);
      colourArray[2] = pixels.Color(0, 0, BLUE_BRT);
      colourArray[3] = pixels.Color(0, GREEN_BRT, 0);
      break;
    case OFF:
      colourArray[0] = 0;
      colourArray[1] = 0;
      colourArray[2] = 0;
      colourArray[3] = 0;
      break;

    default:
      colourArray[0] = pixels.Color(RED_BRT, 0, 0);
      ;
      colourArray[1] = pixels.Color(RED_BRT, 0, 0);
      ;
      colourArray[2] = pixels.Color(RED_BRT, 0, 0);
      ;
      colourArray[3] = pixels.Color(RED_BRT, 0, 0);
      ;
      break;
  }
  setLEDs();
}
void loop() {


  if (currentMode == AUTO) {
    autoModeIndex = (autoModeIndex + 1) % 5;
    setColour((Modes)autoModeIndex);
    delay(DELAYVAL);
  } else {
    setColour(currentMode);
    delay(DELAYVAL / 3);
  }
}
