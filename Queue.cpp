#include <iostream>
using namespace std;
template <typename T>
class QueueUsingCircularArray
{
    T *a;
    int front;
    int capacity;
    int size;
    void createNewQueue()
    {
        cout << "Creating new Queue\n";
        T *temp = new T[2 * capacity];
        for (int i = 0; i < size; i++)
            temp[i] = a[(front + i) % capacity];
        delete[] a;
        a = temp;
        capacity = 2 * capacity;
        front = 0;
    }

public:
    QueueUsingCircularArray(int c = 1) : capacity(c), size(0), front(0), a(new T[c]) {}
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
    int getFront()
    {
        return front;
    }
    int getRear()
    {
        return (front + size - 1) % capacity;
    }
    void enqueue(T d)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            createNewQueue();
        }
        int rear = getRear();
        rear = (rear + 1) % capacity;
        a[rear] = d;
        size++;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }
    void print()
    {
        if (isEmpty())
            return;
        int f = front;
        int rear = getRear();
        while (true)
        {
            if (f == rear)
            {
                cout << a[f] << endl;
                break;
            }
            cout << a[f] << " ";
            f = (f + 1) % capacity;
        }
    }
};
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T d) : data(d), next(nullptr) {}
};
template <typename T>
class QueueUsingLinkedList
{
    unsigned int size;
    Node<T> *front;
    Node<T> *rear;

public:
    QueueUsingLinkedList() : front(nullptr), rear(nullptr), size(0) {}
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(T d)
    {
        Node<T> *node = new Node<T>(d);
        if (front == nullptr)
            front = node;
        else
            rear->next = node;
        rear = node;
        size++;
    }
    void dequeue()
    {
        if (!isEmpty())
        {
            front = front->next;
            if (front == nullptr)
                rear = nullptr;
            size--;
        }
    }
    void print()
    {
        if (!isEmpty())
        {
            Node<T> *curr = front;
            while (curr != nullptr)
            {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    QueueUsingLinkedList<int> q;
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();
    q.enqueue(1);
    q.enqueue(2);
    q.print();
}