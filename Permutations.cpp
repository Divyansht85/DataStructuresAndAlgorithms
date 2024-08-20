#include <iostream>
#include <vector>
using namespace std;
void getPermutations(string s, vector<string> &ans, int i = 0)
{
    if (i == s.length() - 1)
    {
        ans.push_back(s);
        return;
    }
    for (int j = i; j < s.length(); j++)
    {
        swap(s[i], s[j]);
        getPermutations(s, ans, i + 1);
        swap(s[i], s[j]);
    }
}
int main()
{
    vector<string> permuatations;
    getPermutations("divy", permuatations);
    // cout << permuatations.size() << endl;
    for (int i = 0; i < permuatations.size(); i++)
        cout << permuatations[i] << endl;
}