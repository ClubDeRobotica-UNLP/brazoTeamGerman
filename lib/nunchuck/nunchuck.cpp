#include <Arduino.h>
#include <Wire.h>
#include <Math.h>

#include "nunchuck.h"

/* Declaración de Variables Global. */
nunchuckDataType nunchuckData;

/* -------------------------------------------------------------------------
 *  Función de Inicalización del Nunchuck.
 * ------------------------------------------------------------------------- */
void nunchuckInit(void)
{
  /* Inicializo la estructura de datos. */
  nunchuckData.jX = 0;
  nunchuckData.jY = 0;
  nunchuckData.aX = 0;
  nunchuckData.aY = 0;
  nunchuckData.aZ = 0;
  nunchuckData.cButton = 0;
  nunchuckData.zButton = 0;

  nunchuckData.pitch = 0;
  nunchuckData.roll = 0;

  /* Inicializo la comunicación I2C. */
  Wire.begin();

  /* Inicializo el nunchuck configurandolo sin encriptación. */
  Wire.beginTransmission(0x52);
  Wire.write(0xF0);
  Wire.write(0x55);
  Wire.write(0xFB);
  Wire.write(0x00);
  Wire.endTransmission();
}

/* -------------------------------------------------------------------------
 *  Función para actualizar los datos del Nunchuck.
 * ------------------------------------------------------------------------- */
void nunchuckGetData(void)
{
  uint8_t i;
  uint8_t buffer[6];

  /* Seteo la dirección de lectura en 0x00. */
  Wire.beginTransmission(0x52);
  Wire.write(0);
  Wire.endTransmission();

  /* Solicito 6 Bytes al esclavo I2C. */
  Wire.requestFrom(0x52, 6);
  for(i = 0; i < 6; i++)
  {
    buffer[i] = Wire.read();
  }

  /*  Actualizo la estructura de datos. */
  nunchuckData.jX = buffer[0];
  nunchuckData.jY = buffer[1];
  nunchuckData.aX = buffer[2] - ACCEL_X_ZERO;
  nunchuckData.aY = buffer[3] - ACCEL_Y_ZERO;
  nunchuckData.aZ = buffer[4] - ACCEL_Z_ZERO;
  nunchuckData.zButton = !(buffer[5] & 0b01);
  nunchuckData.cButton = !((buffer[5] & 0b10) >> 1);

  /* Calculo los ángulos de Pitch y Roll. */
  nunchuckData.pitch = acos((float) nunchuckData.aY / (float) NUNCHUCK_RADIUS);
  nunchuckData.roll = atan((float) nunchuckData.aX / (float) nunchuckData.aZ);

  /* Paso los ángulos a grados. */
  nunchuckData.pitch = (nunchuckData.pitch * 180.0 / M_PI) - 90;
  nunchuckData.pitch = constrain(nunchuckData.pitch, -90, 90);
  nunchuckData.roll = nunchuckData.roll * 180.0 / M_PI;
}

