#include "algoritmos.h"

void quicksort( int iz, int de, struct lista tabla[]) {
	struct lista aux;
	int i = iz, j = de;
	int pivote = tabla[(i + j) / 2].clave;

	do {
		while (tabla[i].clave < pivote && i < de)
			i++;
		while (tabla[j].clave > pivote && j > iz)
			j--;
		if (i <= j) {
			aux = tabla[i]; tabla[i] = tabla[j]; tabla[j] = aux;
			i++; j--;
		}
	} while (i <= j);
	if (iz < j) quicksort(iz, j, tabla);
	if (i < de) quicksort(i, de, tabla);
}
