/* -------------------------------------------------------------------------
 * Proyecto: Brazo Team Germán
 *
 * Descripción:
 *  Se busca desarrollar un brazo robótico basado en la estructura de
 *  bentommye [Thingiverse] controlado por un Arduino y operado mediante un
 *  joystick Nunchuck.
 * ------------------------------------------------------------------------- */
#include <Arduino.h>
#include <nunchuck.h>
#include <angulos.h>
#include <motores.h>

/* Variables Globales. */
angulosDataType angles;

/* -------------------------------------------------------------------------
 *  Función de Inicalización del Código
 * ------------------------------------------------------------------------- */
void setup()
{
	/* Inicialización de módulos. */
    Serial.begin(9600);
    nunchuckInit();

    /* Fin de la Inicialización. */
    Serial.println("Inicio del Programa:");
}

/* -------------------------------------------------------------------------
 *  Main Loop
 * ------------------------------------------------------------------------- */
void loop()
{
    /* Obtengo el estado del joystick. */
	nunchuckGetData();

    /* Imprimo los datos. */
    Serial.print("jX: ");
    Serial.print(nunchuckData.jX);
    Serial.print(" | jY: ");
    Serial.print(nunchuckData.jY);
    Serial.print(" | aX: ");
    Serial.print(nunchuckData.aX);
    Serial.print(" | aY: ");
    Serial.print(nunchuckData.aY);
    Serial.print(" | aZ: ");
    Serial.print(nunchuckData.aZ);
    Serial.print(" | bC: ");
    Serial.print(nunchuckData.cButton);
    Serial.print(" | bZ: ");
    Serial.print(nunchuckData.zButton);
    Serial.print(" | Pitch: ");
    Serial.print(nunchuckData.pitch);
    Serial.print(" | Roll: ");
    Serial.println(nunchuckData.roll);

    /* Respiro. */
    delay(100);
}
