/*
*	FICHERO: funciones.c
*	AUTORES: Jorge Hunter    Iñaki Echevarría    José Miguel Hervás
*
*	Funciones que se utilizan en el fichero "main.c".
*/

#include "main.h"
#include "funciones.h"
#include "algoritmos.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>


void mezclar(struct lista *tabla, long tamTabla) 
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < tamTabla - 1; i++) {
		int j = i + rand() / (RAND_MAX / (tamTabla - i) + 1);
		int t = tabla[j].clave;
		tabla[j].clave = tabla[i].clave;
		tabla[i].clave = t;
	}
}

void crearTabla(struct lista *tabla, long ordTabla, long tamTabla)
{
	switch (ordTabla) {
	case 1:
		for (int i = 0; i < tamTabla; i++) {
			tabla[i].clave = i;
		}
		break;
	case 2:
		for (int i = 1; i < tamTabla + 1; i++) {
			tabla[i - 1].clave = tamTabla - i;
		}
		break;
	case 3:
		for (int i = 0; i < tamTabla; i++) {
			tabla[i].clave = i;
		}
		mezclar(tabla, tamTabla);
		break;
	}
}

void ordenarTabla(struct lista *tabla, long tamTabla, long tipAlg,long *nmov,long *ncomp)
{
	switch (tipAlg) {
	case 1:
            burbuja(tabla, tamTabla - 1, nmov,ncomp);
		break;
	case 2:
		insercion(tabla, tamTabla - 1,nmov,ncomp);
		break;
	case 3:
		seleccion(tabla, tamTabla - 1,nmov,ncomp);
		break;
	case 4:
		shell(tabla, tamTabla - 1,nmov,ncomp);
		break;
	case 5:
		monticulo(tabla, tamTabla - 1,nmov,ncomp);
		break;
	case 6:
		quicksort(0, tamTabla - 1, tabla,nmov,ncomp);
		break;
	}
}
