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
int n , m , k ;
vector<vector<int> > g ;
vector<int> special , deg ;
vector<bool> vis ;
int cnt = 0 ;
int degrees = 0 ;
void dfs(int x){
    vis[x] = true ;
    cnt++ ;
    degrees += deg[x] ;
    for(int &c : g[x]){
        if ( vis[c] ) continue ;
        dfs(c) ;
    }
}
int F(int x){
    return x * (x + 1) / 2 ;
}
signed main(){
    fastio
    cin >> n >> m >> k ;
    g = vector<vector<int> >(n) ;
    deg = vector<int>(n) ;
    special = vector<int>(k) ;
    vis = vector<bool>(n) ;
    for(int i = 0; i < k; i++){
        cin >> special[i] ; 
        special[i]--;
    }
    for(int i = 0; i < m; i++){
        int a , b ; 
        cin >> a >> b ; a--, b-- ;
        deg[a]++ ;
        deg[b]++ ;
        g[a].emplace_back(b) ;
        g[b].emplace_back(a) ;
    }
    int nax = 0 ;
    int ans = 0 ;
    for(int &c : special){
        if ( vis[c] ) continue ;
        cnt = 0 ;
        degrees = 0 ; 
        dfs(c) ;
        ans += F(cnt - 1) - degrees / 2 ;
        nax = max(nax, cnt) ;
    }
    for(int i = 0; i < n; i++){
        if ( vis[i] ) continue ;
        degrees = 0 ;
        cnt = 0 ;
        dfs(i) ;
        ans += F(cnt - 1) - degrees / 2 ;
        ans += nax * cnt ;
        nax += cnt ;
    }
    cout << ans << endl;
    return 0; 
}