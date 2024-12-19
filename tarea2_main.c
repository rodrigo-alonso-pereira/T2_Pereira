#include <stdio.h>
#include <stdlib.h>
#include "tarea2.h"

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        fprintf(stderr, "Uso: %s <tiempo_simulacion> <intervalo_llegada> <probabilidad de embarque>\n", argv[0]);
        return 1;
    }

    int tiempo_simulacion = atoi(argv[1]);
    int tiempo_intervalo = atoi(argv[2]);
    float probabilidad_embarque = atof(argv[3]);

    printf("Tiempo simulacion: %d\n", tiempo_simulacion);
    printf("Intervalo de llegada: %d\n", tiempo_intervalo);
    printf("Probabilidad de embarque: %.2f\n", probabilidad_embarque);

    cola *cola_embarque = crea_cola(); // cola cuando las cargas son embarcadas
    cola *cola_espera = crea_cola(); // cola cuando las cargas esperan ser embarcadas

    simular(cola_embarque, cola_espera, tiempo_simulacion, tiempo_intervalo, probabilidad_embarque);
    printf("Cola de embarque\n");
    //printf("Frente: %d\n", frente(cola_embarque)->num_carga);
    //printf("Final: %d\n", final(cola_embarque)->num_carga);
    imprime_cola(cola_embarque);

    /*double count = 0.0;
    for (int i = 0; i < 1000; i++) {
        int prob = embarcar(probabilidad_embarque);
        if (prob) {
          printf("Embarque exitoso: %d\n", prob);
          count++;  
        } else {
          printf("Embarque fallido: %d\n", prob);  
        }
    }
    printf("Embarques exitosos: %.2f\n", count/1000);
    */

    return 0;
}