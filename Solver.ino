#include "arduino_secrets.h"

/*

*/
#include <string.h>
#include <Encoder.h>
#include <Servo.h>

int kR_PORT = 9;
int kR_CLK = 5;
int kR_DT = 2;
int rEncCount = 0;

int kL_PORT = 11;
int kL_CLK = 19;
int kL_DT = 16;

int kF_PORT = 12;
int kF_CLK = 3;
int kF_DT = 4;

int kB_PORT = 8;
int kB_CLK = 15;
int kB_DT = 20;

int kD_PORT = 10;
int kD_CLK = 21;
int kD_DT = 17;

int colorsens;

int rCount = 0;
int lCount = 0;
int fCount = 0;
int bCount = 0;
int dCount = 0;

Encoder rEncoder(kR_CLK, kR_DT);
Encoder lEncoder(kL_CLK, kL_DT);
Encoder dEncoder(kD_CLK, kD_DT);
Encoder fEncoder(kF_CLK, kF_DT);
Encoder bEncoder(kB_CLK, kB_DT);

Servo right;
Servo left;
Servo down;
Servo front;
Servo back;

int buttonStart = 0;
int buttonR = 0;
int buttonL = 0;
int buttonF = 0;
int buttonB = 0;
int buttonD = 0;

void setup() {
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);
  pinMode(29, INPUT);


  Serial.begin(9600);

  right.attach(kR_PORT);
  left.attach(kL_PORT);
  down.attach(kD_PORT);
  front.attach(kF_PORT);
  back.attach(kB_PORT);
  turnR(right, rEncoder, 90);
  // turn(down, dEncoder, 95, "down");
  // delay(1000);
  // turn(right, rEncoder, 95, "right");
  // delay(1000);
  // turn(left, lEncoder, 95, "left");
  // delay(1000);
  // turn(front, fEncoder, 95, "front");
  // delay(1000);
  // turn(back, bEncoder, 95, "back");
  // delay(1000);
  // turn(down, dEncoder, 95, "down");
  // delay(1000);
  // turn(right, rEncoder, 95, "right");
  // delay(1000);
  // turn(left, lEncoder, 95, "left");
  // delay(1000);
  // turn(front, fEncoder, 95, "front");
  // delay(1000);
  // turn(back, bEncoder, 95, "back");
  // delay(10000);
  // // String movesString = "R L F2 B2 R' L' D' R L F2 B2 R' L' L2 R L F2 B2 R' L' D R L F2 B2 R' L' F' R' L' D' F' R' F' L B2 R2 R L F2 B2 R' L' D2 R L F2 B2 R' L' B2 R L F2 B2 R' L' D' R L F2 B2 R' L' D2 L2 F2 R L F2 B2 R' L' D R L F2 B2 R' L' L2";
  delay(10000);
  String movesString = "R2 L2 F2 B2 R L F2 B2 R' L' D2 R' L' F2 B2 R L D2 ";
  String movesArray[300];
  int count = 0;
  int start = 0;
  for (int i = 0; i < movesString.length(); i++) {
    if (movesString[i] == ' ') {
      movesArray[count] = movesString.substring(start, i);
      // Serial.println(movesString.substring(start, i));
     
      start = i + 1;
      count += 1;
    }
  }

  String move = "";
  // Serial.println(movesArray[1]);
  // for (int i = 0; i<300; i++) {
  //   Serial.println(movesArray[i]);
  // }

  for (int i; i < 300; i++) {
    move = movesArray[i];
    Serial.println(move);
    /*
    R TURNS
    */
    if (move == "R") {
      turn(right, rEncoder, 90, "right");
    }
    else if (move == "R'") {
      turn(right, rEncoder, -90, "right");
    }
    else if (move == "R2") {
      turn(right, rEncoder, 180, "right");
    }
   
   
    /*
    L TURNS
    */
    if (move == "L") {
      turn(left, lEncoder, 90, "left");
    }
    else if (move == "L'") {
      turn(left, lEncoder, -90, "left");
    }
    else if (move == "L2") {
      turn(left, lEncoder, 180, "left");
    }
   
    /*
    D TURNS
    */
    if (move == "D") {
      turn(down, dEncoder, 90, "down");
    }
    else if (move == "D'") {
      turn(down, dEncoder, -90, "down");
    }
    else if (move == "D2") {
      turn(down, dEncoder, 180, "down");
    }
   
    /*
    F TURNS
    */
    if (move == "F") {
      turn(front, fEncoder, 90, "front");
    }
    else if (move == "F'") {
      turn(front, fEncoder, -90, "front");
    }
    else if (move == "F2") {
      turn(front, fEncoder, 180, "front");
    }
   
    /*
    B TURNS
    */
    if (move == "B") {
      turn(back, bEncoder, 90, "back");
    }
    else if (move == "B'") {
      turn(back, bEncoder, -90, "back");
    }
    else if (move == "B2") {
      turn(back, bEncoder, 180, "back");
    }
    /*
    Empty move (means solve is done)
    */
    if (move == "") {
      turn(back, bEncoder, 0, "back");
      turn(front, fEncoder, 0, "front");
      turn(down, dEncoder, 0, "down");
      turn(left, lEncoder, 0, "left");
      turn(right, rEncoder, 0, "right");

      break;
    }
    delay(500);
  }
 
 

}

