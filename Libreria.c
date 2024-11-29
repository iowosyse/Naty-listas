#include <stdlib.h>
#include <stdio.h>
#include "Libreria.h"

NodoSimple *cabezaSimple = NULL;
NodoDoble *cabezaDoble = NULL;
NodoDobleCircular *cabezaDobleCircular = NULL;


void insertarInicioSimple(int num){//listas enlazadas simples
    NodoSimple* nuevo = (NodoSimple*)malloc(sizeof(NodoSimple));
    nuevo->dato = num;         // Asigna el valor al nuevo nodo
    if (cabezaSimple == NULL)
    {
        cabezaSimple = nuevo;
    }
    else
    {
        nuevo->siguiente = cabezaSimple; // Enlaza el nuevo nodo con la cabeza actual
        cabezaSimple = nuevo; 
    }
     
}

void insertarFinSimple(int num){
 NodoSimple* nuevo = (NodoSimple*)malloc(sizeof(NodoSimple));
    if (!nuevo) {
        printf("No se pudo asignar memoria.\n");
        return;
    }
    nuevo->dato = num;
    nuevo->siguiente = NULL;

    if (cabezaSimple == NULL) {
        // Si la lista está vacía, el nuevo nodo es la cabeza
        cabezaSimple = nuevo;
    } else {
        // Encuentra el último nodo de la lista
        NodoSimple* temp = cabezaSimple;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        // Enlaza el nuevo nodo al final de la lista
        temp->siguiente = nuevo;
    }
}

void insertarOrdenadoSimple(int num){
 NodoSimple* nuevo = (NodoSimple*)malloc(sizeof(NodoSimple));
    if (!nuevo) {
        printf("No se pudo asignar memoria.\n");
        return;
    }
    nuevo->dato = num;

    if (cabezaSimple == NULL || cabezaSimple->dato >= num) {
        // Inserta al inicio si la lista está vacía o el nuevo nodo es menor que la cabeza
        nuevo->siguiente = cabezaSimple;
        cabezaSimple = nuevo;
    } else {
        // Busca la posición correcta para insertar
        NodoSimple* temp = cabezaSimple;
        while (temp->siguiente != NULL && temp->siguiente->dato < num) {
            temp = temp->siguiente;
        }
        nuevo->siguiente = temp->siguiente;
        temp->siguiente = nuevo;
    }
}

void borrarSimple(int num){
 if (cabezaSimple == NULL) {
        printf("La lista está vacía. No se puede borrar ningún elemento.\n");
        return;
    }

    NodoSimple* temp = cabezaSimple;
    NodoSimple* anterior = NULL;

    // Busca el nodo a borrar
    while (temp != NULL && temp->dato != num) {
        anterior = temp;
        temp = temp->siguiente;
    }

    // Si el nodo no fue encontrado
    if (temp == NULL) {
        printf("Elemento %d no encontrado en la lista.\n", num);
        return;
    }

    // Si el nodo a borrar es la cabeza
    if (anterior == NULL) {
        cabezaSimple = cabezaSimple->siguiente;
    } else {
        anterior->siguiente = temp->siguiente;
    }

    free(temp);  // Libera la memoria del nodo eliminado
    printf("Elemento %d borrado de la lista.\n", num);
}



void insertarInicioDoble(int num){
NodoDoble* nuevo = (NodoDoble*)malloc(sizeof(NodoDoble));
    if (!nuevo) {
        printf("No se pudo asignar memoria.\n");
        return;
    }
    nuevo->dato = num;
    nuevo->anterior = NULL;
    nuevo->siguiente = cabezaDoble;

    if (cabezaDoble != NULL) {
        cabezaDoble->anterior = nuevo;  // Si la lista no está vacía, apunta el primer nodo actual hacia el nuevo nodo
    }
    
    cabezaDoble = nuevo;  // Actualiza la cabeza de la lista
}

