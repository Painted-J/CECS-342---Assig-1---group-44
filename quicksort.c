//Ian Cheong
#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int part = partition(arr, low, high);

        quicksort(arr, low, part - 1);
        quicksort(arr, part + 1, high);
    }
}

int main() {
    int test[] = {10, 3, 5, 18, 39, 64, 3, 128};
    int n = sizeof(test)/sizeof(test[0]);

    printf("Unsorted arary: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", test[i]);
    }
    printf("\n");

    quicksort(test, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", test[i]);
    }

    return 0;
}