void loop() {
  buttonStart = digitalRead(24);
  buttonR = digitalRead(25);
  buttonL = digitalRead(26);
  buttonF = digitalRead(27);
  buttonB = digitalRead(28);
  buttonD = digitalRead(29);

  if(buttonStart == HIGH){
    // if (!Serial.available()) {
    //   algo = Serial.readString();

    // }

    //  while (!Serial.available()) {
    //    algo = Serial.readString();
    //    Serial.write(algo);
    //  }  
  }
  else {
    if(buttonR == HIGH)
      turn(right, rEncoder, 0, "right");
    else if(buttonL == HIGH)
      turn(left, lEncoder, 0, "left");
    else if(buttonF == HIGH)
      turn(front, fEncoder, 0, "front");
    else if(buttonB == HIGH)
      turn(back, bEncoder, 0, "back");
    else if(buttonD == HIGH)
      turn(down, dEncoder, 0, "down");
  }
}
void turnR(Servo servo, Encoder encoder, int degrees){
  int setpoint = rEncCount + degrees;
  int error = setpoint - (-encoder.read());
  
  if (error > 0) {
    while (abs(error) < 5) {
      if (abs(error) > 60) {
        servo.write(1600);
      }
      else if (abs(error) <= 30) {
      servo.write(1550);
      }
      error = setpoint - (-encoder.read());
    }
  }
  else if (error < 0) {
    while (abs(error) < 5) {
      if (abs(error) > 60) {
        servo.write(1400);
      }
      else if (abs(error) <= 30) {
      servo.write(1450);
      }
      error = setpoint - (-encoder.read());
    }
    servo.write(1500);
  }

  servo.write(1500);
}
void turn(Servo servo, Encoder encoder, int degrees, String side) {
  // degrees += 5;
  // if (degrees == -85) {
  //   degrees = -95;
  // }
  int setpoint = (-encoder.read()) + degrees;
  int error = setpoint - (-encoder.read());
  int speed = 1900;
  float kP = 0.05;
  int output;
  while (abs(error) > 5) {
   
    // Serial.println(error);
    error = setpoint - (-encoder.read());
    // if (side == "down") {
    //   // error = setpoint - encoder.read();
    //   // error = error / 2;
    // }
    output = error * kP; // output from -450 to 450 if -90 or 90

   
   
    // bounding output from -100 to -450, or 100 to 450
    if (output > 450) {
      output = 450;
    }
    else if (output < -200) {
      output = -200;
    }
    if ((output > 0) and (output < 100)) {
      output = 100;
    }
    else if ((output < 0) and (output > -100)) {
      output = -100;
    }
    if (side == "down") {
 
    }
    output = output + 1500; // sets output from 1000-2000, the range of the servo
    Serial.println(output);

    servo.write(output);
  // ADD MORE POWER TO DOWN MOTOR
   
  }
 
  servo.write(1500);
}