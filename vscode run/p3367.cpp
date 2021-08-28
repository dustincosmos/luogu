/*
题目描述
如题，现在有一个并查集，你需要完成合并和查询操作。

输入格式
第一行包含两个整数 N,MN,M ,表示共有 NN 个元素和 MM 个操作。

接下来 MM 行，每行包含三个整数 Z_i,X_i,Y_iZ 
i
​
 ,X 
i
​
 ,Y 
i
​
  。

当 Z_i=1Z 
i
​
 =1 时，将 X_iX 
i
​
  与 Y_iY 
i
​
  所在的集合合并。

当 Z_i=2Z 
i
​
 =2 时，输出 X_iX 
i
​
  与 Y_iY 
i
​
  是否在同一集合内，是的输出 Y ；否则输出 N 。

输出格式
对于每一个 Z_i=2Z 
i
​
 =2 的操作，都有一行输出，每行包含一个大写字母，为 Y 或者 N 。

输入输出样例
输入 #1复制
4 7
2 1 2
1 1 2
2 1 2
1 3 4
2 1 4
1 2 3
2 1 4
输出 #1复制
N
Y
N
Y
说明/提示
对于 30\%30% 的数据，N \le 10N≤10，M \le 20M≤20。

对于 70\%70% 的数据，N \le 100N≤100，M \le 10^3M≤10 
3
 。

对于 100\%100% 的数据，1\le N \le 10^41≤N≤10 
4
 ，1\le M \le 2\times 10^51≤M≤2×10 
5
 ，1 \le X_i, Y_i \le N1≤X 
i
​
 ,Y 
i
​
 ≤N，Z_i \in \{ 1, 2 \}Z 
i
​
 ∈{1,2}。
*/
#include<bits/stdc++.h>
using namespace std;
int arr[11000];
vector<char> brr;

int find(int x)
{   
    if(arr[x]<=0)
        return x;
    else
        return arr[x]=find(arr[x]);
}
void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
        return ;
    if(arr[a]>arr[b])
    {
        arr[b]+=arr[a];
        arr[a]=b;
    }
    else
    {
        arr[a]+=arr[b];
        arr[b]=a;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        arr[i]=-1;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>c>>a>>b;
        if(c==2)
        {
            if(find(a)==find(b))
                brr.push_back('Y');
            else 
                brr.push_back('N');
        }
        else if(c==1)
            Union(a,b);
    }
    int len=brr.size();
    for(int i=0;i<len;i++)
        cout<<brr[i]<<endl;
    system("pause");
    return 0;
}