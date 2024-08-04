#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bucketSort(int *a, int n, int k)
{
    int maxVal = a[0];
    for (int i = 0; i < n; i++)
        maxVal = max(maxVal, a[i]);
    maxVal++;
    vector<int> bucket[k];
    for (int i = 0; i < n; i++)
        bucket[(a[i] * k) / maxVal].push_back(a[i]);
    for (int i = 0; i < k; i++)
        sort(bucket[i].begin(), bucket[i].end());
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        for (int x : bucket[i])
            a[index++] = x;
    }
}
int main()
{
    int arr[12] = {8, 9, 15, 2, 3, 56, 34, 23, 78, 90, 6, 30};
    bucketSort(arr, 12, 5);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}