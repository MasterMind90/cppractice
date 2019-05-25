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
	vector<ll> v(n) ;     
	vector<bool> mark(n) ;     
	for(ll &x : v){
		cin >> x ; 
	}
	sort(v.begin(),v.end());
	vector<pair<ll,ll> > choose(m) ; 
	for(ll i=0;i<m;i++){
		ll b , c ; 
		cin >> b >> c ; 
		choose.push_back({c,b}) ; 
	}
	sort(choose.rbegin(),choose.rend());
	debug() << imie(v) ; 
	debug() << imie(choose) ; 
	ll ans = 0 ; 
	ll cur = 0 ; 	
	for(ll i=0;i<n;i++){
		debug() << imie(ans) ; 
		for(ll j=0;j<choose[cur].second;j++){
			if ( i+j < n && v[i+j] < choose[cur].first ){
				ans += choose[cur].first ; 
				mark[i+j] = true ; 
				debug() << imie(mark) ; 
			}
			else{
				// maybe i = j - 1 ; 
				i = i+j ; 
				break ; 
			}
		}
		if ( cur < m ) 
			i = i + choose[cur].second - 1 ; 
		debug() << imie(i) ; 
		cur++ ; 
	}
	for(ll i=0;i<n;i++){
		if ( !mark[i] ) ans += v[i] ; 
	}
	cout << ans << endl;
    return 0 ;
}
