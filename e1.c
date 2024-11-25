/*
    Dynamic allocation of memory

    [2p] Să se scrie un program care citeşte de la tastatură un număr pozitiv n împreună cu alt număr
    pozitiv max. Programul va aloca apoi dinamic un vector de întregi de n elemente, pe care îl va
    iniţializa cu numere aleatoare în intervalul [0..max-1]. Sortaţi vectorul, folosind metoda
    preferată, afişându-i conţinutul atât înainte, cât şi după ce sortarea a avut loc.

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, max;
    scanf("%d %d", &n, &max);

    int *v = calloc(n, sizeof(n));

    for(int i = 0; i < n; i++) {
        printf("%d", v[i]);
    }
}