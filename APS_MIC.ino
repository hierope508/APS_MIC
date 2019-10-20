/*

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ButtonStateChange
*/

// this constant won't change:
//Times
const int  t1 = 15000;
const int  t2 = 30000;
const int  t3 = 60000;

//Buttons
const int  buttonPin1 = 2;    // the pin that the button led1 is attached to
const int  buttonPin2 = 3;    // the pin that the button led2 is attached to
const int  buttonPin3 = 4;    // the pin that the button led3 is attached to
const int  buttonPin4 = 5;    // the pin that the button led4 is attached to

const int  buttonPin5 = A0;    // the pin that the button led3 is attached to
const int  buttonPin6 = A1;    // the pin that the button led4 is attached to

//Leds
const int ledPin1 = 6;       // the pin that the LED1 is attached to
const int ledPin2 = 7;       // the pin that the LED2 is attached to
const int ledPin3 = 8;       // the pin that the LED3 is attached to
const int ledPin4 = 9;       // the pin that the LED4 is attached to

const int lightPin1 = 13;       // the pin that the Light1 is attached to
const int lightPin2 = 14;       // the pin that the Light2 is attached to

//Temps
const int temp1Pin = 10;       // the pin that temp1 is attached to
const int temp2Pin = 11;       // the pin that temp2 is attached to
const int temp3Pin = 12;       // the pin that temp3 is attached to


// Variables will change:
//L1
int bt1State = 0;         // current state of the button
int nextL1State = 0;     // next state of the button
int currentL1State = 0; //current led state
long L1TurnedOnAt = 0;
int L1currentTime = 0;

//L2
int bt2State = 0;         // current state of the button
int nextL2State = 0;     // next state of the button
int currentL2State = 0; //current led state
long L2TurnedOnAt = 0;
int L2currentTime = 0;

//L3
int bt3State = 0;         // current state of the button
int nextL3State = 0;     // next state of the button
int currentL3State = 0; //current led state
long L3TurnedOnAt = 0;
int L3currentTime = 0;

//L4
int bt4State = 0;         // current state of the button
int nextL4State = 0;     // next state of the button
int currentL4State = 0; //current led state
long L4TurnedOnAt = 0;
int L4currentTime = 0;

//Light1
int bt5State = 0;         // current state of the button
int nextL5State = 0;     // next state of the button
int currentL5State = 0; //current led state
long L5TurnedOnAt = 0;
int L5currentTime = 0;

//Light2
int bt6State = 0;         // current state of the button
int nextL6State = 0;     // next state of the button
int currentL6State = 0; //current led state
long L6TurnedOnAt = 0;
int L6currentTime = 0;

