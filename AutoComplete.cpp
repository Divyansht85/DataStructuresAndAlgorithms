//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class AutoCompleteSystem
{
    class TrieNode
    {
    public:
        unordered_map<char, TrieNode *> children;
        bool isEnd;
        int freq;
        TrieNode() : isEnd(false), freq(0) {}
    };
    string currentString;
    TrieNode *root;
    void insertSentence(const string &s, int frequency)
    {
        TrieNode *curr = root;
        for (const char &c : s)
        {
            if (curr->children.find(c) == curr->children.end())
                curr->children.insert({c, new TrieNode()});
            curr = curr->children[c];
        }
        curr->isEnd = true;
        curr->freq += frequency;
    }

public:
    class compare
    {
    public:
        bool operator()(const auto &p1, const auto &p2)
        {
            if (p1.second != p2.second)
                return p1.second < p2.second;
            return p1.first > p2.first
        }
    };
    AutoCompleteSystem(vector<string> &sentences, vector<int> &times) : currentString(""), root(new TrieNode())
    {
        for (int i = 0; i < sentences.size(); i++)
            insertSentence(sentences[i], times[i]);
    }
    void getSuggestions(TrieNode *curr, string s, auto &pq)
    {
        if (curr->isEnd)
        {
            pq.push({s, curr->freq});
            if (pq.size() > 3)
                pq.pop();
        }
        for (const auto &m : curr->children)
            getSuggestions(m.second, s + m.first, pq);
    }
    vector<string> input(char c)
    {
        if (c == '#')
        {
            insertSentence(currentString, 1);
            currentString = "";
            return {};
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;
        currentString += c;
        TrieNode *curr = root;
        for (const char &c : currentString)
        {
            if (curr->children.find(c) == curr->children.end())
                return {};
            curr = curr->children[c];
        }
        getSuggestions(curr, currentString, pq);
        vector<string> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * Your AutoCompleteSystem object will be instantiated and called as such:
 * AutoCompleteSystem* obj = new AutoCompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int n;
        cin >> n;
        cin.ignore();
        vector<string> sentences(n);
        vector<int> times(n);
        for (int i = 0; i < n; ++i)
        {

            getline(cin, sentences[i]);
            cin >> times[i];
            cin.ignore();
        }
        AutoCompleteSystem *obj = new AutoCompleteSystem(sentences, times);
        int q;
        cin >> q;
        cin.ignore();

        for (int i = 0; i < q; ++i)
        {
            string query;
            getline(cin, query);
            string qq = "";
            for (auto &x : query)
            {
                qq += x;
                vector<string> suggestions = obj->input(x);
                if (x == '#')
                    continue;
                cout << "Typed : \"" << qq << "\" , Suggestions: \n";
                for (auto &y : suggestions)
                {
                    cout << y << "\n";
                }
            }
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends