/*
题目背景
Czyzoiers 都想知道小 x 为什么对鸡蛋饼情有独钟。经过一番逼问，小 x 道出了实情：因为他喜欢圆。

题目描述
最近小 x 又发现了一个关于圆的有趣的问题：在圆上有 2N2N 个不同的点，小 x 想用 N 条线段把这些点连接起来（每个点只能连一条线段）， 使所有的线段都不相交，他想知道这样的连接方案有多少种？

输入格式
有且仅有一个正整数 N 。 （N \le 2999N≤2999）

输出格式
要求的方案数（结果 \bmod 100000007mod100000007）。

输入输出样例
输入 #1复制
24
输出 #1复制
4057031
*/
#include<bits/stdc++.h>
using namespace std;
long long f[3000];
int main()
{
    int n;
    cin>>n;
    memset(f,0,sizeof(f));
    f[0]=f[1]=1,f[2]=2;
    for(int i=1;i<=n;i++)
    {
        if(f[i]!=0)
            continue;
        for(int j=0;j<i;j++)
        {
            f[i]+=f[j]*f[i-j-1];
            f[i]%=100000007;
        }
    }
    cout<<f[n];//%100000007;
    system("pause");
    return 0; 
}