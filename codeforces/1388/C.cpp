#ifndef LOCAL
#pragma GCC optimize("O3")
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
int n , m ;
vector<vector<int> > g ;
vector<int> h ;
vector<int> v ;
vector<int> sz ;
vector<int> good;
vector<int> bad;
void dfs1(int x, int p = -1){
    sz[x] = v[x];
    for(int &c : g[x]){
        if ( c == p ) continue ;
        dfs1(c, x) ;
        sz[x] += sz[c] ;
    }

}
bool ok = true ;
void dfs2(int x, int p){
    int sum = 0 ;
    for(int &c : g[x]){
        if ( c == p ) continue ;
        sum += good[c] ;
        dfs2(c, x) ; 
    }
    if ( sum > good[x] ) ok = false ;
}
void solve(){
    cin >> n >> m ;
    g = vector<vector<int> >(n) ;
    v = vector<int>(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    h = vector<int>(n) ;
    for(int i = 0; i < n; i++){
        cin >> h[i] ;
    }
    sz = vector<int>(n) ;
    for(int i = 0; i < n - 1; i++){
        int a , b ;
        cin >> a >> b ; 
        a--, b-- ; 
        g[a].emplace_back(b) ;
        g[b].emplace_back(a) ;
    }
    dfs1(0) ;
    ok = true ;
    good = vector<int>(n) ;
    bad = vector<int>(n) ;
    for(int i = 0; i < n; i++){
        good[i] = (h[i] + sz[i]) ;
        if ( good[i] % 2 != 0 ) ok = false ;
        good[i] /= 2 ;
        bad[i] = (sz[i] - h[i]) ;
        if ( bad[i] % 2 != 0 ) ok = false ;
        bad[i] /= 2 ;
        if ( good[i] + bad[i] != sz[i] ) ok = false ;
        if ( good[i] < 0 || bad[i] < 0 ) ok = false ;
    }
    dfs2(0, -1) ;
    if ( ok ) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}