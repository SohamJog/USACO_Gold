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


using namespace std;



#define ll long long
#define clr(x) memset(x, 0, sizeof(x))
#define tcase ll t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define GCJ ll t;cin>>t;for(ll H=1;H<=t;H++){cout<<"CASE #"<<H<<": ";solve();}
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define endl "\n"
//comment out the above line when coding probs which require flushing the output
#define prarr(a,n) for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;
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


const ll MAXN = 100010;


ll n;
ll id[2*MAXN];


ll root(ll x)
{
    return x==id[x]?x:id[x]=root(id[x]);
}
bool merge(ll x, ll y)
{
    ll p=root(x), q=root(y);
    if(p==q)
    {
        return false;
    }
    id[x]=id[y]=id[p]=id[q]=(rand()%2?id[p]:id[q]);
    
    return true;
}


void solve()
{
    cin>>n;
    rep(i,n*2)
    {
        id[i]=i;
    }
    vii a, b;
    a.resize(2*(n+1));
    crep(i,1,n+1)
    {
        ll c,x;
        cin>>c;
        b.pb({c,i});
        rep(j,2)
        {
            cin>>x;
            if(a[x].ff==0)a[x].ff=i;
            else a[x].ss=i;
        }
        rep(j,2)
        {
            cin>>x;
            if(a[x].ff==0)a[x].ff=i+n;
            else a[x].ss=i+n;
        }
    }
    
    crep(i,1,1+(2*n))
    {
        merge(a[i].ff, a[i].ss);
    }
    sort(all(b));
    ll ans=0;
    rep(i,n)
    {
        if(merge(b[i].ss, b[i].ss+n))ans+=b[i].ff;
    }
    cout<<ans<<endl;
}


int main()
{
    fast;
    solve();
}

