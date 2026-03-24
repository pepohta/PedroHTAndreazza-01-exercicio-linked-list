#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int conteudo;
    Node* proximo;
};

struct ListaSimplesmenteEncadeada {
    int cardinalidade;
    Node* inicio;
};

ListaSimplesmenteEncadeada* criaLista();
void destroiLista(ListaSimplesmenteEncadeada &lista);
void insere(ListaSimplesmenteEncadeada &lista, int conteudo);
void mostrarLista(const ListaSimplesmenteEncadeada &lista);
bool listaVazia(const ListaSimplesmenteEncadeada &lista);
int numeroElementos(const ListaSimplesmenteEncadeada &lista);
bool insereNaPosicao(ListaSimplesmenteEncadeada &lista, int conteudo, int posicao);
bool removeDaPosicao(ListaSimplesmenteEncadeada &lista, int posicao);
void inverteLista(ListaSimplesmenteEncadeada &lista);

#endif // LINKED_LIST_H
