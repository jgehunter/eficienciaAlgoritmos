#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    
    int tab, tam, alg;
    int i;
   struct lista {
        int clave;
        /*  char *first_name;*/
        /*  char *last_name;*/
        };
    
    
    
    struct lista tabla[tam], tablaaleat[tam], tablainv[tam], aux;
    
    
    srand (time(NULL));
    tab=0; tam=0; alg=0;
    printf("Selecciona tamaño:   \n"); /*  aqui podemos poner constantes o bien elegir el tamaño a numero */
    scanf("%d", &tam);
    
    printf("Selecciona tabla: \n 1.ordenado \n 2.aleatorio\n 3.inverso   \n"); /* elegir entre ordenado inverso aleatorio   */
    scanf("%d", &tab);
    
    printf("Selecciona algoritmo: \n 1.Burbuja\n 2.Inserción\n 3.Selección\n 4.Shell\n 5.Montículo\n 6.Quicksort \n");
    scanf("%d", &alg);
    
    
   
    printf("Seleccionado: tamaño=%d, tabla= %d, algoritmo=%d \n", tam, tab, alg);
    
    
    /* obtencion claves aleatorio  */
    for (i=0; i < tam; i++){
        tabla[i].clave = rand() % (10*tam)+ 1;
    }
    
    for (i=0; i < tam; i++){             /* rellenar la tabla aleatoria */
       tablaaleat[i]=tabla[i];
    }
    
    
    
    
    /* Ordenarlo */
    
    /* quick(0,tam-1); */
    
    
    /* Invertirlo */
    
    for (i=0; i< tam; i++)  tablainv[tam]=tabla[i];
    
    for (i=0; i< tam; i++)  tablainv[i]=tabla[tam-1-i];  /* rellenar la tabla inversa */
    
    /* mostrarlo para pruebas */
    
    for (i =0; i < tam; i++){
        printf("%d  ", tabla[i].clave);
    }
    printf("\n ");
    
    for (i =0; i < tam; i++){
        printf("%d  ", tablaaleat[i].clave);
    }
    printf("\n ");
    
    for (i =0; i <tam; i++){
        printf("%d  ", tablainv[i].clave);
    }
    printf("\n ");
    
   switch ( alg )
     
     {
     
     case 1  : burbuja(tabla[],tam);
    
     case 2  : insercion(tabla[],tam);
 
     case 3  : seleccion(tabla[],tam);
     
     case 4  : shell(tabla[],tam);
     
     case 5  : monticulo(tabla[],tam);
     
     case 6  : quicksort(tabla[],tam);
     
    
     
     break;
     
     }
    
    
    return 0;
}

