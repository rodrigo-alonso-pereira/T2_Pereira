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
            //[c=numero de carga_tc=tiempo de carga-te=tiempo de embarque-tp=tiempo de permanencia]
			printf("[c=%d_tc=%d-te=%d-tp=%d-ta=%d]\n", 
                ptr->num_carga, 
                ptr->datos_carga->tiempo_carga, 
                ptr->datos_carga->tiempo_embarque, 
                ptr->datos_carga->tiempo_permanencia,
                ptr->datos_carga->tiempo_activacion);
			ptr = ptr->siguiente;
		}
		printf("\n");
	} else {
		printf("[]\n\n");
	}
}

// contar_cola(c) cuenta los elementos de la cola c
// orden de complejidad: O(n)
int contar_cola(cola* c) {
    int count = 0;
    if (es_cola_vacia(c) == 0) {
        carga* ptr = c->frente;
        while (ptr != NULL) {
            count++;
            ptr = ptr->siguiente;
        }
    }
    return count;
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

// simular(cola_espera, cola_embarque, tiempo_simulacion, tiempo_intervalo, probabilidad_embarque) simula el proceso de embarque
// orden de complejidad: O(n)
void simular(cola* cola_espera, cola* cola_embarque ,int tiempo_simulacion, int tiempo_intervalo, float probabilidad_embarque) {
       //TODO: Implementar la simulación según las especificaciones del enunciado
       int count_tiempo = 0;
       int num_carga = 1;
       int proceso_embarque = 0; //Proceso de embarque no activo por defecto
       int tiempo_activacion = 0; //Tiempo en que se activa el embarque
       while (count_tiempo <= tiempo_simulacion) { //Mientras sea menor que el tiempo de simulacion
            printf("--------------------------------\n");
            printf("*** Tiempo de simulacion: %d ***\n", count_tiempo);
            printf("--------------------------------\n");
            if (count_tiempo % tiempo_intervalo == 0) { //Si el tiempo actual es multiplo del intervalo
                datos* datos_carga = (datos*)malloc(sizeof(datos)); //Crear datos de carga
                datos_carga->tiempo_carga = count_tiempo; //Asignar tiempo cuando entra a cola de espera 
                datos_carga->tiempo_embarque = 0; 
                datos_carga->tiempo_permanencia = 0;
                datos_carga->tiempo_activacion = 0;
                encolar(cola_espera, datos_carga, num_carga); //Encolar carga nueva
                num_carga++; //Aumentar numero de carga
            }
            int embarque = embarcar(probabilidad_embarque); //Embarcar
            if (embarque == 1 || proceso_embarque == 1) { //Si se puede embarcar o ya se esta embarcando
                if (!es_cola_vacia(cola_espera)) { //Si la cola de espera no esta vacia
                    printf("\n*Proceso de embarque activo ");
                    if (!proceso_embarque)
                        tiempo_activacion = count_tiempo; //Asignar tiempo de activacion de embarque
                    printf("desde tiempo %d...\n\n", tiempo_activacion);
                    proceso_embarque = 1; //Iniciar proceso de embarque
                    carga* carga_actual = frente(cola_espera); //Obtener carga actual
                    if (carga_actual->datos_carga->tiempo_carga < tiempo_activacion) { //Si el tiempo de la carga es menor al tiempo de inicio embarque
                        carga_actual->datos_carga->tiempo_embarque = count_tiempo; //Asignar tiempo de embarque
                        carga_actual->datos_carga->tiempo_permanencia = count_tiempo - carga_actual->datos_carga->tiempo_carga; //Asignar tiempo de permanencia
                        carga_actual->datos_carga->tiempo_activacion = tiempo_activacion; //Asignar tiempo de activacion de embarque
                        encolar(cola_embarque, carga_actual->datos_carga, carga_actual->num_carga); //Encolar carga en espera
                        desencolar(cola_espera); //Desencolar carga actual
                    } else { //Si n
                        proceso_embarque = 0; //Terminar proceso de embarque
                    }
                } else {
                    proceso_embarque = 0; //Terminar proceso de embarque
                }
            }
            printf("Cola de espera\n");
            imprime_cola(cola_espera);
            printf("Cola de embarque\n");
            imprime_cola(cola_embarque);
            count_tiempo++; //Aumentar tiempo en 1
       }
}

void imprimir_informacion(cola* cola_embarque, cola* cola_espera) {
    printf("\n\nRESUMEN DE SIMULACION:\n");
    printf("Tiempos de activacion de periodos de embarque: ");
    imprimir_tiempo_activacion(cola_embarque);
    
}

void imprimir_tiempo_activacion(cola* cola_embarque) {
    if (es_cola_vacia(cola_embarque) == 0) {
		carga* ptr = cola_embarque->frente;
        int tiempo_activacion = 0;
		while (ptr != NULL) {
            if (ptr->datos_carga->tiempo_activacion != tiempo_activacion) {
                printf("%d ", 
                    ptr->datos_carga->tiempo_activacion);
                tiempo_activacion = ptr->datos_carga->tiempo_activacion;
            }
            ptr = ptr->siguiente;   
		}
		printf("\n");
	} else {
		printf("0\n");
	} 
}

void imprimir_momento_embarque(cola* embarque, cola* espera) {
    
}