#include "push_swap.h"

static void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

static void bubbleSort(int *arr, int n) {
    int i;
    int j;

    i = 0;
    while (i < n - 1) {
        j = 0;
        while (j < n - i - 1) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
            j++;
        }
        i++;
    }
}

int *sort_list(t_stack *a) {
    int len;
    int *array;
    int i;

    if (!a)
        return NULL;
    len = stack_len(a);
    array = malloc(sizeof(int) * len);
    if (!array)
        return NULL;
    i = 0;
    while (a) {
        array[i++] = a->value;
        a = a->next;
    }
    bubbleSort(array, len);
    return array;
}

// Helper function to swap integers
// static void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// Quick sort implementation
static void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        // Use middle element as pivot to handle already sorted arrays better
        int pivot = arr[(low + high) / 2];
        int i = low - 1;
        int j = high + 1;
        
        while (1)
        {
            do {
                i++;
            } while (arr[i] < pivot);
            
            do {
                j--;
            } while (arr[j] > pivot);
            
            if (i >= j)
                break;
                
            swap(&arr[i], &arr[j]);
        }
        
        quick_sort(arr, low, j);
        quick_sort(arr, j + 1, high);
    }
}

// Function to create sorted copy of stack values
int *sort_array_copy(t_stack *stack, int size)
{
    int *arr;
    int i;
    t_stack *tmp;
    
    // Allocate memory for array
    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return NULL;
    
    // Copy stack values to array
    i = 0;
    tmp = stack;
    while (tmp)
    {
        arr[i] = tmp->value;
        i++;
        tmp = tmp->next;
    }
    
    // Sort array
    quick_sort(arr, 0, size - 1);
    
    return arr;
}

// Optional: Function to check if array is sorted (for debugging)
int is_array_sorted(int *arr, int size)
{
    int i;
    
    for (i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}
