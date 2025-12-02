#include <stdio.h>
#include <time.h>


long long povrh_rek(int n, int m) {
    if (n == m || m == 0) return 1;
    if (m == 1) return n;
    return povrh_rek(n - 1, m - 1) + povrh_rek(n - 1, m);
}

int main() {
    int n = 30;
    int m = n / 2;

    clock_t t1 = clock();
    long long result = povrh_rek(n, m);
    clock_t t2 = clock();

    double ms = (double)(t2 - t1) * 1000.0 / CLOCKS_PER_SEC;

    printf("Rekurzija: %lld\n", result);
    printf("Vrijeme: %.3f ms\n", ms);

    return 0;
}