#include <stdio.h>
#include <stdlib.h>
#include "tarea2.h"

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

// encolar(c, d) agrega el dato d al final de la cola c
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
		printf("Cola: ");
		while (ptr != NULL) {
			printf("C%d ", ptr->num_carga);
			ptr = ptr->siguiente;
		}
		printf("\n");
	} else {
		printf("Cola vacia\n");
	}
}

/*------------- operaciones SIMULACION -------------*/