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

MYSQL mysql, * sock;//�������ݿ�����Ӿ��
MYSQL_RES* res;//��ѯ��������ṹ����
MYSQL_FIELD* fd;//�����ֶ���Ϣ�Ľṹ
MYSQL_ROW row;//���һ�в�ѯ������ַ�������
char qbuf[256];//��Ų�ѯsql����ַ���

void FreeConnect()

{
	//�ͷ���Դ

	mysql_free_result(res);
	mysql_close(&mysql);

}
void createcarinfor()//����µĽγ���Ϣ
{
	cout << "�����������Ŀ����Ϣ������š��ͺš���ɫ���������ҡ��������ڡ��۸�ÿ��enter������" << endl;
	int number; char type[20]; char color[20]; char manufacturer[20]; int produced; int price;//�������
	cin >> number >> type >> color >> manufacturer >> produced >> price;
	sprintf_s(qbuf, "insert into carinfor values (%d,'%s','%s','%s',%d,%d);", number, type, color, manufacturer, produced, price);
	mysql_query(&mysql, qbuf);
	cout << endl;
	cout << endl;
	cout << "��� �ͺ� ��ɫ �������� �������� �۸�" << endl;
	mysql_query(&mysql, "select * from carinfor");//��������
	res = mysql_store_result(&mysql);
	int n; 
	n = mysql_num_fields(res);//�����������ֵ��n����ѭ����ʾ
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
void deletecarinfor()//ɾ���γ���Ϣ
{
	cout << "������ɾ���γ���Ϣ�ı��:" << endl;
	int a;
	cin >> a;
	sprintf_s(qbuf, "delete from carinfor where number=%d;", a);
	mysql_query(&mysql, qbuf);
	cout << endl;
	cout << endl;
	cout << "ɾ�������ݺ�Ľγ���Ϣ" << endl;
	cout << "��� �ͺ� ��ɫ �������� �������� �۸�" << endl;
	mysql_query(&mysql, "select*from carinfor");//��������
	res = mysql_store_result(&mysql);
	int n; n = mysql_field_count(&mysql);//��ȡ�ֶ���
	while (row = mysql_fetch_row(res))
	{
		for (int i = 0; i < n; i++)
			printf("%s\t", row[i]);
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
void altercarinfor()//�޸Ľγ���Ϣ
{

	cout << "������Ҫ�޸ĵĽγ���Ϣ�ı��:" << endl;
	int a;
	cin >> a;
	cout << "������Ҫ�޸ĵ��ֶ�����Ҫ�޸ĵ�����" << endl;
	char a1[20]; char b1[20];
	cin >> a1 >> b1;
	sprintf_s(qbuf, "update carinfor set %s='%s' where number=%d;", a1, b1, a);
	mysql_query(&mysql, qbuf);
	cout << endl;
	cout << endl;
	cout << "�޸������ݺ�Ľγ���Ϣ" << endl;
	cout << "��� �ͺ� ��ɫ �������� �������� �۸�" << endl;
	mysql_query(&mysql, "select*from carinfor");//��������
	res = mysql_store_result(&mysql);
	int n; n = mysql_field_count(&mysql);//����ֶ���
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

void selectcarinfor()//��ѯ�γ���Ϣ
{
	cout << "������Ҫ��ѯ���ֶ�����Ҫ��ѯ������" << endl;
	char a1[20]; char b1[20];
	cin >> a1 >> b1;
	sprintf_s(qbuf, "select * from carinfor where %s='%s';", a1, b1);
	mysql_query(&mysql, qbuf);
	cout << endl;
	cout << endl;
	cout << "��ѯ�����ݺ�Ľγ���Ϣ" << endl;
	cout << "��� �ͺ� ��ɫ �������� �������� �۸�" << endl;
	mysql_query(&mysql, "select*from carinfor");//��������
	res = mysql_store_result(&mysql);
	int n; n = mysql_field_count(&mysql);//����ֶ���
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
		cout << "������֣�" << endl;
		cout << "��ӭ����γ���Ϣ����ϵͳ" << endl;
		cout << "��������еĲ���(��enter������)��0.��������1.����γ���Ϣ  2.ɾ����Ϣ  3.������Ϣ  4.�޸���Ϣ" << endl;
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