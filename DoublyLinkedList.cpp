#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList
{
public:
    Node *head;
    DoublyLinkedList() : head(nullptr) {}
    void insert(int d)
    {
        if (head == nullptr)
        {
            head = new Node(d);
        }
        else
        {
            Node *node = new Node(d);
            Node *curr = head;
            while (curr->next != nullptr)
                curr = curr->next;
            curr->next = node;
            node->prev = curr;
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
    void insertAt(int d, int p)
    {
        if (p <= 0 || head == nullptr)
            return;
        Node *node = new Node(d);
        if (p == 1)
        {
            node->next = head;
            head->prev = node;
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
            if (curr->next != nullptr)
                curr->next->prev = node;
            node->prev = curr;
            curr->next = node;
        }
    }
    void deleteAt(int p)
    {
        if (p <= 0 || head == nullptr)
            return;
        if (p == 1)
        {
            Node *temp = head->next;
            delete head;
            head = temp;
            head->prev = nullptr;
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i <= p - 2; i++)
            {
                curr = curr->next;
                if (curr->next == nullptr)
                    return;
            }
            Node *temp = curr->next;
            curr->next = curr->next->next;
            if (curr->next != nullptr)
                curr->next->prev = curr;
            delete temp;
        }
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
            curr->prev = next;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    Node *reverseRecursive(Node *node)
    {
        if (node == nullptr || node->next == nullptr)
            return node;
        Node *temp = reverseRecursive(node->next);
        node->next->next = node;
        node->prev = node->next;
        node->next = nullptr;
        return temp;
    }
};
int main()
{
    DoublyLinkedList list;
    list.insert(2);
    list.insert(5);
    list.insert(7);
    list.insert(1);
    list.insert(1);
    list.insert(10);
    list.insert(8);
    list.print();
    list.head = list.reverseRecursive(list.head);
    list.print();
}