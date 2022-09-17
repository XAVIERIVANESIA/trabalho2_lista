#include<stdio.h>

typedef int dado;

struct Node {

    dado valor;
    Node *prox;

    Node() {
        prox = NULL;
    }

    Node(dado _valor) {
        valor = _valor;
        prox = NULL;
    }

    void print() {
        printf("%d -> ", valor);
    }

};

struct List {

    Node *cabeca, *cauda;
    int size;

    List() {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

    /*
        empty = testa se a lista est� vazia ou n�o
        size = retorna o tamanho da lista
        pushFront = insere no inicio
        pushBack = insere no final
        popFront = remove no inicio
        popBack = remove no final
    */

    bool empty() { //O(1)
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node* pushBack(dado valor) { //O(1)
        Node *novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        } else {
            cauda->prox = novo;
            cauda = novo;
        }
        size++;
        return cauda;
    }

    Node* pushFront(dado valor) { //O(1)
        Node *novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        size++;
        return cabeca;
    }

    /*int size() { //O(n)
        int s = 0;
        Node *tmp = cabeca;
        while (tmp != NULL) {
            s++;
            tmp = tmp->prox;
        }
        return s;
    }*/

    void print() { //O(n)
        Node *tmp = cabeca;
        while (tmp != NULL) {
            tmp->print();
            tmp = tmp->prox;
        }
        printf("\n");
    }

    Node* popFront() { //O(1)
        if (!empty()) {
            if (cabeca == cauda) { // Apenas 1 elemento
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                Node *tmp = cabeca;
                cabeca = cabeca->prox;
                delete(tmp);
            }
            size--;
        }
        return cabeca;
    }

    Node* popBack() { //O(n)
        if (!empty()) {
            if (cabeca == cauda) {
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                Node *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            size--;
        }
        return cauda;
    }
    //1.
    void apagar(int n ){
    for(int i = 0;i < n; i++) {
        popBack();
    }

    }
    //3.
    void insererNoFinal(){
    pushBack(size + 10);

    }
    //4.
    void receber(int n ){
    for(int i = 10;i <= n; i++) {
        pushBack (i);
    }
    }
    //2. e 6.
    void deletarItem(int n) { //O(n)

        int i = 10;

        Node *tmp = cabeca;
        Node *tmp2;
        while (tmp != NULL) {

                if(i==n) {
                 tmp2->prox = tmp->prox;
                 delete(tmp);
                 break;
                }
            ++i;
            tmp2=tmp;
            tmp=tmp->prox;
        }
    }

};




int main() {

    int n;

    List l;
    //l.pushBack(50);
    //l.pushBack(30);
    //l.pushBack(10);
    //l.pushBack(20);
    //l.pushBack(10);
    //l.pushBack(100);
    //l.pushBack(250);
    //l.pushBack(200);1
    //l.popFront();
    //l.popFront();
    //l.popBack();
    /*l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();*/
    //scanf("%d", &n);
    l.insererNoFinal();
    l.apagar(n);
    l.receber(20);
    l.deletarItem(11);
    l.print();
    printf("%d\n", l.size);
    return 0;
}



