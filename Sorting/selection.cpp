#include <iostream>
using namespace std;
void selectionsort(int arr[], int n)
{
    int key;
    for (int j = 0; j < n; j++)
    {
        key = j;
        for (int k = j + 1; k < n; k++)
        {
            if (arr[key] > arr[k])
            {
                key = k;
            }
        }
        // Replacing with key
        // Added flag
        if (key != j)
        {
            int temp = arr[j];
            arr[j] = arr[key];
            arr[key] = temp;
        }
    }
}
int main()
{
    int arr[] = {1, 55, 22, 11, 8, 39};
    selectionsort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}