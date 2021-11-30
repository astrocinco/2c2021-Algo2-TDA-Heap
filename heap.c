// NOTAS INTRAEQUIPO -- BORRAR PARA ENTREGA
// * No se si existe un estandar de resultados de notas de comparacion. Por ahora voy a usar que 
//   cmp(elem1, elem2) da negativo cuando elem1 es menor, y positivo cuando elem1 mayor (porque es así en strcmp)

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 
#include <stddef.h> 
#include <string.h>
#include "heap.h"

#define CAP_INIC 50ul
#define FACTOR_NVA_CAP 2ul
#define FACTOR_CARGA_MINIMA 2


// Funcion de algoritmo de ordenamiento heap_sort. No es parte del TDA-Heap

// Funcion auxiliar de swap. Recibe punteros (llamar con &)
bool aux_swap_generico(void* x, void* y) {
    void* aux = malloc(sizeof(void*));
    if (aux == NULL) return false;

    memcpy(aux, x, sizeof(void*));
    memcpy(x, y, sizeof(void*));
    memcpy(y, aux, sizeof(void*));
    free(aux);
    return true;
}



// STRUCTS
typedef struct heap{
    void** datos;
    size_t cant;
    size_t tam;
    cmp_func_t cmp;
} heap_t;


// PRIMITIVAS HEAP
heap_t *heap_crear(cmp_func_t cmp){
    heap_t* nuevo_heap = malloc(sizeof(heap_t));
    if (nuevo_heap == NULL) return NULL;

    nuevo_heap->cant = 0;
    nuevo_heap->cmp = cmp;
    nuevo_heap->tam = CAP_INIC;

    nuevo_heap->datos = malloc(nuevo_heap->tam * sizeof(void*));
    if (nuevo_heap->datos == NULL) return NULL;
    return nuevo_heap;
}


// Función auxiliar que retorna true si el primer valor es mayor que el segundo.
bool aux_es_mayor(void* arreglo[],size_t n, size_t posicion1, size_t posicion2,cmp_func_t cmp){
    //printf("C59 %lu %lu\n", posicion1, posicion2);
    if (posicion1 == posicion2) return true;

    if (posicion1 > n || posicion2 > n){
        printf("Kawabunga\n");
        return false; // ARREGLAR. LEE DONDE NO HAY NADA
    }
    void* elem_pos1 = arreglo[posicion1];
    void* elem_pos2 = arreglo[posicion2];
    //printf("C66 %d %d\n", *(int*)elem_pos1, *(int*)elem_pos2);

    int resultado = cmp(elem_pos1, elem_pos2);

    return (resultado > 0);
}




// Funcion auxiliar heap_encolar
// Esta funcion presupone que se sabe que es correcto hacer un unheap
void aux_upheap(void* arreglo[],size_t n, size_t pos_padre, size_t pos_inferior, cmp_func_t cmp){
    //printf("UPHEAP\n");
    aux_swap_generico(&arreglo[pos_padre], &arreglo[pos_inferior]);
    if (pos_padre == 0){
        return;
    } 
    pos_inferior = pos_padre;
    pos_padre = (pos_padre -1) / 2;
    //printf("C96 %lu %lu\n", pos_inferior, pos_padre);
    if (!aux_es_mayor(arreglo,n, pos_padre, pos_inferior,cmp)){
        aux_upheap(arreglo,n, pos_padre, pos_inferior,cmp);
    }
}


void aux_downheap(void* arreglo[],size_t n, size_t pos_padre,cmp_func_t cmp){
    size_t pos_hijo_izq = (2 * pos_padre) +1;
    size_t pos_hijo_der = (2 * pos_padre) +2;

    if (pos_hijo_der >= n && pos_hijo_izq < n){ 
    // Der no existe, izq si
        aux_swap_generico(&arreglo[pos_padre], &arreglo[pos_hijo_izq]);
        pos_padre = pos_hijo_izq;
    } else if (pos_hijo_der < n){ // Ambos existen
        if (aux_es_mayor(arreglo, n, pos_hijo_izq, pos_hijo_der, cmp)){ // Se elige el mayor de los dos
            aux_swap_generico(&arreglo[pos_padre], &arreglo[pos_hijo_izq]); 
            // Acá izq es mayor que der
            pos_padre = pos_hijo_izq;
        }else{
            aux_swap_generico(&arreglo[pos_padre], &arreglo[pos_hijo_der]); 
            // Acá der es mayor que izq
            pos_padre = pos_hijo_der;
        }
    } else if (pos_hijo_izq >= n){ // Izq y der no existen
        return;
    } else {
        printf("ERROR AUX_DOWNHEAP NO DEBERÍA LLEGAR ACÁ");
    }
    aux_downheap(arreglo, n, pos_padre, cmp);
}












// https://www.youtube.com/watch?v=gc4MdD10w7w&t=6s

// Funcion auxiliar para heapify
void heapify(void* arreglo[], size_t cant, cmp_func_t cmp,size_t actual){ // REHACER
    for (int i = cant -1; i >= 0; i--){
        printf("C137 %d\n", i);
        aux_downheap(arreglo, cant, i, cmp);
    }
}


void heap_sort(void *arr[], size_t cant, cmp_func_t cmp){ // REVISAR TEORÍA
    heapify(arr,cant,cmp,0);

    int pos_maximo = 0;
    for (int i = 0; i < cant-1; i++){
        aux_swap_generico(arr[pos_maximo],arr[cant-1-i]);
        aux_downheap(arr,cant,pos_maximo,cmp);
    }
}

