#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include <string.h>

#define DIM 30
/*Estructuras----------------------------------------------------------------------*/
typedef struct nodoDoble {
    int dato;
    struct nodoDoble *ptrAnterior;
    struct nodoDoble *ptrSiguiente;
}nodoDoble;

typedef struct Fila {
    nodoDoble *Primero;
    nodoDoble *Ultimo;
}Fila;

/*Prototipado----------------------------------------------------------------------*/
void menu();
void consignas();

void ejercicio1();
void inicializarFila(Fila *ptrFila);
nodoDoble *crearNodoDoble(int dato);
void ponerEnFila(Fila *ptrFila, int dato);
void ponerEnFilaHasta(Fila *ptrFila);

void ejercicio2();
void mostrarFila(Fila ptrFila);

void ejercicio3();
nodoDoble *buscarDato(Fila ptrFila, int dato);

void ejercicio4();
void pasarDeListaAlArchivo(Fila structFila, char nombreArchivo[]);
void mostrarArchivo(char nombreArchivo[]);

void ejercicio5();
void cargarFilaDesdeArchivo(Fila *ptrFila, char nombreArchivo[]);

void ejercicio6();
void mostrarFilaRecursiva(Fila *structFila);

void ejercicio7();
void guardaBuscados(Fila structFila, int dato, char nombreArchivo[]);

void ejercicio8();
/*--------------------------------------------------------------------------------------------------------*/
int main(){

    menu();
    return 0;
}
/*--------------------------------------------------------------------------------------------------------*/
//Funciones

void menu() {
    srand(time(NULL));
    char eleccion = 's';
    int ejercicio;

    consignas();

    do {
    printf("Ingrese el Numero de ejercicio a dirigirse --> ");
    fflush(stdin);
    scanf("%i", &ejercicio);
    printf("\n");


    switch(ejercicio) {

    case 1:
        ejercicio1();
        break;

    case 2:
        ejercicio2();
        break;

    case 3:
        ejercicio3();
        break;

    case 4:
        ejercicio4();
        break;

    case 5:
        ejercicio5();
        break;

    case 6:
        ejercicio6();
        break;

    case 7:
       ejercicio7();
        break;

    case 8:
        ejercicio8();
        break;


    default:
        printf("Has ingresado un numero incorrecto, vuelve a intentarlo \n\n");
        break;
        }

        printf("\nPulse 's' para ingresar a otro ejercicio --> ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");

    }while(eleccion == 's');
}

void consignas() {
    printf("1)Crear la/s funciones basicas de fila para permitir que el usuario ingrese datos  enteros a la misma. No sabemos cuantos datos seran ingresados \n\n");
    printf("2)Crear la funcion (muestraFila), la cual recorrera y mostrara el contenido de la fila  pasada por parametro \n\n");
    printf("3)Crear una funcion (buscaDato) que permita al usuario buscar un elemento  especifico de la fila. La funcion debera hacer lo indicado informando cuantas ocurrencias hubo \n\n");
    printf("4)Crear una funcion (crearArchivoTexto) que guarde el contenido de la fila  doblemente enlazada en un archivo de texto \n\n");
    printf("5)Crear una funcion (cargaFila) que permita al usuario cargar una fila a partir de los  datos previamente guardados en un archivo de texto. Debe leer el archivo y construir la  fila doblemente enlazada a partir de los datos almacenados \n\n");
    printf("6)Implementar una funcion recursiva (muestraFilaRecursiva) que recorra la fila  doblemente enlazada desde el principio hasta el final e imprima los elementos \n\n");
    printf("7)Crear una funcion (guardaBuscados) que guarde en un archivo de texto las  posiciones (dentro de la fila) donde se encuentre un dato buscado. Tener en cuenta que el dato puede aparecer varias veces \n\n");
    printf("8)Crear la funcion (muetraArchivoFila), la cual recibira un archivo de texto como parametro y mostrara su contenido \n\n");
}
//Ejercicios
void ejercicio1() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 1 \n\n");

    Fila structFila;
    inicializarFila(&structFila);
    printf("DEBUG -> Mostrando Primero y Ultimo en NULL: |%p| |%p| \n\n", structFila.Primero, structFila.Ultimo);

    ponerEnFilaHasta(&structFila);

    printf("\n--------------------------------------------------------------------------------------------------\n");

}

void inicializarFila(Fila *ptrFila) {

    (*ptrFila).Primero = NULL;
    (*ptrFila).Ultimo = NULL;
}

nodoDoble *crearNodoDoble(int dato) {

    nodoDoble *nuevoNodo = (nodoDoble*) malloc(sizeof(nodoDoble));

    nuevoNodo->dato = dato;
    nuevoNodo->ptrAnterior = NULL;
    nuevoNodo->ptrSiguiente = NULL;

    return nuevoNodo;
}

