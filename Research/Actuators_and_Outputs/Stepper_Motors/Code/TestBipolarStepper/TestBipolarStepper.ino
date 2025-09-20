const uint8_t pinA1 = 18;
const uint8_t pinA2 = 19;
const uint8_t pinB1 = 20;
const uint8_t pinB2 = 21;

const bool bitSequence[] = { 1, 1, 0, 0 };
uint8_t stepIndex = 0;

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Starting");

  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
}

void loop() {
  Serial.println(stepIndex);

  bool stateA1 = bitSequence[stepIndex];
  bool stateA2 = !stateA1;
  bool stateB1 = bitSequence[(stepIndex+1)%4];
  bool stateB2 = !stateB1;
  
  digitalWrite(pinA1, stateA1);
  digitalWrite(pinA2, stateA2);
  digitalWrite(pinB1, stateB1);
  digitalWrite(pinB2, stateB2);


  Serial.printf("%d %d %d %d\n",stateA1, stateA2, stateB1, stateB2 );

  stepIndex++;
  stepIndex = stepIndex++%4;


  delay(50); //Adjust to change speed, fastest speed is about 5ms per step
}
