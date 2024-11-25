/*
    Dynamic allocation of memory

    [2p] Să se scrie un program care citeşte de la tastatură un număr pozitiv n împreună cu alt număr
    pozitiv max. Programul va aloca apoi dinamic un vector de întregi de n elemente, pe care îl va
    iniţializa cu numere aleatoare în intervalul [0..max-1]. Sortaţi vectorul, folosind metoda
    preferată, afişându-i conţinutul atât înainte, cât şi după ce sortarea a avut loc.

*/
#include <stdio.h>
#include <stdlib.h>


void generate_randoms(int *arr, int max, int count) {
    int min = 0;
    unsigned int rand;

    FILE* f = fopen("/dev/urandom", "rb");
    if (f == NULL) {
        exit(1);
    }
    for (int i = 0; i < count; i++) {

        if (fread(&rand, sizeof(rand), 1, f) != 1) {
            fclose(f);
            exit(1);
        }

        arr[i] = min + (rand % (max - min));
    }

    fclose(f); 
}

void display(int *v, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int cmpfunc(const void *a, const void *b) {
   const int *A = a, *B = b;
   return (*A > *B) - (*A < *B);
}

int main() {
    int n, max;
    scanf("%d %d", &n, &max);

    int *v = malloc(n * sizeof(int));
    if (v == NULL) {
        return 1;
    }
    generate_randoms(v, max, n);
    display(v, n);
    qsort(v, n, sizeof(int), cmpfunc);
    display(v, n);
    free(v);
    return 0;
}