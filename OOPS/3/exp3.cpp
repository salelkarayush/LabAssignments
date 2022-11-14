#include<iostream>

using namespace std;

class A
{
    int id;
    public:
        //parameterized constructor
        A(int i)
        {
            id = i;
        }
        //copy constructor
        A(A &a)
        {
            id = a.id;
        }
        void display(){
            cout<<"id = "<<id<<endl;
        }
        ~A()
        {
            cout<<"Destructor called for id = "<<id<<endl;
        }
};

int main()
{
    A a1(10);//calling parameterized constructor
    A a2(a1);//calling copy constructor
    A a3 = a1;//calling copy constructor
    cout << "\na1 ID = ";
    a1.display();
    cout << "\na2 ID = ";
    a2.display();
    cout << "\na3 ID = ";
    a3.display();
    return 0;
}
