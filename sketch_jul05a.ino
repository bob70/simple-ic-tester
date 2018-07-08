/*
 * IC Tester Simple
 * 
 * By Prof. Shiburaj Pappu
 * Date: 7/5/2018
 * Department: Computer Engg.
 * 
 * Pin Mappings                 
 * ZIF  ---->   Nano            LED   --->    Nano          Switch    --->    Nano
 * 1    ---->   D9              RED   --->    D1            SW1       --->    A4
 * 2    ---->   D8              Green --->    D0            SW2       --->    A5
 * 3    ---->   D7                                          SW3       --->    A6
 * 4    ---->   D6                                          SW4       --->    A7
 * 5    ---->   D5      
 * 6    ---->   D4              INPUT   ---->   Gates
 * 7    ---->   D3              0001    ---->   7404 NOT
 * 8    ---->   D2              0010    ---->   7408 AND
 * 9    ---->   D13             0011    ---->   7432 OR
 * 10   ---->   A0              0100    ---->   7400 NAND
 * 11   ---->   A1              0101    ---->   7402 NOR
 * 12   ---->   A2              0110    ---->   7486 XOR
 * 13   ---->   A3              0111    ---->   74LS138 3:8 Decoder 
 * 14   ---->   D12             1000    ---->   74LS47  BCD to 7 Seg Decode
 * 15   ---->   D11             1001    ---->   74151 1:8 MUX
 * 16   ---->   D10             1010    ---->   74LS73  JK FF
 * 
 * 
 */
boolean printSerial = false;

