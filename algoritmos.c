/*
*	FICHERO: algoritmos.c
*	AUTORES: Jorge Hunter    I–aki Echevarr’a    JosŽ Miguel Herv‡s
*
*	Distintos algoritmos que se utilizan para la ordenación de tablas.
*/

#include "main.h"
#include "algoritmos.h"


void burbuja(struct lista tabla[], int elementos ,long *nmov,long *ncomp)
{
	struct lista aux;

	for (int i = 0; i < elementos + 1; i++) {
		for (int j = elementos; j > i; j--) {
            *ncomp=*ncomp+1;
			
            if (tabla[j - 1].clave > tabla[j].clave) {
				aux = tabla[j - 1];
				tabla[j - 1] = tabla[j];
                tabla[j] = aux;
                *nmov=*nmov+3;
			}
		}
	}
}

void insercion(struct lista tabla[], int elementos,long *nmov,long *ncomp)
{
	struct lista aux;

	for (int i = 1; i < elementos + 1; i++) {
		aux = tabla[i];
        (*nmov)++;
		for (int j = i - 1; j >= 0; j--) {
			
            (*ncomp)++;
            if (tabla[j].clave > aux.clave) {
				tabla[j + 1] = tabla[j];
                (*nmov)++;
			}
			else {
				break;
			}
			tabla[j] = aux;
            (*nmov)++;

		}
	}

}

void seleccion(struct lista tabla[], int elementos ,long *nmov,long *ncomp)
{
	struct lista aux;
	int menor;

	for (int i = 0; i < elementos; i++) {
		menor = i;
		for (int j = i + 1; j <= elementos; j++) {
			(*ncomp)++;
            if (tabla[j].clave < tabla[menor].clave) {
				menor = j;
			}
            if (menor != i) {
				aux = tabla[i];
				tabla[i] = tabla[menor];
				tabla[menor] = aux;
                *nmov=*nmov+3;
			}
		}
	}
}

int calcularPasos(int tam)
{
	int numPasos;

	if (tam > 701) {
		numPasos = 8;
	}
	else if (tam > 301) {
		numPasos = 7;
	}
	else if (tam > 132) {
		numPasos = 6;
	}
	else if (tam > 57) {
		numPasos = 5;
	}
	else if (tam > 23) {
		numPasos = 4;
	}
	else if (tam > 10) {
		numPasos = 3;
	}
	else if (tam > 4) {
		numPasos = 2;
	}
	else {
		numPasos = 1;
	}

	return numPasos;
}

void shell(struct lista tabla[], int tam ,long *nmov,long *ncomp)
{
	struct lista aux;
	int h[8] = { 701, 301, 132, 57, 23, 10, 4, 1 };
	int numPasos;
	int j;

	numPasos = calcularPasos(tam);
	for (int paso = 0; paso < numPasos; paso++)
		for (int k = 0; k < h[7 - paso]; k++)
			for (int i = h[7 - paso] + k; i <= tam; i += h[7 - paso]) {
				aux = tabla[i];
                (*nmov)++;
				for (j = i - h[7 - paso]; j >= 0; j -= h[7 - paso])
					
                    (*ncomp)++;
                if (tabla[j].clave > aux.clave){
						tabla[j + h[7 - paso]] = tabla[j];
                    (*nmov)++;}
					else
						break;
				tabla[j + h[7 - paso]] = aux;
                (*nmov)++;
			}

}

void criba(int iz, int de, struct lista tabla[],long *nmov,long *ncomp)
{
	int doble;
	int i;
	struct lista aux;

	aux = tabla[iz];
    (*nmov)++;
    
	for (i = iz; doble = 2 * i + 1, doble <= de; i = doble) {
		
        (*ncomp)++;
        if (doble < de && tabla[doble].clave < tabla[doble + 1].clave) {
			doble++;
		}
        
        (*ncomp)++;
		if (aux.clave < tabla[doble].clave) {
			tabla[i] = tabla[doble];
            (*nmov)++;
		}
		else break;
	}
	tabla[i] = aux;
    (*nmov)++;
}

void monticulo(struct lista tabla[], int elementos ,long *nmov,long *ncomp)
{
	int i;
	struct lista aux;

	for (i = ((elementos + 1) / 2) - 1; i >= 0; i--) {
		criba(i, (elementos + 1) - 1, tabla,nmov,ncomp);
	}
	for (i = (elementos + 1) - 2; i >= 0; i--) {
		aux = tabla[0];
		tabla[0] = tabla[i + 1];
		tabla[i + 1] = aux;
        *nmov=*nmov+3;
        
		criba(0, i, tabla,nmov,ncomp);
	}
}

void quicksort(int iz,int de, struct lista tabla[],long *nmov,long *ncomp)
{
	struct lista aux;
	int i = iz, j = de;
	int pivote = tabla[(i + j) / 2].clave;

	do {
        
        while (tabla[i].clave < pivote && i < de){
            i++; (*ncomp)++;}
        
        
        while (tabla[j].clave > pivote && j > iz){
            j--;(*ncomp)++;}
		
        if (i <= j) {
			aux = tabla[i]; tabla[i] = tabla[j]; tabla[j] = aux;  *nmov=*nmov+3;
			i++; j--;
		}
	} while (i <= j);
	
    if (iz < j) quicksort(iz, j, tabla,nmov,ncomp);
	if (i < de) quicksort(i, de, tabla,nmov,ncomp);
}


