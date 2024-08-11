#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};
int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
void printTree(TreeNode *root)
{
    if (!root)
        return;
    struct NodeInfo
    {
        TreeNode *node;
        int depth;
        int pos;
    };
    int h = height(root);
    int max_width = (1 << h) - 1;
    vector<string> lines(h * 2 - 1, string(max_width * 4 - 1, ' ')); // Increased space for better alignment
    queue<NodeInfo> q;
    q.push({root, 0, max_width / 2});
    while (!q.empty())
    {
        NodeInfo curr = q.front();
        q.pop();
        int pos = curr.pos * 4; // Adjust the position multiplier for better spacing
        string value = to_string(curr.node->data);
        for (int i = 0; i < value.length(); i++)
        {
            lines[curr.depth * 2][pos + i] = value[i];
        }
        if (curr.node->left)
        {
            q.push({curr.node->left, curr.depth + 1, curr.pos - (1 << (h - curr.depth - 2))});
            lines[curr.depth * 2 + 1][pos - (1 << (h - curr.depth - 2)) * 2] = '/';
        }
        if (curr.node->right)
        {
            q.push({curr.node->right, curr.depth + 1, curr.pos + (1 << (h - curr.depth - 2))});
            lines[curr.depth * 2 + 1][pos + (1 << (h - curr.depth - 2)) * 2] = '\\';
        }
    }
    for (const string &line : lines)
    {
        cout << line << endl;
    }
    cout << endl
         << endl
         << endl;
}
TreeNode *insertRecursive(TreeNode *root, int d)
{
    if (root == nullptr)
    {
        root = new TreeNode(d);
        return root;
    }
    if (d < root->data)
        root->left = insertRecursive(root->left, d);
    else
        root->right = insertRecursive(root->right, d);
    return root;
}
bool searchRecursive(TreeNode *root, int d)
{
    if (root == nullptr)
        return false;
    if (root->data == d)
        return true;
    if (d < root->data)
        return searchRecursive(root->left, d);
    else
        return searchRecursive(root->right, d);
}
bool searchIterative(TreeNode *root, int x)
{
    TreeNode *curr = root;
    while (curr != nullptr)
    {
        if (curr->data == x)
            return true;
        if (x < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return false;
}
TreeNode *insertIterative(TreeNode *&root, int d)
{
    TreeNode *node = new TreeNode(d);
    TreeNode *curr = root;
    TreeNode *parent = nullptr;
    while (curr != nullptr)
    {
        parent = curr;
        if (d < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (parent == nullptr)
        root = node;
    else
    {
        if (d < parent->data)
            parent->left = node;
        else
            parent->right = node;
    }
    return root;
}
void makeBST(TreeNode *&root, const vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        root = insertIterative(root, v[i]);
    }
}
TreeNode *getSuccessor(TreeNode *root)
{
    if (root == nullptr)
        return root;
    TreeNode *curr = root->right;
    while (curr != nullptr && curr->left != nullptr)
        curr = curr->left;
    return curr;
}
TreeNode *deleteNode(TreeNode *root, int x)
{
    if (root == nullptr)
        return root;
    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else
    {
        if (root->left == nullptr)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            TreeNode *succ = getSuccessor(root);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}
int ceil(TreeNode *root, int x)
{
    TreeNode *curr = root;
    int ans = -1;
    while (curr != nullptr)
    {
        if (curr->data == x)
            return x;
        if (curr->data < x)
            curr = curr->right;
        else
        {
            ans = curr->data;
            curr = curr->left;
        }
    }
    return ans;
}
int floor(TreeNode *root, int x)
{
    TreeNode *curr = root;
    int ans = -1;
    while (curr != nullptr)
    {
        if (curr->data == x)
            return x;
        if (curr->data > x)
            curr = curr->left;
        else
        {
            ans = curr->data;
            curr = curr->right;
        }
    }
    return ans;
}
int main()
{
    TreeNode *root = nullptr;
    vector<int> v = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    makeBST(root, v);
    printTree(root);
    cout << floor(root, 0) << endl;
}