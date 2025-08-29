// The pinout is setup for the Arduino Pro Micro
//Note: set the board type as Arduino Leonardo when using the Pro Micro

// Data Pins
const uint8_t DAT_PIN_0 = 1;
const uint8_t DAT_PIN_1 = 0;  //Switched to match physical pinout
const uint8_t DAT_PIN_2 = 2;
const uint8_t DAT_PIN_3 = 3;
const uint8_t DAT_PIN_4 = 4;
const uint8_t DAT_PIN_5 = 5;
const uint8_t DAT_PIN_6 = 6;
const uint8_t DAT_PIN_7 = 7;

const uint8_t DATA_PINS[] = { DAT_PIN_0, DAT_PIN_1, DAT_PIN_2, DAT_PIN_3, DAT_PIN_4, DAT_PIN_5, DAT_PIN_6, DAT_PIN_7 };

//Address
const uint8_t ADDR_PIN_0 = 21;
const uint8_t ADDR_PIN_1 = 20;
const uint8_t ADDR_PIN_2 = 19;
const uint8_t ADDR_PIN_3 = 18;
const uint8_t ADDR_PIN_4 = 15;
const uint8_t ADDR_PIN_5 = 14;
const uint8_t ADDR_PIN_6 = 16;
const uint8_t ADDR_PIN_7 = 10;

const uint8_t ADDR_PINS[] = { ADDR_PIN_0, ADDR_PIN_1, ADDR_PIN_2, ADDR_PIN_3, ADDR_PIN_4, ADDR_PIN_5, ADDR_PIN_6, ADDR_PIN_7 };

//Enable Pins
const uint8_t EN_PIN = 8;       //Chip Enable, LOW to activate
const uint8_t GATE_EN_PIN = 9;  //Gate Out Enable, LOW to activate


void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Starting");

  //Setup both the data and address lines
  //Only uses 8 bit address
  for (uint8_t i = 0; i < 8; i++) {
    pinMode(DATA_PINS[i], INPUT);
    pinMode(ADDR_PINS[i], OUTPUT);
  }

  //Setup the chip and gate enable pins
  pinMode(EN_PIN, OUTPUT);
  pinMode(GATE_EN_PIN, OUTPUT);

  //Set high to disable
  digitalWrite(EN_PIN, 1);
  digitalWrite(GATE_EN_PIN, 1);
}

void printDataBin() {
  for (uint8_t i = 0; i < 8; i++) {
    Serial.print(digitalRead(DATA_PINS[7 - i]));
  }

  Serial.println('b');
}


uint8_t printDataHex() {
  uint8_t data = 0;
  for (uint8_t i = 0; i < 8; i++) {
    data = data | (digitalRead(DATA_PINS[i])) << i;
  }
  Serial.print("0x");
  Serial.println(data, HEX);
  return data;
}


void setAddress(uint16_t addr) {
  // Serial.print("addr: ");
  // Serial.print(addr);
  // Serial.print(' ');
  for (uint8_t i = 0; i < 8; i++) {
    digitalWrite(ADDR_PINS[i], (addr >> i) & 1);
    // Serial.print((addr >> i) & 1);
    // Serial.print(' ');
  }
  // Serial.println();
}


uint8_t addr = 0;

void loop() {
  setAddress(addr);
  digitalWrite(EN_PIN, 0);       //Enable Chip
  digitalWrite(GATE_EN_PIN, 0);  //Enable Gate
  delay(10);
  Serial.print("0x");
  Serial.print(addr, HEX);
  Serial.print(": ");
  uint8_t readData = printDataHex();
  if (addr != readData) {
    Serial.println("ERROR: incorrect data");
  }

  delay(10);                     //Split up the delay so the LEDs stay on
  digitalWrite(EN_PIN, 1);       //Enable Chip
  digitalWrite(GATE_EN_PIN, 1);  //Enable Gate
  delay(10);

  if (addr == 0xFF) {
    for (;;);
  }

  addr++;
}
