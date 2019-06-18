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
const ll MAXN = 200000 + 10 ; 
vector<ll> sum(MAXN) ; 
vector<ll> ans(MAXN) ; 
int main(){
	ll n , k , q ; 
	cin >> n >> k >> q ; 
	for(ll i=0;i<n;i++){
		ll l , r ; 
		cin >> l >> r ; 
		sum[l] += 1 ;
		sum[r+1] -= 1 ;
	}
	for(ll i=1;i<MAXN;i++){
		sum[i] += sum[i-1] ; 
	}
	for(ll i=1;i<MAXN;i++){
		if ( sum[i] >= k ){
			ans[i] = 1 ; 
		}
		ans[i] += ans[i-1] ; 
	}
	for(ll i=1;i<=100;i++){
		debug() << imie(i) imie(ans[i]) ; 
	}
	while(q--){
		ll l , r ; 
		cin >> l >> r ; 
		cout << ans[r] - ans[l-1] << endl;
	}
    return 0 ;
}
