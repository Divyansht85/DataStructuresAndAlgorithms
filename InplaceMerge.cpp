#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
void merge(int *a, int *b, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[0])
        {
            pop_heap(b, b + m, greater<int>());
            swap(a[i], b[m - 1]);
            push_heap(b, b + m, greater<int>());
        }
    }
    sort(b, b + m);
}
int main()
{
    system("clear");
    int a[5] = {3, 5, 6, 9, 10};
    int b[6] = {0, 1, 2, 4, 7, 20};
    merge(a, b, 5, 6);
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < 6; i++)
        cout << b[i] << " ";
}