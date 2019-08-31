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
const ll N = 2e5 + 10;
int main(){
    fastio
    ll n , k ; 
    cin >> n >> k ; 
    vector<ll> v(n) ; 
    vector<vector<ll> > cnt(N);
    for(ll i = 0; i < n; i++){
    	cin >> v[i] ; 
    	ll x = v[i] ; 
    	ll cur = 0 ;
    	while(x > 0){
    		cnt[x].push_back(cur) ;
    		x/=2;
    		cur++;
    	}
    }
    ll ans = 1e18;
    for(ll i = 0; i < N; i++){
    	ll m = cnt[i].size();
    	if ( m >= k ){
    		sort(cnt[i].begin(),cnt[i].end());
    		ll cur = 0 ;
    		for(ll j = 0; j < k; j++){
    			cur += cnt[i][j] ;
    		}
    		if ( m >= k ) ans = min(ans,cur) ;
    	}
    }
    cout << ans << endl;
    return 0 ;
}
