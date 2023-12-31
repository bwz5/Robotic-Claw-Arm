// Servo Initializations 

#include <Servo.h>


Servo base; // handles horizontal rotation 
Servo baseArm; 
Servo clawArm; 
Servo claw; 

int pos = 0; // position of servo currently being turned 

int potPin = 0; // potentiometer pin 
int val; // value the pot will read 

int buttonPin = 2; 



void setup() {
  // put your setup code here, to run once:
  base.attach(3); 
  baseArm.attach(5); 
  clawArm.attach(6); 
  claw.attach(9); 

  claw.write(0); // closed 
  clawArm.write(180); // vertical 

  pinMode(buttonPin, INPUT); 
}

void potentiometerTurn(Servo s){
    val = analogRead(potPin); 
    val = map(val, 0, 1023, 0, 180); 
    s.write(val); 
    delay(15); 
}

void loop() {
  // put your main code here, to run repeatedly:
  potentiometerTurn(base); 

  int digitalVal = digitalRead(buttonPin); 

  if (HIGH == digitalVal){
    pickUp(); 
    delay(1000); 
  } 

}

void pickUp(){
  clawArmDown(clawArm); 
  openClaw(claw); 
  clawArmUp(clawArm); 
}

void openClaw(Servo s){
  for (pos = 0; pos <= 40; pos+=1){
    s.write(pos);
    delay(15); 
  }
  delay(1000); 
  closeClaw(s); 
}

void closeClaw(Servo s){
  for(pos = 40; pos >= 0; pos-=1){
    s.write(pos);
    delay(15); 
  }
  delay(100); 
}

void turn180(Servo s){
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    s.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    }

    for (pos = 180; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    s.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    }

    
}

void clawArmDown(Servo s){ // from 0
  for (pos = 180; pos >= 75; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    s.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    }
}
void clawArmUp(Servo s){
  for (pos = 75; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    s.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    }
}

void turn180to90(Servo s){
  for (pos = 180; pos >= 90; pos -= 1){
    s.write(pos); 
    delay(15); 
  }
}
