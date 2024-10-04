#include <iostream>
#include <cstdlib>
using namespace std;
#define d 256
const int q = 101;
void naiveMethod(string s, string pattern)
{
    for (int i = 0; i <= s.size() - pattern.size(); i++)
    {
        int j;
        for (j = 0; j < pattern.size() && i + j < s.size(); j++)
        {
            if (s[i + j] != pattern[j])
                break;
        }
        if (j == pattern.size())
            cout << i << " ";
    }
}
void searchDistinctPattern(string s, string pattern)
{
    for (int i = 0; i <= s.size() - pattern.size();)
    {
        int j;
        for (j = 0; j < pattern.size() && i + j < s.size(); j++)
        {
            if (s[i + j] != pattern[j])
            {
                i += j;
                break;
            }
        }
        if (j == pattern.size())
        {
            cout << i << " ";
            i++;
        }
        if (j == 0)
            i++;
    }
}
void RabinKarp(string text, string pat)
{
    int p = 0, t = 0, h = 1, m = pat.size(), n = text.size();
    if (n < m)
        return;
    for (int i = 1; i <= m - 1; i++)
        h = (h * d) % q;
    for (int i = 0; i < m; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + text[i]) % q;
    }
    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            int j;
            for (j = 0; j < m; j++)
            {
                if (pat[j] != text[i + j])
                    break;
            }
            if (j == m)
                cout << i << " ";
        }
        if (i < n - m)
        {
            t = (d * (t - (text[i] * h)) + text[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
}
void fillLps(string pat, int *lps)
{
    int m = pat.size(), len = 0, i = 1;
    lps[0] = 0;
    while (i < m)
    {
        if (pat[i] == pat[len])
            lps[i++] = ++len;
        else
        {
            if (len == 0)
                lps[i++] = 0;
            else
                len = lps[len - 1];
        }
    }
}
void KMP(string text, string pat)
{
    int n = text.size(), m = pat.size(), i = 0, j = 0;
    if (m > n)
        return;
    int lps[m];
    fillLps(pat, lps);
    while (i < n)
    {
        if (text[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
        if (j == m)
        {
            cout << (i - m) << " ";
            j = lps[m - 1];
        }
    }
}
int main()
{
    system("clear");
    KMP("hi How are yo hihi yo hi", "hihi");
}