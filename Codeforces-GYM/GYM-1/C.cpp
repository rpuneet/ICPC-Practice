#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while(t--){
        ll k , p , n;
        cin >> k >> p >> n;
        ll ans = max(0LL , (k - p) * n );
        cout << ans << endl;
    }
}
