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
int main(){
	fastio
	string s ;
	cin >> s ;
	int n = (int) s.size() ;
	int both = 0;
	bool first = false ;
	bool second = false;
	for(int i=0;i+2<=n;i++){
		debug() << imie(i) imie(s[i]) ;
		if ( i + 3 <= n && s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'A' ) both++ , i += 2 ;
		else if ( i + 3 <= n && s[i] == 'B' && s[i+1] == 'A' && s[i+2] == 'B' ) both++ , i += 2 ;
		else if ( s[i] == 'A' && s[i+1] == 'B' ){
			first = true , i++ ;
		}
		else if ( s[i] == 'B' && s[i+1] == 'A' ) second = true , i++;

	}
	if ( first && second ){
		cout << "YES" << endl;
	}
	else if ( first && both ){
		cout << "YES" << endl;
	}
	else if ( second && both ){
		cout << "YES" << endl;
	}
	else if ( both > 1 ){
        cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0 ;
}
