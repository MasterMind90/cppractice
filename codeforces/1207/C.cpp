#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
ll n , a , b ;
string s ;
ll dp[N][2] ;

ll dfs(ll x,ll height){
	if ( x == n ){
		if ( height == 1 ) return INF ;
		return 0 ;
	}
	if ( dp[x][height] != -1 ) return dp[x][height] ;
	ll ans = INF ;
	if ( s[x] == '0' ){
		if ( height == 1 ){
			ans = min(ans, dfs(x+1,1) + a + b + b ) ;
			ans = min(ans, dfs(x+1,0) + a + a + b + b ) ;
		}
		else{
			ans = min(ans, dfs(x+1,0) + a + b) ;
			ans = min(ans, dfs(x+1,1) + a + a + b) ;
		}
	}
	else{
		if ( height == 1 )
			ans = min(ans, dfs(x+1,1) + a + b + b ) ;
	}
	return dp[x][height] = ans ;
}

void solve(){
	memset(dp,-1,sizeof dp) ;
	cin >> n >> a >> b ;
	cin >> s ;
	cout << dfs(0,0) + b << endl;
}
int main(){
	fastio
	ll t;
	cin >> t ;
	while(t--){
		solve() ;
	}
	return 0 ;
}
