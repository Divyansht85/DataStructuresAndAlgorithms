#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {};
};
class CircularLinkedList
{
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}
    void insert(int d)
    {
        if (head == nullptr)
        {
            head = new Node(d);
            head->next = head;
        }
        else
        {
            Node *curr = head;
            while (curr->next != head)
                curr = curr->next;
            curr->next = new Node(d);
            curr->next->next = head;
        }
    }
    void print()
    {
        if (head == nullptr)
            return;
        Node *curr = head;
        do
        {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
    void insertAt(int d, int p)
    {
        if (head == nullptr || p <= 0)
            return;
        Node *node = new Node(d);
        if (p == 1)
        {
            node->next = head;
            Node *curr = head;
            while (curr->next != head)
                curr = curr->next;
            curr->next = node;
            head = node;
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i <= p - 2; i++)
            {
                curr = curr->next;
                if (curr == head)
                    return;
            }
            node->next = curr->next;
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
            if (temp == head)
            {
                delete head;
                head = nullptr;
                return;
            }
            Node *curr = head;
            while (curr->next != head)
                curr = curr->next;
            curr->next = temp;
            delete head;
            head = temp;
        }
        Node *curr = head;
        for (int i = 1; i <= p - 2; i++)
        {
            curr = curr->next;
            if (curr->next == head)
                return;
        }
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
};
int main()
{
    CircularLinkedList list;
    list.insert(2);
    list.insert(5);
    list.insert(7);
    list.insert(1);
    list.insert(1);
    list.insert(10);
    list.insert(8);
    list.print();
    list.deleteAt(1);
    list.print();
}