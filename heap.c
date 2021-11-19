// NOTAS INTRAEQUIPO -- BORRAR PARA ENTREGA
// * No se si existe un estandar de resultados de notas de comparacion. Por ahora voy a usar que 
//   cmp(elem1, elem2) da negativo cuando elem1 es menor, y pos cuando elem1 mayor (porque es así en strcmp)

#include <stdbool.h> 
#include <stddef.h> 
#include "heap.h"

#define CAP_INIC 50ul

// Funcion de algoritmo de ordenamiento heap_sort. No es parte del TDA-Heap
void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp){

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


// Funcion auxiliar para ordenar los arreglos para que cumplan las condiciones del heap
void NOMBRE_FUNC_AUX_ORDENAR(heap_t* heap){
    // DEFINIR NOMBRE
    // ESTA FUNCION ORDENA UN ARREGLO PARA QUE CUMPLA CON LAS CONDICIONES DE UN HEAP
}

// Función auxiliar de heap_guardar y heap_borrar
void NOMBRE_FUNC_AUX_REDIMENSIONAR(heap_t* heap, size_t nueva_cap){
    // DEFINIR NOMBRE
    // ESTA FUNCION CAMBIA LA CAPACIDAD DEL ARREGLO DEL HEAP
    heap->tam = nueva_cap;
}


heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp){
    heap_t* nuevo_heap = malloc(sizeof(heap_t));
    if (nuevo_heap == NULL) return NULL;

    nuevo_heap->cmp = cmp;
    nuevo_heap->tam = CAP_INIC;
    // heap->datos = arreglo --- HACER ---
    // Ordenar el arreglo recibido para que cumpla las condiciones de heap --- HACER ---

    return nuevo_heap;
}

bool heap_esta_vacio(const heap_t *heap){
    return heap->cant == 0;
}

size_t heap_cantidad(const heap_t *heap){
    return heap->cant;
}

bool heap_encolar(heap_t *heap, void *elem){
    // Insertar elemento en arreglo
    // Reordenar para que cumpla con condiciones de heap -- HACER FUNCION AUX --
    heap->cant++;
    // Revisar que no haya que redimensionar -- HACER FUNCION AUX --
    return true; // ¿Return false si no se pudo redimensionar? Habría que redimensionar antes de guardar?
}

void *heap_desencolar(heap_t *heap){
    // ¿Pertenece?
    void* dato_a_retornar; // = GUARDAR DATO
    // ? Sacar de arreglo
    // Reordenar para que cumpla con condiciones de heap -- HACER FUNCION AUX --
    heap->cant--;
    // Revisar si hay que redimensionar -- HACER FUNCION AUX --
    return dato_a_retornar;
}

void *heap_ver_max(const heap_t *heap){
    // Hay que retornar heap->datos[0] ¿No?
}

void heap_destruir(heap_t *heap, void (*destruir_elemento)(void *e)){
    // Iterar todo el arreglo y destruir los elementos con destruir_elemento
    free(heap->datos);
    free(heap);
}
// FIN PRIMITIVAS HEAP
