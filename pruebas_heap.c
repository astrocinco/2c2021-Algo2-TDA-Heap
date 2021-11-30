#include <stdio.h>
#include <stdlib.h>
#include "testing.h"
#include <string.h>
#include "heap.h"
//#define RAND_MAX 1000


// Retorna 1 si el primer valor es mayor que el segundo
int aux_num_es_mayor(const void* dato1, const void* dato2){
    size_t num1 = *(size_t*) dato1;
    size_t num2 = *(size_t*) dato2;
    if (num1 == num2){
        return 0;
    }
    if (num1 > num2){
        return 1;
    }
    return -1;
}


// Retorna 1 si el primer valor del arreglo1 es mayor que el primer valor del arreglo2
/*
int aux_arreglo_es_mayor(const void* arreglo_1, const void* arreglo_2){
    int** arreglo_11 = arreglo_1;
    int** arreglo_22 = arreglo_2;
    if (arreglo_11[0] > arreglo_22[0]){
        return 1;
    }
    return -1;
}
*/

int comparar_char(const void* primero, const void* segundo){
    const char* pri = primero;
    const char* seg = segundo;
    if (*pri == *seg){
        return 0;
    }
    if ((*pri) > (*seg)){
        return 1;
    }
    return -1;

}

void pruebas_heap_vacio(){
    printf("\nPRUEBAS HEAP: Vacío\n");
    heap_t* heap = heap_crear(aux_num_es_mayor);

    print_test("La cantidad es 0", heap_cantidad(heap) == 0);
    print_test("El heap está vacío", heap_esta_vacio(heap));
    void* sacado = heap_desencolar(heap);
    print_test("Sale NULL del heap vacío", sacado == NULL);

    heap_destruir(heap, NULL);
}


void pruebas_heap_un_elemento(){
    printf("\nPRUEBAS HEAP: Un elemento\n");
    char* letra_1 = "A";
    heap_t* heap = heap_crear(comparar_char);

    print_test("El heap está vacío", heap_esta_vacio(heap));
    print_test("Puedo encolar A", heap_encolar(heap, letra_1));
    print_test("La cantidad es 1", heap_cantidad(heap) == 1);
    char* sacado = heap_desencolar(heap);
    print_test("Sale 'A'", strcmp(letra_1, sacado) == 0);

    heap_destruir(heap, NULL);
}


void pruebas_heap_varios_elem(){
    printf("\nPRUEBAS HEAP: Varios elementos\n");
    int num_1 = 1;
    int num_2 = 2;
    int num_3 = 3;
    int num_4 = 4;

    heap_t* heap = heap_crear(aux_num_es_mayor);

    print_test("Puedo encolar 2", heap_encolar(heap, &num_2));
    print_test("Puedo encolar 4", heap_encolar(heap, &num_4));
    print_test("El heap no está vacío", !heap_esta_vacio(heap));
    print_test("La cantidad es 2", heap_cantidad(heap) == 2); 
    print_test("Puedo encolar 1", heap_encolar(heap, &num_1));
    print_test("Puedo encolar 3", heap_encolar(heap, &num_3));
    print_test("La cantidad es 4", heap_cantidad(heap) == 4);
    int* tope = heap_ver_max(heap);
    print_test("El máximo elemento es 4", *tope == num_4);
    
    //debug_heap(heap);
    // Sacar uno por uno
    int* sacado = heap_desencolar(heap);
    print_test("Salió 4", *sacado == num_4);
    //debug_heap(heap);
    sacado = heap_desencolar(heap);
    print_test("Salió 3", *sacado == num_3);
    //debug_heap(heap);
    sacado = heap_desencolar(heap);
    print_test("Salió 2", *sacado == num_2);
    sacado = heap_desencolar(heap);
    print_test("Salió 1", *sacado == num_1);
    sacado = heap_desencolar(heap);
    print_test("Salió NULL", sacado == NULL);
    
    heap_destruir(heap, NULL);
}


