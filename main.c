#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "algoritmos.h"

#define ELEM 10000


struct lista tabla[ELEM];

void main() {
	srand(time(NULL));

	for (int i = 0; i <= ELEM; i++) {
		tabla[i].clave = rand();
	}
	

	startTimer();

	burbuja(tabla, ELEM);

	

	printf("\nBurbuja ha tardado %lld micros\n", tiempoPasado());

	for (int i = 0; i <= ELEM; i++) {
		tabla[i].clave = rand();
	}

	

	startTimer();
	insercion(tabla, ELEM);

	


	printf("\nInsercion ha tardado %lld micros\n", tiempoPasado());

	for (int i = 0; i <= ELEM; i++) {
		tabla[i].clave = rand();
	}

	

	startTimer();
	monticulo(tabla, ELEM);

	printf("\nMonticulo ha tardado %lld micros\n", tiempoPasado());

	for (int i = 0; i <= ELEM; i++) {
		tabla[i].clave = rand();
	}

	

	startTimer();
	quicksort(0, ELEM-1, tabla);



	printf("\nQuicksort ha tardado %lld micros\n", tiempoPasado());

	for (int i = 0; i <= ELEM; i++) {
		tabla[i].clave = rand();
	}


	startTimer();
	seleccion(tabla, ELEM);


	printf("\nSeleccion ha tardado %lld micros\n", tiempoPasado());

	for (int i = 0; i <= ELEM; i++) {
		tabla[i].clave = rand();
	}

	startTimer();
	shell(tabla, ELEM);

	printf("\nShell ha tardado %lld micros", tiempoPasado());
}
