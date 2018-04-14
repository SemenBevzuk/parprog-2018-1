#include <omp.h>

void Swap(int* array, int i, int j) {
    int tmp = *(array + i);
    *(array + i) = *(array + j);
    *(array + j) = tmp;
}

int Partition(int* array, int left, int right) {
    double barrier = *(array + right);
    int i = left - 1;
    int j;

    for (j = left; j < right; j++) {
        if (*(array + j) <= barrier) {
            i++;
            Swap(array, i, j);
        }
    }
    Swap(array, right, i + 1);
    return i + 1;
}

void ParallelQuickSort_hidden(int* array, int left, int right, int size_barrier) {
    int pos;

    if (((right - left)<size_barrier)) {
        if (left < right) {
            pos = Partition(array, left, right);
            ParallelQuickSort_hidden(array, left, pos - 1, size_barrier);
            ParallelQuickSort_hidden(array, pos + 1, right, size_barrier);
        }

    }
    else {
        if (left < right) {
            pos = Partition(array, left, right);
            #pragma omp task
            { ParallelQuickSort_hidden(array, left, pos - 1, size_barrier); }
            #pragma omp task
            { ParallelQuickSort_hidden(array, pos + 1, right, size_barrier); }
        }
    }
}

void ParallelQuickSort(int* array, int size, int numThreads) {
    int size_barrier = 100;
    #pragma omp parallel num_threads(numThreads)
    {
        #pragma omp single nowait
        {
            ParallelQuickSort_hidden(array, 0, size - 1, size_barrier);
        }
    }
}