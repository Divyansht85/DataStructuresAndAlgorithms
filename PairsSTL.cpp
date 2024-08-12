#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    // pair<int, int> p(1, 2);
    // pair<int, int> p;
    // // p = {1, 2};
    // p = make_pair(2, 2);
    // pair<int, int> p2(1, 3);
    // // cout << p.first << " " << p.second << endl;
    // cout << (p > p2);
    vector<pair<int, int>> v;
    v.push_back({1, 2});
    v.push_back({5, 1});
    v.push_back({2, 10});
    v.push_back({3, -1});
    v.push_back({3, 2});
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << "(" << v[i].first << ", " << v[i].second << ")\n";
}