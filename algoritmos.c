/*
*	FICHERO: algoritmos.c
*	AUTORES: Jorge Hunter   I–aki Echevarr’a    JosŽ Miguel Hervas
*
*	Distintos algoritmos que se utilizan para la ordenaci—n de tablas
*/

#include "main.h"
#include "algoritmos.h"

// La funci—n ordena una tabla utilizando el mŽtodo de la burbuja
//
// Inputs: puntero struct lista que apunta al comienzo de la tabla y int que
//		   contiene el nœmero de elementos en la tabla
//
// Outputs: la funci—n opera sobre la tabla y la ordena
//
// Se van comparando elementos adyacentes de dos en dos y si estan desordenados
// se intercambian. Cada vez que se completa este proceso a lo largo de toda la
// tabla el menor êndice queda colocado por lo que repitiendo varias veces el
// proceso se ordena la tabla
void burbuja(struct lista tabla[], int elementos) 
{
	struct lista aux;

	for (int i = 0; i < elementos + 1; i++) {
		for (int j = elementos; j > i; j--) {
			if (tabla[j - 1].clave > tabla[j].clave) {
				aux = tabla[j - 1];
				tabla[j - 1] = tabla[j];
				tabla[j] = aux;
			}
		}
	}
}

// La funci—n ordena una tabla por inserci—n
//
// Inputs: puntero struct lista que apunta al comienzo de la tabla y int que
//		   contiene el número de elementos en la tabla
//
// Outputs: la función opera sobre la tabla y la ordena
//
// Se comienza con un conjunto formado por el primer elemento que, claramente,
// está ordenado y se va a–adiendo elementos al conjunto de uno en uno
// comparandolos con todos los elementos anteriores y insert‡ndolos en la
// posici—n que les corresponde

void insercion(struct lista tabla[], int elementos) 
{
	struct lista aux;

	for (int i = 1; i < elementos + 1; i++) {
		aux = tabla[i];
		for (int j = i - 1; j >= 0; j--) {
			if (tabla[j].clave > aux.clave) {
				tabla[j + 1] = tabla[j];
			}
			else {
				break;
			}
			tabla[j] = aux;
		}
	}

}

// La funci—n ordena una tabla por selección
//
// Inputs: puntero struct lista que apunta al comienzo de la tabla y int que
//		   contiene el nœmero de elementos en la tabla
//
// Outputs: la funci—n opera sobre la tabla y la ordena
//
// Se recorren todos los elementos de la tabla hasta encontrar el menor, que se
// coloca en la primera posici—n y se vuelve a repetir el proceso sin usar
// los elementos ya seleccionados hasta que queda ordenada la tabla

void seleccion(struct lista tabla[], int elementos) 
{
	struct lista aux;
	int menor;

	for (int i = 0; i < elementos; i++) {
		menor = i;
		for (int j = i + 1; j <= elementos; j++) {
			if (tabla[j].clave < tabla[menor].clave) {
				menor = j;
			}
			if (menor != i) {
				aux = tabla[i];
				tabla[i] = tabla[menor];
				tabla[menor] = aux;
			}
		}
	}
}

// La funci—n proporciona el numero de pasos que le corresponde a cierto tama–o
//
// Inputs: int que contiene el tama–o de la tabla
//
// Outputs: int que contiene el nœmero de pasos correspondientes
//
// Nos basamos en el tama–o de los pasos propuesto por Ciura derivado
// experimentalmente

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

// La función ordena una tabla mediante el procedimiento shell
//
// Inputs: puntero struct lista que apunta al comienzo de la tabla y int que
//		   contiene el número de elementos en la tabla
//
// Outputs: la función opera sobre la tabla y la ordena
//
// Se utiliza el mismo principio que en el algoritmo de la burbuja solo con la
// diferencia de que, para salvar el inconveniente de que en el algoritmo de la
// burbuja los índices solo se intercambian con una posición adyacente, primero
// intercambia elementos que estan alejados entre sí hasta que al final acaba
// realizando el algoritmo de la burbuja sobre una tabla algo más ordenada

void shell(struct lista tabla[], int tam) 
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
				for (j = i - h[7 - paso]; j >= 0; j -= h[7 - paso])
					if (tabla[j].clave > aux.clave)
						tabla[j + h[7 - paso]] = tabla[j];
					else
						break;
				tabla[j + h[7 - paso]] = aux;
			}

}

// La función realiza una estructura de montículo
//
// Inputs: int con el índice del primer elemento con el que queremos
//         formar el montículo, int con el índice del último elemento
//         con el que queremos formar el montículo y puntero struct lista
//         hacia a la tabla
//
// Outputs: la función forma un montículo con los elementos indicado
//
// Se colocan los elementos de manera que cada elemento sea menor que los dos
// que los dos siguientes

void criba(int iz, int de, struct lista tabla[]) 
{
	int doble;
	int i;
	struct lista aux;

	aux = tabla[iz];
	for (i = iz; doble = 2 * i + 1, doble <= de; i = doble) {
		if (doble < de && tabla[doble].clave < tabla[doble + 1].clave) {
			doble++;
		}
		if (aux.clave < tabla[doble].clave) {
			tabla[i] = tabla[doble];
		}
		else break;
	}
	tabla[i] = aux;
}


// La función ordena una tabla mediante el método del montículo
//
// Inputs: puntero struct lista que apunta al comienzo de la tabla y int que
//		   contiene el número de elementos en la tabla
//
// Outputs: la función opera sobre la tabla y la ordena
//
// Se van creando montículos a partir de los elementos de la tabla y así
// se va consiguiendo el elemento menor hasta que queda ordenada la tabla

void monticulo(struct lista tabla[], int elementos) 
{
	int i;
	struct lista aux;

	for (i = ((elementos + 1) / 2) - 1; i >= 0; i--) {
		criba(i, (elementos + 1) - 1, tabla);
	}
	for (i = (elementos + 1) - 2; i >= 0; i--) {
		aux = tabla[0];
		tabla[0] = tabla[i + 1];
		tabla[i + 1] = aux;
		criba(0, i, tabla);
	}
}

// La función ordena una tabla mediante el procedimiento quicksort
//
// Inputs: int que contiene el primer elemento con de la tabla con el que
//         se quiere hacer el quicksort, int que contiene el último elemento
//         de la tabla con el que se quiere hacer el quicksort y puntero struct
//         lista que apunta a la tabla
//
// Outputs: la función opera sobre la tabla y la ordena
//
// Se escoge un elemento pivote que cumple que todos los elementos superiores
// a el estan por delante y todos los elementos inferiores estan por detras, 
// de manera que el pivote está ordenado. A continuación se tienen dos subtablas
// y se repite el proceso con cada una de ellas recursivamente hasta que la
// tabla queda totalmente ordenada

void quicksort(int iz, int de, struct lista tabla[]) 
{
	struct lista aux;
	int i = iz, j = de;
	int pivote = tabla[(i + j) / 2].clave;

	do {
		while (tabla[i].clave < pivote && i < de)
			i++;
		while (tabla[j].clave > pivote && j > iz)
			j--;
		if (i <= j) {
			aux = tabla[i]; tabla[i] = tabla[j]; tabla[j] = aux;
			i++; j--;
		}
	} while (i <= j);
	if (iz < j) quicksort(iz, j, tabla);
	if (i < de) quicksort(i, de, tabla);
}


