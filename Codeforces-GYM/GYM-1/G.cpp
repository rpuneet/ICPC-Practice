#include<bits/stdc++.h>
#define ll long long
#define INF 1000000000000
using namespace std;
vector<vector<pair<long long,long long> > >vec;
vector<vector<long long> >src;
map<long long,long long>mp;
vector<long long>ans,quer;

void dfs(long long v,long long par,long long wt,long long mxwt,long long pwt)
{
 //  cout<<"v is "<<v<<"\n";
    mp[wt]=v;
    for(auto i:vec[v]){
        if(i.first!=par){

            if(i.second<=mxwt){
            long long val;
             auto x = upper_bound(src[v].begin(),src[v].end(),i.second);
             if(x==src[v].end())
                val=INF;
            else{
                if((*x)==pwt){
                    x++;
                }
            if(x==src[v].end())
                val=INF;
            else
                val=*x;

            }
        if(wt<min(mxwt,val))
        dfs(i.first,v,max(wt,i.second),min(mxwt,val),i.second);
        else return ;}
        }
    }
}

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,q;
        cin>>n>>q;
        src.clear();
        src.resize(n+1);
        mp.clear();
        vec.clear();
        ans.clear();
        quer.clear();
        vec.resize(n+1);
        quer.resize(q);
        for(long long i=0;i<n-1;i++)
        {
            long long x,y,w;
            cin>>x>>y>>w;
            vec[x].push_back({y,w});
            vec[y].push_back({x,w});
            src[x].push_back(w);
            src[y].push_back(w);
        }
    for(long long i=0;i<src.size();i++)
        sort(src[i].begin(),src[i].end());
     for(long long i=0;i<q;i++)
        cin>>quer[i];
    dfs(1,-1,-1,INF,-1);
    long long sum=0;
    for(auto it=mp.begin();it!=mp.end();it++)
        ans.push_back(it->first);
    for(long long i=0;i<q;i++)
    {
        auto x = lower_bound(ans.begin(),ans.end(),quer[i]);
        x--;
        sum+=mp[*x];
        cout<<mp[*x]<<" ";
    }
   // cout<<sum<<"\n";
   /* for(auto it=mp.begin();it!=mp.end();it++)
        cout<<(it->first.first)<<" "<<it->first.second<<" "<<it->second<<"\n";*/
    }

}
/*2
14 27
1 2 8
1 5 15
1 6 4
2 3 10
2 4 7
3 13 9
5 14 20
6 7 25
6 8 3
6 9 2
7 10 23
8 11 6
9 12 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
5 16
1 2 4
2 3 2
3 4 3
4 5 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
*/
