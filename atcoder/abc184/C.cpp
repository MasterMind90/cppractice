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
bool check(int a, int b, int x, int y){
    if ( a == x && b == y ){
    	return true ;
    }
    if ( a + b == x + y ) {
    	return true ;
    }
    if ( a - b == x - y ) {
    	return true ;
    }
    if ( abs(a - x) + abs(b - y) <= 3 ){
    	return true ;
    }
    return false ;
}
signed main(){
    fastio
    int a , b , x , y ; 
    cin >> a >> b >> x >> y ; 
    if ( a == x && b == y ){
    	cout << 0 << endl;
    	return 0 ;
    }
    if ( a + b == x + y ) {
    	cout << 1 << endl;
    	return 0 ;
    }
    if ( a - b == x - y ) {
    	cout << 1 << endl;
    	return 0 ;
    }
    if ( abs(a - x) + abs(b - y) <= 3 ){
    	cout << 1 << endl;
    	return 0 ;
    }
    int startx = a - 2, starty = b - 2  ; 
    for(int i = 0; i < 5; i++){
    	for(int j = 0; j < 5; j++){
    		if ( check(startx + i, starty + j, x, y) ){
    			cout << 2 << endl;
    			return 0 ;
    		}
    	}
    }
    if ( (a + b) % 2 == (x + y) % 2 ){
    	cout << 2 << endl ;
    	return 0 ;
    }
    else cout << 3 << endl;

    return 0; 
}