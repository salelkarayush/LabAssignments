/*Write a C++ program to create a vector of ‘n’ elements (allocate the memory
dynamically) and then multiply a scalar value with each element of a vector. Also show
the result of addition of two vectors.*/

#include <iostream>
using namespace std;

class vector
{
    int len, *ptr;

public:
    vector()
    {
        len = 0;
        ptr = NULL;
    }
    vector(int);
    friend istream &operator>>(istream &in, class vector &v);
    friend ostream &operator<<(ostream &out, class vector &v);
    friend void operator*(int, vector &);
    vector operator+(vector);
};

void operator*(int n, vector &v)
{
    for (int i = 0; i < v.len; i++)
        v.ptr[i] *= n;
    cout << v;
}

vector vector::operator+(vector v2)
{
    vector temp(len);
    for (int i = 0; i < len; i++)
        temp.ptr[i] = ptr[i] + v2.ptr[i];
    return temp;
}

istream &operator>>(istream &in, class vector &v)
{
    for (int i = 0; i < v.len; i++)
        in >> v.ptr[i];
    return in;
}

ostream &operator<<(ostream &out, class vector &v)
{
    out << "( ";
    for (int i = 0; i < v.len; i++)
        out << v.ptr[i] << " ";
    out << ")" << endl;
    return out;
}

vector::vector(int n)
{
    len = n;
    ptr = new int[len];
}

int main()
{
    int size;
    cout << "Enter the size of Vector: ";
    cin >> size;
    vector v1(size), v2(size);
    cout << "Enter first vector: ";
    cin >> v1;
    cout << "Enter second vector: ";
    cin >> v2;
    cout << "Enter the scalar to be multiplied: ";
    int n;
    cin >> n;
    cout << "vector1*" << n << "=";
    n *v1;
    cout << "vector2*" << n << "=";
    n *v2;
    vector v3(2 * size);
    cout << "vector1 + vector2 = ";
    v3 = v1 + v2;
    cout << v3;
    return 0;
}