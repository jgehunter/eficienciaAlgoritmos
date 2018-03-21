#include "main.h"
#include "algoritmos.h"

#define NPASOS 3

void shell(struct lista tabla[], int tam) {

	struct lista aux;
	int i, j, k, paso, h[NPASOS] = { 7, 3, 1 };
	for (paso = 0; paso<NPASOS; paso++)
		for (k = 0; k<h[paso]; k++)
			for (i = h[paso] + k; i<=tam; i += h[paso]) {
				aux = tabla[i];
				for (j = i - h[paso]; j >= 0; j -= h[paso])
					if (tabla[j].clave > aux.clave)
						tabla[j + h[paso]] = tabla[j];
					else
						break;
				tabla[j + h[paso]] = aux;
			}

}
