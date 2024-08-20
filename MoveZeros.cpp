#include <iostream>
using namespace std;
int moveZerosToEnd(int *a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            swap(a[count++], a[i]);
    }
    return count;
}
int main()
{
    int arr[10] = {1, 2, 0, 3, 0, 0, 5, 0, 6, 7};
    int count = moveZerosToEnd(arr, 10);
    for (int i = 0; i < count; i++)
        cout << arr[i] << " ";
    cout << endl;
}