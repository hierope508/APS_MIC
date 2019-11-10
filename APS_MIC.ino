/*cxvv    x

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ButtonStateChange
*/

// this constant won't change:

//Buttons
const int  buttonPin1 = 2;    // the pin that the button led1 is attached to
const int  buttonPin2 = 3;    // the pin that the button led2 is attached to
const int  buttonPin3 = 4;    // the pin that the button led3 is attached to
const int  buttonPin4 = 5;    // the pin that the button led4 is attached to

const int  buttonPin5 = 6;    // the pin that the button led3 is attached to
const int  buttonPin6 = 7;    // the pin that the button led4 is attached to

//Leds
const int ledPin1 = 8;       // the pin that the LED1 is attached to
const int ledPin2 = 9;       // the pin that the LED2 is attached to
const int ledPin3 = 10;       // the pin that the LED3 is attached to
const int ledPin4 = 11;       // the pin that the LED4 is attached to

const int lightPin1 = 12;       // the pin that the Light1 is attached to
const int lightPin2 = 13;       // the pin that the Light2 is attached to

// Variables will change:
//L1
int bt1State = 0;         // current state of the button
int nextL1State = 0;     // next state of the button
int currentL1State = 0; //current led state

//L2
int bt2State = 0;         // current state of the button
int nextL2State = 0;     // next state of the button
int currentL2State = 0; //current led state

//L3
int bt3State = 0;         // current state of the button
int nextL3State = 0;     // next state of the button
int currentL3State = 0; //current led state

//L4
int bt4State = 0;         // current state of the button
int nextL4State = 0;     // next state of the button
int currentL4State = 0; //current led state

//Light1
int bt5State = 0;         // current state of the button
int nextL5State = 0;     // next state of the button
int currentL5State = 0; //current led state

//Light2
int bt6State = 0;         // current state of the button
int nextL6State = 0;     // next state of the button
int currentL6State = 0; //current led state


void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  
  // initialize the LED as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  // initialize the Lights as an output:
  pinMode(lightPin1, OUTPUT);
  pinMode(lightPin2, OUTPUT);

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);


  
  // initialize serial commundication:
  //Serial.begin(9600);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(lightPin1, LOW);
  digitalWrite(lightPin2, LOW);
}

byte seven_seg_digits[16][7] = { 
 { 1,1,1,1,1,1,0 },  //DIGITO 0
 { 0,1,1,0,0,0,0 },  //DIGITO 1
 { 1,1,0,1,1,0,1 },  //DIGITO 2
 { 1,1,1,1,0,0,1 },  //DIGITO 3
 { 0,1,1,0,0,1,1 },  //DIGITO 4
 { 1,0,1,1,0,1,1 },  //DIGITO 5
 { 1,0,1,1,1,1,1 },  //DIGITO 6
 { 1,1,1,0,0,0,0 },  //DIGITO 7
 { 1,1,1,1,1,1,1 },  //DIGITO 8
 { 1,1,1,0,0,1,1 },  //DIGITO 9
 { 1,1,1,0,1,1,1 },  //DIGITO A
 { 0,0,1,1,1,1,1 },  //DIGITO B
 { 1,0,0,1,1,1,0 },  //DIGITO C
 { 0,1,1,1,1,0,1 },  //DIGITO D
 { 1,0,0,1,1,1,1 },  //DIGITO E
 { 1,0,0,0,1,1,1 }   //DIGITO F
};

int pinos[] = {0,1,A0,A1,A2,A3,A4};

void ligaSegmentosDisplay(byte digit){ //FUNÇÃO QUE ACIONA O DISPLAY
 int i = 0;
 for (byte contadorSegmentos = 0; contadorSegmentos < 7; ++contadorSegmentos){ //PARA "contadorSegmentos"
      //IGUAL A 0, ENQUANTO "contadorSegmentos" MENOR QUE 7, INCREMENTA "contadorSegmentos"
        digitalWrite(pinos[i], seven_seg_digits[digit][contadorSegmentos]); //PERCORRE O ARRAY E LIGA OS  
        i++;
    }
}

