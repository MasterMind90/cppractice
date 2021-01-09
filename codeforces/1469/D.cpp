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
void solve(){
	int n ;
	cin >> n ;
	if ( n == 3 ) {
		cout << 2 << endl;
		cout << 3 << ' ' << 2 << endl;
		cout << 3 << ' ' << 2 << endl;
		return ;
	}
	vector<pair<int,int> > ans ;
	for(int i = 3; i < n; i++){
		if ( i == 10 ) continue ;
		if ( i == 100 ) continue ;
		ans.emplace_back(i, i + 1) ;
	}
	if ( n > 100 ) {
		int last = n ;
		while(last != 1){
			ans.emplace_back(n, 100) ;
			last = (last + 99) / 100 ;
		}
		last = 100 ;
		while(last != 1){
			ans.emplace_back(100, 10) ;
			last = (last + 9) / 10 ;
		}
		last = 10 ;
		while(last != 1){
			ans.emplace_back(10, 2) ;
			last = (last + 1) / 2 ;
		}
	}
	else if ( n > 10 ){
		int last = n ;
		while(last != 1){
			ans.emplace_back(n, 10) ;
			last = (last + 9) / 10 ;
		}
		last = 10 ;
		while(last != 1){
			ans.emplace_back(10, 2) ;
			last = (last + 1) / 2 ;
		}
	}
	else {
		int last = n ;
		while(last != 1){
			ans.emplace_back(n, 2) ;
			last = (last + 1) / 2 ;
		}
	}
	assert((int)ans.size() <= n + 5) ;
	cout << ans.size() << endl;
	for(auto &p : ans){
		cout << p.first << ' ' << p.second << endl;
	}
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}