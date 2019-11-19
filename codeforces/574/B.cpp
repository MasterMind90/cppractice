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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ; 
const ll nax = 2e9 ; 
int main(){
    fastio
    ll n , m ;
    cin >> n >> m ; 
    ll g[n + 1][n + 1] ; 
    memset(g, 0, sizeof g) ;
    vector<ll> deg(n + 1) ; 
    for(ll i = 0; i < m; i++){
        ll x , y ; 
        cin >> x >> y ; 
        g[x][y] = 1 ;
        g[y][x] = 1 ; 
        deg[x]++ ;
        deg[y]++ ; 
    }
    ll ans = INF ; 
    for(ll i = 1; i <= n - 2; i++){
        for(ll j = i + 1; j <= n - 1; j++){
            for(ll k = j + 1; k <= n; k++){
                if ( g[i][j] && g[i][k] && g[j][k] ) {
                    debug() << imie(g[i][j]) imie(g[i][k]) imie(g[j][k]) ;
                    debug() << imie(i) imie(j) imie(k) ; 
                    ans = min(ans, deg[i] + deg[j] + deg[k] - 6) ; 
                }
            }
        }
    }
    if ( ans == INF ) cout << -1 << endl;
    else cout << ans << endl;
    return 0 ; 
}