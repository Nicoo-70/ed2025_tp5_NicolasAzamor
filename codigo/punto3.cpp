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
void mostrar_lista(lista l) {
    pnodo i;
    for (i = l.inicio; i != NULL; i = i->siguiente) {
        cout << i->dato << " ";
    }
    cout << endl;
}
int buscar_indice(lista l, int valor) {
    pnodo i = l.inicio;
    int pos = 0;
    while (i != NULL) {
        if (i->dato == valor) {
            return pos;
        }
        i = i->siguiente;
        pos++;
    }
    return -1;
}

pnodo buscar_por_indice(lista l, int indice) {
    if (indice < 0 || indice >= l.cantidad) {
        return NULL;
    }
    pnodo i = l.inicio;
    int pos = 0;
    while (i != NULL && pos < indice) {
        i = i->siguiente;
        pos++;
    }
    return i;
}
int main() {
    lista l;
    pnodo nuevo;

    iniciar_lista(l);

    crear_nodo(nuevo, 8);
    agregar_final(l, nuevo);

    crear_nodo(nuevo, 15);
    agregar_final(l, nuevo);

    crear_nodo(nuevo, 23);
    agregar_final(l, nuevo);

    crear_nodo(nuevo, 42);
    agregar_final(l, nuevo);

    mostrar_lista(l); // salida esperada: 8 15 23 42

    int indice = buscar_indice(l, 23);
    cout << "El valor 23 esta en la posicion: " << indice << endl; // salida esperada: 2

    pnodo resultado = buscar_por_indice(l, 3);
    if (resultado != NULL) {
        cout << "El valor en la posicion 3 es: " << resultado->dato << endl; // salida esperada: 42
    } else {
        cout << "Indice fuera de rango" << endl;
    }

    resultado = buscar_por_indice(l, 5);
    if (resultado != NULL) {
        cout << "El valor en la posicion 5 es: " << resultado->dato << endl;
    } else {
        cout << "Indice fuera de rango" << endl; // salida esperada
    }

    return 0;
}
