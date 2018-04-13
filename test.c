/* 
*	FICHERO: main.c
*	AUTORES: Jorge Hunter	Iñaki Echevarría	José Miguel Hervás
*
*	El programa permite al usuario elegir el numero de elementos de una tabla,
*	la ordenacion previa de la tabla y el algoritmo que se quiere utilizar para
*	ordenarla y devuelve al usuario el valor en microsegundos del tiempo que
*	tarda el algoritmo elegido en ordenar la tabla elegida.
*
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_TABLA 1000000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"
#include "main.h"
#include "algoritmos.h"
#include "measureTime.h"


int main()
{
	long tamTabla;				// Tamaño de la tabla.
	long ordTabla;				// Tipo de ordenación de la tabla.
	long tipAlg;				// Tipo de algoritmo de ordenación.
	long long micros;			// Tiempor que tarda en microsegundos.
	struct lista *tabla;		// Tabla a ordenar.
	char input[256];			// Lectura del input del usuario.
	char *tmp;					
    long ncomp;
    long nmov;
    
    
    
    tipAlg = 6;
   
    ordTabla = 3;
    

    
    for(tamTabla=20; tamTabla<=1000; tamTabla=tamTabla+20){
        
		tabla = malloc(tamTabla * sizeof(struct lista));
		crearTabla(tabla, ordTabla, tamTabla);
		startTimer();
		ordenarTabla(tabla, tamTabla, tipAlg,&nmov,&ncomp);
		micros = getTime();
		free(tabla);
        
        printf("%lld \n", micros);
	}

	return 0;
}

