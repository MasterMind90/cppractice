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
typedef long long ll;

int main(){
	ll n , m ; 
	cin >> n >> m ; 
	ll a , b ; 
	cin >> a >> b ; 
	ll k ;
	cin >> k ; 
	ll curx = a , cury = b ; 
	ll res = 0 ; 
	while(k--){
		ll x , y ; 
		cin >> x >> y ; 
		ll L = 1 , R = 1e9 ; 
		ll ans = -1 ; 
		while(L<=R){
			ll mid = L + (R-L)/2 ; 
			debug() << imie(mid) ; 
			ll c = curx+mid*x ; 
			ll t = cury+mid*y ; 
			if ( c >= 1 && c <= n && t >= 1 && t <= m ){
				ans = mid ; 
				L = mid + 1 ; 
			}
			else R = mid - 1 ; 
		}
		debug() << imie(ans) ; 
		if ( ans != -1 ){
			curx = curx + ans*x ; 
			cury = cury + ans*y ; 
			res += ans ; 
		}
		debug() << imie(curx) imie(cury) ;
	}
	cout << res << endl;
    return 0 ;
}