void loop() {
  
  // read pushbutton's input's pin:
  bt1State = digitalRead(buttonPin1);
  if(bt1State){
    delay(250);
    bt1State = digitalRead(buttonPin1);
    if(bt1State){
      Temp1();
      return;
    }
    bt1State = HIGH;
  }
  

  bt2State = digitalRead(buttonPin2);
  if(bt2State){
    delay(250);
    bt2State = digitalRead(buttonPin2);
    if(bt2State){
      Temp2();
      return;
    }
    bt2State = HIGH;
  }
  
  bt3State = digitalRead(buttonPin3);
  if(bt3State){
    delay(250);
    bt3State = digitalRead(buttonPin3);
    if(bt3State){
      Temp3();
      return;
    }
      bt3State = HIGH;
  }
  
  bt4State = digitalRead(buttonPin4);
  delay(100);
  bt5State = digitalRead(buttonPin5);
  delay(100);
  bt6State = digitalRead(buttonPin6);
  delay(100);
  
  // L1
  if (bt1State) {
      //Serial.println("Li o botão");
      if(currentL1State){
        nextL1State = 0;
        //Serial.println("Li o vai desligar");
      }else{
        nextL1State = 1 ;
        //Serial.println("Li o vai ligar");
      }
      digitalWrite(ledPin1, nextL1State);
      currentL1State = nextL1State;
      ligaSegmentosDisplay(1);
  }

  //L2
  if (bt2State) {
      //Serial.println("Li o botão");
      if(currentL2State){
        nextL2State = 0;
        //Serial.println("Li o vai desligar");
      }else{
        nextL2State = 1 ;
        //Serial.println("Li o vai ligar");
      }
      digitalWrite(ledPin2, nextL2State);
     currentL2State = nextL2State;
     ligaSegmentosDisplay(2);
  }

  //L3
  if (bt3State) {
      //Serial.println("Li o botão");
      if(currentL3State){
        nextL3State = 0;
        //Serial.println("Li o vai desligar");
      }else{
        nextL3State = 1 ;
        //Serial.println("Li o vai ligar");
      }
      digitalWrite(ledPin3, nextL3State);
      currentL3State = nextL3State;
      ligaSegmentosDisplay(3);
  }

  //L4
  if (bt4State) {
      //Serial.println("Li o botão");
      if(currentL4State){
        nextL4State = 0;
        //Serial.println("Li o vai desligar");
      }else{
        nextL4State = 1 ;
        //Serial.println("Li o vai ligar");
      }
      digitalWrite(ledPin4, nextL4State);
      currentL4State = nextL4State;
      ligaSegmentosDisplay(4);
  }

  //L5
  if (bt5State) {
      //Serial.println("Li o botão");
      if(currentL5State){
        nextL5State = 0;
        //Serial.println("Li o vai desligar");
      }else{
        nextL5State = 1 ;
        //Serial.println("Li o vai ligar");
      }
      digitalWrite(lightPin1, nextL5State);
      currentL5State = nextL5State;
      ligaSegmentosDisplay(5);
  }

  //L6
  if (bt6State) {
      //Serial.println("Li o botão");
      if(currentL6State){
        nextL6State = 0;
        //Serial.println("Li o vai desligar");
      }else{
        nextL6State = 1 ;
        //Serial.println("Li o vai ligar");
      }
      digitalWrite(lightPin2, nextL6State);
      currentL6State = nextL6State;
      ligaSegmentosDisplay(6);
  }

  //delay(120);
  //lastButtonState = buttonState;
  
}

void Temp1(){
  ligaSegmentosDisplay(10);
  //Serial.println("TEMP1");
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(lightPin1, LOW);
  digitalWrite(lightPin2, LOW);

  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(lightPin1, HIGH);
  digitalWrite(lightPin2, HIGH);
  delay(3000);  

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(lightPin1, LOW);
  digitalWrite(lightPin2, LOW);

  currentL1State = 0;
  currentL2State = 0;
  currentL3State = 0;
  currentL4State = 0;
  currentL5State = 0;
  currentL6State = 0;
}

void Temp2(){
  ligaSegmentosDisplay(11);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(lightPin1, LOW);
  digitalWrite(lightPin2, LOW);

  int i = 0;
  while (i<3){
    digitalWrite(ledPin1, HIGH);
    delay(500);
    digitalWrite(ledPin1, LOW);

    digitalWrite(ledPin2, HIGH);
    delay(500);
    digitalWrite(ledPin2, LOW);

    digitalWrite(ledPin3, HIGH);
    delay(500);
    digitalWrite(ledPin3, LOW);

    digitalWrite(ledPin4, HIGH);
    delay(500);
    digitalWrite(ledPin4, LOW);
    
    digitalWrite(lightPin1, HIGH);
    delay(500);
    digitalWrite(lightPin1, LOW);
    
    digitalWrite(lightPin2, HIGH);
    delay(500);
    digitalWrite(lightPin2, LOW);
    
    i = i + 1;
  }

  
  currentL1State = 0;
  currentL2State = 0;
  currentL3State = 0;
  currentL4State = 0;
  currentL5State = 0;
  currentL6State = 0;
 
}


void Temp3(){
  ligaSegmentosDisplay(12);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(lightPin1, LOW);
  digitalWrite(lightPin2, LOW);

  int i = 0;
  while (i<3){
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    delay(500);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    delay(500);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);

    digitalWrite(lightPin1, HIGH);
    digitalWrite(lightPin2, HIGH);
    delay(500);
    digitalWrite(lightPin1, LOW);
    digitalWrite(lightPin2, LOW);
    
    i = i + 1;
  }
 
  currentL1State = 0;
  currentL2State = 0;
  currentL3State = 0;
  currentL4State = 0;
  currentL5State = 0;
  currentL6State = 0;
}
