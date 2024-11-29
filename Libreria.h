#ifndef LIBRERIA_H
#define LIBRERIA_H

// Estructura para lista doblemente ligada
typedef struct NodoDoble {
    int dato;
    struct NodoDoble* anterior;
    struct NodoDoble* siguiente;
} NodoDoble;

// Estructura para lista doblemente ligada circular
typedef struct NodoDobleCircular {
    int dato;
    struct NodoDobleCircular* anterior;
    struct NodoDobleCircular* siguiente;
} NodoDobleCircular;
/////////////////////////////////////////////////
typedef struct NodoSimple {
    int dato;
    struct NodoSimple* siguiente;
} NodoSimple;

void insertarInicioSimple(int num);
void insertarFinSimple(int num);
void insertarOrdenadoSimple(int num);
void borrarSimple(int num);
void mostrarSimple();

void insertarInicioDoble(int num);
void insertarFinDoble(int num);
void insertarOrdenadoDoble(int num);
void borrarDoble(int num);
void mostrarDoble();

void insertarInicioDobleCircular(int num);
void insertarFinDobleCircular(int num);
void insertarOrdenadoDobleCircular(int num);
void borrarDobleCircular(int num);
void mostrarDobleCircular();

#endif