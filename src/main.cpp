#include <Arduino.h>
#include <nunchuck.h>
#include <angulos.h>
#include <Motores.h>

angulosDataType angles;

void setup()
{
    Serial.begin(9600);
    MotoresInit();

    Serial.println("Inicio... ");
    MotoresMov(90, 90, 90);
    delay(1000);

    angles = angulosCalcular(110, 120);
    Serial.print("Angulo A =");
    Serial.print(angles.A);

    Serial.print(" - Angulo B =");
    Serial.print(angles.B);

    Serial.print(" - Angulo C =");
    Serial.println(angles.C);

    MotoresMov(angles.A, angles.B, angles.C);
}

void loop()
{

}
