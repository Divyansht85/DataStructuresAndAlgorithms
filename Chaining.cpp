#include <iostream>
#include <list>
#include <functional>
using namespace std;
template <typename T>
class MyHashMap
{
    unsigned int capacity;
    list<T> *BUCKET;
    int hashFunction(const T &key)
    {
        hash<T> myHash;
        return myHash(key) % capacity;
    }

public:
    MyHashMap(const unsigned int &c)
    {
        capacity = c;
        BUCKET = new list<T>[c];
    }
    bool search(const T &key)
    {
        int i = hashFunction(key);
        for (const auto &x : BUCKET[i])
        {
            if (x == key)
                return true;
        }
        return false;
    }
    void insert(const T &key)
    {
        BUCKET[hashFunction(key)].push_back(key);
    }
    void remove(const T &key)
    {
        BUCKET[hashFunction(key)].remove(key);
    }
    void printHashMap() const
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << i << "-->";
            for (const auto &x : BUCKET[i])
                cout << x << " ";
            cout << endl;
        }
    }
};
int main()
{
    MyHashMap<int> m(5);
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