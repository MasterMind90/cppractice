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
    int a , b ;
    cin >> a >> b ;
    int two1 = 0 ;
    int three1 = 0 ;
    int five1 = 0 ;
    while(a % 2 == 0){
    	a /= 2 ;
    	two1++ ;
    }
    while(a % 3 == 0){
    	a /= 3 ;
    	three1++ ;
    }
    while(a % 5 == 0){
    	a /= 5 ;
    	five1++ ;
    }
    int two2 = 0 ;
    int three2 = 0 ;
    int five2 = 0 ;
    while(b % 2 == 0){
    	b /= 2 ;
    	two2++ ;
    }
    while(b % 3 == 0){
    	b /= 3 ;
    	three2++ ;
    }
    while(b % 5 == 0){
    	b /= 5 ;
    	five2++ ;
    }
    if ( a == b ) {
	    int ans = abs(two2 - two1) ;
	    ans += abs(three2 - three1) ;
	    ans += abs(five2 - five1) ;
	    cout << ans << endl;
    }
    else cout << -1 << endl;
    return 0; 
}