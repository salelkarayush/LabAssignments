#include<iostream>
using namespace std;

int add(int a, int b){
    return a+b;
}

double add(double a, double b){
    return a+b;
}

int main(){
    int a = add(10,20);
    double b = add(15.4, 12.1);
    cout << "int addition: " << a << endl;
    cout << "double addition: " << b << endl;
}