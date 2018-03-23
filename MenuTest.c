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
    while(tab!=1 && tab!=2 && tab!=3){
        printf("Seleccion incorrecta, prueba otra vez\n");
        scanf("%d", &tab);}
    
    printf("Selecciona algoritmo: \n 1.Burbuja\n 2.Inserción\n 3.Selección\n 4.Shell\n 5.Montículo\n 6.Quicksort \n");
    scanf("%d", &alg);
    while(alg!=1 && alg!=2 && alg!=3 && alg!=4 && alg!=5 && alg!=6){
        printf("Seleccion incorrecta, prueba otra vez\n");
        scanf("%d", &alg);}
    
    
   
    printf("Seleccionado: tamaño=%d, tabla= %d, algoritmo=%d \n", tam, tab, alg);
   
    
    struct lista tabla[tam],tablainv[tam];  /* CREO QUE NO ES CORRECTO PONERLO AQUI  */
    
    /* obtencion claves aleatorio  */
    for (i=0; i < tam; i++){
        tabla[i].clave = rand() % (10*tam)+ 1;
    }
    
    /* mostrarlo para pruebas */
    printf(" tabla generada:\n ");
    for (i =0; i < tam; i++){
        printf(" %d  ", tabla[i].clave);
    }
    printf("\n ");
    
    
    
    if(tab!=2){
            insercion(tabla,tam-1);   /* Ordenarlo */
       
        if(tab==3){                  /* Invertirlo */
    
            for (i=0; i< tam; i++)  tablainv[i]=tabla[i]; /* Usando tabla auxiliar */
            for (i=0; i< tam; i++)  tabla[i]=tablainv[tam-1-i];
            
             }
  
    }
        
    
    
    /* mostrarlo tabla con la que trabajo */
    printf("tabla a trabajar:\n ");
    for (i =0; i < tam; i++){
        printf(" %d  ", tabla[i].clave);
    }
    printf("\n ");
   
  
    
    
    
/* seleccion tabla (aqui se puede optimizar poniendolo antes de crear cosas innecesarias, mas adelante*/
    
   
  
    
    


    

    
/* seleccion algoritmo*/
  
    switch ( alg )
     
     {
     
     case 1 : burbuja(tabla,tam-1);
    
     case 2 : insercion(tabla,tam-1);
 
     case 3 : seleccion(tabla,tam-1);
     
     case 4 : shell(tabla,tam-1);
     
     case 5 : monticulo(tabla,tam-1);
     
     case 6 : quicksort( 0,tam-1,tabla);
     
    
     
     break;
     
     }
    

    
    
    printf("tabla resultado:\n ");
    for (i =0; i < tam; i++){
        printf(" %d  ", tabla[i].clave);
    }
    printf("\n ");
    
    return 0;
}

