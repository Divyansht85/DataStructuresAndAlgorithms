#include <iostream>
using namespace std;
void cycleSort(int *a, int n)
{
    for (int cs = 0; cs < n - 1; cs++)
    {
        int item = a[cs];
        int pos = cs;
        for (int i = cs + 1; i < n; i++)
        {
            if (a[i] < item)
                pos++;
        }
        if (pos == cs)
            continue;
        while (a[pos] == item)
            pos++;
        swap(item, a[pos]);
        while (pos != cs)
        {
            pos = cs;
            for (int i = cs + 1; i < n; i++)
            {
                if (a[i] < item)
                    pos++;
            }
            while (item == a[pos])
                pos++;
            if (a[pos] != item)
                swap(a[pos], item);
        }
    }
}
int main()
{
    int a[20] = {7, 5, 6, 3, 4, 2, 1, 0, -1, -3, -2, 4, 7, -2, 4, 0, 1, 3, 5, 2};
    for (int i = 0; i < 20; i++)
        cout << a[i] << " ";
    cout << endl;
    cycleSort(a, 20);
    for (int i = 0; i < 20; i++)
        cout << a[i] << " ";
    cout << endl;
}