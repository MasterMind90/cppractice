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
    ll q ; 
    cin >> q ; 
    while(q--){
    	ll k , n , a , b ; 
    	cin >> k >> n >> a >> b ; 
    	ll L = 0 , R = n ; 
    	ll ans = -1 ; 
    	while(L<=R){
    		ll mid = L + (R-L) / 2 ; 
    		bool flag = false ; 
    		ll turns = 0 ; 
    		ll cur = k ; 
    		debug() << imie(a) imie(mid) ; 
    		if ( mid * a < cur ){
    			turns += mid ; 
    			cur -= mid * a ; 
    			turns += (cur-1) / b ; 
    			if ( turns >= n ) flag = true ; 
    		}
    		debug() << imie(turns) ;
    		if ( flag ) {
    			ans = mid ; 
    			L = mid + 1 ; 
    		}
    		else R = mid - 1 ; 
    	}
    	cout << ans << endl;
    }

    return 0 ;
}
