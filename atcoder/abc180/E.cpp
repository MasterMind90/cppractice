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
int n ;
vector<pair<pair<int,int>, int> > v ; 
vector<vector<int> > dp ;
int cost(int a, int b){
	int ans = abs(v[a].first.first - v[b].first.first) ;
	ans += abs(v[a].first.second - v[b].first.second) ;
	ans += max(0LL, v[b].second - v[a].second) ;
	return ans ;
}
int dfs(int cur, int x){
	if ( cur == (1 << n) - 1 ){
		return 0 ;
	}
	if ( dp[cur][x] != -1 ) return dp[cur][x] ;
	int ans = INF ; 
	if ( cur == (1 << n) - 2 ) {
		ans = min(ans, cost(x, 0) + dfs(cur |= 1, 1)) ;
	}
	else {
		for(int i = 1; i < n; i++){
			if ( i == x ) continue ;
			if ( (1 << i) & cur ) continue ;
			ans = min(ans, cost(x, i) + dfs(cur | (1 << i), i)) ;
		}
	}
	return dp[cur][x] = ans ;
}
signed main(){
    fastio
    cin >> n ;
    v = vector<pair<pair<int,int>, int > >(n) ;
    dp = vector<vector<int> >((1 << n), vector<int>(20, -1)) ;
    for(int i = 0; i < n; i++){
    	cin >> v[i].first.first >> v[i].first.second >> v[i].second ;
    }
    int ans = dfs(0, 0) ;
    cout << ans << endl;
    return 0; 
}