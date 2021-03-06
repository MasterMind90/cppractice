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
    ll t ; 
    cin >> t ;
    while(t--){
        ll n ; 
        cin >> n ; 
        vector<ll> v(n) ; 
        vector<ll> left(n + 1) ; 
        vector<ll> right(n + 1) ; 
        ll sum = 0 ; 
        for(ll i = 0; i < n; i++){
            cin >> v[i] ; 
            sum += v[i] ; 
        }
        for(ll i = 0; i < n; i++){
            left[i + 1] = left[i] + v[i] ; 
        }
        for(ll i = n - 1; i >= 0; i--){
            right[i] = right[i + 1] + v[i];
        }
        debug() << imie(left) ;
        debug() << imie(right) ;
        ll nax = -INF ; 
        for(ll i = 1; i <= n; i++){
            nax = max({nax,left[i - 1], right[i]});
        }
        if ( nax >= sum ) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0 ;
}