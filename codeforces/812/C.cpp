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
    int n , s ;
    cin >> n >> s ;
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
    	cin >> v[i] ;
    }
    int L = 0, R = n ;
    int ans = -1 ;
    int price = -1 ;
    while(L <= R){
    	int mid = L + (R - L) / 2 ;
    	vector<int> t ;
    	for(int i = 0; i < n; i++){
    		t.push_back(v[i] + mid * (i + 1)) ;
    	}
    	sort(t.begin(), t.end()) ;
    	int sum = 0 ;
    	for(int i = 0; i < mid; i++){
    		sum += t[i] ;
    	}
    	if ( sum <= s ){
    		price = sum ;
    		ans = mid ;
    		L = mid + 1; 
    	}
    	else R = mid - 1 ;
    }
    assert(ans != -1) ;
    if ( ans == 0 ) {
    	cout << 0 << ' ' << 0 << endl;
    	return 0 ;
    }
    cout << ans << ' ' << price << endl;
    return 0; 
}