#include <bits/stdc++.h>
using namespace std;

int sqrtUsingNewtonRhapson(int x)
{
    // int n = 1;
    if (x <= 1)
        return x;
    double ans = x / 2;
    while (fabs(ans * ans - x) >= 1)
    {
        ans = 0.5 * (ans + (x / ans));
        // n++;
    }
    // cout << "Newton Raphson iterations: " << n << endl;
    return ans;
}

int sqrtUsingBinarySearch(int x)
{
    // int n = 0;
    if (x <= 1)
        return x;
    int l = 0, r = x / 2;
    while (l <= r)
    {
        // n++;
        int mid = l + (r - l) / 2;
        long long temp = (long long)mid * mid;
        if (temp == x)
            return mid;
        if (temp < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    // cout << "Binary Search iterations: " << n << endl;
    return r;
}

int main()
{
    const int iterations = INT_MAX>>5; // Number of times to run the functions
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
    {
        sqrtUsingNewtonRhapson(INT_MAX);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration1 = end - start;
    cout << "sqrtUsingNewtonRhapson time for " << iterations << " runs: " << duration1.count() << " ms" << endl;

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
    {
        sqrtUsingBinarySearch(INT_MAX);
    }
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration2 = end - start;
    cout << "sqrtUsingBinarySearch time for " << iterations << " runs: " << duration2.count() << " ms" << endl;

    return 0;
}
