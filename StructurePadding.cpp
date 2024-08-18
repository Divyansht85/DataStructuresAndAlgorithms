#include <iostream>
#include <stdint.h> // Include the appropriate header file for 'packed' attribute
using namespace std;
struct s1
{
    char c1;
    double d1;
    char c2;
};
struct s2
{
    char c1;
    char c2;
    double d1;
};
struct s3
{
    double d1;
    char c1;
    char c2;
} __attribute__((packed));
int main()
{
    cout << "Size of s1: " << sizeof(s1) << endl;
    cout << "Size of s2: " << sizeof(s2) << endl;
    cout << "Size of s3: " << sizeof(s3) << endl;
}