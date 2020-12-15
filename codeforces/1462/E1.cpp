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
	vector<int> v(n) ;
	vector<int> pos[n + 5] ;
	for(int i = 0; i < n; i++){
		cin >> v[i] ;
		pos[v[i]].emplace_back(i) ;
	}
	auto get = [&](int val, int L, int R) -> unsigned long long{
		if ( val <= 0 ) return 0 ;
		if ( val > n ) return 0 ;
		if ( pos[val].empty() ) return 0 ;
		vector<int> &t = pos[val] ;
		debug() << imie(val) imie(t) ;
		return upper_bound(t.begin(), t.end(), R) - lower_bound(t.begin(), t.end(), L) ;
	};
	unsigned long long ans = 0 ;
	for(int i = 1; i < n - 1; i++){
		debug() << imie(i) ;
		// case one: all equal 
		int val = v[i] ;
		set<pair<int,int> > s ;
		for(int j = val - 2; j <= val + 2; j++){
			for(int k = val - 2; k <= val + 2; k++){
				if (s.count(make_pair(j, k))) continue ;
				vector<int> t ;
				t.emplace_back(val) ;
				t.emplace_back(j) ;
				t.emplace_back(k) ;
				sort(t.begin(), t.end()) ;
				if ( t.back() - t.front() <= 2 ) {
					s.emplace(j, k) ;
					ans += get(j, 0, i - 1) * get(k, i + 1, n - 1) ;
				}
			}
		}
	}
	cout << ans << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}