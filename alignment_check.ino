#define flashPin 3      // the number of Flash pin to Optocoupler
#define ledPin 13      // the number of the LED pin
#define laser 7
#define lasersensor 8

void setup() {
  Serial.begin(9600);
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(flashPin, OUTPUT);
  pinMode(laser, OUTPUT);
  pinMode(lasersensor, INPUT);

  digitalWrite(laser, HIGH);
}

void loop() {
  bool value = digitalRead(lasersensor);

  if (value == 0) {
    Serial.println("laser not blocked");
    digitalWrite(flashPin, LOW);
    digitalWrite(ledPin, LOW);
  } 
  else {
    Serial.println("laser blocked");
    delay(90);
    digitalWrite(flashPin, HIGH); // fire flash
    //delay(50);
    //digitalWrite(flashPin, LOW);
    digitalWrite(ledPin, HIGH);
  }
  
}      
