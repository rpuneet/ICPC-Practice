#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll len(ll n)
{
    ll res=0;
    while(n)
    {
        res++;
        n/=10;
    }
    return res;

}

ll get(ll tot_dig, ll x)
{
    ll cnt = 0;

    while(1)
    {
        ll lx= len(x);
        ll a = (ll)pow(10,lx);
        ll b = (a-x)*lx;
        if(b >= tot_dig)
        {
            if(tot_dig%(lx) == 0)
                cnt+=tot_dig/(lx);
            else
                cnt=-1;

            return cnt;

        }
        cnt+=(a-x);
        x = a;
        tot_dig-=b;
    }

}


int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        cout<<get(n,x)<<endl;
    }
}
close
