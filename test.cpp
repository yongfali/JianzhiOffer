#include <iostream>
 
using namespace std;
 
 
class A{
public:
 	A(){
	 	cout << " A" <<endl; 
	 }
 	~A(){
	 	cout << "delete A " <<endl;
	 }
};

class B : public A{
	B(){
		cout << "B" << endl;
	}
	~B(){
		cout << "delete B" << endl;
	}
};

int main()
{
	B b2();
	int c();
	//delete b2;
	return 0;
	//A a = A(1);
//	A b;
	//A *c = new A(2);
//	cout << &a << " " << &b << " " << &c <<endl; 
    /*int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
 
    Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);/*这里原文第三个参数要减1否则内存越界*/
 
    //for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    //{
       // cout << a[i] << " ";
    //}
   
     
    return 0;
}