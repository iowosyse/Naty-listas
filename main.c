#include <stdio.h>
#include <stdlib.h>
#include "Libreria.h"

int main(){

    int opcion = 0, num = 0, lista=0;

    do
    {

    printf("\n>>>>>MENU<<<<<\n");
    printf("1.-Insertar al inicio con listas simplemente ligadas\n");
    printf("2.-Insertar al final con listas simplemente ligadas\n");
    printf("3.-Insertar ordenado con listas simplemente ligadas\n");
    printf("4.-Borar con listas simplemente ligadas\n");

    printf("5.-Insertar al inicio con listas doblemente ligadas\n");
    printf("6.-Insertar al final con listas doblemente ligadas\n");
    printf("7.-Insertar ordenado con listas doblemente ligadas\n");
    printf("8.-Borar con listas doblemente ligadas\n");

    printf("9.-Insertar al inicio con listas doblemente ligadas circulares\n");
    printf("10.-Insertar al final con listas doblemente ligadas circulares\n");
    printf("11.-Insertar ordenado con listas doblemente ligadas circulares\n");
    printf("12.-Borar con listas doblemente ligadas circulares\n");
    printf("13.-Mostar en listas simplemente ligadas\n");
    printf("14.-Mostar en listas doblemente ligadas\n");
    printf("15.-Mostar en listas doblemente ligadas circulares\n");

    printf("Seleccione una opción: \n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Ingrese un número para insertar al inicio (Lista Simple): ");
            scanf("%d", &num);
            insertarInicioSimple(num);

            break;
        case 2:
            printf("Ingrese un número para insertar al final (Lista Simple): ");
            scanf("%d", &num);
            insertarFinSimple(num);
            break;
        case 3:
            printf("Ingrese un número para insertar ordenado (Lista Simple): ");
            scanf("%d", &num);
            insertarOrdenadoSimple(num);
            break;
        case 4:
            printf("Ingrese un número para borrar (Lista Simple): ");
            scanf("%d", &num);
            borrarSimple(num);
            break;
        case 5:
            printf("Ingrese un número para insertar al inicio (Lista Doblemente Ligada): ");
            scanf("%d", &num);
            insertarInicioDoble(num);
            break;
        case 6:
            printf("Ingrese un número para insertar al final (Lista Doblemente Ligada): ");
            scanf("%d", &num);
            insertarFinDoble(num);
            break;
        case 7:
            printf("Ingrese un número para insertar ordenado (Lista Doblemente Ligada): ");
            scanf("%d", &num);
            insertarOrdenadoDoble(num);
            break;
        case 8:
            printf("Ingrese un número para borrar (Lista Doblemente Ligada): ");
            scanf("%d", &num);
            borrarDoble(num);
            break;
        case 9:
            printf("Ingrese un número para insertar al inicio (Lista Doblemente Ligada Circular): ");
            scanf("%d", &num);
            insertarOrdenadoDobleCircular(num);
            break;
        case 10:
            printf("Ingrese un número para insertar al final (Lista Doblemente Ligada Circular): ");
            scanf("%d", &num);
            insertarFinDobleCircular(num);
            break;
         case 11:
            printf("Ingrese un número para insertar ordenado (Lista Doblemente Ligada Circular): ");
            scanf("%d", &num);
            insertarOrdenadoDobleCircular(num);
            break;
        case 12:
            printf("Ingrese un número para borrar (Lista Doblemente Ligada Circular): ");
            scanf("%d", &num);
            borrarDobleCircular(num);
            break;
        case 13:
            printf("Su lista simplemente ligada es:");
        mostrarSimple(lista);
        break;
        case 14:
            printf("Su lista doblemente ligada es:");
        break;
        case 15:
            printf("Su lista doblemente ligada circular es:");
        break;
        case 0:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opción no vál ida. Por favor, seleccione otra opción.\n");
            break;
        }
    } while (opcion != 0);
    

    return 0;
}