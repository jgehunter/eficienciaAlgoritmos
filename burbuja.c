#include "main.h"
#include "algoritmos.h"

void burbuja( struct lista tabla[], int elementos) {
	int i, j;
	struct lista aux;

	for (i = 0; i < elementos+1; i++) {
		for (j = elementos; j > i; j--) {
			if (tabla[j - 1].clave > tabla[j].clave) {
				aux = tabla[j - 1];
				tabla[j - 1] = tabla[j];
				tabla[j] = aux;
			}
		}
	}
}
