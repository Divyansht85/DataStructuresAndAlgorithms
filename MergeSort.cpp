#include <iostream>
using namespace std;
void merge(int *a, int left, int mid, int right)
{
    int l = left, r = mid + 1, k = 0;
    int temp[right - left + 1];
    while (l <= mid && r <= right)
    {
        if (a[l] <= a[r])
            temp[k++] = a[l++];
        else
            temp[k++] = a[r++];
    }
    while (l <= mid)
        temp[k++] = a[l++];
    while (r <= right)
        temp[k++] = a[r++];
    k = 0, l = left, r = mid + 1;
    while (l <= mid)
        a[l++] = temp[k++];
    while (r <= right)
        a[r++] = temp[k++];
}
void mergeSort(int *arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    mergeSort(arr, 0, 4);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}