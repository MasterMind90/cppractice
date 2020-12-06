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
vector<vector<char> > t ;
bool ok(vector<vector<char> > &v){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if ( v[i][j] == 'X' ) {
				if ( j > 1 && v[i][j - 1] == 'X' && v[i][j - 2] == 'X' ) return false ;
				if ( i > 1 && v[i - 1][j] == 'X' && v[i - 2][j] == 'X' ) return false ;
			}
			if ( v[i][j] == 'O' ) {
				if ( j > 1 && v[i][j - 1] == 'O' && v[i][j - 2] == 'O' ) return false ;
				if ( i > 1 && v[i - 1][j] == 'O' && v[i - 2][j] == 'O' ) return false ;
			}
		}
	}
	return true ;
}
void solve(){
	cin >> n ;
	vector<vector<int> > g(n, vector<int>(n)) ;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			g[i][j] = (i + j) % 3 ;
		}
	}
	for(auto p : g){
		debug() << imie(p) ;
	}
	t = vector<vector<char> > (n, vector<char>(n)) ;
	int k = 0 ; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> t[i][j] ;
			k += t[i][j] != '.' ;
		}
	}
	// dfs(0, 0, k / 3, 2, 2, 2, 2) ;
	for(int c = 0; c < 3; c++){
		vector<vector<char> > v = t ;
		int cnt = 0 ;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if ( (i + j) % 3 == c ) {
					if ( v[i][j] == 'X' ) {
						v[i][j] = 'O' ;
						cnt++ ;
					}
				}
			}
		}
		auto same = [&](int x, int y) -> bool{
			if ( x > 1 ) {
				if ( v[x - 1][y] == 'X' && v[x - 2][y] == 'X' ) return true ;
			}
			if ( x + 2 < n ) {
				if ( v[x + 1][y] == 'X' && v[x + 2][y] == 'X' ) return true ;
			}
			if ( y > 1 ) 
				if ( v[x][y - 1] == 'X' && v[x][y - 2] == 'X' ) return true ;
			if ( y + 2 < n ) 
				if ( v[x][y + 1] == 'X' && v[x][y + 2] == 'X' ) return true ;
			if ( x > 0 && x + 1 < n ){
				if ( v[x - 1][y] == 'X' && v[x + 1][y] == 'X' ) return true ;
			}
			if ( y > 0 && y + 1 < n ) {
				if ( v[x][y - 1] == 'X' && v[x][y + 1] == 'X' ) return true ;
			}
			return false ;
		};
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if ( (i + j) % 3 == c ) {
					if ( v[i][j] == 'O' && same(i, j) ) {
						continue ;
					}
					else if ( v[i][j] == 'O' ) {
						v[i][j] = 'X' ;
						cnt-- ;
					}
				}
			}
		}
		debug() << imie(c) imie(cnt) ;
		if ( ok(v) ) {
			debug() << imie(c) imie(cnt) ;
			if ( cnt <= k / 3 ) {
				for(int i = 0; i < n; i++){
					for(int j = 0; j < n; j++){
						cout << v[i][j] ;
					}
					cout << endl;
				}
				return ;
			}
		}
	}
	assert(false) ;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}

// XXOX
// XOXX
// OXXO
// XXOX

// XXOXXO
// XOXXOX
// OXXOXX
// XXOXXO
// XOXXOX
// OXXOXX

// 36 / 3

// XOXX
// XXOX
// XXXO
// OXXX

// XOXX
// XXOX
// OXXO
// XOXX

// OXX
// XOX
// XX.

// XXOXX
// XXOXX
// OXOXO
// XXOXX
// XXOXX



// XXXX
// XXXX
// XXXX
// XXXX

// XXXXX
// OXXX
// XXOX
// OXXO
// XOXX

// XOXX
// XXOX
// OXXO
// XOXX