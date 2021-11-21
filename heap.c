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
void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp){
    // HACER
}


// STRUCTS
typedef struct heap{
    void** datos;
    size_t cant;
    size_t tam;
    cmp_func_t cmp;
} heap_t;


// Funcion de debug. -- BORRAR PARA ENTREGA
void debug_heap(const heap_t* heap){
    printf("PRINTER DEBUGGER\n");
    for (size_t i = 0; i < heap->cant; i++){
        printf("    %d\n", *(int*)heap->datos[i]);
    }
    printf("FIN PRINTER DEBUGGER\n");
}


// PRIMITIVAS HEAP
heap_t *heap_crear(cmp_func_t cmp){
    heap_t* nuevo_heap = malloc(sizeof(heap_t));
    if (nuevo_heap == NULL) return NULL;

    nuevo_heap->datos = malloc(nuevo_heap->tam * sizeof(void*));
    if (nuevo_heap->datos == NULL) return NULL;

    nuevo_heap->cant = 0;
    nuevo_heap->cmp = cmp;
    nuevo_heap->tam = CAP_INIC;
    return nuevo_heap;
}


// Función auxiliar que retorna true si el primer valor es mayor que el segundo.
bool aux_cumple_heap(heap_t* heap, size_t posicion1, size_t posicion2){
    if (posicion1 == posicion2) return true;
    void* elem_pos1 = heap->datos[posicion1];
    void* elem_pos2 = heap->datos[posicion2];

    cmp_func_t funcion_cmp = heap->cmp;
    int resultado = funcion_cmp(elem_pos1, elem_pos2);

    return (resultado > 0);
}


// Funcion auxiliar de swap. Recibe punteros (llamar con &)
bool aux_swap_generico(void* x, void* y) { // <---------------------------------------------------- Testear
    void* aux = malloc(sizeof(void*));
    if (aux == NULL) return false;

    memcpy(aux, x, sizeof(void*));
    memcpy(x, y, sizeof(void*));
    memcpy(y, aux, sizeof(void*));
    return true;
}


void aux_upheap(){
    // HACER
}


void aux_downheap(){
    // HACER
}


// Funcion auxiliar para ordenar los arreglos para que cumplan las condiciones del heap
void aux_ordenar_arreglo_entero(heap_t* heap){
    // ESTA FUNCION ORDENA UN ARREGLO PARA QUE CUMPLA CON LAS CONDICIONES DE UN HEAP
}


// Función auxiliar de heap_guardar y heap_borrar
void aux_redimensionar(heap_t* heap, size_t nueva_cap){
    // Revisar nueva cap >= CAP_INIC
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
    heap->datos[heap->cant] = elem;
    size_t pos_nuevo = heap->cant;
    size_t pos_padre = (pos_nuevo -1) / 2;

    if (!aux_cumple_heap(heap, pos_padre, pos_nuevo)){
        aux_upheap();
    }
    heap->cant++;
    if (heap->cant == heap->tam) aux_redimensionar(heap, heap->tam * FACTOR_NVA_CAP);
    return true; 
}


void *heap_desencolar(heap_t *heap){
    if (heap->cant == 0) return NULL;
    void* dato_a_retornar; // = GUARDAR DATO
    // ? Sacar de arreglo
    // Reordenar para que cumpla con condiciones de heap -- HACER FUNCION AUX --
    heap->cant--;
    if (heap->cant == heap->tam / FACTOR_CARGA_MINIMA) aux_redimensionar(heap, heap->tam / FACTOR_NVA_CAP);
    return dato_a_retornar;
}


void *heap_ver_max(const heap_t *heap){
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
