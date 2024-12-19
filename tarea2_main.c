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

    for (int i = 0; i < 10; i++) {
        int prob = embarcar(probabilidad_embarque);
        (prob) ? printf("Embarque exitoso: %d\n", prob) : printf("Embarque fallido: %d\n", prob);
    }


    return 0;
}