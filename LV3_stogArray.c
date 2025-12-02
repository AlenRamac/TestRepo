#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

//---------
typedef struct Stack_
{
    int Items[MAX];
    long long top;

} Stack;



//---------
void initLL(Stack *s) {
    s->top = -1;
}

int isEmptyLL(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void pushLL(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    s->Items[++(s->top)] = value;
}

int popLL(Stack *s) {
    if (isEmptyLL(s)) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return s->Items[(s->top)--];
}

long long peek(Stack *s){ 
    if(isEmptyLL(s)) { 
        printf("Stack is empty!"); 
        return -1; 
    } 
    return s->Items[(s->top)]; 
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

    printf("Stog (polje): %lld\n", r);
    printf("Vrijeme: %.3f ms\n", ms);
}