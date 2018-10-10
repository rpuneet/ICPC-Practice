#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while(t--){
        ll n , k;
        cin >> n >> k;
        vector<int > B;
        for(int i = 0 ; i < n ; i++){
            vector<int> A(3);
            cin >> A[0] >> A[1] >> A[2];
            sort(A.begin() , A.end());
            B.push_back(A[0]);
            B.push_back(A[1]);
        }
        sort(B.begin() , B.end());

        ll ans = 0;
        for(int i = 0 ; i < k ; i++){
            ans += B[i];
        }
        cout << ans << endl;
    }
}
