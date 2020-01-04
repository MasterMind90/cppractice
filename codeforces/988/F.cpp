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
const ll N = 2e3 + 10 ;
const ll INF = 1e9 + 10 ;
const ll P = 1e5 + 5 ;
ll a , n , m ; 
vector<ll> rain(N) ; 
vector<ll> umbrella(N, INF) ; 
ll dp[N][N] ; 
ll dfs(ll x, ll index){
    if ( x == a ){
        return 0 ; 
    }
    if ( dp[x][index] != -1 ) return dp[x][index] ; 
    ll ans = INF ; 
    if ( rain[x] ){
        if ( index ) ans = umbrella[index] + dfs(x + 1, index);
        if ( umbrella[x] != INF ) ans = min(ans,umbrella[x] + dfs(x + 1, x));
    }
    else{
        if ( index ) ans = umbrella[index] + dfs(x + 1, index) ; 
        if ( umbrella[x] != INF ) ans = min(ans, umbrella[x] + dfs(x + 1, x)) ; 
        ans = min(ans, dfs(x + 1, 0));
    }
    return dp[x][index] = ans ; 
}
int main(){
    fastio
    memset(dp, -1, sizeof dp) ;
    cin >> a >> n >> m ; 
    a++;
    for(ll i = 0; i < n; i++){
        ll x , y ; 
        cin >> x >> y ; 
        x++, y++;
        for(ll j = x; j < y; j++){
            rain[j] = 1 ; 
        }
    }
    for(ll i = 0; i < m; i++){
        ll x , w ; 
        cin >> x >> w ;
        x++;
        umbrella[x] = min(umbrella[x], w) ; 
    }
    ll ans = dfs(1, 0) ; 
    if ( ans == INF ){
        cout << -1 << endl;
    }
    else cout << ans << endl;
    return 0; 
}