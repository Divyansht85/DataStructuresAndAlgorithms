#include <iostream>
#include <algorithm>
using namespace std;
void rotateLeft(int *a, int n, int d)
{
    d = d % n;
    reverse(a, a + d);
    reverse(a + d, a + n);
    reverse(a, a + n);
}
void rotateRight(int *a, int n, int d)
{
    d = d % n;
    reverse(a, a + n - d);
    reverse(a + n - d, a + n);
    reverse(a, a + n);
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    rotateRight(arr, 10, 11);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
}