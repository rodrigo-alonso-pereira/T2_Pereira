#include <stdio.h>
#include <stdlib.h>
#include "tarea2.h"

/*------------- operaciones COLA -------------*/

cola* crea_cola(void);
int es_cola_vacia(cola *c);
void encolar(cola* c, int d);
void desencolar(cola* c);
carga* frente(cola* c);
carga* final(cola* c);
void imprime_cola(cola* c);