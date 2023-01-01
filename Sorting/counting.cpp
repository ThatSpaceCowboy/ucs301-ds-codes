#include <iostream>
using namespace std;
void countsort(int arr[], int n)
{
    int output[n + 1];
    // First we get the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int count[max + 1];
    // initializing array with zeroes
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // Storing count of each element
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Find cumulative frequency
    for (int i = 1; i <= max; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
int main()
{
    int arr[] = {49, 12, 42, 7, 88, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    countsort(arr, n);
    for (int c = 0; c < n; c++)
    {
        cout << arr[c] << " ";
    }
}