void insertarFinDoble(int num){
NodoDoble* nuevo = (NodoDoble*)malloc(sizeof(NodoDoble));
    if (!nuevo) {
        printf("No se pudo asignar memoria.\n");
        return;
    }
    nuevo->dato = num;
    nuevo->siguiente = NULL;

    if (cabezaDoble == NULL) {
        // Si la lista está vacía, el nuevo nodo es la cabeza
        nuevo->anterior = NULL;
        cabezaDoble = nuevo;
    } else {
        // Encuentra el último nodo de la lista
        NodoDoble* temp = cabezaDoble;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        // Enlaza el nuevo nodo al final de la lista
        temp->siguiente = nuevo;
        nuevo->anterior = temp;  // Actualiza el puntero anterior del nuevo nodo
    }
}

void insertarOrdenadoDoble(int num){
 NodoDoble* nuevo = (NodoDoble*)malloc(sizeof(NodoDoble));
    if (!nuevo) {
        printf("No se pudo asignar memoria.\n");
        return;
    }
    nuevo->dato = num;

    if (cabezaDoble == NULL || cabezaDoble->dato >= num) {
        // Inserta al inicio si la lista está vacía o el nuevo nodo es menor que la cabeza
        nuevo->siguiente = cabezaDoble;
        nuevo->anterior = NULL;
        if (cabezaDoble != NULL) {
            cabezaDoble->anterior = nuevo;
        }
        cabezaDoble = nuevo;
    } else {
        // Busca la posición correcta para insertar
        NodoDoble* temp = cabezaDoble;
        while (temp->siguiente != NULL && temp->siguiente->dato < num) {
            temp = temp->siguiente;
        }
        nuevo->siguiente = temp->siguiente;
        nuevo->anterior = temp;

        if (temp->siguiente != NULL) {
            temp->siguiente->anterior = nuevo;
        }
        temp->siguiente = nuevo;
    }
}

void borrarDoble(int num){
    if (cabezaDoble == NULL) {
        printf("La lista está vacía. No se puede borrar ningún elemento.\n");
        return;
    }

    NodoDoble* temp = cabezaDoble;

    // Busca el nodo a borrar
    while (temp != NULL && temp->dato != num) {
        temp = temp->siguiente;
    }

    // Si el nodo no fue encontrado
    if (temp == NULL) {
        printf("Elemento %d no encontrado en la lista.\n", num);
        return;
    }

    // Si el nodo a borrar es la cabeza
    if (temp->anterior != NULL) {
        temp->anterior->siguiente = temp->siguiente;
    } else {
        cabezaDoble = temp->siguiente;  // Mueve la cabeza si se borra la cabeza
    }

    if (temp->siguiente != NULL) {
        temp->siguiente->anterior = temp->anterior;
    }

    free(temp);  // Libera la memoria del nodo eliminado
    printf("Elemento %d borrado de la lista.\n", num);
}



void insertarInicioDobleCircular(int num){
 NodoDobleCircular* nuevo = (NodoDobleCircular*)malloc(sizeof(NodoDobleCircular));
    if (!nuevo) {
        printf("No se pudo asignar memoria.\n");
        return;
    }
    nuevo->dato = num;

    if (cabezaDobleCircular == NULL) {
        // Si la lista está vacía, el nuevo nodo se apunta a sí mismo en ambas direcciones
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        cabezaDobleCircular = nuevo;
    } else {
        // Inserta al inicio, actualizando los punteros de la cabeza actual y el último nodo
        NodoDobleCircular* ultimo = cabezaDobleCircular->anterior;

        nuevo->siguiente = cabezaDobleCircular;
        nuevo->anterior = ultimo;
        
        ultimo->siguiente = nuevo;
        cabezaDobleCircular->anterior = nuevo;

        cabezaDobleCircular = nuevo;  // Actualiza la cabeza al nuevo nodo
    }
}

void insertarFinDobleCircular(int num){
 NodoDobleCircular* nuevo = (NodoDobleCircular*)malloc(sizeof(NodoDobleCircular));
    if (!nuevo) {
        printf("No se pudo asignar memoria.\n");
        return;
    }
    nuevo->dato = num;

    if (cabezaDobleCircular == NULL) {
        // Si la lista está vacía, el nuevo nodo se apunta a sí mismo
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        cabezaDobleCircular = nuevo;
    } else {
        // Encuentra el último nodo
        NodoDobleCircular* ultimo = cabezaDobleCircular->anterior;

        // Enlaza el nuevo nodo al final de la lista
        nuevo->siguiente = cabezaDobleCircular;  // El siguiente del nuevo nodo apunta a la cabeza
        nuevo->anterior = ultimo;                // El anterior del nuevo nodo apunta al último nodo

        ultimo->siguiente = nuevo;               // El último nodo apunta al nuevo nodo
        cabezaDobleCircular->anterior = nuevo;   // La cabeza apunta hacia el nuevo nodo como el último
    }
}

