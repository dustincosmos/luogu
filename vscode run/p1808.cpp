/*
题目描述
Oliver为了学好英语决定苦背单词，但很快他发现要直接记住杂乱无章的单词非常困难，他决定对单词进行分类。

两个单词可以分为一类当且仅当组成这两个单词的各个字母的数量均相等。

例如“AABAC”，它和“CBAAA”就可以归为一类，而和“AAABB”就不是一类。

现在Oliver有N个单词，所有单词均由大写字母组成，每个单词的长度不超过100。你要告诉Oliver这些单词会被分成几类。

输入格式
输入文件的第一行为单词个数N，以下N行每行为一个单词。

输出格式
输出文件仅包含一个数，表示这N个单词分成的类数

输入输出样例
输入 #1复制
3 
AABAC 
CBAAA 
AAABB
输出 #1复制
2
说明/提示
对于70%的数据满足N≤100。 对于100%的数据满足N≤10000。
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int sum;
    int len;
    int s[102];
}f[10001];
int ans=1;
bool cmp(node A,node B)
{
    if(A.sum!=B.sum)
        return A.sum>B.sum;
    else
    {
        int c=1;
        while(A.s[c]==B.s[c])
            c++;
        return A.s[c]<B.s[c];
    }
}
char s[101];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=1;j<=strlen(s);j++)
        {
            f[i].s[j]=s[j-1];
            f[i].sum+=s[j-1];
        }
        f[i].len=strlen(s),sort(f[i].s+1,f[i].s+f[i].len+1);
    }
    sort(f+1,f+1+n,cmp);
    for(int i=2;i<=n;i++)
    {
        if(f[i].sum!=f[i-1].sum||f[i].len!=f[i-1].len)
            ans++;
        else
        {
            for(int j=1;j<=f[i].len+1;j++)
                if(f[i].s[j]!=f[i-1].s[j])
                {
                    ans++;
                    break;
                }
        }
    }
    cout<<ans;
    system("pause");
    return 0;
}