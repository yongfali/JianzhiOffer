#include<iostream>
#include<windows.h>
using namespace std;  

int main()
{	//C++允许连续赋值 
	int a, b, c;
    a = b = c = 10;
    printf("%d\n%d\n%d\n", a,b,c);
    printf("\n");	 
    cout << a << " " << b << " "<< c << endl; 
   	return 0; 
}