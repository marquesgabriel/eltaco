#include <Tone.h>

int a = 2;  //For display segment "a"
int b = 3;  //For display segment "b"
int c = 4;  //For display segment "c"
int d = 5;  //For display segment "d"
int e = 6;  //For display segment "e"
int f = 8;  //For display segment "f"
int g = 9;  //For display segment "g"

int yellow = 12;
int red = 13;

Tone kmh;
void setup() {
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G

  pinMode(yellow, OUTPUT);  //Yellow Shift Light
  pinMode(red, OUTPUT);    //Red Shift Light
}

void turnOff(){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);

  digitalWrite(yellow,LOW);
  digitalWrite(red,LOW);
}

void loop() {
  if(Serial.available()>0){
    char kind_of_data = Serial.read();
    delay(1);
    int Data100 = Serial.read() - '0';
    delay(1);
    int Data10 = Serial.read()- '0';
    delay(1);
    int Data1 = Serial.read()- '0';
    // trecho de código retirado do projeto alemão. está no arquivo README.md
    while (Data1 < 0) {
      Data1 = Data10;
      Data10 = Data100;
      Data100 = 0;
    }
    int Data = 100*Data100 + 10*Data10 + Data1;

    //G = gear - 'marcha'
    //S = speed - 'velocidade'
    //R = RPM
    if (kind_of_data == 'G') {
      if(Data == 255) reverse();
      else if(Data == 127) neutral();
      else if(Data == 140) gearOne();
      else if(Data == 153) gearTwo();
      else if(Data == 166) gearThree();
      else if(Data == 179) gearFour();
      else if(Data == 191) gearFive();
      else if(Data == 204) gearSix();
    }
    else if (kind_of_data == 'R') {
      if(Data > 480) {
        digitalWrite(red, HIGH);
      }
      if(Data > 320) {
        digitalWrite(yellow, HIGH);
        digitalWrite(red, LOW);
      }
      else {
        digitalWrite(red, LOW);
        digitalWrite(yellow, LOW);
      }
    }
  }
}
// gear functions to show on 7 segments display
void reverse(){
 digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,HIGH);
 digitalWrite(e,LOW);
 digitalWrite(f,LOW);
 digitalWrite(g,LOW);
}
void neutral(){
 digitalWrite(a,HIGH);
 digitalWrite(b,LOW);
 digitalWrite(c,HIGH);
 digitalWrite(d,HIGH);
 digitalWrite(e,LOW);
 digitalWrite(f,HIGH);
 digitalWrite(g,LOW);
}
void gearOne(){
 digitalWrite(a,HIGH);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,HIGH);
 digitalWrite(e,HIGH);
 digitalWrite(f,HIGH);
 digitalWrite(g,HIGH);
}
void gearTwo(){
 digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,HIGH);
 digitalWrite(d,LOW);
 digitalWrite(e,LOW);
 digitalWrite(f,HIGH);
 digitalWrite(g,LOW);
}
void gearThree(){
 digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
 digitalWrite(e,HIGH);
 digitalWrite(f,HIGH);
 digitalWrite(g,LOW);
}
void gearFour(){
 digitalWrite(a,HIGH);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,HIGH);
 digitalWrite(e,HIGH);
 digitalWrite(f,LOW);
 digitalWrite(g,LOW);
}
void gearFive(){
 digitalWrite(a,LOW);
 digitalWrite(b,HIGH);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
 digitalWrite(e,HIGH);
 digitalWrite(f,LOW);
 digitalWrite(g,LOW);
}
void gearSix(){
 digitalWrite(a,LOW);
 digitalWrite(b,HIGH);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
 digitalWrite(e,LOW);
 digitalWrite(f,LOW);
 digitalWrite(g,LOW);
}
