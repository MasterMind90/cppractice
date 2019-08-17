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
const ll INF = 1e18 + 10 ; 
int main(){
    fastio
    ll n ;
    cin >> n ; 
    vector<ll> v(n+1) ; 
    for(ll i=1;i<=n;i++){
    	cin >> v[i] ; 
    }
    ll dp[n+1] ; // the minimum cost up the current stone
    for(ll i=0;i<=n;i++){
    	dp[i] = INF ; 
    }
    dp[0] = dp[1] = 0 ; 
    dp[2] = abs(v[2]-v[1]) ;
    for(ll i=3;i<=n;i++){
    	dp[i] = min(abs(v[i]-v[i-1])+dp[i-1],abs(v[i]-v[i-2])+dp[i-2]);
    }
    cout << dp[n] << endl;
    return 0 ;
}
