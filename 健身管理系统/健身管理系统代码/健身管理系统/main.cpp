#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "Node.h"
#include "Class.h"
using namespace std;
int main() {
	int i, a = 1;
	while (a>0) {
		menu();
		cout << "请选择功能:";
		cin >> i;
		switch (i)
		{
		case 1:
			Inputpeople();
			break;
		case 2:
		{
			Node* p = FindIDpeople();
			if (p != NULL) {
				cout << "成功找到该人员" << endl;
				cout << "ID\t俱乐部人员\t姓名\t性别\t职务\t健身卡时间" << endl;
				cout << p->peo.id << "\t" << p->peo.people << "\t" << p->peo.name <<  "\t" << p->peo.sex
					<< "\t" << p->peo.staff << "\t" << p->peo.time << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 3: {
			Node* p = FindNAMEpeople();
			if (p != NULL) {
				cout << "成功找到该人员" << endl;
				cout << "ID\t俱乐部人员\t姓名\t性别\t职务\t健身卡时间" << endl;
				cout << p->peo.id << "\t" << p->peo.people << "\t" << p->peo.name <<  "\t" << p->peo.sex
					<< "\t" << p->peo.staff << "\t" << p->peo.time << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 4:
			Printpeople();
			break;
		case 5:
			Modifypeople();
			break;
		case 6:
			Deletepeople();
			break;
		case 7: {
			int t = Countpeople();
			cout <<"系统内人员个数"<< t << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8:
			Savepeople();
			break;
		case 9:
			Readpeople();
			break;
		default:
			cout << "退出系统！\n";
			a = -1; //跳出循环
			break;
		}
	}

	return 0;
}


void menu() {
	Printdata st;
	st.Print("健身房俱乐部", "管理系统");
	st.Print("启动！");
	A* a = new (B); //子类初始化父类
	a->show(); //虚函数使用，应用B的show()函数
	print<string>("****欢迎来到健身房俱乐部管理系统****"); //函数模板
	C c("************请选择功能列表**********");
	//C c; //默认参数
	print(c);
	cout << "*************1.添加功能*************\n";
	cout << "***********2.查询功能(ID)***********\n";
	cout << "**********3.查询功能(NAME)**********\n";
	cout << "*************4.显示功能*************\n";
	cout << "*************5.编辑功能*************\n";
	cout << "*************6.删除功能*************\n";
	cout << "*************7.统计功能*************\n";
	cout << "*************8.保存功能*************\n";
	cout << "*************9.读取功能*************\n";
	cout << "*************0.退出系统*************\n";
	return;
}

void Inputpeople() {
	char ID[25];
	cout << "请输入人员id" << endl;
	cin >> ID;
	Node* p = g_pHead;
	while (p != NULL) {
		if (strcmp(p->peo.id, ID) == 0) {
			cout << "人员已存在，取消添加";
			system("pause");
			system("cls");
			return;
		}
		p = p->pNext;
	}9++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	Node* pNewNode = (Node*)malloc(sizeof(Node)); //创建新节点
	pNewNode->pNext = NULL;
	//头插入
	if (g_pHead == NULL) { //头节点为空
		g_pHead = pNewNode;
	}
	else {
		pNewNode->pNext = g_pHead; //插入新节点
		g_pHead = pNewNode; //更新头节点
	}
	strcpy(pNewNode->peo.id, ID);
	cout << "请输入员工或会员" << endl;
	cin >> pNewNode->peo.people;
	cout << "请输入人员姓名" << endl;
	cin >> pNewNode->peo.name;
	cout << "请输入人员性别" << endl;
	cin >> pNewNode->peo.sex;
	cout << "请输入人员职务" << endl;
	cin >> pNewNode->peo.staff;
	cout << "请输入健身卡时间" << endl;
	cin >> pNewNode->peo.time;

	cout << "信息录入成功" << endl;
	system("pause");
	system("cls");
}

Node* FindIDpeople() {
	cout << "请输入查找人员id信息" << endl;
	char ID[20];
	cin >> ID;
	Node* p = g_pHead;
	while (p != NULL) {
		if (strcmp(p->peo.id ,ID) == 0) {
			return p;
		}
		p = p->pNext;
	}
	if (p == NULL) {
		cout << "找不到该人员";
	}
	system("pause");
	system("cls");
}

Node* FindNAMEpeople() {
	cout << "请输入查找人员name信息" << endl;
	char NAME[20];
	cin >> NAME;
	Node* p = g_pHead;
	while (p != NULL) {
		if (strcmp(p->peo.name, NAME) == 0) {
			return p;
		}
		p = p->pNext;
	}
	if (p == NULL) {
		cout << "找不到该人员";
	}
	system("pause");
	system("cls");
}
void Printpeople() {
	Node* p = g_pHead;
	cout << "ID\t俱乐部人员\t姓名\t性别\t职务\t健身卡时间" << endl;
	while (p != NULL) {
		//cout << "ID\t俱乐部人员\t姓名\t性别\t职务\t健身卡时间" << endl;
		cout << p->peo.id << "\t" << p->peo.people << "\t\t" << p->peo.name << "\t" << p->peo.sex
			<< "\t" << p->peo.staff << "\t" << p->peo.time<<endl;
		p = p->pNext;
	}
	system("pause");
	system("cls");
}

void Modifypeople() {
	char ID[25], ID2[25];
	cout << "请输入查找人员id信息：" << endl;
	cin >> ID;
	cout << "请输入修改后人员id信息：" << endl;
	cin >> ID2;
	Node* p = g_pHead;
	while (p != NULL) {
		if (strcmp(p->peo.id, ID2) == 0) {
			cout << "修改后id已存在，修改失败" << endl;
			system("pause");
			system("cls");
			return;
		}
		p = p->pNext;
	}
	Node* p1 = g_pHead;
	while (p1 != NULL) {
		if (strcmp(p1->peo.id ,ID) == 0) { 
			cout << "请输入修改后人员信息\t俱乐部人员\t姓名\t性别\t职务\t健身卡时间" << endl;
			strcpy(p1->peo.id, ID2);
			cin >> p1->peo.people >> p1->peo.name >> p1->peo.sex >> p1->peo.staff >> p1->peo.time ;
			cout << endl << "修改成功" << endl;
			system("pause");
			system("cls");
			return;

		}
		p1 = p1->pNext;

	}
	if (p1 == NULL) {
		cout << "没有找到该人员信息"<<endl;
		system("pause");
		system("cls");
	}
}

void Deletepeople() {
	cout << "请输入删除人员id信息" << endl;
	char ID[25];
	cin >> ID;
	Node* p1 = NULL;
	if (strcmp(g_pHead->peo.id, ID) == 0) {  //删除头节点
		p1 = g_pHead;
		g_pHead = g_pHead->pNext;
		free(p1);
		cout << "删除成功" << endl;
		system("pause");
		system("cls");
		return;
	}
	Node* p = g_pHead;
	Node* p2 = NULL;
	while (p->pNext != NULL) { //删除中间节点
		if (strcmp(p->pNext->peo.id, ID) == 0) {
			p2 = p->pNext;
			p->pNext = p2->pNext;
			free(p2);
			cout << "删除成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		p = p->pNext;
		if (p->pNext == NULL) {
			break;
		}
	}
	if (p->pNext == NULL) {
		cout << "记录为空！" << endl;
	}
	system("pause");
	system("cls");
}

int Countpeople() { 
	int cnt = 0;
	Node* p = g_pHead;
	while (p != NULL) {
		cnt++;
		p = p->pNext;
	}
	return cnt;
}

void Savepeople() {
	ofstream ofs;
	ofs.open("people.txt", ios::out || ios::binary); //二进制写入
	Node* p = g_pHead;
	while (p != NULL) {
		ofs.write((const char*)&p->peo, sizeof(person));
		p = p->pNext;
	}
	ofs.close(); //关闭文件
	cout << "保存成功"<<endl;
	system("pause");
	system("cls");
}

void Readpeople() {
	FILE* fp = fopen("people.txt", "r");
	if (fp == NULL) {
		cout << "文件打开失败";
	}
	person per;
	while (fread(&per, 1, sizeof(person), fp)) {
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->pNext = NULL;
		memcpy(pNewNode, &per, sizeof(person));
		if (g_pHead == NULL) { //头节点为空
			g_pHead = pNewNode;
		}
		else {
			pNewNode->pNext = g_pHead; //插入新节点
			g_pHead = pNewNode; //更新头节点
		}
	}
	cout << "读取成功" << endl;
	system("pause");
	system("cls");
}

void print(C c) { //作为友元函数调用类C中的
	cout << c.s << endl;
}








