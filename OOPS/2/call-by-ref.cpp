#include <iostream>
using namespace std;

void check(int &b){
    if (b % 2 == 0){
        cout << "Even" << endl;
    }
    else{
        cout << "Odd" << endl;
    }

    if (b < 0){
        cout << "Negative" << endl;
    }
    else{
        cout << "Positive" << endl;
    }
}

int main(){
    int a;
    cout << "Enter a number to check: ";
    cin >> a;
    check(a);
    return 0;
}