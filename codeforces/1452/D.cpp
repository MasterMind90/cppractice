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
// const ll MOD = 1e9 + 7 ;
const ll MOD = 998244353 ; 
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int fast(int a, int b){
	if ( b == 0 ) return 1 ;
	if ( b == 1 ) return a ;
	int y = fast(a , b / 2) ;
	y *= y ;
	y %= MOD ;
	if ( b & 1 ) y *= a ;
	return y %= MOD ;
}
int inv(int x){
	return fast(x, MOD - 2) ;
}
vector<int> dp ;
int dfs(int x){
	if ( x == 0 ) return 1 ;
	if ( dp[x] != -1 ) return dp[x] ;
	int ans = 0 ;
	for(int i = 1; i <= x; i += 2){
		ans += dfs(x - i) ;
	}
	return dp[x] = ans ;
}
signed main(){
    fastio
    int n ;
    cin >> n ;
    dp = vector<int>(n + 1, 0) ;
    dp[0] = 1 ;
    int even = dp[0] ;
    dp[1] = 1 ;
    int odd = dp[1] ;
    // even: 0 + 2 + 4 + 6 + ..... 
    // odd : 1 + 3 + 5 + 7 + .....
    // dp[4] = dp[3] + dp[1]
    for(int i = 2; i < n + 1; i++){
    	if ( i & 1 ) {
    		dp[i] = even ;
    		odd += dp[i] ;
    	}
    	else {
    		dp[i] = odd ;
    		even += dp[i] ;
    	}
    	dp[i] %= MOD ;
    	odd %= MOD ;
    	even %= MOD ;
    }
    int answer = dp[n] * inv(fast(2, n)) ;
    answer %= MOD ;
    cout << answer << endl;
    // cout << dp[n] << endl;
    // int ans = dfs(n) ;
    // debug() << imie(ans) ;
    // ans *= inv(fast(2, n)) ;
    // ans %= MOD ;
    // cout << ans << endl;
    return 0; 
}

// 0 1 2 3 4 5 6
// - 1 1 1 1 1 - 
// - - 2 - 1 1 - 

// 5 

// the number of ways to form n as the sum of odd numbers
