#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;

ll solve(ll a, ll b){
    return (a - 1) + (b - 1) ;
}

int main(){
    ll n ;
    cin >> n ;
    vector<ll> div ;
    for(ll i = 1; i * i <= n; i++){
        if ( n % i == 0 ){
            div.push_back(i) ;
            if ( n / i != i ) div.push_back(n / i) ;
        }
    }
    ll ans = 1e18 + 10 ;
    for(int i = 0; i < (int)div.size(); i++){
        ll a = div[i] ;
        ll b = n / div[i] ;
        if ( a > b ) swap(a,b) ;
        ans = min(ans, solve(a, b));
    }
    cout << ans << endl;
    return 0 ;
}
