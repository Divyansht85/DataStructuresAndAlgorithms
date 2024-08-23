#include <iostream>
#include <vector>
using namespace std;
inline int normalSum(vector<int> &nums)
{
    int ans = nums[0];
    int max_so_far = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (max_so_far < 0)
            max_so_far = 0;
        max_so_far += nums[i];
        ans = max(ans, max_so_far);
    }
    return ans;
}
int maxSubarraySumCircular(vector<int> &nums)
{
    int normalsum = normalSum(nums);
    if (normalsum < 0)
        return normalsum;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        nums[i] = (-1) * nums[i];
    }
    return max(normalsum, sum + normalSum(nums));
}
int main()
{
    vector<int> nums = {-3, -2, -3};
    cout << maxSubarraySumCircular(nums) << endl;
}