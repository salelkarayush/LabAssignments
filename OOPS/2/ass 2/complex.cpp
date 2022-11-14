#include<iostream>
using namespace std;

class complex{
    int real,imaginary;
    public:
    void input();
    void display();
    friend complex sum(complex,complex);
};

void complex::input(){
    cout<<"Enter the real part: ";
    std::cin>>real;
    cout<<"Enter the imaginary part: ";
    std::cin>>imaginary;
}

void complex::display(){
    cout<<real;
    if(imaginary>0){
        if(imaginary == 1){
            cout << "+i" << endl;
        }
        else
        cout << "+";
        cout << imaginary << "i" << endl;
    }
    if(imaginary<0){
        if(imaginary == -1){
            cout << "-i" << endl;
        }
        else
        cout << imaginary << "i" << endl;
    }
}

complex sum(complex A,complex B){
    complex C;
    C.real=A.real+B.real;
    C.imaginary=A.imaginary+B.imaginary;
    return C;
}

int main(){
    complex a,b,c;
    cout<<"Object 1 -"<<endl;
    a.input();
    cout<<"Object 2 -"<<endl;
    b.input();
    c=sum(a,b);
    cout<<"a = ";
    a.display();
    cout<<"b = ";
    b.display();
    cout<<"c = ";
    c.display();
    return 0;
}
