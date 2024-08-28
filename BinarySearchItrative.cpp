#include <iostream>
using namespace std;
bool binarySearch(int *a, int low, int high, int x)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
            return true;
        else if (x < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}
int firstOccurance(int *a, int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x < a[mid])
            high = mid - 1;
        else if (x > a[mid])
            low = mid + 1;
        else
        {
            if (mid == 0 || a[mid - 1] != a[mid])
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int lastOccurance(int *a, int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x < a[mid])
            high = mid - 1;
        else if (x > a[mid])
            low = mid + 1;
        else
        {
            if (mid == n - 1 || a[mid] != a[mid + 1])
                return mid;
            else
                low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[10] = {1, 2, 3, 6, 6, 6, 6, 7, 8, 9};
    cout << lastOccurance(arr, 10, 6) << endl;
}