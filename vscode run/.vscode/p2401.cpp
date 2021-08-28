/*
题目描述
将 11 到 nn 任意排列，然后在排列的每两个数之间根据他们的大小关系插入> 和 <。问在所有排列中，有多少个排列恰好有 kk 个 <。答案对 20152015 取模。

注：1 \sim n1∼n 的排列指的是 1 \sim n1∼n 这 nn 个数各出现且仅出现一次的数列。

输入格式
一行两个整数，表示 nn 和 kk。

输出格式
一个整数表示答案。

输入输出样例
输入 #1复制
5 2
输出 #1复制
66
说明/提示
对于 30\%30% 的数据，n\leq 10n≤10；

对于 100\%100% 的数据，0\leq k<n\leq 10000≤k<n≤1000。
*/
#include<bits/stdc++.h>
using namespace std;
long long f[1001][1001];
int main()
{
    int n,k;
    cin>>n>>k;
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
        f[i][0]=f[i][i-1]=1;
    //f[2][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            f[i][j]=(j+1)*f[i-1][j];
            if(i>j)
                f[i][j]+=f[i-1][j-1]*(i-j);
            f[i][j]%=2015;
        }
    }
    cout<<f[n][k];
    system("pause");
    return 0;
}