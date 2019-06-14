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
	vector<int> v(n+1) ; 
	for(int i=1;i<=n;i++){
		cin >> v[i] ; 
	}
	int cnt = 0 ; 
	int ans = 0 ; 
	for(int i=1;i<=n;i++){
		if ( i == v[i] ){
			cnt++ ; 
			while(i+1<=n && v[i+1] == i+1 ){
				cnt++ ; 
				i++ ; 
			}
		}
		else{
			ans += (cnt+1)/2 ; 
			cnt = 0 ; 
		}
		debug() << imie(cnt) ; 
	}
	if ( cnt ){
		ans += (cnt+1)/2 ; 
	}
	cout << ans << endl;

    return 0 ;
}
