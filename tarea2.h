#include <stdio.h> 
#include <stdlib.h>

/*------------- estructura de datos -------------*/
typedef struct{
    int tiempo_carga;
    int tiempo_embarque;
    int tiempo_permanencia;
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