#include <iostream>
using namespace std;
template <typename T>
class SmartPointer
{
    T *ptr;

public:
    SmartPointer(T *p = nullptr) : ptr(p) {}
    ~SmartPointer()
    {
        delete ptr;
        cout << "\nDestructor called\n";
    }
    T *operator=(T &x)
    {
        ptr = &x;
        return ptr;
    }
    T operator*() const
    {
        return *ptr;
    }
};
int main()
{
    SmartPointer<int> a;
    int num = 5;
    a = num;
    cout << *a;
}