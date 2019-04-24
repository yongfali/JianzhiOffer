#include<iostream>

using namespace std;

/**
 
struct/class/union�ڴ����ԭ�����ĸ���

1).���ݳ�Ա������򣺽ṹ(struct)(������(union))�����ݳ�Ա����һ�����ݳ�Ա����
offsetΪ0�ĵط����Ժ�ÿ�����ݳ�Ա�洢����ʼλ��Ҫ�Ӹó�Ա��С���߳�Ա���ӳ�Ա��С
��ֻҪ�ó�Ա���ӳ�Ա������˵�����飬�ṹ��ȣ�����������ʼ
(����int�ڣ���λ��Ϊ���ֽ�, ��Ҫ�ӣ�����������ַ��ʼ�洢),
�������Ͳ�����struct/class/uinon��

2).�ṹ����Ϊ��Ա:���һ���ṹ����ĳЩ�ṹ���Ա,
��ṹ���ԱҪ�����ڲ�"���������ͳ�Ա"����������ַ��ʼ�洢.
(struct a�����struct b,b����char,int ,double��Ԫ��,��bӦ�ô�8����������ʼ�洢.)��

3).��β����:�ṹ����ܴ�С,Ҳ����sizeof�Ľ��,.
���������ڲ�����Ա��"���������ͳ�Ա"��������.
�����Ҫ����.(�������Ͳ�����struct/class/uinon)��

4).sizeof(union)���Խṹ����size���Ԫ��Ϊunion��size,
��Ϊ��ĳһʱ�̣�unionֻ��һ����Ա�����洢�ڸõ�ַ��


Ҳ�ɲμӲ��� �� https://songlee24.github.io/2014/09/20/memory-alignment/
 **/
 
#pragma pack(4) 

class A{
	char a;
	//int b;
	//char c;
	char b[5];
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
