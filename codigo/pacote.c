#include "pacote.h"

// inicializa um pacote com conteúdo, destinatário, peso e distância
void inicializarpacote(pacote* p, char* conteudo, char* destinatario, double peso, double distancia_km) {
    strcpy(p->conteudo, conteudo);
    strcpy(p->destinatario, destinatario);
    p->peso = peso;
    p->distancia_km = distancia_km;
}

// getters e setters pro pacote

// retorna o conteúdo do pacote
char* getconteudo(pacote* p) {
    return p->conteudo;
}

// altera o conteúdo do pacote
void setconteudo(pacote* p, char* conteudo){
    strcpy(p->conteudo, conteudo);
}

// retorna o destinatário do pacote
char* getdestinatario(pacote* p) {
    return p->destinatario;
}

// altera o destinatário do pacote
void setdestinatario(pacote* p, char* destinatario){
    strcpy(p->destinatario, destinatario);
}

// retorna o peso do pacote
double getpeso(pacote* p){
    return p->peso;
}

// altera o peso do pacote
void setpeso(pacote *p, double peso){
    p->peso = peso;
}

// retorna a distância do pacote
double getdistancia_km(pacote* p){
    return p->distancia_km;
}

// altera a distância do pacote
void setdistancia_km(pacote *p, double distancia_km){
    p->distancia_km = distancia_km;
}
