#include <stdio.h>
#include <stdlib.h>

// function to merge two sorted arrays given
void my_merge(int *my_array, int left, int mid, int right, int *temp_val) {
    int left_array = left;       // Index for the left subarray i 
    int right_array = mid + 1;    // Index for the right subarray j 
    int temp_array = 0;          // Index for the temporary array k 

    // merge in sorted order
    while (left_array <= mid && right_array <= right) 
    {
        if (my_array[left_array] <= my_array[right_array]) 
        {
            temp_val[temp_array++] = my_array[left_array++];
        } else 
        {
            temp_val[temp_array++] = my_array[right_array++];
        }
    }

    // copy remaining elements from the left side
    while (left_array <= mid) 
    {
        temp_val[temp_array++] = my_array[left_array++];
    }

    // copy remaining elements from the right side
    while (right_array <= right) 
    {
        temp_val[temp_array++] = my_array[right_array++];
    }

    // copy the merged elements back to the original array
    for (left_array = 0; left_array < temp_array; left_array++) 
    {
        my_array[left + left_array] = temp_val[left_array];
    }
}

// recursive function to perform merge sort
void merge_sort_recursion(int *my_array, int left, int right, int *temp_val) 
{
    if (left < right) 
    {
        int mid = (left + right) / 2;

        // sort the left and right half recursively 
        merge_sort_recursion(my_array, left, mid, temp_val);
        merge_sort_recursion(my_array, mid + 1, right, temp_val);

        // merge the sorted halves
        my_merge(my_array, left, mid, right, temp_val);
    }
}

// function to sort the merge
void merge_sort(int *my_array, int n) 
{
    // create a temporary array for merging
    int *temp_val = (int *)malloc(n * sizeof(int));

    // call the recursive merge sort function
    merge_sort_recursion(my_array, 0, n - 1, temp_val);

    // dynamically allocate temp array
    free(temp_val);
}

int main() 
{
    // example using mergesort function
    int my_array[] = {24, 19, 2, 5, 49, 100, 63, 45, 28};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    printf("\nOur old unsorted array: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", my_array[i]);
    }
    printf("]");

    // call mergesort function to sort the arrays
    merge_sort(my_array, n);

    printf("\nOur new sorted array: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", my_array[i]);
    }
    printf("]\n");

    int my_array2[] = {};
    int n2 = sizeof(my_array2) / sizeof(my_array2[0]);

    printf("\nOur old unsorted empty array: [ ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", my_array2[i]);
    }
    printf("]");

    merge_sort(my_array2, n2);

    printf("\nOur new sorted empty array: [ ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", my_array2[i]);
    }
    printf("]\n\n");

    return 0;
}