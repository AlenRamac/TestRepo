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


OE* kreirajPovezaniPopis(int *V, int n) {
    OE *prvi = NULL;
    OE *temp = NULL;


    prvi = (OE*)malloc(sizeof(OE));
    if (prvi == NULL) {
            printf("Greska pri alokaciji memorije!\n");
            exit(1);
    }

    temp = prvi;
    for (int i = 0; i < n-1; i++) {
        temp->sljedeci = (OE*)malloc(sizeof(OE));
        if (temp->sljedeci == NULL) {
            printf("Greska pri alokaciji memorije!\n");
            exit(1);
        }
        temp = temp->sljedeci;
    }
    temp->sljedeci = NULL;

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


void odradi(int n){
    int *niz;
    OE *popis;
    int found = 0;
    double vrijeme[4];
    clock_t t1, t2;


    //
    t1 = clock();
    niz = kreirajNiz(n);
    t2 = clock();

    vrijeme[0] = (double)(t2-t1) / CLOCKS_PER_SEC * 1000;


    //
    t1 = clock();
    popis = kreirajPovezaniPopis(niz, n);
    t2 = clock();

    vrijeme[1] = (double)(t2-t1) / CLOCKS_PER_SEC * 1000;


    //
    t1 = clock();
    found = pretraziNiz(niz, n, -1);
    t2 = clock();

    vrijeme[2] = (double)(t2-t1) / CLOCKS_PER_SEC * 1000;


    //
    t1 = clock();
    found = pretraziPovezaniPopis(popis, -1);
    t2 = clock();

    vrijeme[3] = (double)(t2-t1) / CLOCKS_PER_SEC * 1000;

    printf("Vremena: %.3f, %.3f, %.3f, %.3f\n", vrijeme[0], vrijeme[1], vrijeme[2], vrijeme[3]);

    free(niz);
    oslobodiPopis(popis);
}


int main(){

    srand(time(NULL));
    odradi(50000);
    odradi(100000);
    odradi(150000);
    odradi(200000);
    odradi(250000);
    odradi(300000);
    odradi(350000);
    
}