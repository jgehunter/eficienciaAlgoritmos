#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "algoritmos.h"

#define ELEM 20


struct lista tabla[ELEM], aux;

void main() {
	srand(time(NULL));

	for (int i = 0; i <= ELEM; i++) {
		tabla[i].clave = rand();
	}
	
	for (int i = 0; i <= ELEM; i++) {
		printf("\nEl numero %d es: %d", i, tabla[i].clave);
	}

	quicksort(0,ELEM, tabla);

	printf("\n");

	for (int i = 0; i <= ELEM; i++) {
		printf("\nEl numero %d es: %d", i, tabla[i].clave);
	}
}
