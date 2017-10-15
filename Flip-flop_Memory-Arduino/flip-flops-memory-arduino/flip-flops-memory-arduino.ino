#define Q1output 2
#define Q1invertedOutput 3

#define InputSet 4
#define InputReset 5

boolean SetInputState;
boolean ResetInputState;
boolean Q1state = true;

 
void setup() {
  // initialize the LED pin as an output:
  pinMode(Q1output, OUTPUT);
  pinMode(Q1invertedOutput, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(InputSet, INPUT);
  pinMode(InputReset, INPUT);

}

void loop() {

  // NAND R-S (Reset-Set) Flip flop
  
  SetInputState = digitalRead(InputSet);
  ResetInputState = digitalRead(InputReset);
  delay(50);

  if (Q1state == true){
    if ((SetInputState == false) && (ResetInputState == false)){
        digitalWrite(Q1output,true);
        digitalWrite(Q1invertedOutput, false);
    } else if ((SetInputState == false) && (ResetInputState == true)){
        digitalWrite(Q1output,false);
        digitalWrite(Q1invertedOutput, true);
        Q1state = true;    
    } else if ((SetInputState == true) && (ResetInputState == false)){
        digitalWrite(Q1output, true);
        digitalWrite(Q1invertedOutput, false);
        Q1state = false;    
    } else if ((SetInputState == true) && (ResetInputState == true)){
         
    }
  } else{
    if ((SetInputState == false) && (ResetInputState == false)){
        digitalWrite(Q1output, false);
        digitalWrite(Q1invertedOutput, true);
    } else if ((SetInputState == false) && (ResetInputState == true)){
        digitalWrite(Q1output, false);
        digitalWrite(Q1invertedOutput, true);
        Q1state = true;    
    } else if ((SetInputState == true) && (ResetInputState == false)){
        digitalWrite(Q1output, true);
        digitalWrite(Q1invertedOutput, false);
        Q1state = false;    
    } else if ((SetInputState == true) && (ResetInputState == true)){
        
    }
  }
  
  
}
