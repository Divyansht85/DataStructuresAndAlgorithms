#include <iostream>
using namespace std;
bool binarySearch(int *a, int low, int high, int x)
{
    if (low > high)
        return false;
    int mid = (low + high) / 2;
    if (a[mid] == x)
        return true;
    if (x > a[mid])
        return binarySearch(a, mid + 1, high, x);
    if (x < a[mid])
        return binarySearch(a, low, mid - 1, x);
}
int main()
{
    int arr[5] = {6, 7, 8, 9, 12};
    cout << std::boolalpha << binarySearch(arr, 0, 4, 13) << endl;
}