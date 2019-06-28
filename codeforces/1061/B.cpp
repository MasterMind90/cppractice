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
    fastio
    ll n , m ; 
    cin >> n >> m ; 
    vector<ll> v(n+1) ; 
    ll nax = 0 ; 
    ll sum = 0 ; 
    for(ll i=1;i<=n;i++){
    	cin >> v[i] ; 
    	sum += v[i] ; 
    	nax = max(nax,v[i]) ; 
    }
    sort(v.begin(),v.end());
    ll lastRow = 1;
    ll cnt = 0 ; 
    for(ll i=1;i<=n;i++){
    	if ( v[i] >= lastRow ){
    		cnt++; 
    		lastRow++;
    	}
    	else{
    		cnt++;
    	}
    }
    debug() << imie(sum) imie(lastRow) imie(cnt);
    ll ans = sum - (nax - lastRow+1 + cnt) ; 
    cout << ans << endl;
    return 0 ;
}
