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
const ll INF = 1e18 + 10 ;
string s ; 
ll n ;
ll dp[N][3] ; 
ll fix(ll x){
    return (x % 3 + 3) % 3 ; 
}
ll dfs(ll x, ll cur){
    if ( x == n ) {
        return 0 ; 
    }
    if ( dp[x][cur] != -1 ) return dp[x][cur] ;
    ll val = s[x] - '0' ; 
    ll ans = 0; 
    if ( fix(cur + val) == 0 ){
        ans = 1 + dfs(x + 1, 0) ; 
    }
    else{
        ans = max(ans, dfs(x + 1, fix(cur + val) ));
        ans = max(ans, dfs(x + 1, cur));
    }
    return dp[x][cur] = ans ; 
}
int main(){
    fastio
    memset(dp, -1, sizeof dp);
    cin >> s ; 
    n = (ll) s.size() ; 
    ll ans = dfs(0, 0) ; 
    cout << ans << endl;
    return 0; 
}