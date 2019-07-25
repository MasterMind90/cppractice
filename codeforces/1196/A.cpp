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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 
void solve(){
	vector<ll> v(3) ; 
	for(int i=0;i<3;i++){
		cin >> v[i] ; 
	}
	sort(v.begin(),v.end()) ; 
	ll a = v[0] , b = v[1] , c = v[2] ; 
	ll r = min(c,b-a);
	c -= r ; 
	a += r ; 
	a += c / 2 ; 
	ll ans = a ; 
	a = v[1] , b = v[2] , c = v[0] ; 
	r = min(c,(b-a));
	c -= r ;
	a += r ; 
	if ( a == b ){
		a += c / 2 ; 
		ans = max(ans,a) ; 
	}
	cout << ans << endl;
}
int main(){
    fastio
    int t ;
    cin >> t ; 
    while(t--){
    	solve() ; 
    }
    return 0 ; 
}