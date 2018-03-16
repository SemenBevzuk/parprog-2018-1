
void Swap(double* array, int i, int j)
{
    double tmp = *(array + i);
    *(array + i) = *(array + j);
    *(array + j) = tmp;
}

int Partition(double* array, int left, int rightr) {
    double barrier = *(array + rightr);
    int i = left - 1;
    int j;

    for (j = left; j < rightr; j++) {
        if (*(array + j) <= barrier) {
            i++;
            Swap(array, i, j);
        }
    }
    Swap(array, rightr, i+1);
    return i + 1;
}

void QuickSort(double* array, int left, int rightr) {
    int pos;
    if (left < rightr) {
        pos = Partition(array, left, rightr);
        QuickSort(array, left, pos - 1);
        QuickSort(array, pos + 1, rightr);
    }
}

void ConsistentQuickSort(double* array, int size)
{
    if (size != 1)
    {
        QuickSort(array, 0, size-1);
    }
}