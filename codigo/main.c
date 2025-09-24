#include "pacote.h"
#include "lista.h"
#include "drone.h"
#include "galpao.h"

int main() {
    FILE* arq = fopen("testes/teste1.txt", "r");
    if(!arq) {
        printf("Erro ao abrir o arquivo..\n");
        return 1;
    }

    double pesoMAX;
    int numPacotes;
    fscanf(arq, "%lf", &pesoMAX);       // lê peso máximo do drone
    fscanf(arq, "%d", &numPacotes);     // lê número de pacotes do dia

    galpao meuGalpao;
    drone meuDrone;
    int id_viagem = 1;
    inicializargalpao(&meuGalpao); // inicializa o galpao
    inicializardrone(&meuDrone, pesoMAX); //inicializa o drone agora com o peso maximo

    // Leitura dos pacotes e adiciona ao galpão
    for(int i = 0; i < numPacotes; i++) {
        char conteudo[30], destinatario[30];
        double peso, distancia;
        fscanf(arq, "%s %s %lf %lf", conteudo, destinatario, &peso, &distancia);
        pacote p;
        inicializarpacote(&p, conteudo, destinatario, peso, distancia); //inicializa o pacote
        receberpacote(&meuGalpao, &p); //adiciona o pacote ao galpão
    }

    fclose(arq);

    // Simula as viagens do drone até o galpão ficar vazio
    while(meuGalpao.l.primeiro != NULL) {
        carregarpacotes(&meuGalpao, &meuDrone); // carrega os pacotes no drone até atingir peso máximo
        lista l; 
        inicializarlista(&l); // inicializa a lista temporária

        double dist_viagem = realizarentrega(&meuDrone, &l); // realiza a entrega e obtém distância da viagem

        imprimirdrone(&l, dist_viagem, id_viagem); //imprime a viagem e limpa a lista temporária

        id_viagem++; // viagem 1:, viagem 2: ...
    }

    // Imprime total de quilômetros percorridos no dia
    printf("Total de Quilômetros Percorridos no Dia: %.0lfkm.\n", meuDrone.dist_total);
    return 0;
}
