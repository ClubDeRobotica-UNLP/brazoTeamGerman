/* -------------------------------------------------------------------------
 * Proyecto: Brazo Team Germán
 *
 * Descripción:
 * TODO.
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
    MotoresInit();

    Serial.println("Inicio del Programa:");
	MotoresMover(90, 90, 90);
	delay(1000);

	/* Test: Calculo de angulos y seteo de motores. */
    angles = angulosCalcular(110, 120);

	/* Imprimo el resultado. */
	Serial.print("Angulo A =");
    Serial.print(angles.A);

    Serial.print(" - Angulo B =");
    Serial.print(angles.B);

    Serial.print(" - Angulo C =");
    Serial.println(angles.C);

	/* Seteo los motores. */
    MotoresMover(angles.A, angles.B, angles.C);
}

/* -------------------------------------------------------------------------
 *  Main Loop
 * ------------------------------------------------------------------------- */
void loop()
{
	/* TODO */
}
