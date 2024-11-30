#include <iostream>
#include <vector>
using namespace std;
int superEggDrop(int k, int n)
{
    vector<int> maxFloorsChecked(k + 1, 0);
    int attempts;
    for (attempts = 1; maxFloorsChecked[k] < n; attempts++)
    {
        for (int eggs = k; eggs >= 1; eggs--)
        {
            maxFloorsChecked[eggs] =
                maxFloorsChecked[eggs] + maxFloorsChecked[eggs - 1] + 1;
        }
        for (int i = 0; i <= k; i++)
        {
            cout << maxFloorsChecked[i] << " ";
        }
        cout << endl;
    }
    return attempts - 1;
}
int main()
{
    cout << superEggDrop(8, 100);
}