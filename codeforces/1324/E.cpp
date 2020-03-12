#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define int long long
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
const ll INF = 1e18 + 10 ;
int n , h , l , r ;
vector<int> v ; 
int dp[N][N] ; 
int dfs(int idx, int wake){
    if ( idx == n ) {
        return 0 ; 
    }
    assert(wake < N && wake >= 0) ; 
    if ( dp[idx][wake] != -1 ) return dp[idx][wake] ; 
    debug() << imie(idx) imie(wake) ;
    int T = (wake + v[idx]) ; 
    if ( T >= h ) T = T - h ; 
    int choice1 = 0 , choice2 = 0 ; 
    if ( T >= l && T <= r ){
        choice1 = 1 + dfs(idx + 1, T);
    }
    else choice1 = dfs(idx + 1, T);
    int time = v[idx] - 1 ;
    T = wake + time ; 
    if ( T >= h ) T = T - h ; 
    if ( T >= l && T <= r ){
        choice2 = 1 + dfs(idx + 1, T ) ;
    }
    else choice2 = dfs(idx + 1, T ) ;
    return dp[idx][wake] = max(choice1, choice2) ;
}
signed main(){
    fastio
    memset(dp, -1, sizeof dp) ;
    cin >> n >> h >> l >> r ;
    v.resize(n) ; 
    for(int i = 0; i < n; i++){
        cin >> v[i] ; 
    }
    int ans = dfs(0, 0) ;
    cout << ans << endl;
    return 0; 
}