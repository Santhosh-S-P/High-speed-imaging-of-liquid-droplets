#define STATE_IDLE 0
#define STATE_READY 1
#define STATE_DISPENSE 2


#define flashPin 3      // the number of Flash pin to Optocoupler
#define ledPin 13      // the number of the LED pin
#define laser 7
#define lasersensor 8


bool laser_val;
int fsm_state;


void setup() {
 Serial.begin(9600); // start serial communication at 9600 bps:
 fsm_state = STATE_IDLE; // state variable initialization


  pinMode(ledPin, OUTPUT);
  pinMode(flashPin, OUTPUT);
  pinMode(laser, OUTPUT);
  pinMode(lasersensor, INPUT);

  digitalWrite(laser, HIGH);

  
}

void loop(){
  laser_val= digitalRead(lasersensor);
  //delay(100);
  //Serial.println(laser_val);
  
  switch (fsm_state){
  case STATE_IDLE:
    Serial.println("idle");
    laser_val= digitalRead(lasersensor);
    
    if (laser_val==0){
      
      fsm_state=STATE_IDLE;
    }
    else{
      
      fsm_state=STATE_READY;
    }
    delay(5);
    break;

  case STATE_READY:
  
    Serial.println("ready");
    laser_val= digitalRead(lasersensor);
    
    if (laser_val==0){
      
      fsm_state=STATE_DISPENSE;
    }
    else{
      
      fsm_state=STATE_READY;
    }
    delay(5);
    break;
 

  case STATE_DISPENSE:
  
    
    
    Serial.println("dispensed");
    
    laser_val= digitalRead(lasersensor);
    
  


    fsm_state=STATE_IDLE;
    delay(5);

    delay(211);

    
    digitalWrite(flashPin, HIGH); // fire flash
    delay(10);
    digitalWrite(flashPin,LOW);
  

    break;
}
}
