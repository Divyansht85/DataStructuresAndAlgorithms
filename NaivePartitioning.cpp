#include <iostream>
using namespace std;
void naivePartition(int *a, int l, int r, int p)
{
    int temp[r - l + 1];
    int k = 0;
    for (int i = l; i <= r; i++)
        if (a[i] < a[p])
            temp[k++] = a[i];
    for (int i = l; i <= r; i++)
        if (a[i] == a[p])
            temp[k++] = a[i];
    for (int i = l; i <= r; i++)
        if (a[i] > a[p])
            temp[k++] = a[i];
    for (int i = l; i <= r; i++)
        a[i] = temp[i - l];
}
int main()
{
    int arr[12] = {8, 9, 15, 2, 3, 56, 34, 23, 78, 90, 6, 1};
    naivePartition(arr, 0, 11, 6);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}