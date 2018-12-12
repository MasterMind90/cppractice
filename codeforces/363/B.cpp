#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main(){
    ll n , k ;
    cin >> n >> k ;
    k--;
    vector<ll> v(n);
    vector<ll> sum(n+1);
    sum[0]=0LL;
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum[i+1] = sum[i]+v[i];
    }
    ll minIndex = 0 ;
    ll minVal = 1e18 ;
    for(int i=1;i<=n-k;i++){
        ll val = sum[k+i] - sum[i-1];
        if ( val < minVal ){
            minVal = val ;
            minIndex = i ;
        }
    }
    cout << minIndex << endl;
    return 0;
}
