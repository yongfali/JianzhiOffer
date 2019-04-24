#include<iostream>

using namespace std;

class A{
	char a;
	int b;
	char c;
};

class B{
	char a;
	char b;
	int c;
};

class C{
	int a;
	char b[33];
	double c;	
};

int main(){
	
	cout << "sizeof(A):" << sizeof(A) << endl;
    cout << "sizeof(B):" << sizeof(B) << endl;
    cout << "sizeof(C):" << sizeof(C) << endl;
	return 0;
}
