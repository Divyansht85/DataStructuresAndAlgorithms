#include <iostream>
#include <vector>
#include <climits>
using namespace std;
bool isFeasible(vector<int> &nums, int maximum, int k)
{
    int minSplits = 1, sum = 0;
    for (const auto &x : nums)
    {
        if (sum + x <= maximum)
            sum += x;
        else
        {
            sum = x;
            minSplits++;
        }
    }
    return minSplits <= k;
}
int splitArray(vector<int> &nums, int k)
{
    int high = 0, low = INT_MIN, ans;
    for (int i = 0; i < nums.size(); i++)
    {
        high += nums[i];
        low = max(low, nums[i]);
    }
    while (low <= high)
    {
        int mid = ((low + high) >> 1);
        if (isFeasible(nums, mid, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    vector<int> v = {2, 3, 1, 1, 1, 1, 1};
    cout << splitArray(v, 5) << endl;
}
