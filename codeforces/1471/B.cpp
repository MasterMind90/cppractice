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
	int n , x ;
	cin >> n >> x ;
	vector<int> v(n) ;
	int index = -1 ;
	for(int i = 0; i < n; i++){
		cin >> v[i] ;
	}
	for(int i = 0; i < n; i++){
		if ( v[i] % x != 0 ) {
			index = i ;
			break ;
		}
	}
	int ans = 0 ;
	// if ( index != -1 ) {
	// 	for(int i = 0; i < index; i++){
	// 		if ( v[i] % x == 0 ) {
	// 			ans += 2 * v[i] ;
	// 		}
	// 	}
	// 	for(int i = index; i < n; i++){
	// 		ans += v[i] ;
	// 	}
	// 	cout << ans << endl ;
	// 	return ;
	// }
	vector<int> cnt(n, 1) ;
	bool ok = false ;
	for(int i = 0; i < 32; i++){
		debug() << imie(v) ;
		debug() << imie(cnt) ;
		for(int j = 0; j < n; j++){
			if ( v[j] % x == 0 ) {
				ans += cnt[j] * v[j] ;
				// ans += (v[j] / cnt[j]) * 2 ;
				cnt[j] *= x ;
				v[j] /= x ;
			}
			else {
				debug() << imie(j) imie(ans) ;
				for(int k = 0; k < n; k++){
					ans += cnt[k] * v[k] ;
					// ans += v[k] / cnt[k] ;
				}
				ok = true ;
				break ;
			}
		}
		if ( ok ) break ;
	}
	cout << ans << endl;
	// for(int i = 0; ; i++){
	// 	i %= n ;
	// 	if ( v[i] % x == 0 ) {
	// 		ans += cnt[i] * v[i] ;
	// 		cnt[i] *= x ;
	// 		v[i] /= x ;
	// 	}

	// }

	// 8 6
	// 8 6
	// 2 => 4
	// 2 => 
	// 8 6 4 4 3 3
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}