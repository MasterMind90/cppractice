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
const ll N = 80 + 10 ;
const ll INF = 1e18 + 10 ;
ll n , m ;
ll a[N][N] ; 
ll b[N][N] ; 
ll dp[N][N][12800] ; 
ll dfs(ll x, ll y, ll curDiff){
    if ( x >= n || y >= m ) return INF ; 
    if ( x == n - 1 && y == m - 1 ){
        return min(abs(curDiff + a[x][y] - b[x][y]), abs(curDiff + b[x][y] - a[x][y])) ;
    }
    if ( dp[x][y][curDiff] != -1 ) return dp[x][y][curDiff] ; 
    ll choice1 = dfs(x + 1, y, curDiff + a[x][y] - b[x][y] ) ;
    ll choice2 = dfs(x + 1, y, curDiff + b[x][y] - a[x][y] ) ;
    ll choice3 = dfs(x, y + 1, curDiff + a[x][y] - b[x][y] ) ;
    ll choice4 = dfs(x, y + 1, curDiff + b[x][y] - a[x][y] ) ;
    return dp[x][y][curDiff] = min({choice1, choice2, choice3, choice4});
}
int main(){
    fastio
    memset(dp, -1, sizeof dp) ;
    cin >> n >> m ; 
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> a[i][j] ; 
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> b[i][j] ; 
        }
    }
    cout << dfs(0, 0, 0) << endl;
    return 0; 
}