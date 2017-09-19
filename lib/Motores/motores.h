/* -------------------------------------------------------------------------
 * Proyecto: Brazo Team Germán
 *
 * Descripción:
 * Header de la biblioteca de funciones para el control de los Servos del
 * brazo.
 * ------------------------------------------------------------------------- */
#ifndef SRC_LIB_MOTORES_H_
#define SRC_LIB_MOTORES_H_

/* Declaración de Funciones. */
void motoresInit(void);
void motoresMover(float A1,float A2,float A3);
void motoresGarra();
void motoresBase();

#endif /* SRC_LIB_MOTORES_H_ */
