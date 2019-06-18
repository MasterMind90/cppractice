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
using ll = long long ;
const long long INF = 1e18 ;
int main(){
	ll n , m , q ;
	cin >> n >> m >> q ;
	vector<ll> s(n+2) , t(m+2);
	for(ll i=1;i<=n;i++){
		cin >> s[i] ;
	}
	for(ll i=1;i<=m;i++){
		cin >> t[i] ;
	}
	s[0] = t[0] = -INF ;
	s[n+1] = t[m+1] = INF ;
	while(q--){
		ll x ;
		cin >> x ;
		ll a = lower_bound(s.begin(),s.end(),x) - s.begin() ;
		ll b = lower_bound(t.begin(),t.end(),x) - t.begin() ;
		ll ans = 1e18 ;
		for(ll i=a-1;i<=a;i++){
			for(ll j=b-1;j<=b;j++){
				ans = min({ans,abs(s[i]-x)+abs(s[i]-t[j]),abs(t[j]-x)+abs(t[j]-s[i])});
			}
		}
		cout << ans << endl;
	}

	return 0 ;
}


