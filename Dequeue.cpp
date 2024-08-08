#include <iostream>
using namespace std;
template <typename T>
class Dequeue
{
    T *arr;
    int capacity;
    int size;
    int front;
    void createNewDequeue()
    {
        cout << "\nCreating new Dequeue\n";
        T *temp = new T[2 * capacity];
        for (int i = 0; i < size; i++)
            temp[i] = arr[(front + i) % capacity];
        delete[] arr;
        arr = temp;
        capacity *= 2;
        front = 0;
    }

public:
    Dequeue(int c) : arr(new T[c]), capacity(c), size(0), front(0) {}
    bool isFull()
    {
        return size == capacity;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void deleteFront()
    {
        if (isEmpty())
            return;
        front = (front + 1) % capacity;
        size--;
    }
    void insertRear(T d)
    {
        if (isFull())
            createNewDequeue();
        arr[(front + size) % capacity] = d;
        size++;
    }
    void deleteRear()
    {
        if (isEmpty())
            return;
        size--;
    }
    void insertFront(T d)
    {
        if (isFull())
            createNewDequeue();
        front = (front + capacity - 1) % capacity;
        arr[front] = d;
        size++;
    }
    void print()
    {
        if (isEmpty())
            return;
        for (int i = 0; i < size; i++)
        {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Dequeue<int> q(5);
    q.insertRear(2);
    q.insertRear(3);
    q.insertFront(6);
    q.insertRear(7);
    q.insertRear(8);
    q.insertRear(9);
    q.print();
}