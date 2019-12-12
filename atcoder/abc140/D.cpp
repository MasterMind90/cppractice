#include <bits/stdc++.h>

using namespace std;

using ll = long long ;

int main(){
    ll n , k ;
    cin >> n >> k ;
    ll t = n ;
    string s ;
    cin >> s ;
    vector<ll> groups ;
    for(ll i = 0; i < n;){
        char c = s[i] ;
        ll cnt = 0 ;
        while(i < n && s[i] == c ){
            cnt++ ;
            i++ ;
        }
        groups.push_back(cnt) ;
    }
    n = (ll)groups.size() ;
    vector<ll> sum(n + 1) ;
    for(ll i = 0; i < n; i++){
        sum[i + 1] = sum[i] + groups[i] ;
    }
    ll window = k + k + 1 ;
    if ( window >= n ){
        return cout << t - 1 << endl, 0 ;
    }
    ll ans = 0 ;
    for(ll i = 1; i + window - 1 <= n; i++){
        ll midInterval = sum[i + window - 1] - sum[i - 1] ;
        ll lastInterval = sum[n] - sum[i + window - 1] ;
        ll cntLastInterval = n - i - window + 1 ;
        ll beginInterval = sum[i - 1] ;
        ll cntBeginInterval = i - 1;
        ans = max(ans, (midInterval - 1) + (lastInterval - cntLastInterval) + (beginInterval - cntBeginInterval) );
    }
    cout << ans << endl;
    return 0 ;
}




