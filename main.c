#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "algoritmos.h"

#define ELEM 20


struct lista prueba[ELEM];

void main() {
	srand(time(NULL));

	for (int i = 0; i <= ELEM; i++) {
		prueba[i].clave = rand();
	}
	
	for (int i = 0; i <= ELEM; i++) {
		printf("\nEl numero %d es: %d", i, prueba[i].clave);
	}

	insercion(prueba, ELEM);

	printf("\n");

	for (int i = 0; i <= ELEM; i++) {
		printf("\nEl numero %d es: %d", i, prueba[i].clave);
	}
}
