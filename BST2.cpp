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

class BST
{
private:
    void destroyTree(TreeNode *root)
    {
        if (root != nullptr)
        {
            destroyTree(root->left);
            destroyTree(root->right);
            delete root;
        }
    }

    int height(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    void printTree(TreeNode *node)
    {
        if (!node)
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
        q.push({node, 0, max_width / 2});

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
    }

public:
    TreeNode *root;
    BST() : root(nullptr) {}

    ~BST()
    {
        destroyTree(root);
    }

    TreeNode *insertRecursive(TreeNode *node, int d)
    {
        if (node == nullptr)
        {
            return new TreeNode(d);
        }
        if (d < node->data)
            node->left = insertRecursive(node->left, d);
        else
            node->right = insertRecursive(node->right, d);
        return node;
    }

    void makeBST(const vector<int> &v)
    {
        for (int i = 0; i < v.size(); i++)
            root = insertRecursive(root, v[i]);
    }

    void print()
    {
        printTree(root);
    }
};

int main()
{
    BST bst;
    vector<int> v = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    bst.makeBST(v);
    bst.insertRecursive(bst.root, 20);
    bst.print();
}
