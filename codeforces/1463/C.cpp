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
	vector<int> t(n) , x(n) ;
	for(int i = 0; i < n; i++){
		cin >> t[i] >> x[i] ;
	}
	int robot = 0 ;
	// want to know at time x[i] where is the robot .
	// at what time was the robot at x[i] 
	int ans = 0 ;
	int a = 0 , b = 0 ;
	int L = 0 , R = 0 ;
	for(int i = 0; i < n; i++){
		if ( t[i] >= b ) {
			int time = t[i] + abs(x[i] - robot) ;
			a = t[i] ;
			b = t[i] + abs(x[i] - robot) ;
			L = robot , R = x[i] ;
			debug() << "===" imie(a) imie(b) imie(L) imie(R) imie(time) ;
			robot = x[i] ;
			if ( i + 1 < n && time >= t[i] && time <= t[i + 1] ) {
				ans++ ;
			}
			if ( i + 1 == n && time >= t[i] ) {
				ans++ ;
			}
		}
		else {
			// 0 - 5 -> 1 - 6
			debug() << imie(t[i]) imie(x[i]) ;
			debug() << "posi: " imie(L) imie(R) ;
			debug() << "time: " imie(a) imie(b) ;
			debug() << "Before : " imie(ans) ;
			if ( L < R ){
				if ( x[i] >= L && x[i] <= R ){
					int time = a + (x[i] - L) ;
					debug() << imie(time) ;
					if ( i + 1 < n && time >= t[i] && time <= t[i + 1] ) {
						ans++ ;
					}
					if ( i + 1 == n && time >= t[i] ) {
						ans++ ;
					}
				}
			}
			else {
				if ( x[i] >= R && x[i] <= L ){
					int time = a + abs(x[i] - L) ;
					debug() << imie(time) ;
					if ( i + 1 < n && time >= t[i] && time <= t[i + 1] ) {
						ans++ ;
					}
					if ( i + 1 == n && time >= t[i] ) {
						ans++ ;
					}
				}
			}
			debug() << "After : " imie(ans) ;
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