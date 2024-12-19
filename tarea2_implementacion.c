#include <stdio.h>
#include <stdlib.h>
#include "tarea2.h"
#include <time.h>


/*------------- operaciones COLA -------------*/

// crea_cola() crea y retorna una cola vacía
// orden de complejidad: O(1)
cola* crea_cola() {
    cola* c = (cola*)malloc(sizeof(cola));
    c->frente = NULL;
    c->final = NULL;
    return c;
}

// es_cola_vacia(c) determina si la cola c está vacía
// orden de complejidad: O(1)
int es_cola_vacia(cola* c) {
    if (c->frente == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// encolar(c, datos_carga, num_carga) agrega un elemento a la cola c
// orden de complejidad: O(1)
void encolar(cola* c, datos* datos_carga, int num_carga) {
    carga* n = (carga*)malloc(sizeof(carga));
    n->datos_carga = datos_carga;
    n->num_carga = num_carga;
    n->siguiente = NULL;
    if (c->frente == NULL) {
        c->frente = n;
        c->final = n;
    } else {
        c->final->siguiente = n;
        c->final = n;
    }
}

// desencolar(c) elimina el primer elemento de la cola c
// orden de complejidad: O(1)
void desencolar(cola* c) {
    if (es_cola_vacia(c) == 0) {
        carga* ptr_aux = c->frente;
        c->frente = c->frente->siguiente;
        free(ptr_aux);
    } else {
        c->final = NULL;
    }
}

// frente(c) retorna el primer elemento de la cola c
// orden de complejidad: O(1)
carga* frente(cola* c) {
    if (es_cola_vacia(c) == 0) {
        return c->frente;
    }
    return NULL;
}

// final(c) retorna el último elemento de la cola c
// orden de complejidad: O(1)
carga* final(cola* c) {
    if (es_cola_vacia(c) == 0) {
        return c->final;
    }
    return NULL;
}

// imprime_cola(c) imprime los elementos de la cola c
// orden de complejidad: O(n)
void imprime_cola(cola* c) {
	if (es_cola_vacia(c) == 0) {
		carga* ptr = c->frente;
		while (ptr != NULL) {
			printf("[c=%d_tc=%d-te=%d-tp=%d]\n", 
                ptr->num_carga, 
                ptr->datos_carga->tiempo_carga, 
                ptr->datos_carga->tiempo_embarque, 
                ptr->datos_carga->tiempo_permanencia);
			ptr = ptr->siguiente;
		}
		printf("\n");
	} else {
		printf("Cola vacia\n");
	}
}

/*------------- operaciones SIMULACION -------------*/

// embarcar(probabilidad) simula el embarque de un pasajero
// orden de complejidad: O(1)
int embarcar(float probabilidad) {
    float aleatorio = 1.0 * rand()/RAND_MAX;
    if (aleatorio < probabilidad) {
        return 1;
    } else {
        return 0;
    };
}

void simular(cola* cola_embarque, cola* cola_espera ,int tiempo_simulacion, int tiempo_intervalo, float probabilidad_embarque) {
       //TODO: Implementar la simulación según las especificaciones del enunciado
       int count_tiempo = 0;
       int num_carga = 1;
       while (count_tiempo <= tiempo_simulacion) { //Mientras sea menor que el tiempo de simulacion
            //printf("Tiempo: %d\n", count_tiempo);
            if (count_tiempo % tiempo_intervalo == 0) { //Si el tiempo actual es multiplo del intervalo
                datos* datos_carga = (datos*)malloc(sizeof(datos)); //Crear datos de carga
                datos_carga->tiempo_carga = count_tiempo; //Asignar tiempo cuando entra a cola de espera 
                datos_carga->tiempo_embarque = 0; 
                datos_carga->tiempo_permanencia = 0;
                encolar(cola_embarque, datos_carga, num_carga); //Encolar carga nueva
                num_carga++; //Aumentar numero de carga
            }
            count_tiempo++; //Aumentar tiempo en 1
       }
       
}