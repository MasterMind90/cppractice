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
	int n , m ;
	cin >> n >> m ;
	vector<vector<char> > v(n + 2, vector<char>(m + 2, '.')) ;
	vector<vector<int> > sum(n + 1, vector<int>(m + 1));
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < m + 1; j++){
			cin >> v[i][j] ;
			if ( v[i][j] == '*' ) {
				sum[i][j] = 1 ;
			}
		}
	}
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < m + 1; j++){
			sum[i][j] += sum[i][j - 1] ;
		}
	}
	int ans = 0 ;
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < m + 1; j++){
			if ( v[i][j] == '*' ) {
				ans++ ;
				int start = 1 ;
				int c = 3 ;
				for(int k = i + 1; k < n + 1; k++){
					if ( !(j + start <= m && j - start >= 1) ) break;
					int cnt = sum[k][j + start] - sum[k][j - start - 1] ;
					debug() << imie(cnt) ;
					if ( cnt != c ) {
						break ;
					}
					ans++ ;
					c += 2; 
					start++ ;
				}
			}
		}
	}
	cout << ans << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t;
    while(t--) solve() ;
    return 0; 
}