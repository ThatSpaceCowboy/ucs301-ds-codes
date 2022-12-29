#include <iostream>
using namespace std;
void insertionsort(int arr[], int n)
{
    int i, j, k;
    for (int i = 1; i < n; i++)
    {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}
int main()
{
    int arr[] = {13, 11, 12, 5, 6};
    insertionsort(arr, 5);
    for (int p = 0; p < 5; p++)
    {
        cout << arr[p] << " ";
    }
}