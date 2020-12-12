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
signed main(){
    fastio
    int x , k ;
    cin >> x >> k ; 
    vector<int> v(4005) ;
    v[x] = 1 ;
    for(int i = 0; i < k; i++){
    	int c ;
    	cin >> c ; 
    	if ( c == 1 ) {
    		int a , b ;
    		cin >> a >> b ;
    		v[a] = 1 ;
    		v[b] = 1 ;
    	}
    	else {
    		int a ;
    		cin >> a ;
    		v[a] = 1 ;
    	}
    }
    int cnt = 0 ;
    int nix = 0 ;
    int nax = 0 ;
    for(int i = 1; i <= x; i++){
    	if ( v[i] != 0 ) {
    		nax += cnt  ;
    		nix += (cnt + 1) / 2 ;
    		cnt = 0 ;
    	}
    	else cnt++ ;
    }
    cout << nix << ' ' << nax << endl;
    return 0; 
}