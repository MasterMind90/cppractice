#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sim template < class c
#define int long long
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
typedef tree< pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    vector<int> a(3) ;
    vector<int> b(3) ;
    for(int i = 0; i < 3; i++){
        cin >> a[i] ;
    }
    for(int i = 0; i < 3; i++){
        cin >> b[i] ;
    }
    // 3 5
    int nix = min(a[2], b[1]) ;
    int ans = nix * 2;
    a[2] -= nix ;
    b[1] -= nix ;
    if ( b[1] != 0 ) {
        int c = min(b[1], a[1]) ;
        b[1] -= c ;
        a[1] -= c ;
    }
    if ( b[1] != 0 ){
        int c = min(b[1], a[0]) ;
        b[1] -= c ;
        a[0] -= c ;
    }
    if ( b[2] != 0 ){
        int c = min(b[2], a[0]) ;
        b[2] -= c ;
        a[0] -= c ;
        c = min(a[2], b[2]) ;
        a[2] -= c ;
        b[2] -= c ;
        ans -= b[2] * 2 ;
    }
    cout << ans << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}