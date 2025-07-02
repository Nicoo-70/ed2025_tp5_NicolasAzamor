#include <iostream>
using namespace std;

typedef struct tnodo {
    int dato;
    tnodo* siguiente;
} *pnodo;
typedef struct {
    pnodo tope;
} Pila;

void iniciar_pila(Pila &p) {
    p.tope = NULL;
}
pnodo crear_nodo(int valor) {
    pnodo nuevo = new tnodo;
    if (nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
    }
    return nuevo;
}
void apilar(Pila &p, int valor) {
    pnodo nuevo = crear_nodo(valor);
    nuevo->siguiente = p.tope;
    p.tope = nuevo;
}
int desapilar(Pila &p) {
    if (p.tope == NULL) return -1;
    pnodo borrado = p.tope;
    int valor = borrado->dato;
    p.tope = p.tope->siguiente;
    delete borrado;
    return valor;
}
void mostrar_pila(Pila p) {
    pnodo i = p.tope;
    cout << "Pila: ";
    while (i != NULL) {
        cout << i->dato << " ";
        i = i->siguiente;
    }
    cout << endl;
}
// COLA
typedef struct {
    pnodo frente;
    pnodo final;
    int cantidad;
} Cola;
void iniciar_cola(Cola &c) {
    c.frente = NULL;
    c.final = NULL;
    c.cantidad = 0;
}
void encolar(Cola &c, int valor) {
    pnodo nuevo = crear_nodo(valor);
    if (c.frente == NULL) {
        c.frente = nuevo;
        c.final = nuevo;
    } else {
        c.final->siguiente = nuevo;
        c.final = nuevo;
    }
    c.cantidad++;
}
int desencolar(Cola &c) {
    if (c.frente == NULL) return -1;
    pnodo borrado = c.frente;
    int valor = borrado->dato;
    c.frente = c.frente->siguiente;
    if (c.frente == NULL) c.final = NULL;
    delete borrado;
    c.cantidad--;
    return valor;
}
void mostrar_cola(Cola c) {
    pnodo i = c.frente;
    cout << "Cola: ";
    while (i != NULL) {
        cout << i->dato << " ";
        i = i->siguiente;
    }
    cout << endl;
    cout << "Cantidad de elementos: " << c.cantidad << endl;
}
int main() {
    Pila pila;
    Cola cola;

    iniciar_pila(pila);
    iniciar_cola(cola);

    apilar(pila, 10);
    apilar(pila, 20);
    apilar(pila, 30);

    mostrar_pila(pila);
    cout << "Desapilo: " << desapilar(pila) << endl;
    mostrar_pila(pila);

    encolar(cola, 100);
    encolar(cola, 200);
    encolar(cola, 300);

    mostrar_cola(cola);
    cout << "Desencolo: " << desencolar(cola) << endl;
    mostrar_cola(cola);

    return 0;
}
