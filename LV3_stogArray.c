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
void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    s->Items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return s->Items[(s->top)--];
}

long long peek(Stack *s){ 
    if(isEmpty(s)) { 
        printf("Stack is empty!"); 
        return -1; 
    } 
    return s->Items[(s->top)]; 
}




//---------
long long povrh_stog(int n, int m)
{
    Stack s1, s2;
    init(&s1);
    init(&s2);

    long long result = 0;

    push(&s1, n);
    push(&s2, m);

    while (!isEmpty(&s1))
    {
        int N = pop(&s1);
        int M = pop(&s2);

        if (M == 0 || M == N)
        {
            result++;
        }
        else
        {
            push(&s1, N - 1);
            push(&s2, M - 1);

            push(&s1, N - 1);
            push(&s2, M);
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
