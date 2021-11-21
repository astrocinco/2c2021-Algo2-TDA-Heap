#include <stdio.h>
#include <stdlib.h>
#include "testing.h"
#include <string.h>
#include "heap.h"
#include "pila.h"


int aux_num_es_mayor(size_t num1, size_t num2){
    if (num1 > num2) return 1;
    return -1;
}


void pruebas_heap_vacio(){
    printf("\nPRUEBAS HEAP: Vacío\n");
    heap_t* heap = heap_crear(aux_num_es_mayor);

    print_test("La cantidad es 0", heap_cantidad(heap) == 0);
    print_test("El heap está vacío", heap_esta_vacio(heap));
    void* sacado = heap_desencolar(heap);
    print_test("Sale NULL del heap vacío", sacado == NULL);

    printf("Aux num %d\n", aux_num_es_mayor(10, 8));

    heap_destruir(heap, NULL);
}


void pruebas_heap_un_elemento(){
    printf("\nPRUEBAS HEAP: Un elemento\n");
    char* letra_1 = "A";
    heap_t* heap = heap_crear(strcmp);

    print_test("El heap está vacío", heap_esta_vacio(heap));
    print_test("Puedo encolar A", heap_encolar(heap, letra_1));
    print_test("La cantidad es 1", heap_cantidad(heap) == 1);
    debug_heap(heap);
    char* sacado = heap_desencolar(heap);
    print_test("Sale 'A'", strcmp(letra_1, sacado));

    heap_destruir(heap, NULL);
}


void pruebas_heap_copiar_arreglo(){
    printf("\nPRUEBAS HEAP: Copiar arreglo\n");
    int arreglo_ints[10] = {3, 5, 4, 0, 1, 2};
    heap_t* heap = heap_crear_arr(arreglo_ints, 10, aux_num_es_mayor);

    print_test("La cantidad es 1", heap_cantidad(heap) == 6);

    // Crear con _copiar arreglo_
    // Revisar que el arreglo ahora tiene el orden correcto
    // Retorna maximo correcto
    // Cantidad == len(arreglo)
    // Borrar
    // Obtener
    // Destruir
}


void pruebas_heapsort(){
    printf("\nPRUEBAS HEAP: Heapsort\n");

    // Ingresar arreglo y recibir "arreglo_ordenado"
    // REvisar que arreglo ordenado esté bien ordenado
    // Revisar que ambos punteros son los mismos, es in-place (REVISAR CONCEPTO)
    // Destruir
}


void pruebas_heap_destruir_NULL(){
    printf("\nPRUEBAS HEAP: Destruir con NULL\n");

    // Crear 
    // Insertar elemento de memoria estatica
    // Destruir

    // Crear 
    // Insertar varios elementoa de memoria estatica
    // Destruir
}


void pruebas_heap_destruir_NONULL(){
    printf("\nPRUEBAS HEAP: Destruir con NO NULL\n");

    // Crear 
    // Insertar elemento de memoria dinamica
    // Destruir

    // Crear 
    // Insertar varios elementoa de memoria dinamica
    // Destruir
}


void pruebas_heap_volumen(size_t volumen){
    printf("\nPRUEBAS HEAP: Volumen\n");
}

// Llama a cada prueba
void pruebas_abb_estudiante(){
    pruebas_heap_vacio();
    pruebas_heap_un_elemento();
    pruebas_heap_copiar_arreglo();
    pruebas_heapsort();
    pruebas_heap_destruir_NULL();
    pruebas_heap_destruir_NONULL();
    pruebas_heap_volumen(1000);
    pruebas_heap_volumen(100000);
}

#ifndef CORRECTOR // Para que no dé conflicto con el main() del corrector.

int main(void){
	pruebas_abb_estudiante();
	return failure_count() > 0; // Indica si falló alguna prueba.
}

#endif //CORRECTOR