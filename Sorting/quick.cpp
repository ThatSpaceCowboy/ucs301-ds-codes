#include <iostream>
using namespace std;
// swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quicksort is another Divide and Conquer algo
// We choose a pivot element and sort the array about it;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // We choose the last element of array as pivot
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int r = partition(arr, low, high);
        quicksort(arr, low, r - 1);
        quicksort(arr, r + 1, high);
    }
}

int main()
{
    int arr[] = {33, 45, 11, 2, 99, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}