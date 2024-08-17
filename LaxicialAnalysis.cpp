#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
bool nextPermutation(int *a, int n)
{
    int pivotIndex = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            pivotIndex = i;
            break;
        }
    }
    if (pivotIndex == -1)
        return false;
    int nextGreater;
    for (int i = n - 1; i > pivotIndex; i--)
    {
        if (a[i] > a[pivotIndex])
        {
            nextGreater = i;
            break;
        }
    }
    swap(a[pivotIndex], a[nextGreater]);
    reverse(a + pivotIndex + 1, a + n);
    return true;
}
bool previousPermutation(int *a, int n)
{
    int pivotIndex = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
        {
            pivotIndex = i;
            break;
        }
    }
    if (pivotIndex == -1)
        return false;
    int nextSmaller;
    for (int i = n - 1; i > pivotIndex; i--)
    {
        if (a[i] < a[pivotIndex])
        {
            nextSmaller = i;
            break;
        }
    }
    swap(a[pivotIndex], a[nextSmaller]);
    reverse(a + pivotIndex + 1, a + n);
    return true;
}
int main()
{
    system("clear");
    int arr[5] = {5, 4, 3, 2,1};
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
    while (previousPermutation(arr, 5))
    {
        for (int i = 0; i < 5; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}