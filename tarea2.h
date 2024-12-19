#include <stdio.h> 
#include <stdlib.h>

/*------------- estructura de datos -------------*/
typedef struct{
    int tiempo_carga;
    int tiempo_embarque;
    int tiempo_permanencia;
    int tiempo_activacion;
} datos;

typedef struct carga{
    int num_carga;
    datos* datos_carga;
    struct carga *siguiente;
}carga;

typedef struct{
 	carga* frente;
    carga* final;
}cola;

/*------------- operaciones COLA -------------*/

cola* crea_cola();
int es_cola_vacia(cola *c);
void encolar(cola* c, datos* datos_carga, int num_carga);
void desencolar(cola* c);
carga* frente(cola* c);
carga* final(cola* c);
void imprime_cola(cola* c);
int contar_cola(cola* c);

/*------------- operaciones SIMULACION -------------*/

int embarcar(float probabilidad);
void simular(cola* cola_espera, cola* cola_embarque ,int tiempo_simulacion, int tiempo_intervalo, float probabilidad_embarque);
void imprimir_informacion(cola* cola_embarque, cola* cola_espera);
void imprimir_tiempo_activacion(cola* cola_embarque);
void imprimir_momento_embarque(cola* cola_embarque, cola* cola_espera);
void imprimir_tiempo_permanencia(cola* cola_embarque, cola* cola_espera);
float promedio_tiempo_permanencia(cola* cola_embarque);