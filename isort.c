#include <stdio.h>

#define ARR_SIZE 50

void shift_element(int *arr, int i);

void insertion_sort(int *arr, int len);

int main()
{
    int arr[ARR_SIZE] = {0};

    for (int i = 0; i < ARR_SIZE; ++i)
    {
        scanf(" %d", (arr + i));
    }
    insertion_sort(arr, ARR_SIZE);

    printf("%d", *arr);

    for (int i = 1; i < ARR_SIZE; ++i)
    {
        printf(",%d", *(arr + i));
    }
    printf("\n");
    return 0;
}

void shift_element(int *arr, int i)
{ // shifts the elements of the array to the right
    for (int item = i; item > 0; item--)
        *(arr + item) = *(arr + item - 1);
}

void insertion_sort(int *arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = *(arr + i), j = (i - 1);

        while (j >= 0 && *(arr + j) > key)
            --j;

        shift_element((arr + j), (i - j));

        *(arr + j + 1) = key;
    }
}