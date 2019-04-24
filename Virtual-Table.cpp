#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
/*
在C++的标准规格说明书中说到：
编译器必需要保证虚函数表的指针存在于对象实例中最前面的位置，
这是为了保证正确取到虚函数的偏移量。
对于A0类型，其对象实例的第一个字节用于存放一个vptr，指向一张虚函数表，表中有一个虚函数
 A0
vptr --> |A0::Dump() |
 */
class A0
{
public:
	A0(){}
	virtual void Dump(){cout << "Dump A0" << endl;}
};

////////////////////////////////////////////////////////////////
/*
对于A1类型，其对象实例的第一个字节用于存放一个vptr，指向一张虚函数表，表中有一个虚函数
 A1
vptr --> |A1::Dump() |
 */
class A1
{
public:
	A1(){}
	virtual void Dump(){cout << "Dump A1" << endl;}
};

////////////////////////////////////////////////////////////////
/*
对于B0类型，其对象实例的前两个字节均为一个vptr，指向不同的虚函数表
表的顺序，取决于继承的基类顺序
表中虚函数的顺序，取决于基类中虚函数的声明顺序
若派生类中声明了新的虚函数，则加到第一张表的里面
 B0
vptr --> |A0::Dump() |B0::DumpX() |B0::DumpY() |
vptr --> |A1::Dump() |
 */
class B0 : public A0, public A1
{
public:
	B0(){}
	virtual void DumpX(){cout << "Dump X" << endl;}
	virtual void DumpY(){cout << "Dump Y" << endl;}
};

////////////////////////////////////////////////////////////////
/*
若派生类中声明的新的虚函数，重载了基类的虚函数，
基类表中的虚函数会被替换为当前派生类的虚函数
 B1
vptr --> |B1::Dump() |B0::DumpX() |B0::DumpY() |
vptr --> |B1::Dump() |
 */
class B1 : public A0, public A1
{
public:
	B1(){}
	virtual void Dump(){cout << "Dump B1" << endl;}
	virtual void DumpX(){cout << "Dump X" << endl;}
	virtual void DumpY(){cout << "Dump Y" << endl;}
};

////////////////////////////////////////////////////////////////
typedef void(*Func)(void);

template<class T>
Func GetVirtualFuncOfObject(T& t, unsigned short nVPtrIdx, unsigned short nFuncIdx)
{
	/*
	 通过强行把 &t 转成int，取得虚函数表的地址，再次取址就可以得到第一个虚函数的地址
	 */
	//cout << "虚函数表地址：" << (int*)(&t) <<endl;
	//cout << "第一张虚函数表中，第一个函数地址：" << ((int*)*((int*)(&t)+0)+0) <<endl;
	//cout << "第二张虚函数表中，第一个函数地址：" << ((int*)*((int*)(&t)+1)+0) <<endl;
	return (Func)*( (int*)  *( (int*)(&t)+nVPtrIdx )  + nFuncIdx );
}

template<class T>
void DisplayObjectFunc(T& t)
{
	Func func00 = GetVirtualFuncOfObject<T>(t, 0, 0); func00();
	Func func01 = GetVirtualFuncOfObject<T>(t, 0, 1); func01();
	Func func02 = GetVirtualFuncOfObject<T>(t, 0, 2); func02();
	Func func10 = GetVirtualFuncOfObject<T>(t, 1, 0); func10();
}

int main(int argc, char const* argv[])
{
	B0 b0;
	DisplayObjectFunc<B0>(b0);
	cout << "---------------" << endl;

	B1 b1;
	DisplayObjectFunc<B1>(b1);
	cout << "---------------" << endl;

	return 0;
}
