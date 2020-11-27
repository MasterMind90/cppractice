#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 
const int MOD = 1e9 + 7 ; 
int n ;
// 0 1 0 1 0 
// 1 red 
// 2 blue 
vector<vector<int> > dp ; 

int dfs(int x, int last){
	if ( x == n ) {
		if ( last != 0 ) return 1 ;
		return 0 ; 
	}
	if ( dp[x][last] != -1 ) return dp[x][last] ;
	int ans = dfs(x + 1, last) ; 
	ans %= MOD ;
	if ( x % 2 == 0 ) {
		if ( last == 0 ) {
			ans += dfs(x + 1, 1) ;
		}
		else if ( last == 2 ) {
			ans += dfs(x + 1, 1) ;
		}
	}
	else {
		if ( last == 0 ) {
			ans += dfs(x + 1, 2) ;
		}
		else if ( last == 1 ) {
			ans += dfs(x + 1, 2) ;
		}
	}
	ans %= MOD ;
	return dp[x][last] = ans  ;
}
signed main(){
    fastio;
    cin >> n ;
    dp = vector<vector<int> >(n, vector<int>(3, -1)) ;
    int ans = dfs(0, 0) ;
    cout << ans << endl;
    return 0 ;
}
