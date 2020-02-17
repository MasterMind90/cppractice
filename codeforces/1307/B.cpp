#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define int long long
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << '\n'; }
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
const ll MOD = 1e9 + 7 ;
const ll N = 1e5 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    int n , x ;
    cin >> n >> x ; 
    vector<int> v(n) ; 
    bool ok = false ;
    bool greater = false ;
    int nax = 0 ; 
    for(int i = 0; i < n; i++){
        cin >> v[i] ; 
        nax = max(nax, v[i]);
        if ( v[i] == x ) ok = true ; 
        if ( v[i] > x ) greater= true ; 
    }
    if ( ok ){
        cout << 1 << endl;
        return ; 
    }
    if ( greater ){
        cout << 2 << endl;
        return ; 
    }
    int ans = (x + nax - 1) / nax ;
    cout << ans << endl;
}
signed main(){
    fastio
    int q ; 
    cin >> q ;
    while(q--) solve() ; 
    return 0 ;
}