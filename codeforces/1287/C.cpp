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
const ll N = 2e5 + 10 ;
const ll INF = 1e12 + 10 ;
vector<ll> v ; 
ll n ; 
ll dp[105][105][105][3] ; 
ll dfs(ll x, ll even, ll odd, ll last){
    if ( x == n ){
        return 0 ; 
    }
    if ( dp[x][even][odd][last] != -1 ) return dp[x][even][odd][last];
    ll ans = INF ; 
    if ( v[x] == 0 ){
        if ( last == 2 ){
            if ( even > 0 ) ans = min(ans, dfs(x + 1, even - 1, odd, 0) );
            if ( odd > 0 ) ans = min(ans, dfs(x + 1, even, odd - 1, 1) );
        }
        else if ( last == 0 ){
            if ( even > 0 ) ans = min(ans, dfs(x + 1, even - 1, odd, 0)  );
            if ( odd > 0 ) ans = min(ans, 1 + dfs(x + 1, even, odd - 1, 1)  );
        }
        else if ( last == 1 ){
            if ( odd > 0 ) ans = min(ans, dfs(x + 1, even, odd - 1, 1)  );
            if ( even > 0 ) ans = min(ans, 1 + dfs(x + 1, even - 1, odd, 0)  );
        }
    }
    else{
        if ( last == 2){
            ans = min(ans, dfs(x + 1, even, odd, v[x] % 2)) ;
        }
        else {
            ans = min(ans, (last != (v[x] % 2)) + dfs(x + 1, even, odd, v[x] % 2) );
        }
    }
    return dp[x][even][odd][last] = ans ; 
}
int main(){
    fastio
    memset(dp, -1, sizeof dp) ; 
    cin >> n ;
    v.resize(n) ; 
    set<ll> s ;
    for(ll i = 0; i < n; i++){
        cin >> v[i] ; 
        s.insert(v[i]) ;
    }
    vector<ll> missing ; 
    for(ll i = 1; i <= n; i++){
        if ( s.find(i) == s.end() ) missing.push_back(i) ;
    }
    ll even = 0 ; 
    ll odd = 0 ; 
    for(ll c : missing){
        if ( c % 2 == 0 ) even++ ; 
        else odd++ ; 
    }
    cout << dfs(0, even, odd, 2) << endl;
    return 0; 
}