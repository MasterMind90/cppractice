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

int main(){
	int n , k ;
	cin >> n >> k ;
	vector<int> L,R ;
	L.push_back(0) ;
	R.push_back(0) ;
	for(int i=0;i<n;i++){
		int x ;
		cin >> x ;
		if ( x <= 0 ) L.push_back(x) ;
		else R.push_back(x) ;
	}
	sort(L.rbegin(),L.rend()) ;
	debug() << imie(L) ;
	debug() << imie(R) ;
	int a = (int)L.size() ;
	int b = (int)R.size() ;
	ll ans = 1e18 ;
	for(int i=0;i<=k;i++){
		if ( i < a ){
			int r = k - i ;
			if ( r < b ){
				if ( r == 0 ) {
					ans = min(ans,L[i]*-1LL);
				}
				else{
					ans = min(ans,L[i]*-1*2LL+R[r]);
				}
			}
		}
		debug() << imie(ans) ;
	}
	for(int i=0;i<=k;i++){
		if ( i < b ){
			int l = k - i ;
			if ( l < a ){
				if ( l == 0 ) {
					ans = min(ans,R[i]*1LL);
				}
				else{
					ans = min(ans,R[i]*1*2LL+L[l]*-1LL);
				}
			}
		}
		debug() << imie(ans) ;
	}

	cout << ans << endl;
	return 0 ;
}
