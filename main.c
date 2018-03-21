#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include "main.h"


struct lista prueba[3];

void main() {
	for (int i = 0; i <= 3; i++) {
		printf("Introduce un numero :");
		scanf("%d", &prueba[i].clave);
	}
	
	for (int i = 0; i <= 3; i++) {
		printf("\nEl numero %d es: %d", i, prueba[i].clave);
	}

	burbuja(prueba, 4);

	printf("\n");

	for (int i = 0; i <= 3; i++) {
		printf("\nEl numero %d es: %d", i, prueba[i].clave);
	}
}