#define ACCEL_X_ZERO 134
#define ACCEL_Y_ZERO 125
#define ACCEL_Z_ZERO 174

#define NUNCHUCK_RADIUS 40

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

extern nunchuckDataType nunchuckData;

void nunchuckInit(void);
void nunchuckGetData(void);

