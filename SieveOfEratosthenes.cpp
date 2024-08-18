#include <iostream>
#include <vector>
using namespace std;
vector<int> getPrimes(int n)
{
    vector<int> ans;
    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            ans.push_back(i);
            for (int j = i * i; j <= n; j = j + i)
                isPrime[j] = false;
        }
    }
    return ans;
}
int main()
{
    vector<int> primes = getPrimes(100);
    for (int i = 0; i < primes.size(); i++)
        cout << primes[i] << " ";
    cout << endl;
}