
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include <cmath>
#include<string.h>
#include <stdio.h>
#include <unordered_map>
#include <queue>
#include<climits>
#include <iomanip>



using namespace std;
#define ll long long
#define clr(x) memset(x, 0, sizeof(x))
#define tcase ll t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define GCJ ll t;cin>>t;for(ll H=1;H<=t;H++){cout<<"CASE #"<<H<<": ";solve();}
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define endl "\n"


int dist[1000][1000][4][2];                 //i, j, oranges, dir
bool dp[5000010][2]={{0}};
int a, b, t;


void recur1(int x)
{
    
    dp[x][0]=1;
    
    
    
    dp[x/2][1]=true;
    if(x+a<=t&&dp[x+a][0]==0)
    {
        recur1(x+a);
    }
    if(x+b<=t&&dp[x+b][0]==0)
    {
        recur1(x+b);
    }
}

void recur2(int x)
{
    
    dp[x][1]=true;
    
    if(x+a<=t&&!dp[x+a][1])
    {
        recur2(x+a);
    }
    if(x+b<=t&&!dp[x+b][1])
    {
        recur2(x+b);
    }
}

int main()
{
    
    ifstream fin("feast.in");
    ofstream fout("feast.out");
    
    
    fin>>t>>a>>b;
    
    clr(dp);
    
    dp[0][0]=dp[0][1]=true;
    
    recur1(0);
    for(int i=0;i<=t;i++)
    {
        if(dp[i][1])
        {
            recur2(i);
        }
    }
    for(int i=t;i>=0;i--)
    {
        if(dp[i][0]||dp[i][1])
        {
            fout<<i<<endl;
            break;
        }
    }

}