void setup() {
  
  // put your setup code here, to run once:

  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  
  if(printSerial){
    Serial.begin(9600);
    Serial.println("IC TESTER Simple By ... Prof. Shiburaj");  
  }else{
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW); 
    delay(5000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean SW1 = digitalRead(A4);
  boolean SW2 = digitalRead(A5);
  boolean SW3 = analogRead(A6);
  boolean SW4 = analogRead(A7);
  
  digitalWrite(0, LOW);
    digitalWrite(1, LOW); 
  if(SW1==LOW && SW2==LOW && SW3==LOW && SW4==HIGH){
    if(printSerial){
      Serial.println("IC 7404 Not Gate");  
    }
    
    //Set VCC & GND
    powerSequence(1);
   
    if(notGate(9,8) && notGate(7,6) && notGate(5,4) && notGate(11,12) && notGate(A3,A2) && notGate(A1,A0)){
      icIsGood();
    }else{
      icIsBad();
    }
    
  }else if(SW1==LOW && SW2==LOW && SW3==HIGH && SW4==LOW){
    if(printSerial){
      Serial.println("IC 7408 AND Gate");
    }
    
    //Set VCC & GND
    powerSequence(1);
   
    if(andGate(9,8,7) && andGate(6,5,4) && andGate(11,12,A3) && andGate(A2,A1,A0)){
      icIsGood();
    }else{
      icIsBad();
    }
  }else if(SW1==LOW && SW2==LOW && SW3==HIGH && SW4==HIGH){
    if(printSerial){
      Serial.println("IC 7432 OR Gate");
    }
    
    //Set VCC & GND
    powerSequence(1);
   
    if(orGate(9,8,7) && orGate(6,5,4) && orGate(11,12,A3) && orGate(A2,A1,A0)){
      icIsGood();
    }else{
      icIsBad();
    }
  }else if(SW1==LOW && SW2==HIGH && SW3==LOW && SW4==LOW){
    if(printSerial){
      Serial.println("IC 7400 NAND Gate");
    }
    
    //Set VCC & GND
    powerSequence(1);
   
    if(nandGate(9,8,7) && nandGate(6,5,4) && nandGate(11,12,A3) && nandGate(A2,A1,A0)){
      icIsGood();
    }else{
      icIsBad();
    }
  }else if(SW1==LOW && SW2==HIGH && SW3==LOW && SW4==HIGH){
    if(printSerial){
      Serial.println("IC 7402 NOR Gate");
    }
    
    //Set VCC & GND
    powerSequence(1);
   
    if(norGate(7,8,9) && norGate(4,5,6) && norGate(A3,12,11) && norGate(A0,A1,A2)){
      icIsGood();
    }else{
      icIsBad();
    }
  }else if(SW1==LOW && SW2==HIGH && SW3==HIGH && SW4==LOW){
    if(printSerial){
      Serial.println("IC 7486 XOR Gate");
    }
    
    //Set VCC & GND
    powerSequence(1);
   
    if(xorGate(9,8,7) && xorGate(6,5,4) && xorGate(11,12,A3) && xorGate(A2,A1,A0)){
      icIsGood();
    }else{
      icIsBad();
    }
  }else if(SW1==LOW && SW2==HIGH && SW3==HIGH && SW4==HIGH){
    if(printSerial){
      Serial.println("IC 74LS138 3:8 Decoder");
    }
    
    //Set VCC & GND
    powerSequence(2);
   
    if(IC74LS138()){
      icIsGood();
    }else{
      icIsBad();
    }
  }else if(SW1==HIGH && SW2==LOW && SW3==LOW && SW4==LOW){
    if(printSerial){
      Serial.println("IC 74LS47 BCD to 7 Segment Decoder");
    }
    
    //Set VCC & GND
    powerSequence(2);
   
    if(IC74LS47()){
      icIsGood();
    }else{
      icIsBad();
    }
  }else if(SW1==HIGH && SW2==LOW && SW3==LOW && SW4==HIGH){
    if(printSerial){
      Serial.println("IC 74151 1:8 MUX");
    }
    
    //Set VCC & GND
    powerSequence(2);
   
    if(IC74151()){
      icIsGood();
    }else{
      icIsBad();
    }
  }else if(SW1==HIGH && SW2==LOW && SW3==HIGH && SW4==LOW){
    if(printSerial){
      Serial.println("IC 74LS73 JK FF");
    }
    
    //Set VCC & GND
    powerSequence(3);
   
    if(IC74LS73()){
      icIsGood();
    }else{
      icIsBad();
    }
  }else{
    if(printSerial){
      Serial.println("No Input Selected");
    }else{
      digitalWrite(0, HIGH);
      digitalWrite(1, HIGH); 
    }
  }
  
  if(printSerial){
    Serial.println("Done Checking IC");
  }
  delay(1000);
}


void icIsGood(){
  if(printSerial){
    Serial.println("IC Good");
  }else{
    digitalWrite(0,LOW);
    digitalWrite(1,HIGH); 
  }
}

void icIsBad(){
  if(printSerial){
    Serial.println("IC Bad");
  }else{
    digitalWrite(0,HIGH);
    digitalWrite(1,LOW); 
  }
}

void powerSequence(int n){
  if(n=1){
    pinMode(10, OUTPUT);
    pinMode(3, OUTPUT);
    digitalWrite(10,HIGH); // Set VCC
    digitalWrite(3,LOW); // Set GND
  }else if(n=2){
    pinMode(10, OUTPUT);
    pinMode(2, OUTPUT);
    digitalWrite(10,HIGH); // Set VCC
    digitalWrite(2,LOW); // Set GND
  }else if(n=3){
    pinMode(6, OUTPUT);
    pinMode(A3, OUTPUT);
    digitalWrite(6,HIGH); // Set VCC
    digitalWrite(A3,LOW); // Set GND
  }
  delay(100);
}

boolean oneInputAndOneOutputCheck(int pin1, int pin2, boolean test1){
  digitalWrite(pin1, test1);
  delay(50);
  return digitalRead(pin2);
}

boolean twoInputAndOneOutputCheck(int pin1, int pin2, int pin3, boolean test1, boolean test2){
    digitalWrite(pin1, test1);
    digitalWrite(pin2, test2);
    delay(50);
    return digitalRead(pin3);
}


boolean notGate(int pin1, int pin2){
    // Set PIN modes
    pinMode(pin1, OUTPUT);
    pinMode(pin2, INPUT);
    
    if(oneInputAndOneOutputCheck(pin1,pin2,HIGH)==LOW && 
        oneInputAndOneOutputCheck(pin1,pin2,LOW) == HIGH){
      return true;
    }
    return false;
}

boolean andGate(int pin1, int pin2, int pin3){
    // Set PIN modes
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, INPUT);

    if(twoInputAndOneOutputCheck(pin1,pin2,pin3,LOW,LOW)==LOW && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,LOW,HIGH)== LOW && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,HIGH,LOW)== LOW && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,HIGH,HIGH)== HIGH){
      return true;
    }
    return false;
}

boolean orGate(int pin1, int pin2, int pin3){
    // Set PIN modes
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, INPUT);

    if(twoInputAndOneOutputCheck(pin1,pin2,pin3,LOW,LOW)==LOW && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,LOW,HIGH)== HIGH && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,HIGH,LOW)== HIGH && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,HIGH,HIGH)== HIGH){
      return true;
    }
    return false;
}

boolean nandGate(int pin1, int pin2, int pin3){
    // Set PIN modes
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, INPUT);

    if(twoInputAndOneOutputCheck(pin1,pin2,pin3,LOW,LOW)==HIGH && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,LOW,HIGH)== HIGH && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,HIGH,LOW)== HIGH && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,HIGH,HIGH)== LOW){
      return true;
    }
    return false;
}

boolean norGate(int pin1, int pin2, int pin3){
    // Set PIN modes
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, INPUT);

    if(twoInputAndOneOutputCheck(pin1,pin2,pin3,LOW,LOW)==HIGH && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,LOW,HIGH)== LOW && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,HIGH,LOW)== LOW && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,HIGH,HIGH)== LOW){
      return true;
    }
    return false;
}