// Función auxiliar de heap_guardar y heap_borrar
void aux_redimensionar(heap_t* heap, size_t nueva_cap){
    printf("REDIMENSION. Vieja: %lu, nueva: %lu\n", heap->tam, nueva_cap);
    if (nueva_cap < CAP_INIC) nueva_cap = CAP_INIC;

    void** nuevo_arreglo = realloc(heap->datos, nueva_cap * sizeof(void*));
    if (nuevo_arreglo == NULL) return;
    heap->datos = nuevo_arreglo;
    heap->tam = nueva_cap;
}


heap_t *heap_crear_arr(void* arreglo[], size_t n, cmp_func_t cmp){
    heap_t* nuevo_heap = malloc(sizeof(heap_t));
    if (nuevo_heap == NULL) return NULL;

    for (int i = 0; i < n; i++){
        printf("C170 original arr[%i] = %i\n", i, *(int*)arreglo[i]);
    }

    nuevo_heap->cmp = cmp;
    nuevo_heap->tam = CAP_INIC;
    nuevo_heap->datos = arreglo;
    nuevo_heap->cant = n;
    printf("C193\n");
    heapify(arreglo, n, cmp, 0); // ASEGURARSE QUE QUEDE ORDENADO DESPUES DE LLAMAR HEAPIFY
    printf("C195\n");
    for (int i = 0; i < n; i++){
        printf("C196 arr[%i] = %i\n", i, *(int*)arreglo[i]);
    }
    
    return nuevo_heap;
}


bool heap_esta_vacio(const heap_t* heap){
    //printf("C152 %p\n", &heap->cant);
    return heap->cant == 0;
}


size_t heap_cantidad(const heap_t* heap){
    //printf("C157 %lu\n", heap->cant);
    size_t valor = heap->cant;
    return valor;
}


bool heap_encolar(heap_t *heap, void *elem){
    heap->datos[heap->cant] = elem;
    heap->cant++;
    //printf("C165 %lu\n", heap->cant);
    if (heap->cant == 1) return true;
    size_t pos_nuevo = heap->cant -1;
    size_t pos_padre = (pos_nuevo -1) / 2;

    if (!aux_es_mayor(heap->datos,heap->cant, pos_padre, pos_nuevo,heap->cmp)){
        //printf("Mando a UPHEAP\n");
        aux_upheap(heap->datos,heap->cant, pos_padre, pos_nuevo,heap->cmp);
    }
    if (heap->cant == heap->tam) aux_redimensionar(heap, heap->tam * FACTOR_NVA_CAP);
    //printf("C178 %lu %p\n", heap->cant, &heap->cant);
    return true; 
}


void* heap_desencolar(heap_t *heap){
    if (heap_esta_vacio(heap)) return NULL;

    printf("\n225\n");
    debug_heap(heap);
    void* dato = heap->datos[0];
    heap->cant--; 
    if (heap->cant == 0) return dato;
    aux_swap_generico(&heap->datos[0], &heap->datos[heap->cant]);
    printf("\n228\n");
    debug_heap(heap);
    aux_downheap(heap->datos, heap->cant,0,heap->cmp);
    printf("\n231\n");
    debug_heap(heap);

    if (heap->cant < heap->tam / FACTOR_CARGA_MINIMA && heap->tam > CAP_INIC) aux_redimensionar(heap, heap->tam / FACTOR_NVA_CAP);

    return dato;
}


void* heap_ver_max(const heap_t *heap){
    return heap->datos[0];
}


void heap_destruir(heap_t *heap, void (*destruir_elemento)(void *e)){
    if (destruir_elemento != NULL){
        for (size_t i = 0; i < heap->cant; i++){ // Revisar que no sea heap->datos +1
            destruir_elemento(heap->datos[i]);
        }
    }
    free(heap->datos);
    free(heap);
}
// FIN PRIMITIVAS HEAP


// Funcion de debug. -- BORRAR PARA ENTREGA
void debug_heap(const heap_t* heap){
    printf("DEBUGGER\n");
    
    /*
    int arreglo[10] = {0, 1, 2, 3, 4, 5};
    void* arreglo_p[10];
    for (int i = 0; i < 10; i++){
        arreglo_p[i] = &arreglo[i];
        printf("%d", *(int*)arreglo_p[i]);
    }
    printf("\n Swap \n");
    aux_swap_generico(&arreglo_p[1], &arreglo_p[4]);
    for (int i = 0; i < 10; i++){
        printf("%d", *(int*)arreglo_p[i]);
    }
    printf("\n");
    */

    //printf("Puntero heap->cant %p\n", &heap->cant);
    bool es_heap = true;
    void** arreglo = heap->datos;
    for (int i = heap->cant -1; i >= 0; i--){
        int* hijo = arreglo[i];
        int* padr = arreglo[(i-1) / 2];

        if (*hijo > *padr) es_heap = false;
    }
    
    printf("PRINTER DEBUGGER\n");
    for (size_t i = 0; i < heap->cant; i++){
        printf("    %d\n", *(int*)heap->datos[i]);
    }
    if (es_heap) printf("ES HEAP\n");
    if (!es_heap) printf(" ---- NO ES HEAP ----\n");
    printf("FIN PRINTER DEBUGGER\n");
    
}