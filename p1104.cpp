/*
题目描述
cjf君想调查学校OI组每个同学的生日，并按照从大到小的顺序排序。但cjf君最近作业很多，没有时间，所以请你帮她排序。

输入格式
有22行，

第11行为OI组总人数nn；

第22行至第n+1n+1行分别是每人的姓名ss、出生年yy、月mm、日dd。

输出格式
有nn行，

即nn个生日从大到小同学的姓名。(如果有两个同学生日相同,输入靠后的同学先输出)

输入输出样例
输入 
3
Yangchu 1992 4 23
Qiujingya 1993 10 13
Luowen 1991 8 1

输出 
Luowen
Yangchu
Qiujingya
说明/提示
数据规模

1<n<1001<n<100
length(s)<20length(s)<20
*/
#include<bits/stdc++.h>
using namespace std;
struct Birday
{
    string name;
    int year;
    int month;
    int day;
    int index;
};

bool cmp(Birday a,Birday b)
{
    if(a.year!=b.year)
        return a.year<b.year;
    else if(a.month!=b.month)
        return a.month<b.month;
    else if(a.day!=b.day)
        return a.day<b.day;
    else
        return a.index>b.index;
}

int main()
{
    int num;
    cin>>num;
    Birday arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i].name>>arr[i].year>>arr[i].month>>arr[i].day;
        arr[i].index=i;
    }
    sort(arr,arr+num,cmp);
    for(int i=0;i<num;i++)
        cout<<arr[i].name<<endl;
    system("pause");
}