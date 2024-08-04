#include <iostream>
using namespace std;
class Complex
{
private:
    int real;
    int imaginary;

public:
    Complex(int r = 0, int i = 0) : real(r), imaginary(i) {}
    Complex operator=(const Complex &other)
    {
        if (this != &other)
        {
            this->real = other.real;
            this->imaginary = other.imaginary;
        }
        return *this;
    }
    Complex operator+(const Complex &other) const
    {
        Complex temp;
        temp.real = this->real + other.real;
        temp.imaginary = this->imaginary + other.imaginary;
        return temp;
    }
    Complex &operator++()
    {
        imaginary++;
        real++;
        return *(this);
    }
    Complex operator++(int)
    {
        Complex temp = *(this);
        ++(*this);
        return temp;
    }
    friend ostream &operator<<(ostream &out, const Complex &other)
    {
        out << std::noshowpos << other.real << " " << std::showpos << other.imaginary << "i" << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Complex &c)
    {
        cout << "Enter real Part:";
        in >> c.real;
        cout << "Enter imaginary Part:";
        in >> c.imaginary;
        return in;
    }
};
int main()
{
    Complex c2;
    cin >> c2;
    cout << c2;
}