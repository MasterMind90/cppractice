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
const ll INF = 1e9 + 10 ;
vector<ll> solve(long long x){
    vector<ll> v(40) ;
    ll cur = 1 ;
    for(ll i = 0; i < 40; i++){
        ll len = (1LL << cur) ;
        ll t = x + 1 ;
        v[i] = t / len * (1LL << i) ;
        ll c = t % len - len / 2 ;
        if ( c >= 0 ) v[i] += c ;
        cur++ ;
    }
    return v ;
}

int main(){
    long long a , b ;
    cin >> a >> b ;
    vector<ll> y = solve(b) ;
    debug() << imie(y) ; 
    if ( a != 0 ){
        a--;
        vector<ll> x = solve(a);
        for(ll i = 0; i < 40; i++){
            y[i] -= x[i] ;
        }
    }
    long long ans = 0 ; 
    for(ll i = 0; i < 40; i++){
        if ( y[i] % 2 != 0 ) ans += (1LL << i) ; 
    }
    cout << ans << endl;
    return 0 ;
}
