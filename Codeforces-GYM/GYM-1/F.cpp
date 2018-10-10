#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        int vis[n + 1] = {0};
        for(int i = 0 ; i < n - 1 ; i++){
            int x;
            cin >> x;
            vis[x] = 1;
        }
        for(int i = 1 ; i <= n ; i++) if(!vis[i]) cout << i << endl;
    }
}
