#include <stdbool.h> 
#include <stddef.h> 
#include "heap.h"

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

}

heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp){

}

bool heap_esta_vacio(const heap_t *heap){

}

size_t heap_cantidad(const heap_t *heap){

}

bool heap_encolar(heap_t *heap, void *elem){

}

void *heap_desencolar(heap_t *heap){

}

void *heap_ver_max(const heap_t *heap){

}

void heap_destruir(heap_t *heap, void (*destruir_elemento)(void *e)){

}
// FIN PRIMITIVAS HEAP