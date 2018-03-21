#include "main.h"
#include "algoritmos.h"

void insercion( struct lista tabla[], int elementos) {
	int i, j;
	struct lista aux;

	for (i = 1; i < elementos+1; i++) {
		aux = tabla[i];
		for (j = i - 1; j >= 0; j--) {
			if (tabla[j].clave > aux.clave) {
				tabla[j + 1] = tabla[j];
			}
			else {
				break;
			}
			tabla[j ] = aux;
		}
	}

	}
