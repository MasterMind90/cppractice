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
    vector<pair<ll,ll> > v(n) ; 
    for(ll i=0;i<n;i++){
    	cin >> v[i].first >> v[i].second ; 
    }
    sort(v.begin(),v.end());
    debug() << imie(v) ; 
    ll ans = 0 ; 
    for(auto p : v){
    	if ( m > 0 ) {
    		ll c = min(m,p.second);
    		ans += c*p.first ; 
    		m -= c ; 
    	}
    }
    cout << ans << endl;
    return 0 ;
}
