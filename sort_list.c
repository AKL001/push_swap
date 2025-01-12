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

