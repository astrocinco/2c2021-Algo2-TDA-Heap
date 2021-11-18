#include <stdio.h>
#include <stdlib.h>
#include "testing.h"
#include <string.h>
#include "heap.h"

void pruebas_heap_vacio(){
    printf("\nPRUEBAS HEAP: x\n");
}


void pruebas_heap_un_elemento(){
    printf("\nPRUEBAS HEAP: x\n");
}


void pruebas_heap_copiar_arreglo(){
    printf("\nPRUEBAS HEAP: x\n");
}


void pruebas_heapsort(){
    printf("\nPRUEBAS HEAP: x\n");
}


void pruebas_heap_destruir_NULL(){
    printf("\nPRUEBAS HEAP: x\n");
}


void pruebas_heap_destruir_NONULL(){
    printf("\nPRUEBAS HEAP: x\n");
}


void pruebas_heap_volumen(){
    printf("\nPRUEBAS HEAP: x\n");
}

// Llama a cada prueba
void pruebas_abb_estudiante(){
    pruebas_heap_vacio();
    pruebas_heap_un_elemento();
    pruebas_heap_copiar_arreglo();
    pruebas_heapsort();
    pruebas_heap_volumen();
    pruebas_heap_destruir_NULL();
    pruebas_heap_destruir_NONULL();
}

#ifndef CORRECTOR // Para que no dé conflicto con el main() del corrector.

int main(void){
	pruebas_abb_estudiante();
	return failure_count() > 0; // Indica si falló alguna prueba.
}

#endif //CORRECTOR