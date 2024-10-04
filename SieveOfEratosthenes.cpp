#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
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
            for (long long j = (long long)i * i; j <= n; j = j + i)
                isPrime[j] = false;
        }
    }
    return ans;
}
int main()
{
    system("clear");
    vector<int> primes = getPrimes(INT_MAX >> 1);
    cout << primes.size() << endl
         << primes[primes.size() - 1];
    // for (int i = 0; i < primes.size(); i++)
    //     cout << primes[i] << endl;
    cout << endl;
}