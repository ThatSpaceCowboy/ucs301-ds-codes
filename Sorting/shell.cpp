#include <iostream>
using namespace std;
// Shell sort is just a variation of insertion sort
// We first divide the array into gaps of equal size then sort these subarrays with insertion sort
void shellsort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int j = gap; j < n; j++)
        {
            int temp = arr[j];
            int k;
            for (k = j; k >= gap && arr[k - gap] > temp; k = k - gap)
            {
                arr[k] = arr[k - gap];
            }
            arr[k] = temp;
        }
    }
}
int main()
{
    int arr[] = {12, 64, 39, 52, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    shellsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}