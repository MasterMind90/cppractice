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
const ll INF = 1e18 + 10 ; 
const ll MAXN = 1e5 + 10 ; 
ll n , k;
vector<ll> v ; 
vector<ll> dp(MAXN,INF) ; 
ll dfs(int idx){
	if ( idx >= n-1 ){
		return 0 ; 
	}
	ll &res = dp[idx] ; 
	if ( res != INF ) return res ; 
	for(int i=1;i<=k;i++){
		if ( idx+i < n )
			res = min(res,dfs(idx+i) + abs(v[idx]-v[idx+i]));
	}
	return res ; 
}
int main(){
    fastio
    cin >> n >> k; 
    v.resize(n) ; 
    for(ll i=0;i<n;i++){
    	cin >> v[i] ; 
    }
    cout << dfs(0) << endl;
    return 0 ;
}
