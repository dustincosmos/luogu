/*
题目背景
话说校长最近很喜欢召开全校教职工大会，让老师们强行听他装逼

题目描述
现在校长在校园网上公布了一份座位表，nn 位老师从左到右依次排成一行。老师们都对这个座位很满意。

然而到了开会时，校长不小心把座位表打乱了，老师们很不满。老师们并不在意自己的位置变了多少，但如果有一对老师 aa 和 bb，他们原来的座位是 aa 在 bb 左边，现在变成了 aa 在 bb 右边，那么这一对老师便会贡献一单位不满值。

校长想知道这些老师的总不满值是多少。

输入格式
第一行一个正整数 nn，为 nn 位老师。

第二行有 nn 个字符串，每个字符串代表老师的名字（大小写敏感）。这一行代表原来的座位表。

第三行有 nn 个字符串，代表打乱后的座位表。

输出格式
一行，一个正整数，表示老师们的总不满值。

输入输出样例
输入 #1复制
3
Stan Kyle Kenny
Kyle Stan Kenny
输出 #1复制
1
输入 #2复制
5
A B C D E
B A D E C
输出 #2复制
3
说明/提示
对于 30\%30% 的数据，1\le n \le 10^31≤n≤10 
3
 。

对于 100\%100% 的数据，1\le n \le 10^51≤n≤10 
5
 ，每位老师名字长度不超过 55，只有大小写字母并且互不相同。注意名字对大小写敏感。
 */
#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
int ans=0;
void merge_sort(int s,int e,int a[],int b[])
{
    if(s>=e)
        return ;
    if(e-s==1)
    {
        if(a[s]>a[e])
        {
            int tem=a[s];
            a[s]=a[e];
            a[e]=tem;
            ans+=1;
            return ;
        }
        else 
            return ;
    }
    int mid=(e-s)/2+s;
    merge_sort(s,mid,a,b);
    merge_sort(mid+1,e,a,b);
    int l=s,m=mid+1,p=s;
    while(l<=mid&&m<=e)
    {
        if(a[l]>a[m])
        {
            b[p++]=a[m++];
            ans+=mid-l+1;
        }
        else
        {
            b[p++]=a[l++];
        }
    }
    while(l<=mid)
        b[p++]=a[l++];
    while(m<=e)
        b[p++]=a[m++];
    for(int i=s;i<=e;i++)
        a[i]=b[i];
}
int main()
{
    string str;
    map<string,int>mymap;
    int num;
    cin>>num;
    for(int i=1;i<=num;i++)
    {
        cin>>str;
        mymap[str]=i;
    }
    for(int i=0;i<num;i++)
    {
        cin>>str;
        a[i]=mymap[str];
    }
    merge_sort(0,num-1,a,b);
    cout<<ans;
    system("pause");
    return 0;
}
