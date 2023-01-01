#include <iostream>
using namespace std;
// Merge sort is a Divide and Conquer algo
void merge(int arr[], int p, int q, int r)
{
    // Creating left and right subarrays
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0; // Current index of left subarray;
    j = 0; // Current index of right subarray;
    k = p; // Current index of main array;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = p + (r - p) / 2;
        mergesort(arr, p, q);
        mergesort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main()
{
    int arr[] = {5, 4, 6, 1, 2, 7, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, 7);
    for (int c = 0; c < 8; c++)
    {
        cout << arr[c] << " ";
    }
    return 0;
}