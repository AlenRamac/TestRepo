#include <stdio.h>
#include <stdlib.h>

struct Cvor {
    char x;
    struct Cvor *lijevi;
    struct Cvor *desni;
};

void dodaj(struct Cvor **korijen, char P) {
    struct Cvor *trenutni = *korijen;
    struct Cvor *nadredjeni = NULL;
    int nadjen = 0;

    while (trenutni != NULL) {
        if (P == trenutni->x) {
            nadjen = 1;
            break;
        }
        nadredjeni = trenutni;
        if (P < trenutni->x) {
            trenutni = trenutni->lijevi;
        } else {
            trenutni = trenutni->desni;
        }
    }

    if (nadjen) return;

    struct Cvor *n = (struct Cvor*)malloc(sizeof(struct Cvor));
    n->x = P;
    n->lijevi = n->desni = NULL;

    if (nadredjeni == NULL) {
        *korijen = n;
    } else {
        if (P < nadredjeni->x) {
            nadredjeni->lijevi = n;
        } else {
            nadredjeni->desni = n;
        }
    }
}

void preorder(struct Cvor *n) {
    if (n == NULL) return;
    printf("%c ", n->x);
    preorder(n->lijevi);
    preorder(n->desni);
}

void inorder(struct Cvor *n) {
    if (n == NULL) return;
    inorder(n->lijevi);
    printf("%c ", n->x);
    inorder(n->desni);
}

void postorder(struct Cvor *n) {
    if (n == NULL) return;
    postorder(n->lijevi);
    postorder(n->desni);
    printf("%c ", n->x);
}

int main() {
    struct Cvor *korijen = NULL;
    char ime[] = "ALENRAMAC";
    
    printf("Dodajemo slova: %s\n", ime);

    for (int i = 0; ime[i] != '\0'; i++) {
        dodaj(&korijen, ime[i]);
    }

    printf("\nPreorder:  "); preorder(korijen);
    printf("\nInorder:   "); inorder(korijen);
    printf("\nPostorder: "); postorder(korijen);
    printf("\n");

    return 0;
}