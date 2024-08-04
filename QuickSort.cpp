#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int lomutoPartition(int *a, int l, int r)
{
    int randomPivotIndex = l + rand() % (r - l + 1);
    swap(a[randomPivotIndex], a[r]);
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++)
        if (a[j] < pivot)
            swap(a[++i], a[j]);
    swap(a[++i], a[r]);
    return i;
}
int horesPartition(int *a, int l, int r)
{
    int pivotIndex = l + rand() % (r - l + 1);
    swap(a[pivotIndex], a[l]);
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i >= j)
            return j;
        swap(a[i], a[j]);
    }
}
void quickSortLomuto(int *a, int l, int r)
{
    if (l < r)
    {
        int p = lomutoPartition(a, l, r);
        quickSortLomuto(a, l, p - 1);
        quickSortLomuto(a, p + 1, r);
    }
}
void quickSortHores(int *a, int l, int r)
{
    if (l < r)
    {
        int p = horesPartition(a, l, r);
        quickSortHores(a, l, p);
        quickSortHores(a, p + 1, r);
    }
}
int main()
{
    srand(time(0));
    int arr[12] = {8, 9, 15, 2, 3, 56, 34, 23, 78, 90, 6, 30};
    quickSortHores(arr, 0, 11);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}