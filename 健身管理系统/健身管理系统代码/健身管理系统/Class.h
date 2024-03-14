#pragma once //类声明
#include <iostream>
#include <string>
using namespace std;

//重载
class Printdata {
public:
	void Print(string a, string b);
	void Print(string a);
};

//继承与虚函数
class A {
public:
	virtual void show(); //虚函数
private:
	string sa;
};

class B: virtual public A { //虚基类
public:
	void show();
private:
	string sb;
};

class C :virtual public A {  //类A多继承，虚基类
public:
	C(string s1="喂你忘写参数了") { //默认参数
		s = s1;
	}
	friend void print(C c); //友元函数
private:
	string s;
};

class D :public B, public C { //棱形继承
};