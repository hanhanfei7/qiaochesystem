#include <iostream>
using namespace std;

int fun(int* a ,int m, int n){
int p = 1, count = 0, num = m,c;
    while (num)
    {
        //δ�������˲��뱨������count��Mʱ����
        if (a[p] != -1 && ++count == n)
        {
            count = 0;
            a[p] = -1; //���ѳ������˱��Ϊ-1
            num--;
            c = p;
        }
        p++;                 //ָ��ָ����һ����
        p = (p - 1) % m + 1; //p��Χת��[1,m]
    }
    return c;
}
int main()    
{
int m,n,kingnum;
cout<<"�����������m�ͱ���n"<<endl;
    cin >> m >> n;
    int *a = new int[m + 1];
    fill(a, a + m + 1, 0);
    kingnum = fun(a,m,n); 
    cout<<"�����ĺ���Ϊ"<<kingnum<<endl;
    return 0;
}
#include <iostream>
using namespace std;

struct Node
{
    int n;
    Node *next;
};
int fun(int N,int K,int M){
	int c;
    Node *head, *node, *p;
    head = new Node;
    head->next = NULL;
    p = head;
    int num = N, count = 0;
    for (size_t i = 0; i < N; i++)
    {
        node = new Node;
        node->n = K;
        p->next = node;
        p = node;
        K++;
        K = (K - 1) % N + 1;
    }
    p->next = head->next;
    delete head;
    while (num)
    {
        if (++count == M)
        {
            count = 0;
            Node *t = p->next->next;
            c=p->next->n ;
            delete p->next;
            p->next = t;
            num--;
        }
        else
            p = p->next;
    }
    return c;
}
int main()
{
    int N,K,M,kingnum;
    cin >> N >> K >> M;
    kingnum = fun(N,K,M);
	cout<<"�����ı��Ϊ"<<kingnum<<endl;
    return 0;
}
