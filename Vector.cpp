#include <iostream>
#include <cstdlib>
#include <exception>

using namespace std;

template <typename T>
class vector
{
    T *arr;
    size_t _size;
    size_t _capacity;

    void resize(size_t newCapacity)
    {
        T *temp = new T[newCapacity];
        for (size_t i = 0; i < _size; i++)
            temp[i] = arr[i];
        delete[] arr;
        arr = temp;
        _capacity = newCapacity;
    }

public:
    vector(size_t c = 0) : _capacity(c), _size(0), arr(c == 0 ? nullptr : new T[c]) {}

    ~vector()
    {
        delete[] arr;
    }

    using iterator = T *;
    using const_iterator = const T *;

    size_t size() const
    {
        return _size;
    }

    size_t capacity() const
    {
        return _capacity;
    }

    void push_back(T d)
    {
        if (_size == _capacity)
            resize(_size == 0 ? 1 : 2 * _capacity);
        arr[_size++] = d;
    }

    void pop_back()
    {
        if (_size == 0)
            throw out_of_range("Size is zero, can't pop");
        --_size;
    }

    iterator begin()
    {
        return arr;
    }

    const_iterator begin() const
    {
        return arr;
    }

    iterator end()
    {
        return arr + _size;
    }

    const_iterator end() const
    {
        return arr + _size;
    }

    T &operator[](size_t i)
    {
        if (i >= _size)
            throw out_of_range("Index out of range");
        return arr[i];
    }

    const T &operator[](size_t i) const
    {
        if (i >= _size)
            throw out_of_range("Index out of range");
        return arr[i];
    }

    void clear()
    {
        _size = 0;
    }
};

int main()
{
    system("clear");

    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(6);
    v.push_back(5);
    v.push_back(7);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "First element: " << v[0] << endl;

    // Pop all elements
    while (v.size() > 0)
    {
        v.pop_back();
    }

    // Attempt to pop from an empty vector
    try
    {
        v.pop_back();
    }
    catch (exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
