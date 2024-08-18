#include <iostream>
using namespace std;
int power(int x, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * x;
        x = x * x;
        n = n >> 1;
    }
    return res;
}
int main()
{
    cout << power(2, 6) << endl;
}