void ponerEnFila(Fila *ptrFila, int dato) {

    nodoDoble *nuevoNodo = crearNodoDoble(dato);

    if((*ptrFila).Primero == NULL){ //Si la Fila esta vacía debemos agregarle un Nodo. Siempre se agregan al comienzo

        (*ptrFila).Primero = nuevoNodo;
        (*ptrFila).Ultimo = nuevoNodo;

    }else{ //Caso en el qué la Fila ya contenga datos. Deberá insertarlos al principio

        (*ptrFila).Ultimo->ptrSiguiente = nuevoNodo;
        nuevoNodo->ptrAnterior = (*ptrFila).Ultimo;
        (*ptrFila).Ultimo = nuevoNodo;

    }
}

void ponerEnFilaHasta(Fila *ptrFila) {

    char eleccion = 's';
    int dato;

    do {
        printf("Ingrese un numero para poner en la Fila --> ");
        fflush(stdin);
        scanf("%i", &dato);
        printf("\n");

        ponerEnFila(ptrFila, dato);

        printf("Plse 's' para ingresar otro numero --> ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");

    }while(eleccion == 's' || eleccion == 'S');
}

void ejercicio2() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 2 \n\n");

    Fila structFila;
    inicializarFila(&structFila);
    printf("DEBUG -> Mostrando Primero y Ultimo en NULL: |%p| |%p| \n\n", structFila.Primero, structFila.Ultimo);

    //Ejercicio 2: Mostrar la Fila

    mostrarFila(structFila);

    ponerEnFilaHasta(&structFila);

    mostrarFila(structFila);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void mostrarFila(Fila ptrFila) {

    nodoDoble *ptrSeguidor = ptrFila.Primero;

    if(ptrSeguidor == NULL) printf("La Fila esta vacia \n\n");

    else {
        printf("Mostrando Fila: ");

        while(ptrSeguidor != NULL){
            printf("|%i| ", ptrSeguidor->dato);
            ptrSeguidor = ptrSeguidor->ptrSiguiente;
        }
        printf("\n\n");
    }
}

void ejercicio3() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 3 \n\n");

    Fila structFila;
    inicializarFila(&structFila);
    printf("DEBUG -> Mostrando Primero y Ultimo en NULL: |%p| |%p| \n\n", structFila.Primero, structFila.Ultimo);

    ponerEnFilaHasta(&structFila);

    mostrarFila(structFila);

    //Ejercicio 3: Buscar dato

    nodoDoble *nodoRta = buscarDato(structFila, 1);

    if(nodoRta == NULL) printf("\nNo se encontraron coincidencias con el dato a buscar \n\n");

    else printf("\nSe encontraron coincidencias con el dato a buscar \n\n");

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

nodoDoble *buscarDato(Fila structFila, int dato) {

    nodoDoble *ptrSeguidor = structFila.Primero;

    if(ptrSeguidor == NULL) printf("La Fila se encuentra vacia \n\n");

    else while((ptrSeguidor != NULL) && (ptrSeguidor->dato != dato)) ptrSeguidor = ptrSeguidor->ptrSiguiente;

    return ptrSeguidor;
}

void ejercicio4() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 4 \n\n");

    Fila structFila;
    inicializarFila(&structFila);
    printf("DEBUG -> Mostrando Primero y Ultimo en NULL: |%p| |%p| \n\n", structFila.Primero, structFila.Ultimo);

    ponerEnFilaHasta(&structFila);

    mostrarFila(structFila);

    char nombreArchivoFila[DIM];

    printf("Ingrese el nombre del archivo --> " );
    fflush(stdin);
    gets(nombreArchivoFila);
    printf("\n");

    pasarDeListaAlArchivo(structFila, nombreArchivoFila);

    printf("Mostrando archivo cargado con los datos de la Fila: ");
    mostrarArchivo(nombreArchivoFila);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void pasarDeListaAlArchivo(Fila structFila, char nombreArchivo[]) {

    FILE *ptrArchivo = fopen(nombreArchivo, "ab");

    if(ptrArchivo == NULL) printf("Error al abrir el archivo \n\n");

    else {
        nodoDoble *ptrSeguidor = structFila.Primero;

        if(ptrSeguidor != NULL) {

            while(ptrSeguidor != NULL) {

                fwrite(&(ptrSeguidor->dato), sizeof(int), 1 , ptrArchivo);//Debo pasarle la dirección de memoria del miembro Dato
                ptrSeguidor = ptrSeguidor->ptrSiguiente;
            }

        }else printf("No existen registros para pasar al Archivo \n\n");

        fclose(ptrArchivo);
    }
}

