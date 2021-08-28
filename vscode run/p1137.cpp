/*
题目描述
小明要去一个国家旅游。这个国家有#NN个城市，编号为11至NN，并且有MM条道路连接着，小明准备从其中一个城市出发，并只往东走到城市i停止。

所以他就需要选择最先到达的城市，并制定一条路线以城市i为终点，使得线路上除了第一个城市，每个城市都在路线前一个城市东面，并且满足这个前提下还希望游览的城市尽量多。

现在，你只知道每一条道路所连接的两个城市的相对位置关系，但并不知道所有城市具体的位置。现在对于所有的i，都需要你为小明制定一条路线，并求出以城市ii为终点最多能够游览多少个城市。

输入格式
第11行为两个正整数N, MN,M。

接下来MM行，每行两个正整数x, yx,y，表示了有一条连接城市xx与城市yy的道路，保证了城市xx在城市yy西面。

输出格式
NN行，第ii行包含一个正整数，表示以第ii个城市为终点最多能游览多少个城市。

输入输出样例
输入 #1复制
5 6
1 2
1 3
2 3
2 4
3 4
2 5
输出 #1复制
1
2
3
4
3
说明/提示
均选择从城市1出发可以得到以上答案。

对于20\%20%的数据，N ≤ 100N≤100；

对于60\%60%的数据，N ≤ 1000N≤1000；

对于100\%100%的数据，N ≤ 100000,M ≤ 200000N≤100000,M≤200000。
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    int indegree;
    node* next;
}f[200001];
int n,m,ans[200001];
queue<int>myq;
int main()
{
    int u,v;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        node *p=new node;
        p->data=v;
        p->next=f[u].next;
        f[u].next=p;
        f[v].indegree++;
    }
    for(int i=1;i<=n;i++)
    {
        f[i].data=i;
        if(f[i].indegree==0)
        {
            ans[i]=1;
            myq.push(i);
        }
    }
    while(!myq.empty())
    {
        int t=myq.front();
        myq.pop();
        node *p=&f[t];
        while(p->next!=NULL)
        {
            ans[p->next->data]=max(ans[p->next->data],ans[f[t].data]+1);
            p=p->next;
            f[p->data].indegree--;
            if(f[p->data].indegree==0)
            {
                myq.push(p->data);
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<endl;
    system("pause");
    return 0;
}











/*
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int ad;
    node* next;
    int indegree;
    int count;
}adj[101000];
int inde[101000]={0};
void Creat(int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        adj[i].ad=i;
        adj[i].next=NULL;
        adj[i].count=0;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        node* p=new node;
        p->ad=x;
        p->next=adj[y].next;
        adj[y].next=p;
        adj[y].count++;
    }
}

int getmax(node adj[],int i)
{
    int t=1;
    node* p=new node;
    p=&adj[i];
    p=p->next;
    while(p!=NULL)
    {
        if(inde[p->ad]>t)
            t=inde[p->ad];
        p=p->next;
    }
    return t;
}

int gettime(int n)
{
    node* p=new node;
    p=&adj[n];
    if(p->count==0)
    {
        inde[p->ad]=1;
        return 1;
    }
    else
    {
        if(inde[p->ad]!=0)
            return inde[p->ad];
        inde[p->ad]+=1;
        p=p->next;
        while(p!=NULL)
        {
            int t=gettime(p->ad);
            inde[p->ad]=t;
            p=p->next;
        }
        inde[adj[n].ad]+=getmax(adj,n);
        return inde[adj[n].ad];
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    Creat(n,m);
    for(int i=1;i<=n;i++)
    {
        cout<<gettime(i)<<endl;;
    }
    system("pause");
}
*/