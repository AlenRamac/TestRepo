#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;




void initLL(Stack* s) {
    s->top = NULL;
}

int isEmptyLL(Stack* s) {
    return s->top == NULL;
}

void pushLL(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error!\n");
        return;
    }
    newNode->value = value;
    newNode->next = s->top;
    s->top = newNode;
}

int popLL(Stack* s) {
    if (isEmptyLL(s)) {
        printf("Stack underflow!\n");
        return -1;
    }

    Node* temp = s->top;
    int value = temp->value;
    s->top = temp->next;
    free(temp);

    return value;
}

int peekLL(Stack* s) {
    if (isEmptyLL(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->top->value;
}




//---------
long long povrh_stog(int n, int m)
{
    Stack s1, s2;
    initLL(&s1);
    initLL(&s2);

    long long result = 0;

    // početni problem (n, m)
    pushLL(&s1, n);
    pushLL(&s2, m);

    while (!isEmptyLL(&s1))
    {
        int N = popLL(&s1);
        int M = popLL(&s2);

        // osnovni slučajevi iz slajda
        if (M == 0 || M == N)
        {
            result++;
        }
        else
        {
            // rekurzija: C(n-1, m-1)
            pushLL(&s1, N - 1);
            pushLL(&s2, M - 1);

            // rekurzija: C(n-1, m)
            pushLL(&s1, N - 1);
            pushLL(&s2, M);
        }
    }

    return result;
}



//---------
int main()
{
    int n = 30;
    int m = n / 2;

    clock_t t1 = clock();
    long long r = povrh_stog(n, m);
    clock_t t2 = clock();

    double ms = (double)(t2 - t1) * 1000.0 / CLOCKS_PER_SEC;

    printf("Stog (popis): %lld\n", r);
    printf("Vrijeme: %.3f ms\n", ms);
}