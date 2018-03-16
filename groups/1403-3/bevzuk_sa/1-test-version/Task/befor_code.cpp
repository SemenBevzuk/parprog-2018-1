#include <cstdio>
#include <omp.h>
#include <iostream>

void ConsistentQuickSort(double* array, int size);

int main(int argc, char * argv[]) {
    int N;
    double* array;
    
    FILE* f1;
    FILE* f2;

    freopen_s(&f1, "..//array.in", "rb", stdin);
    freopen_s(&f2, "..//array.out", "wb", stdout);

    // чтение данных 
    fread(&N, sizeof(N), 1, stdin);
    array = new double[N];
    fread(array, sizeof(*array), N, stdin); 

    // запуск и замер последовательной версии
    double time = omp_get_wtime();
    ConsistentQuickSort(array, N);
    time = omp_get_wtime() - time;

    // запись результатов
    fwrite(&time, sizeof(time), 1, stdout); 
    fwrite(&N, sizeof(N), 1, stdout);
    fwrite(array, sizeof(*array), N, stdout);

    fclose(f1);
    fclose(f2);
    return 0;
}