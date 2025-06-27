#include <iostream>
using namespace std;

typedef struct nodo *pnodo;

typedef struct nodo {
    int dato;
    pnodo siguiente;
};

typedef struct lista {
    pnodo inicio;
    pnodo final;
    int cantidad;
};

void iniciar_lista(lista &l) {
    l.inicio = NULL;
    l.final = NULL;
    l.cantidad = 0;
}

void crear_nodo(pnodo &nuevo, int valor) {
    nuevo = new nodo;
    if (nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
    }
}

void agregar_final(lista &l, pnodo nuevo) {
    if (l.inicio == NULL) {
        l.inicio = nuevo;
        l.final = nuevo;
    } else {
        l.final->siguiente = nuevo;
        l.final = nuevo;
    }
    l.cantidad++;
}

void agregar_inicio(lista &l, pnodo nuevo) {
    if (l.inicio == NULL) {
        l.inicio = nuevo;
        l.final = nuevo;
    } else {
        nuevo->siguiente = l.inicio;
        l.inicio = nuevo;
    }
    l.cantidad++;
}

pnodo eliminar_inicio(lista &l) {
    pnodo borrado;
    if (l.inicio == NULL) {
        borrado = NULL;
    } else {
        borrado = l.inicio;
        l.inicio = borrado->siguiente;
        borrado->siguiente = NULL;
        if (l.inicio == NULL) {
            l.final = NULL;
        }
        l.cantidad--;
    }
    return borrado;
}

pnodo eliminar_final(lista &l) {
    pnodo borrado, i;
    if (l.inicio == NULL) {
        borrado = NULL;
    } else if (l.inicio == l.final) {
        borrado = l.inicio;
        l.inicio = NULL;
        l.final = NULL;
    } else {
        for (i = l.inicio; i->siguiente != l.final; i = i->siguiente);
        borrado = l.final;
        l.final = i;
        l.final->siguiente = NULL;
    }
    l.cantidad--;
    return borrado;
}

int cantidad_elementos(lista l) {
    return l.cantidad;
}

void mostrar_lista(lista l) {
    pnodo i;
    for (i = l.inicio; i != NULL; i = i->siguiente) {
        cout << i->dato << " ";
    }
    cout << endl;
}

int main() {
    lista l;
    pnodo nuevo;

    iniciar_lista(l);

    crear_nodo(nuevo, 10);
    agregar_final(l, nuevo);

    crear_nodo(nuevo, 20);
    agregar_final(l, nuevo);

    crear_nodo(nuevo, 5);
    agregar_inicio(l, nuevo);

    mostrar_lista(l);

    cout << "Cantidad de elementos: " << cantidad_elementos(l) << endl;

    eliminar_inicio(l);
    mostrar_lista(l);

    eliminar_final(l);
    mostrar_lista(l);

    cout << "Cantidad final: " << cantidad_elementos(l) << endl;

    return 0;
}