void pruebas_heap_muchos_elem(){
    printf("\nPRUEBAS HEAP: Muchos elementos\n");
    int num_1 = 1;
    int num_2 = 2;
    int num_3 = 3;
    int num_4 = 4;
    int num_5 = 5;
    int num_6 = 6;
    int num_7 = 7;

    heap_t* heap = heap_crear(aux_num_es_mayor);

    print_test("Puedo encolar 5", heap_encolar(heap, &num_5));
    //debug_heap(heap);
    print_test("Puedo encolar 2", heap_encolar(heap, &num_2));
    print_test("Puedo encolar 4", heap_encolar(heap, &num_4));
    print_test("Puedo encolar 6", heap_encolar(heap, &num_6));
    //debug_heap(heap);
    print_test("El heap no está vacío", !heap_esta_vacio(heap));
    print_test("La cantidad es 2", heap_cantidad(heap) == 4); 
    print_test("Puedo encolar 1", heap_encolar(heap, &num_1));
    print_test("Puedo encolar 3", heap_encolar(heap, &num_3));
    print_test("Puedo encolar 7", heap_encolar(heap, &num_7));
    //debug_heap(heap);
    print_test("La cantidad es 4", heap_cantidad(heap) == 7);
    int* tope = heap_ver_max(heap);
    print_test("El máximo elemento es 7", *tope == num_7);
    
    //debug_heap(heap);
    // Sacar uno por uno
    //printf("\n");
    int* sacado = heap_desencolar(heap);
    print_test("Salió 7", *sacado == num_7);
    //debug_heap(heap);
    sacado = heap_desencolar(heap);
    print_test("Salió 6", *sacado == num_6);
    //debug_heap(heap);
    sacado = heap_desencolar(heap);
    print_test("Salió 5", *sacado == num_5);
    //debug_heap(heap);
    sacado = heap_desencolar(heap);
    print_test("Salió 4", *sacado == num_4);
    //debug_heap(heap);
    sacado = heap_desencolar(heap);
    print_test("Salió 3", *sacado == num_3);
    //debug_heap(heap);
    sacado = heap_desencolar(heap);
    print_test("Salió 2", *sacado == num_2);
    sacado = heap_desencolar(heap);
    print_test("Salió 1", *sacado == num_1);
    sacado = heap_desencolar(heap);
    print_test("Salió NULL", sacado == NULL);
    
    heap_destruir(heap, NULL);
}


void pruebas_heap_copiar_arreglo(){
    printf("\nPRUEBAS HEAP: Copiar arreglo\n");
    int arreglo_ints_cor[10] = {5, 4, 3, 2, 1, 0};
    int* arreglo_p_ints_cor[10];
    for (int j = 0; j < 6; j++){ // Tal vez esto tenga que ser un 6
        arreglo_p_ints_cor[j] = &arreglo_ints_cor[j];
    }

    int arreglo_ints[10] = {3, 5, 4, 0, 1, 2};
    void* arreglo_p_ints[10];
    for (int i = 0; i < 6; i++){ // Tal vez esto tenga que ser un 6
        arreglo_p_ints[i] = &arreglo_ints[i];
    }

    heap_t* heap = heap_crear_arr(arreglo_p_ints, 6, aux_num_es_mayor);

    print_test("La cantidad es 6", heap_cantidad(heap) == 6);
    //printf("La cantidad es %lu\n", heap_cantidad(heap));
    //print_test("El máximo es correcto", *(int*)heap_ver_max(heap) == *(int*)arreglo_p_ints_cor[0]); // DESCOMENTAR
    printf("El maximo es %i\n", *(int*)heap_ver_max(heap));

    bool todo_ok = true;
    int* sacado;
    for (int k = 0; k < 6; k++){
        sacado = heap_desencolar(heap);
        if (sacado != arreglo_p_ints_cor[k]) todo_ok = false;
        printf("    Salió %i\n", *sacado);
    }
    print_test("Salen todos los elementos de forma ordenada", todo_ok);

    heap_destruir(heap, NULL);
}


void pruebas_heapsort(){
    printf("\nPRUEBAS HEAP: Heapsort\n");

    bool todo_ok = true;
    int arreglo_int[8] = {1, 3, 9, 7,5,6,8};

    int arreglo_cor[8] = {9,8, 7,6,5, 3, 1};


    void* arreglo_pu[8];
    for (int i = 0; i < 4; i++){ // Tal vez esto tenga que ser un 4
        arreglo_pu[i] = &arreglo_int[i];
    }
    heap_sort(arreglo_pu, 7, aux_num_es_mayor);

    for (int j = 0; j < 4; j++){
        printf("%i   xxDD\n", (*(int*)arreglo_pu[j]));
        if ( (*(int*)arreglo_pu[j]) != arreglo_cor[j]){
            todo_ok = false; 
        }
    }



    print_test("Heapsort ordenó correctamente el arreglo", todo_ok);
    // Ingresar arreglo y recibir "arreglo_ordenado"
    // REvisar que arreglo ordenado esté bien ordenado
    // Revisar que ambos punteros son los mismos, es in-place (REVISAR CONCEPTO)
    // Destruir
}


