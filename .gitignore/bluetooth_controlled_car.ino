#include <SoftwareSerial.h>
#include <Servo.h>
//#include <LiquidCrystal.h>

SoftwareSerial EEBlue(10, 11 );// RX | TX
Servo myservo;
//const int rs = 12, en = 13, d4 = 9, d5 = 8, d6 = 7, d7 = 6;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char bluetooth();
void str();
void stp();
void left();
void right();
const int in1 =  2;
const int in2 =  3;
const int in3 =  4;
const int in4 =  5;

void setup() {
  Serial.begin(9600);
  EEBlue.begin(9600);
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  //lcd.begin(16, 2);
  //lcd.write("   Hello World!");
  delay(100);
  lab:
  char a=bluetooth();
  if(a=='1'){
    Serial.write("start");
    delay(100);
    while(1){
      str();
      char a=bluetooth();
      if(a=='2')
        left();
      else if(a=='3')
        right();
      else if(a=='0'){
        stp();
        goto lab;
       }
     }
    delay(10);
  }
}

char bluetooth(){
  char temp;
  if (EEBlue.available()){
    temp=EEBlue.read();
    Serial.write(temp);
    delay(100);
  }
  if (Serial.available())
    EEBlue.write(Serial.read());
  return temp;
}

void left(){
  //lcd.write("  Turning Left");
  //delay(50);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(300);
  }
  
void right(){
  //lcd.write(" Turning Right");
  //delay(50);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(300);
}
void stp(){
  //lcd.write("    Stopped");
  //delay(50);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(10);
}
void str(){
  //lcd.write("       ^_^");
  //delay(50);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(10);
}