int btTemp1 = 0;
int btTemp2 = 0;
int btTemp3 = 0;

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);

  // initialize the temp as an input:
  pinMode(temp1Pin, INPUT);
  pinMode(temp2Pin, INPUT);
  pinMode(temp3Pin, INPUT);
  
  // initialize the LED as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  // initialize the Lights as an output:
  pinMode(lightPin1, OUTPUT);
  pinMode(lightPin2, OUTPUT);
  
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read pushbutton's input's pin:
  bt1State = digitalRead(buttonPin1);
  delay(50);
  btTemp1 = digitalRead(temp1Pin);
  btTemp2 = digitalRead(temp2Pin);
  btTemp3 = digitalRead(temp3Pin);

  bt2State = digitalRead(buttonPin2);
  delay(50);
  btTemp1 = digitalRead(temp1Pin);
  btTemp2 = digitalRead(temp2Pin);
  btTemp3 = digitalRead(temp3Pin);

  bt3State = digitalRead(buttonPin3);
  delay(50);
  btTemp1 = digitalRead(temp1Pin);
  btTemp2 = digitalRead(temp2Pin);
  btTemp3 = digitalRead(temp3Pin);

  bt4State = digitalRead(buttonPin4);
  delay(50);
  btTemp1 = digitalRead(temp1Pin);
  btTemp2 = digitalRead(temp2Pin);
  btTemp3 = digitalRead(temp3Pin);

  bt5State = digitalRead(buttonPin5);
  delay(50);
  btTemp1 = digitalRead(temp1Pin);
  btTemp2 = digitalRead(temp2Pin);
  btTemp3 = digitalRead(temp3Pin);

  bt6State = digitalRead(buttonPin6);
  delay(50);
  btTemp1 = digitalRead(temp1Pin);
  btTemp2 = digitalRead(temp2Pin);
  btTemp3 = digitalRead(temp3Pin);
  
  // L1
  if (bt1State) {
      Serial.println("Li o botão");
      if(currentL1State){
        nextL1State = 0;
        Serial.println("Li o vai desligar");
      }else{
        nextL1State = 1 ;
        Serial.println("Li o vai ligar");
      }
      digitalWrite(ledPin1, nextL1State);
      
      if(btTemp1){
        L1TurnedOnAt = millis();
        L1currentTime = t1;
      }

      if(btTemp2){
        L1TurnedOnAt = millis();
        L1currentTime = t2;
      }

      if(btTemp3){
        L1TurnedOnAt = millis();
        L1currentTime = t3;
      }
      
      currentL1State = nextL1State;
  }

  //L2
  if (bt2State) {
      Serial.println("Li o botão");
      if(currentL2State){
        nextL2State = 0;
        Serial.println("Li o vai desligar");
      }else{
        nextL2State = 1 ;
        Serial.println("Li o vai ligar");
      }
      digitalWrite(ledPin2, nextL2State);
      
      if(btTemp1){
        L2TurnedOnAt = millis();
        L2currentTime = t1;
      }

      if(btTemp2){
        L2TurnedOnAt = millis();
        L2currentTime = t2;
      }

      if(btTemp3){
        L2TurnedOnAt = millis();
        L2currentTime = t3;
      }
      
      currentL2State = nextL2State;
  }

  //L3
  if (bt3State) {
      Serial.println("Li o botão");
      if(currentL3State){
        nextL3State = 0;
        Serial.println("Li o vai desligar");
      }else{
        nextL3State = 1 ;
        Serial.println("Li o vai ligar");
      }
      digitalWrite(ledPin3, nextL3State);
      
      if(btTemp1){
        L3TurnedOnAt = millis();
        L3currentTime = t1;
      }

      if(btTemp2){
        L3TurnedOnAt = millis();
        L3currentTime = t2;
      }

      if(btTemp3){
        L3TurnedOnAt = millis();
        L3currentTime = t3;
      }
      
      currentL3State = nextL3State;
  }

  //L4
  if (bt4State) {
      Serial.println("Li o botão");
      if(currentL4State){
        nextL4State = 0;
        Serial.println("Li o vai desligar");
      }else{
        nextL4State = 1 ;
        Serial.println("Li o vai ligar");
      }
      digitalWrite(ledPin4, nextL4State);
      
      if(btTemp1){
        L4TurnedOnAt = millis();
        L4currentTime = t1;
      }

      if(btTemp2){
        L4TurnedOnAt = millis();
        L4currentTime = t2;
      }

      if(btTemp3){
        L4TurnedOnAt = millis();
        L4currentTime = t3;
      }
      
      currentL4State = nextL4State;
  }

  //L5
  if (bt5State) {
      Serial.println("Li o botão");
      if(currentL5State){
        nextL5State = 0;
        Serial.println("Li o vai desligar");
      }else{
        nextL5State = 1 ;
        Serial.println("Li o vai ligar");
      }
      digitalWrite(lightPin1, nextL5State);
      
      if(btTemp1){
        L5TurnedOnAt = millis();
        L5currentTime = t1;
      }

      if(btTemp2){
        L5TurnedOnAt = millis();
        L5currentTime = t2;
      }

      if(btTemp3){
        L5TurnedOnAt = millis();
        L5currentTime = t3;
      }
      
      currentL5State = nextL5State;
  }

  //L6
  if (bt6State) {
      Serial.println("Li o botão");
      if(currentL6State){
        nextL6State = 0;
        Serial.println("Li o vai desligar");
      }else{
        nextL6State = 1 ;
        Serial.println("Li o vai ligar");
      }
      digitalWrite(lightPin2, nextL6State);
      
      if(btTemp1){
        L6TurnedOnAt = millis();
        L6currentTime = t1;
      }

      if(btTemp2){
        L6TurnedOnAt = millis();
        L6currentTime = t2;
      }

      if(btTemp3){
        L6TurnedOnAt = millis();
        L6currentTime = t3;
      }
      
      currentL6State = nextL6State;
  }


  checkTemp(ledPin1,&L1currentTime, &L1TurnedOnAt, currentL1State);
  checkTemp(ledPin2,&L2currentTime, &L2TurnedOnAt, currentL2State);
  checkTemp(ledPin3,&L3currentTime, &L3TurnedOnAt, currentL3State);
  checkTemp(ledPin4,&L4currentTime, &L4TurnedOnAt, currentL4State);
  checkTemp(lightPin1,&L5currentTime, &L5TurnedOnAt, currentL5State);
  checkTemp(lightPin2,&L6currentTime, &L6TurnedOnAt, currentL6State);
  
  //delay(120);
  //lastButtonState = buttonState;
  
}

void checkTemp(int pin, int *time, long *ledTurnedOnAt, int state){
  
  //Serial.println((*time));
  
  if((*time)>0){
    if((millis() -((*ledTurnedOnAt)) ) > (*time)){
      digitalWrite(pin, !state);
      *time = 0;
      *ledTurnedOnAt= 0;

      switch(pin){
        case 6:
          currentL1State = 0;
          break;
        default:
          break; 
      }
    }
  }
}
