#include <iostream>
using namespace std;
int leftChild(int i)
{
    return 2 * i + 1;
}
int rightChild(int i)
{
    return 2 * i + 2;
}
int parent(int i)
{
    return (i - 1) / 2;
}
int minHeapify(int *a, int size, int i)
{
    if (i < size)
    {
        int left = leftChild(i);
        int right = rightChild(i);
        int minIndex = i;
        if (left < size && a[left] < a[minIndex])
            minIndex = left;
        if (right < size && a[right] < a[minIndex])
            minIndex = right;
        if (minIndex != i)
        {
            swap(a[i], a[minIndex]);
            minHeapify(a, size, minIndex);
        }
    }
}
int maxHeapify(int *a, int size, int i)
{
    int left = leftChild(i);
    int right = rightChild(i);
    int maxIndex = i;
    if (left < size && a[left] > a[maxIndex])
        maxIndex = left;
    if (right < size && a[right] > a[maxIndex])
        maxIndex = right;
    if (maxIndex != i)
    {
        swap(a[i], a[maxIndex]);
        maxHeapify(a, size, maxIndex);
    }
}
void buildMinHeap(int *a, int size)
{
    for (int i = (size - 2) / 2; i >= 0; i--)
        minHeapify(a, size, i);
}
void buildMaxHeap(int *a, int size)
{
    for (int i = (size - 2) / 2; i >= 0; i--)
        maxHeapify(a, size, i);
}
void heapSortIncreasing(int *a, int size)
{
    buildMaxHeap(a, size);
    for (int i = size - 1; i >= 1; i--)
    {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}
void heapSortDecreasing(int *a, int size)
{
    buildMinHeap(a, size);
    for (int i = size - 1; i >= 1; i--)
    {
        swap(a[0], a[i]);
        minHeapify(a, i, 0);
    }
}
int main()
{
    int a[10] = {10, 9, 8, 2, 3, 4, 7, 6, 5, 1};
    heapSortDecreasing(a, 10);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
}