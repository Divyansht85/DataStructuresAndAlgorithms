#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    cout << endl;
}
int main()
{
    system("clear");
    // vector<int> v(5, -1); // Size 5 and all values -1;
    // for (int i = 0; i < v.size(); i++)
    //     cout << v[i] << endl;
    int arr[5]{2, 3, 4, 5, 6};
    vector<int> v(arr, arr + 5);
    print(v);
    v.resize(7, -1);
    print(v);
    // v.erase(v.begin(), v.begin() + 3);
    // print(v);
    // for (auto it = v.crbegin(); it != v.crend(); it++)
    //     cout << *it << " " << endl;
    // v.push_back(10);
    // print(v);
    // v.pop_back();
    // print(v);
    // cout << v.front() << endl;
    // cout << v.back() << endl;
    // v.insert(v.begin() + 2, 3, 100);
    // print(v);
    // vector<int> v2;
    // v2.insert(v2.begin(), v.begin(), v.begin() + 2);
    // print(v2);
    // v.clear();
    // print(v);
}