#define PEDAL_A 2
#define PEDAL_B 3
#define PEDAL_C 4
#define PEDAL_D 5

int pinStates[4];

void setup() {
  Serial.begin(115200);
  
  pinMode(PEDAL_A, INPUT_PULLUP);
  pinMode(PEDAL_B, INPUT_PULLUP);
  pinMode(PEDAL_C, INPUT_PULLUP);
  pinMode(PEDAL_D, INPUT_PULLUP);
  
  pinStates[0] = pinStates[1] = pinStates[2] = pinStates[3] = 1;
}

void checkPin(int pin, int idx)
{
  int state = digitalRead(pin);
  if( state != pinStates[idx] )
  {
    pinStates[idx] = state;
    if( state == 1 ) return;
    
    Serial.print("PIN_");
    Serial.println(idx);
  }
}

void loop() {
  checkPin(PEDAL_A, 0);
  checkPin(PEDAL_B, 1);
  checkPin(PEDAL_C, 2);
  checkPin(PEDAL_D, 3);
  
  delay(20);
}