boolean xorGate(int pin1, int pin2, int pin3){
    // Set PIN modes
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, INPUT);

    if(twoInputAndOneOutputCheck(pin1,pin2,pin3,LOW,LOW)==LOW && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,LOW,HIGH)== HIGH && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,HIGH,LOW)== HIGH && 
        twoInputAndOneOutputCheck(pin1,pin2,pin3,HIGH,HIGH)== LOW){
      return true;
    }
    return false;
}

boolean IC74LS138(){
    // Set PIN modes
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    
    pinMode(11, INPUT);
    pinMode(12, INPUT);
    pinMode(A3, INPUT);
    pinMode(A2, INPUT);
    pinMode(A1, INPUT);
    pinMode(A0, INPUT);
    pinMode(13, INPUT);
    pinMode(7, INPUT);

    // Set Flags
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);

    if(
        fun3to8DecoderCheck(7,8,9,11,LOW,LOW,LOW)==LOW &&
        fun3to8DecoderCheck(7,8,9,12,LOW,LOW,HIGH)==LOW &&
        fun3to8DecoderCheck(7,8,9,A3,LOW,HIGH,LOW)==LOW &&
        fun3to8DecoderCheck(7,8,9,A2,LOW,HIGH,HIGH)==LOW &&
        fun3to8DecoderCheck(7,8,9,A1,HIGH,LOW,LOW)==LOW &&
        fun3to8DecoderCheck(7,8,9,A0,HIGH,LOW,HIGH)==LOW &&
        fun3to8DecoderCheck(7,8,9,13,HIGH,HIGH,LOW)==LOW &&
        fun3to8DecoderCheck(7,8,9,3,HIGH,HIGH,HIGH)==LOW
    ){
      // Set Flags
      digitalWrite(6, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW);
      return true;
    }
    return false;
}

boolean fun3to8DecoderCheck(int A, int B, int C,int Y,boolean s1,boolean s2,boolean s3){
    digitalWrite(A, s1);
    digitalWrite(B, s2);
    digitalWrite(C, s3);
    delay(100);
    /*Serial.println(Y);
    Serial.println(digitalRead(Y));
    delay(2000);*/
    return digitalRead(Y);
}


boolean IC74LS47(){
    // Set PIN MODES
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(3, OUTPUT);
    
    pinMode(11, INPUT);
    pinMode(12, INPUT);
    pinMode(A3, INPUT);
    pinMode(A2, INPUT);
    pinMode(A1, INPUT);
    pinMode(A0, INPUT);
    pinMode(13, INPUT);

    // Set Flags
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);

    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(3, LOW);
    delay(100);


      Serial.println(digitalRead(A3));
      Serial.println(digitalRead(A2));
      Serial.println(digitalRead(A1));
      Serial.println(digitalRead(A0));
      Serial.println(digitalRead(13));
      Serial.println(digitalRead(11));
      Serial.println(digitalRead(12));
    /*if(
      digitalRead(A3)==LOW &&
      digitalRead(A2)==LOW &&
      digitalRead(A1)==LOW &&
      digitalRead(A0)==LOW &&
      digitalRead(13)==LOW &&
      digitalRead(11)==LOW &&
      digitalRead(12)==HIGH
      )
    {
      return true;
    }
    return false;*/
}

boolean IC74151(){
    // Set PIN modes
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A2, OUTPUT);
    
    pinMode(4, INPUT);
    pinMode(5, INPUT);

    // Set Flags
    digitalWrite(3, LOW);

    if(
        fun1to8MUXCheck(6,LOW,LOW,LOW)==true &&
        fun1to8MUXCheck(7,LOW,LOW,HIGH)==true &&
        fun1to8MUXCheck(8,LOW,HIGH,LOW)==true &&
        fun1to8MUXCheck(9,LOW,HIGH,HIGH)==true &&
        fun1to8MUXCheck(11,HIGH,LOW,LOW)==true &&
        fun1to8MUXCheck(12,HIGH,LOW,HIGH)==true &&
        fun1to8MUXCheck(A3,HIGH,HIGH,LOW)==true &&
        fun1to8MUXCheck(A2,HIGH,HIGH,HIGH)==true
    ){
      // Set Flags
      digitalWrite(3, HIGH);
      return true;
    }
    return false;
}

boolean fun1to8MUXCheck(int D,boolean s1,boolean s2,boolean s3){
    digitalWrite(13, s1);
    digitalWrite(A0, s2);
    digitalWrite(A1, s3);
    digitalWrite(D, LOW);
    delay(100);
    boolean cond1 = digitalRead(5);
    digitalWrite(D, HIGH);
    delay(100);
    boolean cond2 = digitalRead(5);
    if(cond1 == LOW && cond2 == HIGH){
      return true;
    }

    return false;
}


boolean IC74LS73(){
    //Set Pin Modes
    
    
}

