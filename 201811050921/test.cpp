#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <winsock.h>
#include <mysql.h>

#pragma comment(lib,"libmysql.lib")

using namespace std;
void FreeConnect();
void createcarinfor();
void deletecarinfor();
void altercarinfor();
void selectcarinfor();

MYSQL mysql, * sock;//定义数据库的连接句柄
MYSQL_RES* res;//查询结果集，结构类型
MYSQL_FIELD* fd;//包含字段信息的结构
MYSQL_ROW row;//存放一行查询结果的字符串数组
char qbuf[256];//存放查询sql语句字符串

void FreeConnect()

{
	//释放资源

	mysql_free_result(res);
	mysql_close(&mysql);

}
void createcarinfor()//添加新的轿车信息
{
	cout << "请输入汽车的库存信息包括编号、型号、颜色、生产厂家、生产日期、价格（每次enter结束）" << endl;
	int number; char type[20]; char color[20]; char manufacturer[20]; int produced; int price;//定义变量
	cin >> number >> type >> color >> manufacturer >> produced >> price;
	sprintf_s(qbuf, "insert into carinfor values (%d,'%s','%s','%s',%d,%d);", number, type, color, manufacturer, produced, price);
	mysql_query(&mysql, qbuf);
	cout << endl;
	cout << endl;
	cout << "编号 型号 颜色 生产厂家 生产日期 价格" << endl;
	mysql_query(&mysql, "select * from carinfor");//储存结果集
	res = mysql_store_result(&mysql);
	int n; 
	n = mysql_num_fields(res);//将表的行数幅值给n用于循环显示
	while (row = mysql_fetch_row(res))
	{
		for (int i = 0; i < n; i++)
		{
			printf("%s", row[i]);
			cout << "\t";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	FreeConnect();
}
void deletecarinfor()//删除轿车信息
{
	cout << "请输入删除轿车信息的编号:" << endl;
	int a;
	cin >> a;
	sprintf_s(qbuf, "delete from carinfor where number=%d;", a);
	mysql_query(&mysql, qbuf);
	cout << endl;
	cout << endl;
	cout << "删除完数据后的轿车信息" << endl;
	cout << "编号 型号 颜色 生产厂家 生产日期 价格" << endl;
	mysql_query(&mysql, "select*from carinfor");//储存结果集
	res = mysql_store_result(&mysql);
	int n; n = mysql_field_count(&mysql);//获取字段数
	while (row = mysql_fetch_row(res))
	{
		for (int i = 0; i < n; i++)
			printf("%s\t", row[i]);
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
void altercarinfor()//修改轿车信息
{

	cout << "请输入要修改的轿车信息的编号:" << endl;
	int a;
	cin >> a;
	cout << "请输入要修改的字段名及要修改的数据" << endl;
	char a1[20]; char b1[20];
	cin >> a1 >> b1;
	sprintf_s(qbuf, "update carinfor set %s='%s' where number=%d;", a1, b1, a);
	mysql_query(&mysql, qbuf);
	cout << endl;
	cout << endl;
	cout << "修改完数据后的轿车信息" << endl;
	cout << "编号 型号 颜色 生产厂家 生产日期 价格" << endl;
	mysql_query(&mysql, "select*from carinfor");//储存结果集
	res = mysql_store_result(&mysql);
	int n; n = mysql_field_count(&mysql);//获得字段数
	while (row = mysql_fetch_row(res))
	{
		for (int i = 0; i < n; i++)
			printf("%s\t", row[i]);
		cout << endl;
	}
	cout << endl;
	cout << endl;
	FreeConnect();
}

void selectcarinfor()//查询轿车信息
{
	cout << "请输入要查询的字段名及要查询的数据" << endl;
	char a1[20]; char b1[20];
	cin >> a1 >> b1;
	sprintf_s(qbuf, "select * from carinfor where %s='%s';", a1, b1);
	mysql_query(&mysql, qbuf);
	cout << endl;
	cout << endl;
	cout << "查询完数据后的轿车信息" << endl;
	cout << "编号 型号 颜色 生产厂家 生产日期 价格" << endl;
	mysql_query(&mysql, "select*from carinfor");//储存结果集
	res = mysql_store_result(&mysql);
	int n; n = mysql_field_count(&mysql);//获得字段数
	while (row = mysql_fetch_row(res))
	{
		for (int i = 0; i < n; i++)
			printf("%s\t", row[i]);
		cout << endl;
	}
	cout << endl;
	cout << endl;

}


int main()
{
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql, "localhost", "root", "forever", "carsystem", 3306, NULL, 0)))
	{
		fprintf(stderr, "Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
	//sprintf_s(qbuf, "create database carmanagesystem;");
	//mysql_query(&mysql, qbuf);
	sprintf_s(qbuf, "use carsystem");
	mysql_query(&mysql, qbuf);
	sprintf_s(qbuf, "create table carinfor(number int,type varchar(20),color varchar(20),manufacturer varchar(20),produced int,price int);");
	mysql_query(&mysql, qbuf);
	int b = 5;
	while (b)
	{
		cout << "新年快乐！" << endl;
		cout << "欢迎进入轿车信息管理系统" << endl;
		cout << "请输入进行的操作(按enter键结束)：0.不做操作1.增添轿车信息  2.删除信息  3.查找信息  4.修改信息" << endl;
		cin >> b;
		if (b == 1)
			createcarinfor();
		else if (b == 2)
			deletecarinfor();
		else if (b == 3)
			selectcarinfor();
		else if (b == 4)
			altercarinfor();
		else if (b == 0)
			break;
	}
	return 0;
}