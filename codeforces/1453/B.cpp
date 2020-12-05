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
// so idea is set all to the first element 
// minus the biggest difference 
void solve() { 
	int n ;
	cin >> n ;
	vector<int> v(n) ;
	for(int i = 0; i < n; i++){
		cin >> v[i] ;
	}
	if ( n == 2  ) {
		cout << 0 << endl;
		return ;
	}
	vector<int> diff ;
	for(int i = 1; i < n; i++){
		diff.emplace_back(abs(v[i] - v[i - 1])) ;
	}
	int m = (int) diff.size() ;
	vector<int> pre(m) ;
	for(int i = 0; i < m; i++){
		if ( i == 0 ) pre[i] = diff[0] ;
		else pre[i] = pre[i - 1] + diff[i] ; 
	}
	vector<int> suf(m) ;
	for(int i = m - 1; i >= 0; i--){
		if ( i == m - 1 ) suf[i] = diff[i] ;
		else suf[i] = suf[i + 1] + diff[i] ;
	}
	// 99 96 97 95
	// 3 1 2
	// 3 4 6
	// 6 3 2
	auto getSuf = [&](int x) -> int{
		if ( x == m ) {
			return 0 ;
		}
		return suf[x] ; 
	};
	auto getPre = [&](int x) -> int{
		if ( x == 0 ) {
			return 0 ;
		}
		x-- ;
		return pre[x] ; 
	};
	int ans = INF ;
	// 3 5 20 23 
	// 0 1 2  3
	for(int i = 0; i < n; i++){
		if ( i == 0 ) {
			ans = min(ans, getSuf(i + 1)) ;
		}
		else if ( i == n - 1 ) {
			ans = min(ans, getPre(i - 1)) ;
		}
		else {
			ans = min(ans, getSuf(i + 1) + getPre(i - 1) + abs(v[i + 1] - v[i - 1])) ;
		}
	}
	cout << ans <<endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}