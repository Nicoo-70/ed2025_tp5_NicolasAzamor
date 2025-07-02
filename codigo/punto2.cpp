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
    if (nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
    }
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
pnodo eliminar_inicio(Lista &lista) {
    pnodo borrado;
    if (lista.inicio == NULL) {
        borrado = NULL;
    } else {
        borrado = lista.inicio;
        lista.inicio = borrado->siguiente;
        if (lista.inicio == NULL) {
            lista.final = NULL;
        }
        lista.cantidad--;
        borrado->siguiente = NULL;
    }
    return borrado;
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

int obtener_cantidad(Lista lista) {
    return lista.cantidad;
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
    cout << "Cantidad de elementos: " << obtener_cantidad(lista) << endl;

    cout << "\nEliminando un nodo del inicio...\n";
    pnodo eliminado = eliminar_inicio(lista);
    if (eliminado != NULL) {
        cout << "Nodo eliminado: " << eliminado->dato << endl;
        delete eliminado;
    }

    cout << "Lista actualizada:\n";
    mostrar(lista);
    cout << "Cantidad actual: " << obtener_cantidad(lista) << endl;

    return 0;
}
