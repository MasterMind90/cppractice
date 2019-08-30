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
    ll n , k ; 
    cin >> n >> k ; 
    vector<ll> v(n) ; 
    ll nax = 0 ; 
    for(ll i = 0; i < n; i++){
    	cin >> v[i] ; 
    	nax = max(nax,v[i]) ; 
    }
    ll res = 1e18 + 10 ;
    for(ll i = 0; i <= nax; i++){
    	ll can = 0 ; 
    	ll ans = 0 ; 
    	vector<int> tmp ; 
    	for(ll j = 0; j < n; j++){
    		ll cur = v[j] ; 
    		ll cnt = 0 ; 
    		bool ok = false ;
    		while(cur >= i){
    			if ( cur == i ){
    				ok = true ;
    				break;
    			}
    			cur /= 2 ;
    			cnt++;
    		}
    		if ( ok ){
    			can++ ; 
    			tmp.push_back(cnt) ;
    		}
    	}
    	sort(tmp.begin(),tmp.end()) ;
    	debug() << imie(tmp) ;
    	bool flag = false ;
    	for(int j = 0; j < can; j++){
    		if ( j + 1 >= k ){
    			ans += tmp[j] ; 
    			flag = true ;
    			break;
    		}
    		ans += tmp[j] ; 
    	}
    	if ( flag )
    		res = min(res,ans) ;
    }
    cout << res << endl;
    return 0 ;
}