void pruebas_heap_destruir_NULL(){
    printf("\nPRUEBAS HEAP: Destruir con NULL\n");

    int num_1 = 1;
    int num_2 = 2;
    int num_3 = 3;
    int num_4 = 4;

    heap_t* heap = heap_crear(aux_num_es_mayor);
    print_test("Puedo encolar 4", heap_encolar(heap, &num_4));
    print_test("Puedo encolar 2", heap_encolar(heap, &num_2));
    print_test("Puedo encolar 3", heap_encolar(heap, &num_3));
    print_test("Puedo encolar 1", heap_encolar(heap, &num_1));
    print_test("La cantidad es 4", heap_cantidad(heap) == 4);

    heap_destruir(heap, NULL);
}


void pruebas_heap_destruir_NONULL(){
    printf("\nPRUEBAS HEAP: Destruir con NO NULL\n");
    int arreglo_aux[4] = {0, 1, 2, 3};

    void** arreglo_1 = malloc(100);
    arreglo_1[0] = &arreglo_aux[0];
    void** arreglo_2 = malloc(200);
    arreglo_2[0] = &arreglo_aux[1];
    void** arreglo_3 = malloc(300);
    arreglo_3[0] = &arreglo_aux[2];
    void** arreglo_4 = malloc(400);
    arreglo_4[0] = &arreglo_aux[3];

    heap_t* heap = heap_crear(aux_num_es_mayor);
    print_test("Puedo encolar 4", heap_encolar(heap, arreglo_1));
    print_test("Puedo encolar 2", heap_encolar(heap, arreglo_2));
    print_test("Puedo encolar 3", heap_encolar(heap, arreglo_3));
    print_test("Puedo encolar 1", heap_encolar(heap, arreglo_4));
    print_test("La cantidad es 4", heap_cantidad(heap) == 4);

    heap_destruir(heap, free);
}


void pruebas_heap_volumen(size_t volumen){
    printf("\nPRUEBAS HEAP: Volumen\n");

    size_t arreglo[volumen];
    size_t* ultimo;
    size_t* actual;
    bool todo_ok = true;
    heap_t* heap = heap_crear(aux_num_es_mayor);

    for (size_t i = 0; i < volumen; i++){
        arreglo[i] = rand()%500;
        //printf("    Arreglo: %lu\n", arreglo[i]);
        heap_encolar(heap, &arreglo[i]);
    } // Hacer un print_test para verificar si el arreglo auxiliar se creó bien?

    ultimo = heap_desencolar(heap);
    for (size_t j = 0; j < volumen-1; j++){
        actual = heap_desencolar(heap);
        printf("ultimo:%lu    actual:%lu\n",*(size_t*)ultimo, *(size_t*)actual);
        if (*actual > * ultimo){
            printf("aca\n");
            todo_ok = false;
        }
        ultimo = actual; // Revisar
    }
    print_test("Las pruebas de volumen desencolan de mayor a menor", todo_ok);

    heap_destruir(heap, NULL);
}

void pruebas_upheap_downheap(){
    heap_t* heap = heap_crear(comparar_char);

    void* a = "a";
    void* b = "b";
    void* c = "c";
    void* d = "d";
    void* e = "e";
    void* f = "f";
    void* g = "g";

    print_test("se encola b",heap_encolar(heap,b));
    print_test("se encola f",heap_encolar(heap,f));
    print_test("se encola a",heap_encolar(heap,a));
    print_test("se encola c",heap_encolar(heap,c));
    print_test("se encola g",heap_encolar(heap,g));
    print_test("se encola e",heap_encolar(heap,e));
    print_test("se encola d",heap_encolar(heap,d));

    void* arreglo[7] = {g,f,b,e,c,a,d};

    heap_sort(arreglo,7,comparar_char);

    for (int i = 0; i < 7; ++i){
        printf("%c\n", (*(char*)arreglo[i]));
    }

}

// Llama a cada prueba
void pruebas_abb_estudiante(){
    /*
    pruebas_heap_vacio(); // :)
    pruebas_heap_un_elemento(); // :)
    pruebas_heap_varios_elem(); // :)
    pruebas_heap_muchos_elem();// :)
    pruebas_heap_destruir_NULL(); // :)
    pruebas_heap_destruir_NONULL(); // :)
    pruebas_heap_volumen(100); // :)
    pruebas_heap_volumen(10000); // :)
    */

    /*
    pruebas_heap_copiar_arreglo(); // Ordenar arreglo
    pruebas_heapsort(); // Ordenar arreglo    
    pruebas_upheap_downheap();
    */
}

#ifndef CORRECTOR // Para que no dé conflicto con el main() del corrector.

int main(void){
	pruebas_abb_estudiante();
	return failure_count() > 0; // Indica si falló alguna prueba.
}

#endif //CORRECTOR