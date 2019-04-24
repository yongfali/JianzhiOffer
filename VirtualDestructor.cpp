#include <iostream>
using namespace std;

class A
{
public:
	A(){}
	virtual ~A(){cout << "delete A" << endl;}
};

class B : public A
{
public:
	B(){}
	~B(){cout << "delete B" << endl;}
};

int main(int argc, char const* argv[])
{
	cout << "\n---------a1---------" << endl; {A a1;}
	cout << "\n---------a2---------" << endl; {A a2();} // A类型的 a2()函数申明。 

	cout << "\n---------b1---------" << endl; {B b1;}
	cout << "\n---------b2---------" << endl; {B b2();}

	cout << "\n---------pA1---------" << endl; {A *pA1 = new B; delete pA1;}
	cout << "\n---------pA2---------" << endl; {A *pA2 = new B(); delete pA2;}

	cout << "\n---------pB1---------" << endl; {B *pB1 = new B; delete pB1;}
	cout << "\n---------pB2---------" << endl; {B *pB2 = new B(); delete pB2;}

	return 0;
}
