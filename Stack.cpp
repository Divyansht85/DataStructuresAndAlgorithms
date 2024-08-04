#include <iostream>
using namespace std;
template <typename T>
class Stack
{
    T *a;
    int Size;
    int capacity;
    int Top;
    void createNewStack()
    {
        cout << "Creating new stack...\n";
        T *temp = new T[2 * capacity];
        for (int i = 0; i <= Top; i++)
            temp[i] = a[i];
        delete[] a;
        a = temp;
        capacity = 2 * capacity;
    }

public:
    Stack(int c) : capacity(c), a(new T[c]), Size(0), Top(-1) {}
    bool isFull()
    {
        return Size == capacity;
    }
    bool isEmpty()
    {
        return Size == 0;
    }
    void push(T d)
    {
        if (isFull())
        {
            cout << "\nStack is full\n";
            createNewStack();
        }
        Top++;
        a[Top] = d;
        Size++;
    }
    T pop()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty\n";
            return -1;
        }
        Top--;
        Size--;
        return a[Top + 1];
    }
    int size()
    {
        return Size;
    }
    T top()
    {
        if (isEmpty())
        {
            cout << "\nArray is Empty\n";
            return -1;
        }
        return a[Top];
    }
    void print()
    {
        if (isEmpty())
        {
            cout << endl;
            return;
        }
        int d = pop();
        print();
        cout << d << " ";
        push(d);
    }
};
template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T d) : data(d), next(nullptr) {}
};
template <typename T>
class StackUingLinkedList
{
    Node<T> *head;
    int size;
    void printReverse(Node<T> *node)
    {
        if (node == nullptr)
        {
            cout << endl;
            return;
        }
        printReverse(node->next);
        cout << node->data << " ";
    }

public:
    StackUingLinkedList() : head(nullptr), size(0) {}
    bool isEmpty()
    {
        return size == 0;
    }
    void push(T d)
    {
        Node<T> *node = new Node<T>(d);
        if (head == nullptr)
        {
            head = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
        size++;
    }
    T pop()
    {
        if (head == nullptr)
        {
            cout << "\nStack is Empty\n";
            return -1;
        }
        else
        {
            Node<T> *temp = head;
            head = head->next;
            T d = temp->data;
            delete temp;
            size--;
            return d;
        }
    }
    T top()
    {
        if (isEmpty())
        {
            cout << "\nStack is Empty\n";
            return -1;
        }
        return head->data;
    }
    void print()
    {
        printReverse(head);
    }
};
int main()
{
    StackUingLinkedList<int> st;
    st.push(6);
    st.push(8);
    st.push(2);
    st.push(3);
    st.push(5);
    st.push(10);
    st.print();
    st.pop();
    st.print();
    cout << "\nTop element =" << st.top() << endl;
    st.pop();
    st.print();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
}