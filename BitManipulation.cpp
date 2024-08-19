#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int countBits(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans++;
        n = n & (n - 1);
    }
    return ans;
}
pair<int, int> twoOddOccuring(int *a, int n)
{
    int x = a[0];
    for (int i = 1; i < n; i++)
        x = x ^ a[i];
    int k = x & (~(x - 1));
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] & k)
            ans1 = ans1 ^ a[i];
        else
            ans2 = ans2 ^ a[i];
    }
    return {ans1, ans2};
}
vector<string> powerSet(string s)
{
    int n = s.length();
    vector<string> ans;
    int total = (1 << n);
    for (int mask = 0; mask <= total; mask++)
    {
        string temp = "";
        for (int j = 0; j <= n; j++)
        {
            if (mask & (1 << j))
                temp += s[j];
        }
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    vector<string> ans = powerSet("div");
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}