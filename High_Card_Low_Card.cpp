
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






int main()
{
    
    
    
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");
    
    int n;
    fin>>n;
    
    map<int, bool>used;
    vector<int>bessie;
    vector<int>els;
    
    for(int i=0;i<n;i++)
    {
        int x;
        fin>>x;
        x--;
        used[x]=true;
        els.push_back(x);
        
    }
    for(int i=0;i<n*2;i++)
    {
        if(!used[i])
        {
            bessie.push_back(i);
        }
    }
    
    sort(els.begin(), els.begin()+n/2);
    sort(els.begin()+n/2, els.end());
    rotate(els.begin(), els.begin() + n/2, els.end());
    
    
    
    int ans=0;
    
    for(int i=n/2, j=n/2; i<n&&j!=n;i++,j++,ans++)
    {
        while(j<n&&bessie[j]<els[i])
        {
            j++;
        }
        if(j==n)
        {
            break;
        }
    }
    for(int i=(n/2)-1, j=(n/2)-1;i>=0&&j!=-1;i--, j--, ans++)
    {
        while(j>=0&&bessie[j]>els[i])
        {
            j--;
        }
        if(j==-1)
        {
            break;
        }
    }
    fout<<ans<<endl;
    
}






















