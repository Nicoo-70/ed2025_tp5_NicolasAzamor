#include <iostream>
using namespace std;

typedef struct tnodo {
    int dato;
    tnodo* siguiente;
} *pnodo;

void iniciar_lista(pnodo &lista) {
    lista = NULL;
}

pnodo crear_nodo(int valor) {
    pnodo nuevo = new tnodo;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

void agregar_inicio(pnodo &lista, pnodo nuevo) {
    nuevo->siguiente = lista;
    lista = nuevo;
}

void mostrar(pnodo lista) {
    pnodo i;
    if (lista != NULL) {
        for (i = lista; i != NULL; i = i->siguiente) {
            cout << "Nodo: " << i->dato << endl;
        }
    } else {
        cout << "Lista vacía" << endl;
    }
}

int minimo(pnodo lista) {
    if (lista == NULL) return -1;

    int menor = lista->dato;
    pnodo i = lista->siguiente;

    while (i != NULL) {
        if (i->dato < menor) {
            menor = i->dato;
        }
        i = i->siguiente;
    }

    return menor;
}

int main() {
    pnodo lista;
    iniciar_lista(lista);

    int valores[] = {6, 4, 9, 5, 8};
    for (int i = 0; i < 5; i++) {
        agregar_inicio(lista, crear_nodo(valores[i]));
    }

    cout << "\nContenido de la lista:\n";
    mostrar(lista);

    int menor = minimo(lista);
    cout << "\nValor mínimo: " << menor << endl;

    return 0;
}
