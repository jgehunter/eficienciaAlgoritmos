#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "algoritmos.h"

#define ELEM 10


struct lista tabla[ELEM];

void main() {
	srand(time(NULL));

	for (int i = 0; i <= ELEM; i++) {
		tabla[i].clave = rand();
	}
	
	for (int i = 0; i <= ELEM; i++) {
		printf("%d ", tabla[i].clave);
	}
	
	burbuja(tabla, ELEM);

	printf("\n");

	for (int i = 0; i <= ELEM; i++) {
		printf("%d ", tabla[i].clave);
	}

	printf("\nBurbuja\n");

	for (int i = 0; i <= ELEM; i++) {
		tabla[i].clave = rand();
	}

	for (int i = 0; i <= ELEM; i++) {
		printf("%d ", tabla[i].clave);
	}

	printf("\n");

	insercion(tabla, ELEM);

	for (int i = 0; i <= ELEM; i++) {
		printf("%d ", tabla[i].clave);
	}

	printf("\nInsercion\n");

	for (int i = 0; i <= ELEM; i++) {
		tabla[i].clave = rand();
	}

	for (int i = 0; i <= ELEM; i++) {
		printf("%d ", tabla[i].clave);
	}

	printf("\n");

	monticulo(tabla, ELEM);

	for (int i = 0; i <= ELEM; i++) {
		printf("%d ", tabla[i].clave);
	}
	printf("\nMonticulo\n");

	for (int i = 0; i <= ELEM; i++) {
		tabla[i].clave = rand();
	}

	for (int i = 0; i <= ELEM; i++) {
		printf("%d ", tabla[i].clave);
	}

	printf("\n");

	quicksort(0, ELEM-1, tabla);

	for (int i = 0; i <= ELEM; i++) {
		printf("%d ", tabla[i].clave);
	}

	printf("\nQuicksort\n");

	for (int i = 0; i <= ELEM; i++) {
		tabla[i].clave = rand();
	}

	for (int i = 0; i <= ELEM; i++) {
		printf("%d ", tabla[i].clave);
	}

	printf("\n");

	seleccion(tabla, ELEM);

	for (int i = 0; i <= ELEM; i++) {
		printf("%d ", tabla[i].clave);
	}

	printf("\nSeleccion\n");

	for (int i = 0; i <= ELEM; i++) {
		tabla[i].clave = rand();
	}

	for (int i = 0; i <= ELEM; i++) {
		printf("%d ", tabla[i].clave);
	}

	printf("\n");

	shell(tabla, ELEM);

	for (int i = 0; i <= ELEM; i++) {
		printf("%d ", tabla[i].clave);
	}

	printf("\nShell");
}
