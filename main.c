#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include "main.h"


struct lista prueba[4];

void main() {
	for (int i = 0; i <= 4; i++) {
		printf("Introduce un numero :");
		scanf("%d", &prueba[i].clave);
	}
	
	for (int i = 0; i <= 4; i++) {
		printf("\nEl numero %d es: %d", i, prueba[i].clave);
	}

	burbuja(prueba, 5);

	printf("\n");

	for (int i = 0; i <= 4; i++) {
		printf("\nEl numero %d es: %d", i, prueba[i].clave);
	}
}
