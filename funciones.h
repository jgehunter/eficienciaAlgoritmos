/*
*	FICHERO: funciones.h
*	AUTORES: Jorge Hunter    I–aki Echevarr’a    JosŽ Miguel Herv‡s
*
*	El fichero contiene algunas funciones que se utilizan en el programa.
*/

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "main.h"

// La función mezcla las posiciones de los índices de una tabla utilizando
// el algoritmo de Fisher-Yates.
//
// Inputs: puntero struct lista que apunta al comienzo de la tabla y int que
//		   contiene el número de elementos en la tabla.
//
// Outputs: la función opera sobre la tabla y la mezcla.
//
// En cada iteración se elige al azar un número entre 1 y el número de elementos
// que queden sin ordenar y se coloca en la nueva tabla aleatoria.

void mezclar(struct lista *, long);

// La función crea la tabla que indica el usuario.
//
// Inputs: puntero struct lista que apunta al comienzo de la tabla, long con el
// tipo de ordenación de la tabla y long con el tamaño de la tabla.
//
// Outputs: la tabla de tamaño y ordenación indicados.

void crearTabla(struct lista *, long, long);

// La función ordena una tabla utilizando el método indicado.
//
// Inputs: puntero struct lista que apunta al comienzo de la tabla, long con el
//         tamaño de la tabla y long con el algoritmo a usar para ordenarla.
//
// Outputs: la función opera sobre la tabla y la ordena.

void ordenarTabla(struct lista *, long, long);

#endif
