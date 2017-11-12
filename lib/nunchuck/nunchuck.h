/* -------------------------------------------------------------------------
 * Proyecto: Brazo Team Germán
 *
 * Descripción:
 * Header de la biblioteca de funciones para interfacear el arduino con el
 * control Nunchuck de la Wii.
 *
 * Conexiones (Nunchuck de tira de pines):
 *     - Blanco = SCL
 *     - Verde  = SDA
 *     - Rojo   = 3V3
 *     - Negro  = GND
 * ------------------------------------------------------------------------- */
#ifndef SRC_LIB_NUNCHUCK_H_
#define SRC_LIB_NUNCHUCK_H_

/* Definición de Constantes. */
#define ACCEL_X_ZERO 134
#define ACCEL_Y_ZERO 125
#define ACCEL_Z_ZERO 174

#define NUNCHUCK_RADIUS 40

/* Definción de esctructuras de Datos. */
typedef struct nunchuckStruct {
  /* Datos Crudos. */
  uint8_t jX;
  uint8_t jY;
  int8_t aX;
  int8_t aY;
  int8_t aZ;
  uint8_t cButton;
  uint8_t zButton;

  /* Datos Compuestos. */
  float pitch;
  float roll;
} nunchuckDataType;

/* Variables Externas. */
extern nunchuckDataType nunchuckData;

/* Declaración de Funciones. */
void nunchuckInit(void);
void nunchuckGetData(void);

#endif /* SRC_LIB_NUNCHUCK_H_ */
