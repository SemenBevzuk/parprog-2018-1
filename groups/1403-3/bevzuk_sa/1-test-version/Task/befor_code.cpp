#include <cstdio>
#include <omp.h>
#include <iostream>

void ConsistentQuickSort(double* array, int size);

int main(int argc, char * argv[]) {
    int N;
    double* array;
    
    FILE* f1;
    FILE* f2;

    std::string fileName = "array";
    if (argc == 2) {
        fileName = argv[1];
    }
    freopen_s(&f1, ("..//" + fileName + ".in").c_str(), "rb", stdin);
    freopen_s(&f2, ("..//" + fileName + ".out").c_str(), "wb", stdout);

    // ������ ������ 
    fread(&N, sizeof(N), 1, stdin);
    array = new double[N];
    fread(array, sizeof(*array), N, stdin); 

    // ������ � ����� ���������������� ������
    double time = omp_get_wtime();
    ConsistentQuickSort(array, N);
    time = omp_get_wtime() - time;

    // ������ �����������
    fwrite(&time, sizeof(time), 1, stdout); 
    fwrite(&N, sizeof(N), 1, stdout);
    fwrite(array, sizeof(*array), N, stdout);

    fclose(f1);
    fclose(f2);
    return 0;
}