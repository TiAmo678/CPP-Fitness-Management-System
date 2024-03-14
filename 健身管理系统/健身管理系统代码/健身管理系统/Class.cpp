#include <iostream>
#include "Class.h"
#include <string>
using namespace std;

void Printdata::Print(string a, string b) { //重载
	cout << a + b << endl;
}
void Printdata::Print(string a) { //默认参数
	cout << a << endl;
}

void A::show() {
	cout << "运行" << endl;
}
void B::show() {
	cout << "开始运行" << endl;
}


