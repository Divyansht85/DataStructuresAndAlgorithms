#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
struct Node
{
    char data;
    int freq;
    Node *left;
    Node *right;
    Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};
struct compare
{
    bool operator()(const Node *n1, const Node *n2)
    {
        return n2->freq < n1->freq;
    }
};
class HuffmanCode
{
    priority_queue<Node *, vector<Node *>, compare> pq;
    unordered_map<char, int> freq;
    unordered_map<char, string> codes;
    Node *root;
    void getHuffmanCodes(Node *root, string code)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            codes[root->data] = code;
        getHuffmanCodes(root->left, code + to_string(0));
        getHuffmanCodes(root->right, code + to_string(1));
    }
    void freeTree(Node *root)
    {
        if (!root)
            return;
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
    vector<bool> convertToBits(const string &code)
    {
        vector<bool> bits(code.size());
        for (int i = 0; i < code.size(); i++)
            bits[i] = code[i] - '0';
        return bits;
    }

    // Converts a vector of bytes to a string of bits
    string convertBitsToString(const vector<bool> &bits)
    {
        string code = "";
        for (const bool &b : bits)
            code += b ? "1" : "0";
        return code;
    }

public:
    HuffmanCode() : root(nullptr) {}
    ~HuffmanCode()
    {
        freeTree(root);
    }
    vector<bool> compress(string s)
    {
        for (char &c : s)
            freq[c]++;
        for (auto &x : freq)
            pq.push(new Node(x.first, x.second));
        while (pq.size() > 1)
        {
            Node *n1 = pq.top();
            pq.pop();
            Node *n2 = pq.top();
            pq.pop();
            Node *n3 = new Node('$', n1->freq + n2->freq);
            n3->left = n1;
            n3->right = n2;
            pq.push(n3);
        }
        root = pq.top();
        getHuffmanCodes(root, "");
        string encodedString = "";
        for (const char &c : s)
            encodedString += codes[c];
        return convertToBits(encodedString);
    }
    string decompress(const vector<bool> &compressedData)
    {
        string code = convertBitsToString(compressedData);
        Node *curr = root;
        string ans = "";
        for (const char &c : code)
        {
            if (c == '0')
                curr = curr->left;
            else
                curr = curr->right;
            if (curr->left == nullptr && curr->right == nullptr)
            {
                ans += curr->data;
                curr = root;
            }
        }
        return ans;
    }
};
int main()
{
    HuffmanCode obj;
    string input = R"()";
    vector<bool> compressedData = obj.compress(input);
    cout << "Compressed data: ";
    for (const bool &b : compressedData)
        cout << b;
    cout << endl;
    string decompressedString = obj.decompress(compressedData);
    cout << "Decompressed: " << decompressedString << endl;
    return 0;
}