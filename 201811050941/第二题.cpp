#include<iostream>
using namespace std;

int MonkyKing(int a[], int m,int n)
{
	int i, j, k = -1;
	for (int i = 0; i < m; i++)
	{
		a[i] = 1;//��ʼ��������m��
	}
	
	for (i = 1; i<= m; i++)//��ʼ��Ȧѭ��
	{
		j = 1;//������J������
		while (j <=n)
		{
			k = (k + 1) % m;//�����к����н���ѭ��
			if (a[k] == 1)//�ҵ�����Ȧ�еĺ���
			{
				j++;
			}
		}
		a[k] = 0;//������Ȧ
		
	}
	return k+1;//����֮�������
}
typedef struct node {
	int data;
	struct node* next;

}monkey;
int Monky(int m, int n)
{
	monkey* head, * p, * s, * q;
	int i, total;
	head = new monkey;
	p = head;
	p->data = 1;
	p->next = p;
	for (int i = 2; i <= m; i++)
	{
		s = new monkey;
		s->data = i;
		s->next = p->next;
		p->next = s;
		p = p->next;

	}
	p = head;
	q = head;
	total = m;
	while (total != 1)
	{
		for (i = 1; i < n; i++)
		{
			p = p->next;
		}
		while (q->next != p)
		{
			q = q->next;	
		}
		q->next = p->next;
		s = p;
		p = p->next;
		delete(s);
		total--;
	}
	int king = p->data;
	return king;

}
int main()
{
	int m, n, a[100];//���Ӹ������100
	cin >> m >> n;
	int king,king1;
	king = MonkyKing(a,m,n);
	cout << "����֮����" << king << endl;
	king1 = Monky(m, n);
	cout << "����֮����" << king1<< endl;

}