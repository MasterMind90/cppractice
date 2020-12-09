#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sim template < class c
#define int long long
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
typedef tree< pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int n , m , x , y; 
vector<int> dot ;
// 0 dot 
// 1 hash 
vector<vector<vector<int> > > dp ;
int dfs(int id, int group, int color){
	debug() << imie(id) imie(group) imie(color) ;
	if ( id == m ) {
		if ( group < x || group > y ) return INF ;
		return 0 ;
	}
	if ( dp[id][group][color] != -1 ) return dp[id][group][color] ;
	int ans = INF ;
	int dots = n - dot[id] ;
	int hash = dot[id] ;
	debug() << imie(dots) imie(hash) ;
	if ( id == 0 ) {
		ans = min(ans, dots + dfs(id + 1, group + 1, 0)) ;
		ans = min(ans, hash + dfs(id + 1, group + 1, 1)) ;
	}
	else {
		if ( color == 0 ) {
			if ( group == y ) {
				ans = min(ans, hash + dfs(id + 1, 1, 1)) ;
			}
			else if ( group < x ) {
				ans = min(ans, dots + dfs(id + 1, group + 1, 0)) ;
			}
			else {
				ans = min(ans, dots + dfs(id + 1, group + 1, 0)) ;
				ans = min(ans, hash + dfs(id + 1, 1, 1)) ;
			}
		}
		else {
			if ( group == y ) {
				ans = min(ans, dots + dfs(id + 1, 1, 0)) ;
			}
			else if ( group < x ) {
				ans = min(ans, hash + dfs(id + 1, group + 1, 1)) ;
			}
			else {
				ans = min(ans, dots + dfs(id + 1, 1, 0)) ;
				ans = min(ans, hash + dfs(id + 1, group + 1, 1)) ;
			}
		}
	}
	return dp[id][group][color] = ans ;
}
signed main(){
    fastio
    cin >> n >> m >> x >> y ; 
    vector<vector<char> > v(n, vector<char>(m)) ;
    dot = vector<int>(m) ;
    dp = vector<vector<vector<int> > >(m + 1, vector<vector<int> >(m + 1, vector<int>(2, -1))) ;
    int d , h ; 
    d = h = 0 ; 
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> v[i][j] ;
    		if ( v[i][j] == '.' ) {
    			dot[j]++ ;
    			d++ ;
    		}
    		else h++ ;
    	}
    }
    debug() << imie(d) imie(h) imie(n * m) ;
    debug() << imie(dot) ;
    int ans = dfs(0, 0, 0) ;
    cout << ans << endl;
    return 0; 
}