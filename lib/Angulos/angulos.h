/* -------------------------------------------------------------------------
 * Proyecto: Brazo Team Germán
 *
 * Descripción:
 * Header de la iblioteca de funciones referentes a la solución del modelo
 * kinético del brazo.
 * ------------------------------------------------------------------------- */
#ifndef SRC_LIB_ANGLES_H_
#define SRC_LIB_ANGLES_H_

/* Declaracion de estructuras de datos. */
typedef struct angulosStruct {
  /* Datos Crudos. */
  float A;
  float B;
  float C;
} angulosDataType;

/* Declaración de Funciones. */
angulosDataType angulosCalcular(float altura, float radio);

#endif /* SRC_LIB_ANGLES_H_ */
