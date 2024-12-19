#include <stdio.h>
#include <stdlib.h>
#include "tarea2.h"

int main(int argc, char *argv[]) {

    if (argc != 4) {
        fprintf(stderr, "Uso: %s <tiempo_simulacion> <intervalo_llegada> <probabilidad de embarque>\n", argv[0]);
        return 1;
    }

    int tiempo_simulacion = atoi(argv[1]);
    int tiempo_intervalo = atoi(argv[2]);
    float probabilidad_embarque = atof(argv[3]);

    printf("Tiempo simulacion: %d\n", tiempo_simulacion);
    printf("Intervalo de llegada: %d\n", tiempo_intervalo);
    printf("Probabilidad de embarque: %.2f\n", probabilidad_embarque);

    cola *cola_espera = crea_cola(); // cola cuando las cargas esperan ser embarcadas
    cola *cola_embarque = crea_cola(); // cola cuando las cargas son embarcadas

    simular(cola_espera, cola_embarque, tiempo_simulacion, tiempo_intervalo, probabilidad_embarque);
    imprimir_informacion(cola_embarque, cola_espera);

    return 0;
}