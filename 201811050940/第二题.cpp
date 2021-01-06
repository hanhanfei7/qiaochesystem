#include <iostream>
using namespace std;

int fun(int* a ,int m, int n){
int p = 1, count = 0, num = m,c;
    while (num)
    {
        //未出环的人参与报数，当count是M时出环
        if (a[p] != -1 && ++count == n)
        {
            count = 0;
            a[p] = -1; //将已出环的人标记为-1
            num--;
            c = p;
        }
        p++;                 //指针指向下一个人
        p = (p - 1) % m + 1; //p范围转成[1,m]
    }
    return c;
}
int main()    
{
int m,n,kingnum;
cout<<"请输入猴子数m和报数n"<<endl;
    cin >> m >> n;
    int *a = new int[m + 1];
    fill(a, a + m + 1, 0);
    kingnum = fun(a,m,n); 
    cout<<"猴王的号数为"<<kingnum<<endl;
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
	cout<<"猴王的编号为"<<kingnum<<endl;
    return 0;
}
