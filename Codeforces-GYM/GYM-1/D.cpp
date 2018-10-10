#include<bits/stdc++.h>
#define ll int
using namespace std;

const int maxn = 1<<21;
ll A[maxn];
ll p , n;
vector< ll > G;
ll ans;
void rec(ll i , ll amp, ll c){
    if(i == p){
        if(c == 0) return;
        ans = max(ans , c + __builtin_popcount(amp));
        return;
    }
    rec(i + 1 , amp , c);
    rec(i + 1 , amp & G[i] , c + 1);
}

int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        ans = 0;
        cin >> p >> n;
        G.clear();
        G.resize(p);
        for(int i = 0 ; i < ((1<<p) - 1) ; i++) A[i] = 0;
        for(int i = 0 ; i < n ; i++){
            int b , g;
            cin >> b >> g;
            b--;
            g--;
            G[g] |= (1<<b);
        }
        rec(0 , maxn - 1 , 0);
        cout << ans << endl;
    }
}
