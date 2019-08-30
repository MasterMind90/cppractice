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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 

int main(){
    fastio
    int t ;
    cin >> t ;
    while(t--){
    	ll n , m ; 
    	cin >> n >> m ; 
    	vector<ll> v ; 
    	v.push_back(m%10) ; 
    	ll sum = v[0] ; 
    	for(ll i = m+m; ; i+=m){
    		if ( i % 10 == v[0] ) break ;
    		v.push_back(i%10) ; 
    		sum += (i % 10) ; 
    	}
    	debug() << imie(v) ; 
    	debug() << imie(sum) ;
    	ll tt = (ll) v.size() ;
    	ll div = n / m ; 
    	debug() << imie(div) ;
    	ll c = div / tt ; 
    	debug() << imie(c) ;
    	ll rem = div % tt ;
    	debug() << imie(rem) ;
    	ll ans = c * sum;
    	debug() << imie(ans) ;
    	for(ll i=0;i<rem;i++){
    		ans += v[i] ;
    	}
    	cout << ans << endl;
    }
    return 0 ;
}
