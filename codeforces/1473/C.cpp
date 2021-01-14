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
/*
n = 4, k = 3 ;

a => 1 2 3 2

I need to find permutation p such as b[i] = p[a[i]] 

inversions of b <= inversions of a 


P : permutation of size k 

Let say p : 1 2 3

b => 1 2 3 2 


Let say p : 3 2 1
b => 3 2 1 2 

n = 4 , k = 1 invalid k <= n < 2k

n = 4 , k = 3

n = 5, k = 3

*/
void solve(){
	int n , k ;
	cin >> n >> k ;
	int till = k - (n - k) ;
	int len = k - till ;
	vector<int> p ;
	for(int i = 0; i < k; i++){
		p.push_back(i + 1) ;
	}
	debug() << imie(len) ;
	debug() << imie(p) ;
	reverse(p.begin() + (k - 1) - len, p.end()) ;
	debug() << imie(p) ;
	for(int &c : p){
		cout << c << ' ' ;
	}
	cout << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}
