#include<iostream>

using namespace std;

/**
 
struct/class/union内存对齐原则有四个：

1).数据成员对齐规则：结构(struct)(或联合(union))的数据成员，第一个数据成员放在
offset为0的地方，以后每个数据成员存储的起始位置要从该成员大小或者成员的子成员大小
（只要该成员有子成员，比如说是数组，结构体等）的整数倍开始
(比如int在３２位机为４字节, 则要从４的整数倍地址开始存储),
基本类型不包括struct/class/uinon。

2).结构体作为成员:如果一个结构里有某些结构体成员,
则结构体成员要从其内部"最宽基本类型成员"的整数倍地址开始存储.
(struct a里存有struct b,b里有char,int ,double等元素,那b应该从8的整数倍开始存储.)。

3).收尾工作:结构体的总大小,也就是sizeof的结果,.
必须是其内部最大成员的"最宽基本类型成员"的整数倍.
不足的要补齐.(基本类型不包括struct/class/uinon)。

4).sizeof(union)，以结构里面size最大元素为union的size,
因为在某一时刻，union只有一个成员真正存储于该地址。


也可参加博客 ： https://songlee24.github.io/2014/09/20/memory-alignment/
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
