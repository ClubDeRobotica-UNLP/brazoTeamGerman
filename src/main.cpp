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
float altura = 10.0;
float radio = 10.0;
float angulo = 90;
float claw = 0;

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

    /* Actualizo el angulo de la base. */
    if (nunchuckData.jX > 200)
    {
        /* Aumento el ángulo de la base. */
        angulo += 1;
    } else if (nunchuckData.jX < 70) {
        /* Reduzco el ángulo de la base. */
        angulo -= 1;
    }

    /* Actualizo el valor de la garra. */
    if ((nunchuckData.cButton == 1) && (nunchuckData.zButton == 0))
    {
        /* Aumento el ángulo de la base. */
        claw += 5;
    } else if ((nunchuckData.cButton == 0) && (nunchuckData.zButton == 1)) {
        /* Reduzco el ángulo de la base. */
        claw -= 5;
    }
    /* Ajusto el valor a los limites del servo. */

    /* Actualizo el radio objetivo. */
    if (nunchuckData.jY > 200)
    {
        /* Aumento el radio. */
        radio += 1;
    } else if (nunchuckData.jY < 70) {
        /* Reduzco el radio. */
        radio -= 1;
    }

    /* Actualizo la altura objetivo. */
    if (nunchuckData.pitch > 30)
    {
        /* Aumento la altura. */
        altura += 1;
    } else if (nunchuckData.pitch < -20) {
        /* Reduzco la altura. */
        altura -= 1;
    }

    /* Ajusto el valor a los limites del servo. */
    angulo = constrain(angulo, 0.0, 180.0);
    claw   = constrain(claw, 0, 180);

    /* Ajusto el valor a los limites del modelo. */
    radio  = constrain(radio, 0.0, 180.0);
    altura = constrain(altura, 0.0, 180.0);

    /* Imprimo los valores. */
    Serial.print("Alt: ");
    Serial.print(altura);
    Serial.print(" - Rad: ");
    Serial.print(radio);
    Serial.print(" - Ang: ");
    Serial.print(angulo);
    Serial.print(" - Garra: ");
    Serial.println(claw);

    /* Respiro. */
    delay(200);
}
