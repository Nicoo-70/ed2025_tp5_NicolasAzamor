#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo {
    int dato;
    pnodo siguiente;
};

void iniciar_lista(pnodo &lista) {
    lista = NULL;
}
void crear_nodo(pnodo &nuevo) {
    nuevo = new tnodo;
    if (nuevo != NULL) {
        cout << "Ingrese valor: ";
        cin >> nuevo->dato;
        nuevo->siguiente = NULL;
    } else {
        cout << "Memoria insuficiente" << endl;
    }
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

    int cantidad;
    cout << "Cuantos nodos desea ingresar: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        pnodo nuevo;
        crear_nodo(nuevo);
        agregar_inicio(lista, nuevo);
    }

    cout << "\nContenido de la lista:\n";
    mostrar(lista);

    int menor = minimo(lista);
    cout << "\nValor mínimo: " << menor << endl;

    return 0;
}
