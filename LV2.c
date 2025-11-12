#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct OE_ {
    int x;
    struct OE_ *sljedeci;
} OE;


int* kreirajNiz(int n) {
    int *V = (int*)malloc(n * sizeof(int));
    if (V == NULL) {
        printf("Greska pri alokaciji niza!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
        V[i] = rand();

    return V;
}


OE* napraviPovezaniPopis(int *V, int n) {
    OE *prvi = NULL;

    for (int i = 0; i < n; i++) {
        OE *novi = (OE*)malloc(sizeof(OE));
        if (novi == NULL) {
            printf("Greska pri alokaciji memorije!\n");
            exit(1);
        }
        novi->x = V[i];
        novi->sljedeci = NULL;

        if (prvi == NULL) prvi = novi;
    }

    return prvi;
}


int pretraziNiz(int *V, int n, int value) {
    for (int i = 0; i < n; i++)
        if (V[i] == value)
            return 1;
    return 0;
}


int pretraziPovezaniPopis(OE *prvi, int value) {
    OE *trenutni = prvi;
    while (trenutni != NULL) {
        if (trenutni->x == value)
            return 1;
        trenutni = trenutni->sljedeci;
    }
    return 0;
}


void oslobodiPopis(OE *prvi) {
    OE *trenutni;
    while (prvi != NULL) {
        trenutni = prvi;
        prvi = prvi->sljedeci;
        free(trenutni);
    }
}


double odradi(int n){

}


int main(){

    
    int *niz;
    int n;


    srand(time(NULL));

    //niz
    clock_t t1 = clock();
    niz = kreirajNiz(n);

    clock_t t2 = clock();

    double vrijeme = (double)(t2-t1) / CLOCKS_PER_SEC * 1000;
    printf("Vrijeme kreiranja niza: %.3f", vrijeme);

    //
    clock_t t1 = clock();

    clock_t t2 = clock();

    double vrijeme = (double)(t2-t1) / CLOCKS_PER_SEC * 1000;
    printf("Vrijeme kreiranja niza: %.3f", vrijeme);


    clock_t t1 = clock();

    clock_t t2 = clock();

    double vrijeme = (double)(t2-t1) / CLOCKS_PER_SEC * 1000;
    printf("Vrijeme kreiranja niza: %.3f", vrijeme);
}