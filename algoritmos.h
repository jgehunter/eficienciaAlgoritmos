/*
*	FICHERO: algoritmos.h
*	AUTORES: Jorge Hunter	Iñaki Echevarría	José Miguel Hervás
*
*	El fichero contiene los algoritmos que vamos a utilizar para ordenar la
*   tabla.
*/

#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include "main.h"

// La función ordena una tabla utilizando el método de la burbuja.
//
// Inputs: puntero struct lista que apunta al comienzo de la tabla y int que
//		   contiene el número de elementos en la tabla.
//
// Outputs: la función opera sobre la tabla y la ordena.
//
// Se van comparando elementos adyacentes de dos en dos y si estan desordenados
// se intercambian. Cada vez que se completa este proceso a lo largo de toda la
// tabla el menor índice queda colocado por lo que repitiendo varias veces el
// proceso se ordena la tabla.

void burbuja(struct lista*, int);

// La función ordena una tabla por inserción.
//
// Inputs: puntero struct lista que apunta al comienzo de la tabla y int que
//		   contiene el número de elementos en la tabla.
//
// Outputs: la función opera sobre la tabla y la ordena.
//
// Se comienza con un conjunto formado por el primer elemento que, claramente,
// está ordenado y se va añadiendo elementos al conjunto de uno en uno
// comparandolos con todos los elementos anteriores y insertándolos en la
// posición que les corresponde.

void insercion(struct lista*, int);

// La función ordena una tabla por selección.
//
// Inputs: puntero struct lista que apunta al comienzo de la tabla y int que
//		   contiene el número de elementos en la tabla.
//
// Outputs: la función opera sobre la tabla y la ordena.
//
// Se recorren todos los elementos de la tabla hasta encontrar el menor, que se
// coloca en la primera posición y se vuelve a repetir el proceso sin usar
// los elementos ya seleccionados hasta que queda ordenada la tabla.

void seleccion(struct lista*, int);

// La función proporciona el numero de pasos que le corresponde a cierto tamaño.
//
// Inputs: int que contiene el tamaño de la tabla.
//
// Outputs: int que contiene el número de pasos correspondientes.
//
// Nos basamos en el tamaño de los pasos propuesto por Ciura derivado 
// experimentalmente.

int calcularPasos(int);

// La función ordena una tabla mediante el procedimiento shell.
//
// Inputs: puntero struct lista que apunta al comienzo de la tabla y int que
//		   contiene el número de elementos en la tabla.
//
// Outputs: la función opera sobre la tabla y la ordena.
//
// Se utiliza el mismo principio que en el algoritmo de la burbuja solo con la
// diferencia de que, para salvar el inconveniente de que en el algoritmo de la
// burbuja los índices solo se intercambian con una posición adyacente, primero
// intercambia elementos que estan alejados entre sí hasta que al final acaba
// realizando el algoritmo de la burbuja sobre una tabla algo más ordenada.

void shell(struct lista*, int);

// La función realiza una estructura de montículo.
//
// Inputs: int con el índice del primer elemento con el que queremos
//         formar el montículo, int con el índice del último elemento
//         con el que queremos formar el montículo y puntero struct lista
//         hacia a la tabla.
//
// Outputs: la función forma un montículo con los elementos indicado.
//
// Se colocan los elementos de manera que cada elemento sea menor que los dos
// que los dos siguientes.

void criba(int, int, struct lista*);

// La función ordena una tabla mediante el método del montículo.
//
// Inputs: puntero struct lista que apunta al comienzo de la tabla y int que
//		   contiene el número de elementos en la tabla.
//
// Outputs: la función opera sobre la tabla y la ordena.
//
// Se van creando montículos a partir de los elementos de la tabla y así
// se va consiguiendo el elemento menor hasta que queda ordenada la tabla.

void monticulo(struct lista*, int);

// La función ordena una tabla mediante el procedimiento quicksort.
//
// Inputs: int que contiene el primer elemento con de la tabla con el que
//         se quiere hacer el quicksort, int que contiene el último elemento
//         de la tabla con el que se quiere hacer el quicksort y puntero struct
//         lista que apunta a la tabla.
//
// Outputs: la función opera sobre la tabla y la ordena.
//
// Se escoge un elemento pivote que cumple que todos los elementos superiores
// a el estan por delante y todos los elementos inferiores estan por detras, 
// de manera que el pivote está ordenado. A continuación se tienen dos subtablas
// y se repite el proceso con cada una de ellas recursivamente hasta que la
// tabla queda totalmente ordenada.

void quicksort( int, int, struct lista*);

#endif