void mostrarArchivo(char nombreArchivo[]) {

    int dato;

    FILE *ptrArchivo = fopen(nombreArchivo, "rb");

    if(ptrArchivo == NULL) printf("Error al abrir el archivo \n\n");

    else {

        while(!feof(ptrArchivo)) {
            fread(&dato, sizeof(int), 1, ptrArchivo);

            if(!feof(ptrArchivo)) printf("|%i| ", dato);
        }
        printf("\n");
        fclose(ptrArchivo);
    }
}

void ejercicio5() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 5 \n\n");

    Fila structFila;
    inicializarFila(&structFila);
    printf("DEBUG -> Mostrando Primero y Ultimo en NULL: |%p| |%p| \n\n", structFila.Primero, structFila.Ultimo);

    char nombreArchivo[] = {"archivoFilas.bin"};

    cargarFilaDesdeArchivo(&structFila, nombreArchivo);

    mostrarFila(structFila);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void cargarFilaDesdeArchivo(Fila *ptrFila, char nombreArchivo[]){

    FILE *ptrArchivo = fopen(nombreArchivo, "rb");

    if(ptrArchivo == NULL) printf("Error al abrir el archivo \n");

    else {
        int dato;

        while(!feof(ptrArchivo)) {

            fread(&dato, sizeof(int), 1, ptrArchivo);

            if(!feof(ptrArchivo)) ponerEnFila(ptrFila, dato);
        }
        fclose(ptrArchivo);
    }
}

void ejercicio6() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 6 \n\n");

    Fila structFila;
    inicializarFila(&structFila);
    printf("DEBUG -> Mostrando Primero y Ultimo en NULL: |%p| |%p| \n\n", structFila.Primero, structFila.Ultimo);

    ponerEnFila(&structFila, 1);
    ponerEnFila(&structFila, 2);
    ponerEnFila(&structFila, 3);
    ponerEnFila(&structFila, 4);
    ponerEnFila(&structFila, 5);

    printf("Mostrando Fila de manera recursiva \n");
    mostrarFilaRecursiva(&structFila);

    mostrarFila(structFila);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void mostrarFilaRecursiva(Fila *structFila) {

    nodoDoble *nodoAux = (*structFila).Primero;

    if(nodoAux != NULL) {

        printf("|%i| ", nodoAux->dato);

        mostrarFilaRecursiva(&(nodoAux->ptrSiguiente));
    }
}

void ejercicio7() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 7 \n\n");

    Fila structFila;
    inicializarFila(&structFila);
    printf("DEBUG -> Mostrando Primero y Ultimo en NULL: |%p| |%p| \n\n", structFila.Primero, structFila.Ultimo);

    ponerEnFila(&structFila, 1);//0
    ponerEnFila(&structFila, 2);//1
    ponerEnFila(&structFila, 3);//2
    ponerEnFila(&structFila, 4);//3
    ponerEnFila(&structFila, 5);//4
    ponerEnFila(&structFila, 1);//5
    ponerEnFila(&structFila, 1);//6
    ponerEnFila(&structFila, 2);//7
    ponerEnFila(&structFila, 3);//8
    ponerEnFila(&structFila, 1);//9

    mostrarFila(structFila);

    char archivoGuardaBuscados[] = {"archivoGuardaBuscados.txt"};

    guardaBuscados(structFila, 1, archivoGuardaBuscados);
    mostrarArchivo(archivoGuardaBuscados);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void guardaBuscados(Fila structFila, int dato, char nombreArchivo[]){

    nodoDoble *ptrSeguidor = structFila.Primero;

    int contadorPosiciones = 0;

    FILE *ptrArchivoGuardaBuscados = fopen(nombreArchivo, "a");

    if(ptrArchivoGuardaBuscados == NULL) printf("Error al abrir el archivo \n");

    else {

        if(ptrSeguidor != NULL) {

            while(ptrSeguidor != NULL) {

                if(ptrSeguidor->dato == dato) {

                    fwrite(&contadorPosiciones, sizeof(int), 1, ptrArchivoGuardaBuscados);
                }
                contadorPosiciones++;
                ptrSeguidor = ptrSeguidor->ptrSiguiente;
            }
        }
        fclose(ptrArchivoGuardaBuscados);
    }
}

void ejercicio8() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 8 \n\n");

    Fila structFila;
    inicializarFila(&structFila);
    printf("DEBUG -> Mostrando Primero y Ultimo en NULL: |%p| |%p| \n\n", structFila.Primero, structFila.Ultimo);

    ponerEnFilaHasta(&structFila);

    mostrarFila(structFila);

    char nombreArchivoFila[DIM];

    printf("Ingrese el nombre del archivo --> " );
    fflush(stdin);
    gets(nombreArchivoFila);
    printf("\n");

    pasarDeListaAlArchivo(structFila, nombreArchivoFila);

    printf("Mostrando archivo cargado con los datos de la Fila: ");
    mostrarArchivo(nombreArchivoFila);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}
