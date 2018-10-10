#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

vector< ll > pref;
const int maxn = 55;

ll dp[maxn][maxn][maxn];

ll rec(ll i , ll j , ll e){
    if(i == e){
        return 1;
    }
    if(dp[i + 1][j + 1][e + 1] != -1){
        return dp[i + 1][j + 1][e + 1];
    }
    ll a = rec(i + 1 , j , e);
    ll sm = pref[i];
    if(j != -1) sm -= pref[j];
    ll b = 0;
    for(int k = i + 1 ; k < e ; k++){
        ll s2 = pref[e - 1] - pref[k - 1];
        if(s2 == sm){
            b = (b + rec(i + 1 , i , k)) % MOD;
        }
    }
    return dp[i + 1][j + 1][e + 1] = (a + b) % MOD;

}
int main()
{
    ll t;
    cin >> t;
    while(t--){

        string s;
        cin >> s;
        for(int i = 0 ; i < maxn ; i++) for(int j = 0 ; j < maxn ; j++) for(int k = 0 ; k < maxn ; k++) dp[i][j][k] = -1;
        pref.clear();
        pref.resize(s.size() + 1);
        for(int i = 0 ; i < pref.size() ; i++){
            pref[i] = s[i] - '0';
            if(i != 0) pref[i] += pref[i-1];
        }
        ll ans = rec(0 , -1 , s.size());
        cout << ans << endl;
    }
}
