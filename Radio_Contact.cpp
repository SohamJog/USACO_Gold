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
//comment out the above line when coding probs which require flushing the output



int dist(pair<int, int>a, pair<int, int>b)
{
    return pow(a.first-b.first, 2)+pow(a.second-b.second, 2);
}

pair<int, int>conv(pair<int, int>cur, char dir)
{
    if(dir=='N')
    {
        return {cur.first, cur.second+1};
    }
    if(dir=='E')
    {
        return {cur.first+1, cur.second};
    }
    if(dir=='S')
    {
        return {cur.first, cur.second-1};
    }
    return {cur.first-1, cur.second};
}



int main()
{
    
    ifstream fin("radio.in");
    ofstream fout("radio.out");
    
    int n, m;
    fin>>n>>m;
    
    vector<pair<int, int>>far, bes;
    
    far.resize(n+1);bes.resize(m+1);
    
    
    
    fin>>far[0].first>>far[0].second>>bes[0].first>>bes[0].second;
    
    int dp[n+1][m+1];
    clr(dp);
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=INT_MAX;
        }
    }
    
    char F[n+1], B[m+1];
    
    for(int i=1;i<=n;i++)
    {
        fin>>F[i];
    }
    for(int i=1;i<=m;i++)
    {
        fin>>B[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        far[i]=conv(far[i-1], F[i]);
    }
    for(int i=1;i<=m;i++)
    {
        bes[i]=conv(bes[i-1], B[i]);
    }
    
    dp[0][0]=0;
    
    for(int i=1;i<=m;i++)
    {
        dp[0][i]=dist(far[0], bes[i])+dp[0][i-1];
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dist(far[i], bes[0])+dp[i-1][0];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=dist(far[i], bes[j])+min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
        }
    }
    
    
    
    fout<<dp[n][m]<<endl;

}
