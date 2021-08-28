/*
题目背景
2018 年 7 月 19 日，某位同学在 NOI Day 1 T1 归程 一题里非常熟练地使用了一个广为人知的算法求最短路。

然后呢？

100 \rightarrow 60100→60；

\text{Ag} \rightarrow \text{Cu}Ag→Cu；

最终，他因此没能与理想的大学达成契约。

小 F 衷心祝愿大家不再重蹈覆辙。

题目描述
给定一个 nn 个点，mm 条有向边的带非负权图，请你计算从 ss 出发，到每个点的距离。

数据保证你能从 ss 出发到任意点。

输入格式
第一行为三个正整数 n, m, sn,m,s。 第二行起 mm 行，每行三个非负整数 u_i, v_i, w_iu 
i
​
 ,v 
i
​
 ,w 
i
​
 ，表示从 u_iu 
i
​
  到 v_iv 
i
​
  有一条权值为 w_iw 
i
​
  的有向边。

输出格式
输出一行 nn 个空格分隔的非负整数，表示 ss 到每个点的距离。

输入输出样例
输入 #1复制
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
输出 #1复制
0 2 4 3
说明/提示
样例解释请参考 数据随机的模板题。

1 \leq n \leq 10^51≤n≤10 
5
 ；

1 \leq m \leq 2\times 10^51≤m≤2×10 
5
 ；

s = 1s=1；

1 \leq u_i, v_i\leq n1≤u 
i
​
 ,v 
i
​
 ≤n；

0 \leq w_i \leq 10 ^ 90≤w 
i
​
 ≤10 
9
 ,

0 \leq \sum w_i \leq 10 ^ 90≤∑w 
i
​
 ≤10 
9
 。

本题数据可能会持续更新，但不会重测，望周知。

2018.09.04 数据更新 from @zzq
*/
#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int f,t,n;
}e[200001];
bool vis[100001];
int f[100001],dist[100001];
int cnt=0;
struct node
{
    int pos,dis;
    bool operator <(const node& x) const
    {
        return x.dis<dis;
    }
};
priority_queue<node>mynode;

void addedge(int u,int v,int d)
{
    cnt++;
    e[cnt].t=v;
    e[cnt].f=d;
    e[cnt].n=f[u];
    f[u]=cnt;
}

void dijkstra()
{
    while(!mynode.empty())
    {
        node tem=mynode.top();
        mynode.pop();
        int x=tem.pos,y=tem.dis;
        if(vis[x])
            continue;
        for(int i=f[x];i;i=e[i].n)
        {
            int t=e[i].t;
            if(dist[t]>dist[x]+e[i].f)
            {
                dist[t]=dist[x]+e[i].f;
            }
            if(!vis[t])
                mynode.push({t,dist[t]});
        }
        vis[x]=true;
    }
}

int n,m,s;
int u,v,d;
int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>d;
        addedge(u,v,d);
    }
    memset(dist,63,sizeof(dist));
    dist[s]=0;
    mynode.push({1,0});
    dijkstra();
    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
    system("pause");
    return 0;
}