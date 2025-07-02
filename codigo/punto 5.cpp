#include <iostream>
using namespace std;

typedef struct tnodo {
    int dato;
    tnodo* siguiente;
} *pnodo;

pnodo crear_nodo(int valor) {
    pnodo nuevo = new tnodo;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

void agregar_final(pnodo &lista, pnodo nuevo) {
    if (lista == NULL) {
        lista = nuevo;
    } else {
        pnodo i;
        for (i = lista; i->siguiente != NULL; i = i->siguiente);
        i->siguiente = nuevo;
    }
}

void mostrar_lista(pnodo lista) {
    cout << "Lista: ";
    for (pnodo i = lista; i != NULL; i = i->siguiente) {
        cout << i->dato << " ";
    }
    cout << endl;
}

void ordenar_seleccion(pnodo &lista) {
    for (pnodo i = lista; i != NULL; i = i->siguiente) {
        pnodo min = i;
        for (pnodo j = i->siguiente; j != NULL; j = j->siguiente) {
            if (j->dato < min->dato) {
                min = j;
            }
        }
        if (min != i) {
            int aux = i->dato;
            i->dato = min->dato;
            min->dato = aux;
        }
    }
}
pnodo combinar_sin_orden(pnodo l1, pnodo l2) {
    pnodo resultado = NULL;
    for (pnodo i = l1; i != NULL; i = i->siguiente)
        agregar_final(resultado, crear_nodo(i->dato));
    for (pnodo i = l2; i != NULL; i = i->siguiente)
        agregar_final(resultado, crear_nodo(i->dato));
    return resultado;
}

pnodo combinar_con_orden(pnodo l1, pnodo l2) {
    pnodo resultado = NULL;
    pnodo i = l1;
    pnodo j = l2;

    while (i != NULL && j != NULL) {
        if (i->dato <= j->dato) {
            agregar_final(resultado, crear_nodo(i->dato));
            i = i->siguiente;
        } else {
            agregar_final(resultado, crear_nodo(j->dato));
            j = j->siguiente;
        }
    }

    while (i != NULL) {
        agregar_final(resultado, crear_nodo(i->dato));
        i = i->siguiente;
    }

    while (j != NULL) {
        agregar_final(resultado, crear_nodo(j->dato));
        j = j->siguiente;
    }

    return resultado;
}
int main() {
    pnodo lista1 = NULL;
    pnodo lista2 = NULL;

    int valores[] = {6, 4, 9, 5, 8};

    for (int i = 0; i < 5; i++) {
        agregar_final(lista1, crear_nodo(valores[i]));
        agregar_final(lista2, crear_nodo(valores[i]));
    }

    cout << "Lista 1 original: ";
