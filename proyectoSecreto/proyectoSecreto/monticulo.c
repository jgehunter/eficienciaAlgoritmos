#include "algoritmos.h"

extern struct lista tabla[], aux;

void criba(int iz, int de) {
	int i, doble;

	aux = tabla[iz];
	for (i = iz; doble = 2 * i + 1, doble <= de; i = doble) {
		if (doble<de && tabla[doble].clave < tabla[doble + 1].clave)
			doble++;
		if (aux.clave < tabla[doble].clave)
			tabla[i] = tabla[doble];
		else
			break;
	}
	tabla[i] = aux;
}

monticulo(struct lista tabla[], int elementos) {
	int i;

	for (i = (elementos/2) - 1; i >= 0; i--) {
		criba(i, elementos - 1);
	}
	for (i = elementos - 2; i >= 0; i--) {
		aux = tabla[0];
		tabla[0] = tabla[i + 1];
		tabla[i + 1] = aux;
		criba(0, i);
	}
}