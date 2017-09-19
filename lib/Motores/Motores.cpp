#include <Arduino.h>
#include <Servo.h>

Servo Base;
Servo S2;
Servo S3;
Servo S4;
Servo Garra;

void MotoresInit(void){
    Base.attach(12);
    S2.attach(11);
    S3.attach(10);
    S4.attach(9);
    Garra.attach(8);
}

void MotoresMov(float A1,float A2,float A3){
    S2.write (A1);
    S3.write (A2);
    S4.write (A3);
}

void MotoresGarra(){

}

void MotoresBase(){

}
