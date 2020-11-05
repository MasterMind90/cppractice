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
// const ll MOD = 1e9 + 7 ;
const ll MOD = 998244353 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    int n , m ;
    cin >> n >> m ;
    vector<int> a(n) ;
    for(int i = 0; i < n; i++){
        cin >> a[i] ;
    }
    debug() << imie(a) ;
    vector<pair<int,int> > adj(n + 1) ;
    for(int i = 0; i < n; i++){
        if ( i == 0 ) {
            if ( n == 1 ) {
                adj[a[i]] = make_pair(0, 0) ;
            }
            else {
                adj[a[i]] = make_pair(0, a[i + 1]) ;
            }
        }
        else if ( i == n - 1 ){
            adj[a[i]] = make_pair(a[i - 1], 0) ;
        }
        else{
            adj[a[i]] = make_pair(a[i - 1], a[i + 1]) ;
        }
        
    }
    debug() << imie(adj) ;
    vector<int> b(m) ;
    vector<int> can(n + 1, true) ;
    can[0] = false ;
    for(int i = 0; i < m; i++){
        cin >> b[i] ;
        can[b[i]] = false ;
    }
    debug() << imie(b) ;
    int ans = 1 ;
    for(int i = 0; i < m; i++){
        int &before = adj[b[i]].first ;
        int &after = adj[b[i]].second ;
        // 1 4 7 3 6 2 5
        // 3 2 4 5
        debug() << imie(b[i]) ;
        debug() << imie(can[before]) ;
        debug() << imie(can[after]) ;
        if ( can[before] && can[after] ) {
            adj[before].second = after ;
            adj[after].first = before ;
            // adj[before].second = b[i] ;
            // adj[after].first = b[i] ;
            ans *= 2 ;
        }
        else if ( can[before] ) {
            adj[adj[before].first].second = b[i] ;
        }
        else if ( can[after] ) {
            adj[adj[after].second].first = b[i] ;
        }
        else {
            ans = 0 ;
        }
        ans %= MOD ;
        debug() << imie(ans) ;
        can[b[i]] = true ;
        debug() << imie(adj) ;
    }
    debug() << imie(adj) ;
    cout << ans << endl;
}
signed main(){
    fastio
    int t; 
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}