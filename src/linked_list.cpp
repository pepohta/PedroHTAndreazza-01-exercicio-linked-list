#include "../include/linked_list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ListaSimplesmenteEncadeada* criaLista()
{
    ListaSimplesmenteEncadeada* lista = (ListaSimplesmenteEncadeada*) malloc(sizeof(ListaSimplesmenteEncadeada));
    lista->cardinalidade = 0;
    lista->inicio = NULL;
    return lista;
}

void destroiLista(ListaSimplesmenteEncadeada &lista)
{
    Node* temp;
    while (lista.inicio != NULL) {
        temp = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        free(temp);
    }
    lista.cardinalidade = 0;
}

void insere(ListaSimplesmenteEncadeada &lista, int conteudo)
{
    Node* novoNode = (Node*) malloc(sizeof(Node));
    if (novoNode == NULL) {
        cerr << "Erro na alocacao de memoria" << endl;
        return;
    }

    novoNode->conteudo = conteudo;
    novoNode->proximo = lista.inicio;

    lista.inicio = novoNode;
    lista.cardinalidade++;
}

void mostrarLista(const ListaSimplesmenteEncadeada &lista)
{
    Node* atual = lista.inicio;

    while (atual != NULL) {
        cout << atual->conteudo << " ";
        atual = atual->proximo;
    }

    cout << endl;
}

bool listaVazia(const ListaSimplesmenteEncadeada &lista)
{
    return lista.inicio == NULL;
}

int numeroElementos(const ListaSimplesmenteEncadeada &lista)
{
    return lista.cardinalidade;
}

bool insereNaPosicao(ListaSimplesmenteEncadeada &lista, int conteudo, int posicao)
{
    if (posicao < 0 || posicao > lista.cardinalidade) {
        return false;
    }

    if (posicao == 0) {
        insere(lista, conteudo);
        return true;
    }

    Node* novoNode = (Node*) malloc(sizeof(Node));
    if (novoNode == NULL) {
        cerr << "Erro na alocacao de memoria" << endl;
        return false;
    }

    novoNode->conteudo = conteudo;

    Node* atual = lista.inicio;
    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    novoNode->proximo = atual->proximo;
    atual->proximo = novoNode;
    lista.cardinalidade++;

    return true;
}

bool removeDaPosicao(ListaSimplesmenteEncadeada &lista, int posicao)
{
    if (posicao < 0 || posicao >= lista.cardinalidade || lista.inicio == NULL) {
        return false;
    }

    Node* temp;

    if (posicao == 0) {
        temp = lista.inicio;
        lista.inicio = lista.inicio->proximo;
    } else {
        Node* atual = lista.inicio;

        for (int i = 0; i < posicao - 1; i++) {
            atual = atual->proximo;
        }

        temp = atual->proximo;
        atual->proximo = temp->proximo;
    }

    free(temp);
    lista.cardinalidade--;

    return true;
}

void inverteLista(ListaSimplesmenteEncadeada &lista)
{
    Node* anterior = NULL;
    Node* atual = lista.inicio;
    Node* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista.inicio = anterior;
}