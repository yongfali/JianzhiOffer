#include<iostream>

using namespace std;
 
 class A{};
 
 class B{ char m_data; int a;};
 
 class C{
 	char m_data[100];
 };
 
 class D{
 	char *data;
 	int a;
 	D():data(new char[100]){} //��ָ���ʼ�� 
 	~D(){delete [] data;}
 };
 
 //���� argc��ʾ������������agrv��ʾ�������飬��һ��Ϊ�ļ���ŵĵ�ַ 
 int main(int argc, char *argv[]){
 	char data[10];
 	char *pData = data;
 	static int a = 10; 
 	long long b;
 	
 	cout << sizeof(data) << endl;
 	cout << sizeof(pData) << endl;
 	cout << sizeof(a) << endl;
 	cout << sizeof(b) << endl;
 	
 	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(D) << endl;
		
 	//for(int i = 0; i < argc; i++)  
       // cout << "argument["<< i<< "] is: " << argv[i] << endl;  
    //system("pause");  
 }