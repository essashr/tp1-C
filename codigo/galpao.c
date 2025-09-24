#include "galpao.h"

//inicializa a lista de pacotes do galpão
void inicializargalpao(galpao* g) {
    inicializarlista(&(g->l)); 
}

//recebe um pacote e adiciona a lista do galpão
void receberpacote(galpao* g, pacote* p) {
    insercaolista(&(g->l), p); 
}

//essa função vai carregar os pacotes no drone até ele atingir o peso máximo
void carregarpacotes(galpao* g, drone* d) {
    celula* c = g->l.primeiro;
    while(c != NULL) {
        pacote p_atual = c->p;
        if(carregamentopacote(d, &p_atual)) { //carrega os pacotes no drone conforme suportado
            pacote temp;
            remocaolista(&(g->l), &temp); // Remove pacote do galpão após ser carregado no drone
            c = g->l.primeiro; //atualiza o ponteiro c
        } else {
            break; // drone atingiu peso máximo
        }
    }
}

// imprime os pacotes que ainda estão no galpão
void imprimirgalpao(galpao* g) {
    printf("Pacotes restantes no galpão:\n");
    celula* c = g->l.primeiro;
    while(c != NULL) {
        printf("%s para %s, peso: %.2lfkg, distância: %.0lfkm\n",
               c->p.conteudo, c->p.destinatario, c->p.peso, c->p.distancia_km);
        c = c->prox;
    }
}