#include <iostream>
#include <vector>
using namespace std;
vector<int> getPrimeFactors(int n)
{
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                ans.push_back(i);
                n = n / i;
            }
        }
    }
    if (n > 1)
        ans.push_back(n);
    return ans;
}
int main()
{
    vector<int> primeFactors = getPrimeFactors(99990000);
    for (int i = 0; i < primeFactors.size(); i++)
        cout << primeFactors.at(i) << " ";
    cout << endl;
}