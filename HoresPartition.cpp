#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
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
int main()
{
    srand(time(0));
    int arr[12] = {8, 9, 15, 2, 3, 56, 34, 23, 78, 90, 6, 30};
    cout << horesPartition(arr, 0, 11) << endl;
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}