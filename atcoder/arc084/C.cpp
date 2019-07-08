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
	ll n ;
	cin >> n ;
	vector<ll> a(n) ,b(n) , c(n) ;
	for(ll i=0;i<n;i++){
		cin >> a[i] ;
	}
	for(ll i=0;i<n;i++){
		cin >> b[i] ;
	}
	for(ll i=0;i<n;i++){
		cin >> c[i] ;
	}
	sort(a.begin(),a.end()) ;
	sort(b.begin(),b.end()) ;
	sort(c.begin(),c.end()) ;
	ll ans = 0 ;
	for(ll i=0;i<n;i++){
		ll index1 = lower_bound(a.begin(),a.end(),b[i]) - a.begin() ;
		ll index2 = upper_bound(c.begin(),c.end(),b[i]) - c.begin() ;
		debug() << imie(index1) imie(index2) ;
		ans += index1 * (n-index2) ;
	}
	cout << ans << endl;
	return 0 ;
}
/*
1 2 3 4 4 5 6 7 8
0 1 2 3
*/
