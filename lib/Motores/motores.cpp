/* -------------------------------------------------------------------------
 * Proyecto: Brazo Team Germán
 *
 * Descripción:
 * Biblioteca de funciones para el control de los servos del Brazo.
 * ------------------------------------------------------------------------- */
#include <Arduino.h>
#include <Servo.h>

#include "motores.h"

/* Variables Globales. */
Servo Base;     /* Handler del Servo de la base.       */
Servo S2;       /* Handler de la primera articulación. */
Servo S3;       /* Handler de la segunda articulación. */
Servo S4;       /* Handler de la tercera articulación. */
Servo Garra;    /* Handler del Servo de la garra.      */

/* -------------------------------------------------------------------------
 *  Función de inicialización de los motores.
 * ------------------------------------------------------------------------- */
void motoresInit(void)
{
	/* Asigno los pines de cada motor. */
    Base.attach(12);
    S2.attach(11);
    S3.attach(10);
    S4.attach(9);
    Garra.attach(8);

    /* Seteo una posición inicial. */
    motoresMover(90, 90, 90);
}

/* -------------------------------------------------------------------------
 *  Función para mover los motores a los 3 angulos especificados en los
 *  argumentos.
 * ------------------------------------------------------------------------- */
void motoresMover(float A1,float A2,float A3)
{
	/* Escribo los angulos en los motores. */
    S2.write (A1);
    S3.write (A2);
    S4.write (A3);
}

/* -------------------------------------------------------------------------
 *  Función para setear la apertura de la garra.
 * ------------------------------------------------------------------------- */
void motoresGarra()
{
	/* TODO */
}

/* -------------------------------------------------------------------------
 *  Función para setar el angulo de la base.
 * ------------------------------------------------------------------------- */
void motoresBase()
{
	/* TODO */
}
