/*
题目描述
出题是一件痛苦的事情！

相同的题目看多了也会有审美疲劳，于是我舍弃了大家所熟悉的 A+B Problem，改用 A-B 了哈哈！

好吧，题目是这样的：给出一串数以及一个数字 CC，要求计算出所有 A - B = CA−B=C 的数对的个数（不同位置的数字一样的数对算不同的数对）。

输入格式
输入共两行。

第一行，两个整数 N, CN,C。

第二行，NN 个整数，作为要求处理的那串数。

输出格式
一行，表示该串数中包含的满足 A - B = CA−B=C 的数对的个数。

输入输出样例
输入 #1复制
4 1
1 1 2 3
输出 #1复制
3
说明/提示
对于 75\%75% 的数据，1 \leq N \leq 20001≤N≤2000。

对于 100\%100% 的数据，1 \leq N \leq 2 \times 10^51≤N≤2×10 
5
 。

保证所有输入数据绝对值小于 2^{30}2 
30
 。

2017/4/29 新添数据两组
*/
#include<bits/stdc++.h>
using namespace std;
int f[200001];
unordered_map<int,int>mymap;
int main()
{
    int n,c,ans=0;
    cin>>n>>c;
    int t=n;
    int i;
    while(n--)
    {
        cin>>i;
        mymap[i]++;
        f[n]=i+c;
    }
    while(t--)
    {
        if(mymap[f[t]])
            ans+=mymap[f[t]];
    }
    cout<<ans;
    system("pause");
    return 0;
}










/*
#include<bits/stdc++.h>
using namespace std;
int arr[201000];
bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int num,c;
    int r1,r2,p1,p2;
    r1=r2=p1=p2=1;
    long long count=0;
    cin>>num>>c;
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    if(c>0)
        sort(arr,arr+num,cmp);
    else
        sort(arr,arr+num);
    for(int i=0;i<num;i++)
    {
        if(c>0)
        {
            while(arr[i]-arr[r1]<c&&r1<num)
                r1++;
            while(arr[i]-arr[r2]<=c&&r2<num)
                r2++;
            if(arr[i]-arr[r1]==c)
                count+=r2-r1;
        }
        else
        {
            while(arr[i]-arr[p1]>c&&p1<num)
                p1++;
            while(arr[i]-arr[p2]>=c&&p2<num)
                p2++;
            if(arr[i]-arr[p1]==c)
                count+=p2-p1;
        }
    }
    cout<<count;
    system("pause");
}
*/