#include "drone.h"

// inicializa o drone com peso máximo e lista de pacotes vazia
void inicializardrone(drone* d, double pesoMAX) {
    d->pesoMAX = pesoMAX;
    d->peso_carregado = 0;
    d->dist_total = 0;
    inicializarlista(&(d->l)); 
}

// tenta carregar um pacote no drone
// retorna 1 se o carregamento foi bem-sucedido, 0 caso contrário
int carregamentopacote(drone* d, pacote* p) {
    // Verifica se o drone suporta o peso adicional do pacote
    if(p->peso + d->peso_carregado <= d->pesoMAX){
        d->peso_carregado += p->peso;   // atualiza o peso carregado
        insercaolista(&(d->l), p);      // Adiciona o pacote à lista do drone
        return 1;  // Sucesso no carregamento
    } else {
        return 0;  // Falha: pacote muito pesado
    }
}

// realiza a entrega de todos os pacotes do drone
// retorna a distância total percorrida nesta viagem
double realizarentrega(drone* d, lista* l) {
    inicializarlista(l); // inicia a lista vazia

    celula* c = d->l.primeiro;
    double dist_viagem = 0.0;
    double pos_atual = 0.0;
    while (c != NULL) { 
        insercaolista(l, &(c->p)); //insere os pacotes no drone para entrega
        dist_viagem += fabs(c->p.distancia_km - pos_atual); // calcula distância percorrida até o próximo pacote
        pos_atual = c->p.distancia_km;
        c = c->prox;
    }
    dist_viagem += pos_atual; //calcula a volta do drone ao galpão
    d->dist_total += dist_viagem;

    // esvazia o drone
    while (d->l.primeiro != NULL) {
        pacote tmp;
        remocaolista(&(d->l), &tmp);
    }
    d->peso_carregado = 0;

    return dist_viagem;
}

// imprime os pacotes transportados pelo drone e a distância percorrida
void imprimirdrone(lista* l, double dist_viagem, int id) {
    printf("Viagem %d\n", id);
    celula* c = l->primeiro;
    while(c != NULL) {
        printf("Entrega: \"%s\" para \"%s\"\n", c->p.conteudo, c->p.destinatario);
        c = c->prox;
    }
    printf("Distância Total: %.0lfkm\n\n", dist_viagem);
    // libera a lista temporária
    pacote tmp;
    while(l->primeiro != NULL) {
        remocaolista(l, &tmp);
    }
}