#include "pacote.h"
#include "lista.h"

// cria uma lista vazia: primeiro e último apontam pra NULL
void inicializarlista(lista* l) {
    l->primeiro = NULL;
    l->ultimo = NULL;
}

// insere pacote no final da lista
void insercaolista(lista* l, pacote* p){
    celula* new = malloc(sizeof(*new)); //aloca memória dinamicamente no heap
    if (new == NULL) {
        printf("Memória insuficiente.\n"); //trata falha de alocação
        exit(EXIT_FAILURE);
    }
    new->p = *p; // copia os dados do pacote
    new->prox = NULL; // será o último, próximo é NULL

    if(l->primeiro == NULL){ // lista estava vazia
        l->primeiro = new; 
        l->ultimo = new; //ambos apontam para a nova celula
    } else { // lista já tinha elementos
        l->ultimo->prox = new; // adiciona a nova celula no final
        l->ultimo = new; // atualiza o ponteiro do ultimo
    }
}

// remove pacote do início da lista
void remocaolista(lista* l, pacote* p) {
    if (l->primeiro != NULL) { // se houver algo para remover
        celula* c = l->primeiro;
        *p = c->p; // copia os dados do pacote removido para fora da lista
        l->primeiro = c->prox; // atualiza ponteiro para o próximo
        if (l->primeiro == NULL) { // lista ficou vazia
            l->ultimo = NULL; // ponteiros primeiro e ultimo passam a NULL
        }
        free(c); // libera a célula antiga
    } else {
        printf("Lista vazia.\n");
    }
}

// imprime todos os pacotes da lista
void imprimirlista(lista* l) {
    celula* current = l->primeiro;
    while (current != NULL) {
        printf("Conteudo: %s | Destinatario: %s | Peso: %.2f | Distancia: %.2f\n",
               current->p.conteudo,
               current->p.destinatario,
               current->p.peso,
               current->p.distancia_km);
        current = current->prox; // passa para o próximo elemento
    }
}
