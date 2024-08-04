#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};
class List
{
public:
    Node *head;
    List() : head(nullptr) {}
    void insert(int d)
    {
        Node *node = new Node(d);
        if (head == nullptr)
            head = node;
        else
        {
            Node *curr = head;
            while (curr->next != nullptr)
                curr = curr->next;
            curr->next = node;
        }
    }
    void print()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    void insertAt(int p, int d)
    {
        if (p <= 0 || head == nullptr)
            return;
        Node *node = new Node(d);
        if (p == 1)
        {
            node->next = head->next;
            head = node;
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i <= p - 2; i++)
            {
                curr = curr->next;
                if (curr == nullptr)
                    return;
            }
            node->next = curr->next;
            curr->next = node;
        }
    }
    void deleteAt(int p)
    {
        if (head == nullptr || p < 1)
            return;
        if (p == 1)
        {
            Node *temp = head->next;
            delete head;
            head = temp;
            return;
        }
        Node *curr = head;
        for (int i = 1; i <= p - 2; i++)
        {
            curr = curr->next;
            if (curr == nullptr)
                return;
        }
        if (curr->next == nullptr)
            return;
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
    void middleNode()
    {
        if (head == nullptr)
            return;
        Node *slow = head;
        Node *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->data << endl;
    }
    void NthNodeFromEnd(int n)
    {
        Node *first = head;
        if (head == nullptr || n <= 0)
            return;
        for (int i = 1; i <= n - 1; i++)
        {
            first = first->next;
            if (first == nullptr)
                return;
        }
        Node *second = head;
        while (first->next != nullptr)
        {
            second = second->next;
            first = first->next;
        }
        cout << second->data << endl;
    }
    void reverseIterative()
    {
        if (head == nullptr || head->next == nullptr)
            return;
        Node *prev = nullptr;
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    Node *reverseRecursive(Node *node)
    {
        if (node == nullptr || node->next == nullptr)
            return node;
        head = reverseRecursive(node->next);
        node->next->next = node;
        node->next = nullptr;
        return head;
    }
};
int main()
{
    List list;
    list.insert(2);
    list.insert(5);
    list.insert(7);
    list.insert(1);
    list.insert(1);
    list.insert(10);
    list.insert(8);
    list.print();
    list.reverseRecursive(list.head);
    list.print();
}
