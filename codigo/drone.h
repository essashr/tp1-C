#ifndef DRONE_H
#define DRONE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"

typedef struct {
    double pesoMAX;
    double peso_carregado;
    double dist_total;
    lista l;
} drone;

void inicializardrone(drone* d, double pesoMAX);
int carregamentopacote(drone* d, pacote* p);
double realizarentrega(drone* d, lista* l);
void imprimirdrone(lista* l, double dist_viagem, int id);

#endif