#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
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

int main(){
    fastio
    ll n , k ; 
    cin >> n >> k ; 
    vector<ll> a(n) , b(n) ; 
    ll total = 0 ; 
    for(ll i=0;i<n;i++){
    	cin >> a[i] ; 
    	total += a[i] ; 
    }
    for(ll i=0;i<n;i++){
    	cin >> b[i] ; 
    }
    ll L = 1 , R = (ll)1e9 ; 
    ll ans = -1 ;
    ll current = 0 ; 
    while(L<=R){
    	ll mid = L + (R-L) / 2 ; 
    	debug() << imie(mid) ;
    	ll curk = 0 ; 
    	for(ll i=0;i<n;i++){
    		if ( mid*a[i] > b[i] ){
    			curk += mid*a[i] - b[i] ; 
    		}
    		if ( curk > k ) {
    			break; 
    		}
    	}
    	if ( curk <= k ){
    		ans = mid ; 
    		current = curk ; 
    		L = mid + 1 ; 
    	}
    	else R = mid - 1 ; 
    }
    if ( ans == -1 ){
    	cout << 0 << endl;
    	return 0 ; 
    }
    ans += (k - current) / total ;
    cout << ans << endl;

    return 0 ;
}
