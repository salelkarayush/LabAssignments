// Write a C++ program to study implementation of Hybrid form of Inheritance(Virtual Base Class)
// using classes and objects.

#include<iostream>
using namespace std;

class A
{
    public:
        int a;
        void get_a(int x)
        {
            a = x;
        }
        void show_a()
        {
            cout << "Value of a is " << a << endl;
        }
};

class B: virtual public A
{
    public:
        int b;
        void get_b(int y)
        {
            b = y;
        }
        void show_b()
        {
            cout << "Value of b is " << b << endl;
        }
};

class C: virtual public A
{
    public:
        int c;
        void get_c(int z)
        {
            c = z;
        }
        void show_c()
        {
            cout << "Value of c is " << c << endl;
        }
};

class D: public B, public C
{
    public:
        int d;
        void get_d(int w)
        {
            d = w;
        }
        void show_d()
        {
            cout << "Value of d is " << d << endl;
        }
};

int main()
{
    D d;
    d.get_a(10);
    d.get_b(20);
    d.get_c(30);
    d.get_d(40);
    d.show_a();
    d.show_b();
    d.show_c();
    d.show_d();
    return 0;
}
