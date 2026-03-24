#include <iostream>
#include <cstdlib>
#include "include/linked_list.h"

using namespace std;

int main() {
    cout << "Exercicio de Linked List" << endl;
    cout << "------------------------\n" << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    insere(*lista, 10);
    insere(*lista, 20);
    insere(*lista, 30);

    cout << "Lista inicial: ";
    mostrarLista(*lista);

    cout << "Lista vazia? " << (listaVazia(*lista) ? "Sim" : "Nao") << endl;
    cout << "Numero de elementos: " << numeroElementos(*lista) << endl;

    insereNaPosicao(*lista, 25, 1);
    cout << "Depois de inserir 25 na posicao 1: ";
    mostrarLista(*lista);

    removeDaPosicao(*lista, 2);
    cout << "Depois de remover da posicao 2: ";
    mostrarLista(*lista);

    inverteLista(*lista);
    cout << "Lista invertida: ";
    mostrarLista(*lista);

    destroiLista(*lista);
    free(lista);

    return 0;
}