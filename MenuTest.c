#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "algoritmos.h"





int main(){
    
    
    int tab, tam, alg;
    int i;
     /*struct lista tabla[tam], tablainv[tam];*/
    
    srand (time(NULL));
    tab=0; tam=0; alg=0;
    
    printf("Selecciona tamaño:   \n"); /*  aqui podemos poner constantes o bien elegir el tamaño a numero */
    scanf("%d", &tam);
    
    printf("Selecciona tabla: \n 1.ordenado \n 2.aleatorio\n 3.inverso   \n"); /* elegir entre ordenado inverso aleatorio   */
    scanf("%d", &tab);
    
    printf("Selecciona algoritmo: \n 1.Burbuja\n 2.Inserción\n 3.Selección\n 4.Shell\n 5.Montículo\n 6.Quicksort \n");
    scanf("%d", &alg);
    
    
   
    printf("Seleccionado: tamaño=%d, tabla= %d, algoritmo=%d \n", tam, tab, alg);
   
    
    struct lista tabla[tam],tablainv[tam];  /* CREO QUE NO ES CORRECTO PONERLO AQUI  */
    
    /* obtencion claves aleatorio  */
    for (i=0; i < tam; i++){
        tabla[i].clave = rand() % (10*tam)+ 1;
    }
    
    /* mostrarlo para pruebas */
    for (i =0; i < tam; i++){
        printf(" %d  ", tabla[i].clave);
    }
    printf("\n ");
    
    
    
    if(tab!=2){
                 burbuja(tabla,tam); /* Ordenarlo */
       
        if(tab==3){                  /* Invertirlo */
    
            for (i=0; i< tam; i++)  tablainv[i]=tabla[i];
            
            for (i=0; i< tam; i++)  tabla[i]=tablainv[tam-1-i];
            
             }
  
    }
        
    
    
    /* mostrarlo para pruebas */
   for (i =0; i < tam; i++){
        printf(" %d  ", tabla[i].clave);
    }
    printf("\n ");
   
  
    
    
    
/* seleccion tabla (aqui se puede optimizar poniendolo antes de crear cosas innecesarias, mas adelante*/
    
   
  
    
    
    
    
/* seleccion algoritmo*/
  
    switch ( alg )
     
     {
     
     case 1 : burbuja(tabla,tam);
    
     case 2 : insercion(tabla,tam);
 
     case 3 : seleccion(tabla,tam);
     
     case 4 : shell(tabla,tam);
     
     case 5 : monticulo(tabla,tam);
     
     case 6 : quicksort( 0,tam-1,tabla);
     
    
     
     break;
     
     }
    
    
    for (i =0; i < tam; i++){
        printf("%d  ", tabla[i].clave);
    }
    printf("\n ");
    
    return 0;
}

