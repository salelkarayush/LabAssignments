#include <iostream>
using namespace std;

class B;  // forward declaration

class A{
private:
    int numA;
    friend int add(A, B);

public:
    A(){
        cout << "Enter a number A: ";
        cin >> numA;
    }
};

class B{
private:
    int numB;
    friend int add(A, B);

public:
    B(){
        cout << "Enter a number B: ";
        cin >> numB;
    }
};

// inline function to access members of both classes

inline int add(A a, B b){
    return (a.numA + b.numB);
}

int main(){
    int sum;
    A A;
    B B;
    sum = add(A, B);
    cout << "Sum: " << sum << endl;
    return 0;
}