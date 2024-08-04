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
int main()
{
    int arr[5] = {6, 7, 8, 9, 12};
    cout << std::boolalpha << binarySearch(arr, 0, 4, 5) << endl;
}