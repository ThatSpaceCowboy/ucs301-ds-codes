#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    int j, k;
    for (j = 1; j < n; j++)
    {
        for (k = 0; k < n - j; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                arr[k] = arr[k] ^ arr[k + 1];
                arr[k + 1] = arr[k] ^ arr[k + 1];
                arr[k] = arr[k] ^ arr[k + 1];
            }
        }
    }
}
int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    bubbleSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}