/* -------------------------------------------------------------------------
 * Proyecto: Brazo Team Germán
 *
 * Descripción:
 * Biblioteca de funciones referentes a la solución del modelo kinético del
 * brazo.
 * ------------------------------------------------------------------------- */
#include <Arduino.h>
#include <math.h>
#include <angulos.h>

/* Definición de constantes. */
#define L1       48.0
#define L2       89.0
#define L3       15.0
#define H        15.0
#define GAMMA    (atan(L3 / L2))
#define hyp      (sqrt(L3*L3 + L2 * L2))

#define limSup   (L1 + hyp)
#define limInf   (sqrt(L1*L1 + hyp*hyp - 2 * L1 * hyp * sin(GAMMA)))
#define rmin     (sqrt(limInf*limInf - (L1+H-altura)*(L1+H-altura)))


/* -------------------------------------------------------------------------
 *  Función para el cálculo de los 3 ángulos del brazo.
 * ------------------------------------------------------------------------- */
angulosDataType angulosCalcular(float altura, float radio)
{
	/* Variables. */
	float temp1, temp2, temp3, r1, r2, r3, r4;
	angulosDataType resultado = {90, 90, 90};

	/* Evalúo que los argumentos sean válidos. */
    if ((altura >= 0) && (radio >= 0))
    {
		Serial.println("Llegaron coordenadas!");

		/* Determino en qué caso se encuentra el punto. */
		r1 = sqrt((L1 + H - altura) * (L1 + H - altura) + radio * radio);
		if ((r1 <= limSup) && (r1 >= limInf) && (radio >= rmin))
		{
			Serial.println("Caso 1:");

			/* Cálculo de variables intermedias. */
			temp1 = acos((L1 + H - altura) / r1);
			temp2 = acos((r1 * r1 + L1 * L1 - hyp * hyp) / (2 * L1 * r1));
			temp3 = acos((L1 * L1 + hyp * hyp - r1 * r1) / (2 * L1 * hyp));

			/* Convierto los valores a Grados. */
			temp1 = temp1 * 180 / PI;
			temp2 = temp2 * 180 / PI;
			temp3 = temp3 * 180 / PI;

			/* Resuelvo los ángulos. */
			resultado.A = 90;
			resultado.B = temp1 + temp2 - 90;
			resultado.C = temp3 - 90 + GAMMA;

		} else if (radio < rmin) {
			Serial.println("Caso 2:");

			/* Cálculo de variables intermedias. */
			r4 = sqrt(radio * radio + (altura - H) * (altura - H));
			temp1 = acos((hyp * hyp + 2 * L1 * L1 - r4 * r4 ) / (2 * hyp * sqrt(2) * L1));
			temp2 = acos((hyp * hyp + 2 * L1 * L1 - hyp * hyp) / (2 * r4 * sqrt(2) * L1));
			temp3 = atan((altura - H) / radio);

			/* Convierto los valores a Grados. */
			temp1 = temp1 * 180 / PI;
			temp2 = temp2 * 180 / PI;
			temp3 = temp3 * 180 / PI;

			/* Resuelvo los ángulos. */
			resultado.A = temp2 + temp3 + 45;
			resultado.B = 0;
			resultado.C = temp1 - 45 + GAMMA;

		} else if ((r1 > limSup) && (altura >= H)) {
			Serial.println("Caso 3:");

			/* Cálculo de variables intermedias. */
			temp3 = atan((altura - H) / radio);
			r2 =  sqrt((radio - L1 * cos(temp3)) * (radio - L1 * cos(temp3)) + (altura - L1 * sin(temp3) - H) * (altura - L1 * sin(temp3) - H));
			if (r2 >= limSup)
			{
				r2 = limSup;
			}

			temp1 = acos((r2 * r2 + L1 * L1 - hyp * hyp) / (2 * L1 * r2));
			temp2 = acos((L1 * L1 + hyp * hyp - r2 * r2) / (2 * L1 * hyp));

			/* Convierto los valores a Grados. */
			temp1 = temp1 * 180 / PI;
			temp2 = temp2 * 180 / PI;
			temp3 = temp3 * 180 / PI;

			/* Resuelvo los ángulos. */
			resultado.A = temp3;
			resultado.B = 90 + temp1;
			resultado.C = temp2 - 90 + GAMMA;

		} else if ((altura < H) && (r1 > limSup)) {
			Serial.println("Caso 4:");

			/* Cálculo de variables intermedias. */
			r3 =  sqrt((radio - L1) * (radio - L1) + (altura - H) * (altura - H));
			if (r3 >= limSup)
			{
				r3 = limSup;
			}

			temp1 = acos((r3 * r3 + L1 * L1 - hyp * hyp) / (2 * L1 * r3));
			temp2 = acos((L1 * L1 + hyp * hyp - r3 * r3) / (2 * L1 * hyp));
			temp3 = acos((H - altura) / r3);

			/* Convierto los valores a Grados. */
			temp1 = temp1 * 180 / PI;
			temp2 = temp2 * 180 / PI;
			temp3 = temp3 * 180 / PI;

			/* Resuelvo los ángulos. */
			resultado.A = 0;
			resultado.B = temp3 + temp1;
			resultado.C = temp2 - 90 + GAMMA;
		}
 	}

	/* Devuelvo el resultado. En caso de error {90, 90, 90}. */
	return resultado;
}
