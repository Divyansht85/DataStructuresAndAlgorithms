#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void merge(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    int i = n - 1, j = 0;
    while (i >= 0 && j < m && (b[j] < a[i]))
    {
        swap(b[j], a[i]);
        j++;
        i--;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}
int main()
{
    vector<int> a = {1, 2, 4, 5, 7, 9};
    vector<int> b = {1, 2, 3, 6, 7, 8};
    merge(a, b);
    for (const int &x : a)
        cout << x << " ";
    cout << endl;
    for (const int &x : b)
        cout << x << " ";
}