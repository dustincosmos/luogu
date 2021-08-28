/*
题目描述
给定 nn 个数，要求把其中重复的去掉，只保留第一次出现的数。

输入格式
本题有多组数据。

第一行一个整数 TT，表示数据组数。

对于每组数据：

第一行一个整数 nn。

第二行 nn 个数，表示给定的数。

输出格式
对于每组数据，输出一行，为去重后剩下的数，两个数之间用一个空格隔开。

输入输出样例
输入 #1复制
2
11
1 2 18 3 3 19 2 3 6 5 4
6
1 2 3 4 5 6
输出 #1复制
1 2 18 3 19 6 5 4
1 2 3 4 5 6
说明/提示
对于 30\%30% 的数据，n \le 100n≤100，给出的数 \in [0, 100]∈[0,100]。

对于 60\%60% 的数据，n \le 10^4n≤10 
4
 ，给出的数 \in [0, 10^4]∈[0,10 
4
 ]。

对于 100\%100% 的数据，1 \le T\le 501≤T≤50，1 \le n \le 5 \times 10^41≤n≤5×10 
4
 ，给出的数在 3232 位有符号整数范围内。
 */
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,bool>mymap;
int read()
{
    int f=0,s=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')
            s*=-1;
        ch=getchar();
    }
    while(ch<='9'&&ch>='0')
    {
        f=f*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}
int main()
{
    int t;
    int n,x;
    cin>>t;
    while(t--)
    {
        mymap.clear();
        n=read();
        for(int i=1;i<=n;i++)
        {
            x=read();
            if(!mymap[x])
            {
                mymap[x]=true;
                cout<<x<<" ";
            }
            
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
vector<int> Hash[100007];
int pos=0;
int t,n,num;
#define mod 100007

inline int read()
{
    int s=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0')
    {
        if(c=='-')
            f=-f;
        c=getchar();
    }
    while(c<='9'&&c>='0')
    {
        s=s*10+c-'0';
        c=getchar();
    }
    return s*f;
}


bool check(int v)
{
    int p=(v%mod+mod)%mod;
    pos=max(p,pos);
    for(int i=0;i<Hash[p].size();i++)
    {
        if(Hash[p][i]==v)
            return true;
    }
    Hash[p].push_back(v);
    return false;
}

int main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=0;i<=pos;i++)
            Hash[i].clear();
        pos=0;
        for(int i=1;i<=n;i++)
        {
            num=read();
            if(!check(num))
                cout<<num<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}

*/