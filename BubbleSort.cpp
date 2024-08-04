#include <iostream>
using namespace std;
void bubbleSort(int *a, int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    bubbleSort(arr, 5);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}