#include <cstdio>
#include <omp.h>
#include <iostream>

void ParallelQuickSort(int* array, int size, int numThreads);

int main(int argc, char * argv[]) { // имя файла, число потоков
    int N;
    int* array;
    int numThreads = 2;

    FILE* f1;
    FILE* f2;

    std::string fileName = "array";
    if (argc == 2) {
        fileName = argv[1];
    }
    else
    {
        if (argc == 3)
        {
            fileName = argv[1];
            numThreads = atoi(argv[2]); 
        }
    }
    freopen_s(&f1, ("..//" + fileName + ".in").c_str(), "rb", stdin);
    freopen_s(&f2, ("..//" + fileName + ".out").c_str(), "wb", stdout);

    // чтение данных 
    fread(&N, sizeof(N), 1, stdin);
    array = new int[N];
    fread(array, sizeof(*array), N, stdin);

    // запуск и замер времени
    double time = omp_get_wtime();
    ParallelQuickSort(array, N, numThreads);
    time = omp_get_wtime() - time;

    // запись результатов
    fwrite(&time, sizeof(time), 1, stdout);
    fwrite(&N, sizeof(N), 1, stdout);
    fwrite(array, sizeof(*array), N, stdout);

    fclose(f1);
    fclose(f2);
    return 0;
}