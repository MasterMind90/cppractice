#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define sim template < class c
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
~debug() { cerr << endl; }
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
typedef long long ll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 
ll f(ll x){
	return (x * (x + 1 ))/2;
}
int main(){
    fastio
    ll n , k ; 
    cin >> n >> k ; 
    ll L = 1 , R = n ; 
    ll ans = -1 ; 
    ll nax = 0 ; 
    while(L<=R){
    	ll mid = L + (R-L) / 2 ;
    	debug() << imie(mid) imie(f(mid));
    	if ( f(mid) - (n-mid) >= k && n-mid >= nax ){
    		ans = mid ; 
    		nax = (n-mid) ;
    		R = mid - 1 ;
    	}
    	else L = mid + 1 ;
    }
    if ( ans == -1 ) {
    	cout << 0 << endl;
    }
    else 
    cout << nax << endl;
    return 0 ;
}
