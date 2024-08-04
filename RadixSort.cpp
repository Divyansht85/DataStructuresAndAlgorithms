#include <iostream>
using namespace std;
void countingSort(int *a, int n, int exp)
{
    int freq[10] = {0};
    for (int i = 0; i < n; i++)
        freq[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        freq[i] += freq[i - 1];
    int output[n];
    for (int i = n - 1; i >= 0; i--) // Iterating in reverse to maintain stability
    {
        output[freq[(a[i] / exp) % 10] - 1] = a[i];
        freq[(a[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}
void radixSort(int *a, int n)
{
    int maxElement = a[0];
    for (int i = 1; i < n; i++)
        maxElement = max(maxElement, a[i]);
    int exp = 1;
    while (maxElement / exp > 0)
    {
        countingSort(a, n, exp);
        exp *= 10;
    }
}
int main()
{
    int arr[12] = {5, 3, 2, 6, 77, 89, 100, 32, 155, 113, 0, 1};
    radixSort(arr, 12);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}