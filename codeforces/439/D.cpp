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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 

int main(){
    fastio
    ll n , m ; 
    cin >> n >> m ; 
    vector<ll> a(n) , b(m) ; 
    for(ll i = 0; i < n; i++){
    	cin >> a[i] ; 
    }
    for(ll i = 0; i < m; i++){
    	cin >> b[i] ;
    }
    sort(a.begin(),a.end()) ; 
    sort(b.begin(),b.end()) ; 
    vector<ll> x(n + 1) , y(m + 1) ; 
    for(ll i = 0; i < n; i++){
    	x[i + 1] = x[i] + a[i] ; 
    }
    for(ll i = 0; i < m; i++){
    	y[i + 1] = y[i] + b[i] ; 
    }
    auto solve = [&](ll mid){
    	ll first = lower_bound(a.begin(),a.end(), mid) - a.begin() ;
    	ll cnt = mid * first - x[first] ; 
    	//debug() << imie (mid) imie(first) imie(cnt) ; 
    	ll second = upper_bound(b.begin(),b.end(),mid) - b.begin() ; 
    	cnt += (y[m] - y[second]) - (m - second) * mid  ; 
    	//debug() << imie(mid) imie(second) imie(cnt) ; 
    	return cnt ; 
    };
    ll L = 0, R = 1e9 + 10 ;
    ll ans = 1e18;
    while(L<=R){
    	ll mid = L + (R - L) / 2;
    	ll midPoint = solve(mid);
    	ll after = solve(mid + 1); 
    	debug() << imie(mid) imie(midPoint) imie(after);
    	ans = min(ans,min(midPoint,after));
    	if ( midPoint > after ){
    		L = mid + 1 ;
    	}
    	else R = mid - 1 ;
    }
    cout << ans << endl;
    return 0 ;
}
