#include <iostream>
#include <climits>
#include <queue>
#include <stack>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};
void preOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int size(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + size(root->left) + size(root->right);
}
int maximum(TreeNode *root)
{
    if (root == nullptr)
        return INT_MIN;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
void printNodesAtDistanceK(TreeNode *root, int k)
{
    if (root == nullptr)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printNodesAtDistanceK(root->left, k - 1);
    printNodesAtDistanceK(root->right, k - 1);
}
void levelOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            TreeNode *front = q.front();
            q.pop();
            cout << front->data << " ";
            if (front->left != nullptr)
                q.push(front->left);
            if (front->right != nullptr)
                q.push(front->right);
        }
        cout << endl;
    }
}
void preOrderIterative(TreeNode *root)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();
        cout << curr->data << " ";
        if (curr->right != nullptr)
            st.push(curr->right);
        if (curr->left != nullptr)
            st.push(curr->left);
    }
}

void inOrderIterative(TreeNode *root)
{
    if (root == nullptr)
        return;
    TreeNode *curr = root;
    stack<TreeNode *> st;
    while (curr != nullptr || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        cout << curr->data << " ";
        st.pop();
        curr = curr->right;
    }
}
void preorderIterativeSpaceOptimized(TreeNode *root)
{
    if (root == nullptr)
        return;
    TreeNode *curr = root;
    stack<TreeNode *> st;
    while (!st.empty() || curr != nullptr)
    {
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            if (curr->right != nullptr)
                st.push(curr->right);
            curr = curr->left;
        }
        if (!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}
void postOrderIterativeUsing2Stacks(TreeNode *root)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        TreeNode *curr = st1.top();
        st2.push(curr);
        st1.pop();
        if (curr->left != nullptr)
            st1.push(curr->left);
        if (curr->right != nullptr)
            st1.push(curr->right);
    }
    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}
void postOrderUsing1Stack(TreeNode *root)
{
    if (root == nullptr)
        return;
    TreeNode *curr = root;
    TreeNode *lastVisited = nullptr;
    stack<TreeNode *> st;
    while (curr != nullptr || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        if (st.top()->right == nullptr || st.top()->right == lastVisited)
        {
            lastVisited = st.top();
            cout << st.top()->data << " ";
            st.pop();
        }
        else
            curr = st.top()->right;
    }
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    postOrderUsing1Stack(root);
}