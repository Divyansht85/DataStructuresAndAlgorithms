#include <iostream>
using namespace std;
void countingSort(int *a, int n, int k)
{
    int freq[k] = {0};
    for (int i = 0; i < n; i++)
        freq[a[i]]++;
    for (int i = 1; i < k; i++)
        freq[i] += freq[i - 1];
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[freq[a[i]] - 1] = a[i];
        freq[a[i]]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}
int main()
{
    int arr[12] = {1, 3, 2, 4, 2, 3, 1, 4, 2, 4, 1, 3};
    countingSort(arr, 12, 5);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}