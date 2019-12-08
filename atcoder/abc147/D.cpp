#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << '\n'; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e3 + 10 ;
const ll INF = 1e18 + 10 ;
int main(){
    fastio
    ll n ;
    cin >> n ; 
    vector<vector<bool>> v(n, vector<bool>(61)) ; 
    for(ll i = 0; i < n; i++){
        ll x ;
        cin >> x ; 
        for(ll j = 0; j < 61; j++){
            if ( x & (1LL << j) ){
                v[i][j] = 1; 
            }
        }
    }
    vector<ll> cnt(61) ;
    for(ll i = 0; i < 61; i++){
        ll ones = 0 ; 
        for(ll j = 0; j < n; j++){
            if ( v[j][i] ) ones++ ; 
        }
        cnt[i] = ones ; 
    }
    ll sum = 0 ;
    for(ll i = 0; i < 61; i++){
        ll ones = cnt[i] ; 
        ll zeroz = n - cnt[i] ; 
        sum += (((ones % MOD) * (zeroz % MOD)) % MOD * ((1LL << i) % MOD)) % MOD ; 
        sum = sum % MOD ; 
    }
    cout << sum << endl;
    return 0; 
}