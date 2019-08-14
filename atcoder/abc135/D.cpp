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
ll n ; 
string s ; 
const ll MAXN = 1e5 + 10 ; 
const ll MOD = 13 ; 
const ll M = (ll)1e9 + 7  ;
ll dp[MAXN][MOD] ; 
ll power(ll x,ll y){
	if ( y == 0 ) return 1 ;
	if ( y == 1 ) return x ;
	if ( y % 2 == 0 ){
		ll f = power(x,y/2LL) ; 
		return ( (f % MOD) * (f % MOD) ) % MOD ; 
	}
	else {
		ll f = power(x,y/2LL) ; 
		return ((((f % MOD) * (f % MOD)) % MOD) * (x % MOD)) % MOD ; 
	}
}
ll dfs(ll index,ll curRemainder){ // DP state are the index of the current number and the remainder up to the current number
	if ( index == n ){
		if ( curRemainder == 5 ) return 1 ; 
		return 0 ; 
	}
	if ( dp[index][curRemainder] != -1 ) return dp[index][curRemainder] ; 
	ll ans = 0 ; 
	if ( s[index] != '?' ){
		ans += dfs(index+1, (curRemainder + (s[index]-'0')*power(10,index) ) % MOD) % M; 
	}
	else{
		for(ll i=0;i<10;i++){
			ans += dfs(index+1, (curRemainder + i % MOD * power(10,index) % MOD ) % MOD) % M ; 
		}
	}
	return dp[index][curRemainder] = ans % M; 
}
int main(){
    fastio
    memset(dp,-1,sizeof dp) ; 
    cin >> s ; 
    reverse(s.begin(),s.end()) ; 
    n = (ll) s.size() ; 
    cout << dfs(0,0) << endl;
    return 0 ;
}