void insertarOrdenadoDobleCircular(int num){
  NodoDobleCircular* nuevo = (NodoDobleCircular*)malloc(sizeof(NodoDobleCircular));
    if (!nuevo) {
        printf("No se pudo asignar memoria.\n");
        return;
    }
    nuevo->dato = num;

    if (cabezaDobleCircular == NULL) {
        // Si la lista está vacía, el nuevo nodo se apunta a sí mismo
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        cabezaDobleCircular = nuevo;
    } else if (cabezaDobleCircular->dato >= num) {
        // Inserta al inicio si el nuevo nodo es menor que la cabeza
        NodoDobleCircular* ultimo = cabezaDobleCircular->anterior;

        nuevo->siguiente = cabezaDobleCircular;
        nuevo->anterior = ultimo;

        ultimo->siguiente = nuevo;
        cabezaDobleCircular->anterior = nuevo;
        cabezaDobleCircular = nuevo;
    } else {
        // Busca la posición correcta para insertar
        NodoDobleCircular* temp = cabezaDobleCircular;
        while (temp->siguiente != cabezaDobleCircular && temp->siguiente->dato < num) {
            temp = temp->siguiente;
        }
        nuevo->siguiente = temp->siguiente;
        nuevo->anterior = temp;

        temp->siguiente->anterior = nuevo;
        temp->siguiente = nuevo;
    }
}

void borrarDobleCircular(int num){
  if (cabezaDobleCircular == NULL) {
        printf("La lista está vacía. No se puede borrar ningún elemento.\n");
        return;
    }

    NodoDobleCircular* temp = cabezaDobleCircular;

    // Busca el nodo a borrar
    do {
        if (temp->dato == num) {
            break;
        }
        temp = temp->siguiente;
    } while (temp != cabezaDobleCircular);

    // Si el nodo no fue encontrado
    if (temp == cabezaDobleCircular && temp->dato != num) {
        printf("Elemento %d no encontrado en la lista.\n", num);
        return;
    }

    // Ajusta los punteros
    if (temp->siguiente == temp) {  // Solo hay un nodo
        cabezaDobleCircular = NULL;
    } else {
        if (temp == cabezaDobleCircular) {
            NodoDobleCircular* ultimo = cabezaDobleCircular->anterior;
            cabezaDobleCircular = temp->siguiente;  // Mueve la cabeza
            ultimo->siguiente = cabezaDobleCircular; // Ajusta el último nodo
            cabezaDobleCircular->anterior = ultimo;
        } else {
            temp->anterior->siguiente = temp->siguiente;
            temp->siguiente->anterior = temp->anterior;
        }
    }

    free(temp);  // Libera la memoria del nodo eliminado
    printf("Elemento %d borrado de la lista.\n", num);
}

void mostrarSimple()
{
    if (cabezaSimple == NULL)
    {
        printf("La lista simple está vacía");
        return;
    }


    NodoSimple *temp = cabezaSimple;
    while (temp != NULL)
    {
        printf("|-%d", temp->dato);
        temp = temp->siguiente;
    }
    printf("-|");
}

void mostrarDoble()
{
    if (cabezaDoble == NULL)
    {
        printf("La lista dobke está vacía");
        return;
    }

    NodoDoble *temp = cabezaDoble;
    while (temp != NULL)
    {
        printf("|-%d", temp->dato);
        temp = temp->siguiente;
    }
    printf("-|");
}

void mostrarDobleCircular()
{
    if (cabezaDobleCircular == NULL)
    {
        printf("La lista dobe circular esta vacia");
        return;
    }

    printf("%d", cabezaDobleCircular->dato);
    NodoDobleCircular *temp = cabezaDobleCircular->siguiente;
    while (temp != cabezaDobleCircular && temp != NULL) //se checa si es NULL por si solo existe la cabeza
    {
        printf("|-%d", temp->dato);
        temp = temp->siguiente;
    }
    printf("-|");

}