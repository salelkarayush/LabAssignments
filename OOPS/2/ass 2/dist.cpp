#include <iostream>
using namespace std;

class DB;
class DM{
    int m, cm;
    public:
    void getdata(){
        cout << "Enter distance in metres and centimetres: ";
        cin >> m >> cm;
    }
    void showdata(){
        cout << "Distance is " << m << " metres and " << cm << " centimetres." << endl;
    }
    friend void add(DM, DB);
};

class DB{
    int f, i;
    public:
    void getdata(){
        cout << "Enter distance in feet and inches: ";
        cin >> f >> i;
    }
    void showdata(){
        cout << "Distance is " << f << " feet and " << i << " inches." << endl;
    }
    friend void add(DM, DB);
};

void add(DM d, DB b){
    int m, cm, f, i;
    m = d.m + b.f * 0.3048;
    cm = d.cm + b.i * 2.54;
    f = m * 3.28084;
    i = cm * 0.393701;
    cout << "Enter 1 to display in metres and centimetres or 2 to display in feet and inches: ";
    int choice;
    cin >> choice;
    if (choice == 1){
        cout << "Distance is " << m;
        cout<<" metres and " << cm << " centimetres." << endl;
    }
    else if (choice == 2){
        cout << "Distance is " << f;
        cout << " feet and " << i << " inches." << endl;
    }
    else{
        cout << "Invalid choice." << endl;
    }
}

int main()
{
    DM d;
    DB b;
    d.getdata();
    b.getdata();
    add(d, b);
    return 0;
}