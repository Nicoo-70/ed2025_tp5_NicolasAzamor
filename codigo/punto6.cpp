#include <iostream>
using namespace std;
typedef struct nodo_entero {
    int dato;
    nodo_entero* siguiente;
} *pnodo_entero;

pnodo_entero crear_nodo_entero(int valor) {
    pnodo_entero nuevo = new nodo_entero;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

void agregar_final(pnodo_entero &lista, pnodo_entero nuevo) {
    if (lista == NULL) {
        lista = nuevo;
    } else {
        pnodo_entero i;
        for (i = lista; i->siguiente != NULL; i = i->siguiente);
        i->siguiente = nuevo;
    }
}

void mostrar_enteros(pnodo_entero lista) {
    cout << "Lista de enteros: ";
    for (pnodo_entero i = lista; i != NULL; i = i->siguiente) {
        cout << i->dato << " ";
    }
    cout << endl;
}

bool es_primo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int contar_primos(pnodo_entero lista) {
    int contador = 0;
    for (pnodo_entero i = lista; i != NULL; i = i->siguiente) {
        if (es_primo(i->dato)) {
            contador++;
        }
    }
    return contador;
}

// lista de caracteres
typedef struct nodo_char {
    char letra;
    nodo_char* siguiente;
} *pnodo_char;

pnodo_char crear_nodo_char(char c) {
    pnodo_char nuevo = new nodo_char;
    nuevo->letra = c;
    nuevo->siguiente = NULL;
    return nuevo;
}

void agregar_final_char(pnodo_char &lista, pnodo_char nuevo) {
    if (lista == NULL) {
        lista = nuevo;
    } else {
        pnodo_char i;
        for (i = lista; i->siguiente != NULL; i = i->siguiente);
        i->siguiente = nuevo;
    }
}

void mostrar_caracteres(pnodo_char lista) {
    cout << "Lista de caracteres: ";
    for (pnodo_char i = lista; i != NULL; i = i->siguiente) {
        cout << i->letra << " ";
    }
    cout << endl;
}

void contar_mayus_minus(pnodo_char lista, int &mayus, int &minus) {
    mayus = 0;
    minus = 0;
    for (pnodo_char i = lista; i != NULL; i = i->siguiente) {
        if (i->letra >= 'A' && i->letra <= 'Z') {
            mayus++;
        } else if (i->letra >= 'a' && i->letra <= 'z') {
            minus++;
        }
    }
}

// main
int main() {
    pnodo_entero lista_enteros = NULL;
    pnodo_char lista_chars = NULL;

    // cargo lista de enteros
    int numeros[] = {7, 4, 5, 11, 9, 13};
    for (int i = 0; i < 6; i++) {
        agregar_final(lista_enteros, crear_nodo_entero(numeros[i]));
    }

    mostrar_enteros(lista_enteros);
    int primos = contar_primos(lista_enteros);
    cout << "Cantidad de números primos: " << primos << endl;

    // cargo lista de caracter
    char letras[] = {'A', 'b', 'C', 'd', 'E', 'f'};
    for (int i = 0; i < 6; i++) {
        agregar_final_char(lista_chars, crear_nodo_char(letras[i]));
    }

    mostrar_caracteres(lista_chars);
    int mayus, minus;
    contar_mayus_minus(lista_chars, mayus, minus);
    cout << "Mayúsculas: " << mayus << ", Minúsculas: " << minus << endl;

    return 0;
}
