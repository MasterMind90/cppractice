#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll n , k ;
ll sum(ll n){
    return (n*(n+1))/2LL;
}
bool p(ll x){
    ll ans = sum(k) - sum(x-1);
    if ( ans >= n ) return true ;
    return false;
}

int main(){
    cin >> n >> k ;
    if ( n == 1 ) {
        cout << 0 << endl;
        return 0 ;
    }
    n--;
    k--;
    if ( sum(k) < n ){
        cout << -1 << endl;
        return 0 ;
    }
    ll l = 1 ;
    ll r = k ;
    while(l<r){
        ll mid = l + (r-l+1)/2;
        if ( p(mid) == false ){
            r = mid - 1 ;
        }
        else {
            l = mid ;
        }
    }
    cout << k-l+1 << endl;
    return 0 ;
}
