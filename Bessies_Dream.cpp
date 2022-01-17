
#include <iostream>
#include <vector>
#include <queue>
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <stdio.h>
#include <string.h>
#include <climits>
#include <queue>
#include<bitset>
#include<fstream>


using namespace std;
#define ll long long
#define clr(x) memset(x, 0, sizeof(x))
#define tcase ll t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define endl "\n"




struct state
{
    ll x, y, wt;bool orange;
    
    bool operator<(const state X)const
    {
        return X.wt<wt;
    }
    
};

priority_queue<state>q;
ll n,m;
ll G[1010][1010]={{0}};
bool vis[1010][1010][2]={{{0}}};
ll dist[1010][1010][2]={{{0}}};
ll dirx[4]={0,0,-1, 1};
ll diry[4]={1,-1,0,0};


bool legal(ll x, ll y, bool orange)
{
    
    
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if(G[x][y]==0)
    {
        return false;
    }
    if(G[x][y]==3)
    {
        return orange;
    }
    return true;
}


int main() {
    
    
    ifstream fin("dream.in");ofstream fout("dream.out");
    
    
    fin>>n>>m;
    
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            fin>>G[i][j];
            dist[i][j][0]=dist[i][j][1]=1000000000;
        }
    }
    
    if(G[0][0]==0)
    {
        fout<<-1<<endl;
        return 0;
    }
    
    if(G[0][0]==2)
    {
        q.push({0,0,0,1});
    }
    else
    {
        q.push({0,0,0,0});
    }
    
    dist[0][0][0]=0;
    
    
    while(!q.empty())
    {
        state node=q.top();
        q.pop();
        
        ll x=node.x, y=node.y, wt=node.wt;
        bool orange=node.orange;
        
        if(vis[x][y][orange])
        {
            continue;
        }
        vis[x][y][orange]=true;
        dist[x][y][orange]=wt;
        if(x==n-1&&y==m-1)
        {
            fout<<dist[x][y][orange]<<endl;
            return 0;
        }
        
        
        for(ll i=0;i<4;i++)
        {
            ll X=dirx[i]+x, Y=diry[i]+y, D=wt+1;bool tor=orange;
            if(!legal(X, Y, tor))
            {
                continue;
            }
            if(G[X][Y]==4)
            {
                tor=0;
                while(legal(X+dirx[i], Y+diry[i], tor)&&G[X][Y]==4)
                {
                    X+=dirx[i], Y+=diry[i], D++;
                }
                
               // cout<<diry[i]<<endl;
               // cout<<X<<" "<<Y<<" "<<D<<endl;
            }
            if(G[X][Y]==2)
            {
                tor=1;
            }
            
            if(dist[X][Y][tor]<=D)
            {
                continue;
            }
            q.push({X, Y, D, tor});
            //cout<<X<<" "<<Y<<" "<<D<<" "<<tor<<endl;
        }

    }
    
    fout<<-1<<endl;
    
}
















