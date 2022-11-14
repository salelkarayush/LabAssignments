#include<iostream>

using namespace std;
class b;
class a{
	int num;
	public:
		a(){
			num=5;
		}
		a operator ++(int){
			a temp;
			temp.num=num++;
			return temp;
		}
	   void display(){
		cout<<"number is: "<<num<<endl;
	}

};
class b{
	int num;
	public:
		b(){
			num=10;
		}
	b operator --(){
		b temp;
		temp.num=--num;
		return temp;
	}
	void display(){
		cout<<"number is: "<<num<<endl;
	}
   
};

int main(){
	a a1;
	b b1;
	//unary prefix 
	b1=--b1;
	b1.display();
	//unary postfix
	a1++;
	a1.display();
	
}
