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
~debug() { cerr << endl; }
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
#define fastio ios_base::sync_with_stdio(false); cin.tie(0) ;
using ll = long long ;
const ll N = 1e5 + 10;
const ll INF = 1e9 + 10 ;
ll n ;
vector<ll> h;
ll dp[N] ;
ll dfs(ll x) {
    if ( x == n - 1 ) return 0 ; 
    if ( x >= n ) return INF ;
    if ( dp[x] != -1 ) return dp[x] ; 
    ll choice1 = abs(h[x + 1] - h[x]) + dfs(x + 1) ;
    ll choice2 = INF ; 
    if ( x + 2 < n )
        choice2 = abs(h[x + 2] - h[x]) + dfs(x + 2);
    ll ans = min(choice1, choice2) ; 
    return dp[x] = ans ; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0) ; 
    memset(dp, -1, sizeof dp) ; 
    cin >> n ; 
    h.resize(n) ;
    for(ll i = 0; i < n; i++){
        cin >> h[i] ; 
    }
    cout << dfs(0) << endl;
    return 0 ;
}
