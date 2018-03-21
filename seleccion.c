#include "main.h"
#include "algoritmos.h"

void seleccion( struct lista tabla[], int elementos) {
	struct lista aux;
	int i, j, menor;

	for (i = 0; i < elementos; i++) {
		menor = i;
		for (j = i + 1; j <= elementos; j++) {
			if (tabla[j].clave < tabla[menor].clave) {
				menor = j;
			}
			if (menor != i) {
				aux = tabla[i];
				tabla[i] = tabla[menor];
				tabla[menor] = aux;
			}
		}
	}
}
