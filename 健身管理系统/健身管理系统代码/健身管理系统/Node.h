#pragma once  //链表与函数声明
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

typedef struct _person {
	char id[25]; //id
	char people[25]; //俱乐部人员
	char name[25];	//姓名
	char sex[25]; //性别
	char staff[25];//职务
	char time[25]; //健身卡时间（员工为零，会员为月.年卡）
}person;

typedef struct _Node {
	person peo;   //数据域
	struct _Node* pNext;  //指针域
}Node;

Node * g_pHead = NULL; //头结点

void menu(); //菜单
void Inputpeople(); //输入功能
Node* FindIDpeople(); //查找功能(ID)
Node* FindNAMEpeople();//查找功能(NAME)
void Printpeople(); //显示功能
void Modifypeople(); //编辑功能
void Deletepeople(); //删除功能
int Countpeople();   //统计功能
void Savepeople();   //保存功能
void Readpeople();   //读取功能
void Print(string a, string b);//函数重载
void Print(string a);

template<class T>//函数模板
void print(T x) {
	cout << x << endl;
}