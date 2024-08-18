#include <iostream>
#include <vector>
using namespace std;
vector<int> getDivisors(int n)
{
    vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i != n / i)
                ans.push_back(n / i);
        }
    }
    return ans;
}
vector<int> getDivisorsSorted(int n)
{
    vector<int> ans;
    int i;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
            ans.push_back(i);
    }
    for (; i >= 1; i--)
    {
        if (n % i == 0)
            ans.push_back(n / i);
    }
    return ans;
}
int main()
{
    vector<int> divisors = getDivisorsSorted(100);
    for (const int &x : divisors)
        cout << x << " ";
    cout << endl;
}