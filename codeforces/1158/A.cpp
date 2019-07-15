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

int main(){
    fastio
    ll n , m ; 
    cin >> n >> m ; 
    vector<ll> b(n) , g(m) ; 
    ll nax = 0 ; 
    ll sum = 0 ; 
    for(ll i=0;i<n;i++){
    	cin >> b[i] ; 
    	nax = max(nax,b[i]) ; 
    }
    ll mix = 1e9 ; 
    for(ll i=0;i<m;i++){
    	cin >> g[i] ; 
    	mix = min(mix,g[i]) ; 
    	sum += g[i] ; 
    }
    if ( nax > mix ){
    	cout << -1 << endl;
    	return 0 ;
    }
    sort(b.begin(),b.end()) ; 
    sort(g.begin(),g.end()) ; 
    if ( b[n-1] != g[0] ){
    	sum += b[n-1] ; 
    	sum += (m-1)*b[n-2] ; 
    	for(ll i=0;i<n-2;i++){
    		sum += m*b[i] ; 
    	}
    }
    else{
    	for(ll i=0;i<n-1;i++){
    		sum += m*b[i] ; 
    	}
    }
    cout << sum << endl;
    return 0 ;
}
