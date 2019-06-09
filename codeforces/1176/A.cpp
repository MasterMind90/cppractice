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
	int n ; 
	cin >> n ; 
	while(n--){
		ll x ; 
		cin >> x ; 
		int cnt = 0 ; 
		while(x!=1){
			bool f = false ; 
			if ( x % 2 == 0 ) {
				x = x / 2 ; 
				cnt++ ; 
				f = true ; 
			}
			else if ( x % 3 == 0 ){
				x = 2*x / 3 ; 	
				cnt++ ; 
				f = true ; 
			}
			else if ( x % 5 == 0 ) {
				x = 4*x / 5 ; 
				cnt++ ; 
				f = true ; 
			}
			if ( !f ) break ; 
		}
		if ( x != 1 ) {
			cout << -1 << endl;
		}
		else cout << cnt << endl;
	}
    return 0 ;
}
