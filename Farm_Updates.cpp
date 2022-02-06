//USACO 2022 Jan Farm Updates using Dijkstra's Algorithm

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
#include <unordered_set>
#include <deque>


using namespace std;



#define ll long long
#define clr(x) memset(x, 0, sizeof(x))
#define tcase ll t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define GCJ ll t;cin>>t;for(ll HtestCase=1;HtestCase<=t;HtestCase++){cout<<"Case #"<<HtestCase<<": ";solve();}
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define endl "\n"
//comment out the above line when coding probs which require flushing the output
#define remDup(v) sort(all(v));v.resize(unique(all(v))-v.begin());
#define vi vector<ll>
#define pii pair<ll, ll>
#define vii vector<pii>
#define vvi vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<n;i++)
#define crep(i,x,n) for(ll i=x;i<n;i++)
#define ss second
#define ff first
#define pb push_back



void USACO(string s){fast;freopen((s+".in").c_str(),"r",stdin);freopen((s+".out").c_str(),"w",stdout);}
void FHC (string s, string o){fast;freopen((s).c_str(),"r",stdin);freopen((o).c_str(),"w",stdout);}



const ll MAXN =100;



struct edge
{
    ll a, b, life;
    bool operator<(const edge X)const
    {
        return life<X.life;
    }
};

struct state
{
    ll x, wt;
    bool operator<(const state X)const
    {
        return wt<X.wt;
    }
};

void solve()
{
    
    ll n, q;
    cin>>n>>q;
    
    
    vector<edge>v;
    vector<vector<edge>>adj;
    adj.resize(n+1);
    bool vis[n+1];clr(vis);
    priority_queue<state>pq;
    
    ll ans[n+1];         //surviving
    
    
    for(ll i=1;i<=n;i++)ans[i]=q;

    for(ll i=1;i<=q;i++)
    {
        char c;
        cin>>c;
      
        if(c=='D')
        {
            ll x;cin>>x;
            ans[x]=i-1;
        }
        if(c=='A')
        {
            ll a, b;
            cin>>a>>b;
            v.pb({a,b,q});
        }
        if(c=='R')
        {
            ll x;cin>>x;
            v[x-1].life=i-1;
        }
       // cout<<i<<" "<<c<<endl;

    }

    for(ll i=1;i<=n;i++)pq.push({i,ans[i]});
    
    for(ll i=0;i<v.size();i++)
    {
        adj[v[i].a].pb({v[i]});
        adj[v[i].b].pb({v[i].b,v[i].a,v[i].life});
    }
    
    while(!pq.empty())
    {
        state X=pq.top();
        pq.pop();
        ll node = X.x;
        
        if(vis[node])
        {
            continue;
        }
        
        vis[node]=true;
        
        for(edge u:adj[node])
        {
            ll v=u.b, life=u.life;
            if(min(life, ans[node])>ans[v])
            {
                ans[v]=min(life, ans[node]);
                pq.push({v,ans[v]});
            }
        }
        
    }
    
    for(ll i=1;i<=n;i++)
    {
        cout<<ans[i]<<endl;
    }
}
    

int main()
{
    
    fast;
    //tcase
        solve();
}
