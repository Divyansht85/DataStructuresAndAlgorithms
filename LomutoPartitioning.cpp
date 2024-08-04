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
int main()
{
    srand(time(0));
    int arr[12] = {8, 9, 15, 2, 3, 56, 34, 23, 78, 90, 6, 30};
    cout << lomutoPartition(arr, 0, 11) << endl;
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}