#include <iostream>
using namespace std;

typedef struct tnodo {
    int dato;
    tnodo* siguiente;
} *pnodo;

typedef struct {
    pnodo inicio;
    pnodo final;
    int cantidad;
} Lista;
void iniciar_lista(Lista &lista) {
    lista.inicio = NULL;
    lista.final = NULL;
    lista.cantidad = 0;
}
pnodo crear_nodo(int valor) {
    pnodo nuevo = new tnodo;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

void agregar_final(Lista &lista, pnodo nuevo) {
    if (lista.inicio == NULL) {
        lista.inicio = nuevo;
        lista.final = nuevo;
    } else {
        lista.final->siguiente = nuevo;
        lista.final = nuevo;
    }
    lista.cantidad++;
}
void mostrar(Lista lista) {
    pnodo i = lista.inicio;
    cout << "Lista: ";
    while (i != NULL) {
        cout << i->dato << " ";
        i = i->siguiente;
    }
    cout << endl;
}
int buscar_indice(Lista lista, int valor) {
    pnodo i = lista.inicio;
    int indice = 0;
    while (i != NULL) {
        if (i->dato == valor)
            return indice;
        i = i->siguiente;
        indice++;
    }
    return -1;  
}

pnodo buscar_por_indice(Lista lista, int posicion) {
    if (posicion < 0 || posicion >= lista.cantidad)
        return NULL;

    pnodo i = lista.inicio;
    int actual = 0;
    while (i != NULL) {
        if (actual == posicion)
            return i;
        i = i->siguiente;
        actual++;
    }
    return NULL;
}

int main() {
    Lista lista;
    iniciar_lista(lista);

    int valores[] = {6, 4, 9, 5, 8};
    for (int i = 0; i < 5; i++) {
        agregar_final(lista, crear_nodo(valores[i]));
    }

    cout << "Contenido de la lista:\n";
    mostrar(lista);

    int valorBuscado = 5;
    int pos = buscar_indice(lista, valorBuscado);
    cout << "\nBuscar valor " << valorBuscado << ": índice = " << pos << endl;

    int indiceBuscado = 2;
    pnodo nodo = buscar_por_indice(lista, indiceBuscado);
    if (nodo != NULL) {
        cout << "Nodo en índice " << indiceBuscado << ": " << nodo->dato << endl;
    } else {
        cout << "Índice inválido." << endl;
    }

    return 0;
}
