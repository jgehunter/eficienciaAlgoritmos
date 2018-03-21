#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include "main.h"

#define ELEM 25


struct lista prueba[ELEM];

void main() {
	for (int i = 0; i <= ELEM; i++) {
		prueba[i].clave = ELEM - i;
	}
	
	for (int i = 0; i <= ELEM; i++) {
		printf("\nEl numero %d es: %d", i, prueba[i].clave);
	}

	burbuja(prueba, 5);

	printf("\n");

	for (int i = 0; i <= ELEM; i++) {
		printf("\nEl numero %d es: %d", i, prueba[i].clave);
	}
}
