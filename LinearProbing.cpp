#include <iostream>
#include <functional>
using namespace std;
class MyHash
{
    unsigned int capacity;
    unsigned int size;
    int *arr;
    int hashFunction(const int &key)
    {
        hash<int> customHash;
        return customHash(key) % capacity;
    }
    void reHash()
    {
        printHashMap();
        int *temp = new int[2 * capacity];
        for (int i = 0; i < 2 * capacity; i++)
            temp[i] = -1;
        for (int i = 0; i < capacity; i++)
        {
            int key = arr[i];
            int h = hashFunction(key);
            while (temp[h] != -1 && temp[h] != key)
                h = (h + 1) % (2 * capacity);
            if (temp[h] != key)
            {
                temp[h] = key;
            }
        }
        capacity = 2 * capacity;
        delete[] arr;
        arr = temp;
        cout << "Rehashed" << endl;
    }

public:
    MyHash(int c) : capacity(c), size(0), arr(new int[c])
    {
        for (int i = 0; i < capacity; i++)
            arr[i] = -1;
    }
    ~MyHash()
    {
        delete[] arr;
    }
    bool search(const int key)
    {
        int h = hashFunction(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
                return true;
            i = (i + 1) % capacity;
            if (i == h)
                return false;
        }
        return false;
    }
    bool insert(const int key)
    {
        if (size == capacity)
            reHash();
        int i = hashFunction(key);
        while (arr[i] != -1 && arr[i] != -2 && arr[i] != key)
            i = (i + 1) % capacity;
        if (arr[i] == key)
            return false;
        else
        {
            arr[i] = key;
            size++;
            return true;
        }
    }
    bool remove(const int key)
    {
        int h = hashFunction(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
            {
                arr[i] = -2;
                size--;
                return true;
            }
            i = (i + 1) % capacity;
            if (i == h)
                return false;
        }
        return false;
    }
    void printHashMap() const
    {
        for (int i = 0; i < capacity; i++)
            cout << i << "--> " << arr[i] << endl;
    }
};
int main()
{
    MyHash m(5);
    m.insert(49);
    m.insert(51);
    m.insert(20);
    m.insert(25);
    m.insert(40);
    m.insert(61);
    m.insert(92);
    m.insert(83);
    m.insert(57);
    m.insert(2);
    m.insert(104);
    m.insert(26);
    m.insert(69);
    m.insert(48);
    m.insert(0);
    m.remove(48);
    m.printHashMap();
    cout << m.search(83);
}