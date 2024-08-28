#include <iostream>
using namespace std;
int getFloor(int *a, int n, int x)
{
    int floor = -1, low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (x == a[mid])
            return a[mid];
        if (x < a[mid])
            high = mid - 1;
        else
        {
            floor = a[mid];
            low = mid + 1;
        }
    }
    return floor;
}
int getCeil(int *a, int n, int x)
{
    int ceil = -1, low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (x == a[mid])
            return x;
        if (x < a[mid])
        {
            ceil = a[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ceil;
}
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
    int arr[10] = {1, 2, 3, 5, 6, 6, 6, 7, 8, 9};
    cout << getCeil(arr, 10, 4) << endl;
}