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
int n , k ;
vector<vector<int> > g ; 
vector<int> h ; 
vector<int> cnt ; 
vector<int> dist ;
vector<int> sub ;
int answer = 0 ;
void dfs(int x, int p, int height){
    dist[x] = height ;
    for(int &c : g[x]){
        if ( c == p ) continue ;
        dfs(c, x, height + 1) ;
    }
}
void dfs2(int x, int p){
    cnt[x] = (h[x] == 0) ;
    for(int &c : g[x]){
        if ( c == p ) continue ;
        dfs2(c, x) ;
        cnt[x] += cnt[c] ;
    }
}
void recur(int x, int p = -1){
    if ( h[x] ) answer += cnt[x] ;
    for(int &c : g[x]){
        if ( c == p ) continue ;
        recur(c, x) ;
    }
}
void subtree(int x, int p){
    sub[x] = 1 ;
    for(int &c : g[x]){
        if ( c == p ) continue ;
        subtree(c, x) ;
        sub[x] += sub[c] ;
    }
}
signed main(){
    fastio
    cin >> n >> k ;
    g.resize(n + 1) ;
    h.resize(n + 1, 1) ;
    cnt.resize(n + 1) ;
    dist.resize(n + 1) ;
    sub.resize(n + 1) ;
    for(int i = 0; i < n - 1; i++){
        int x , y ;
        cin >> x >> y  ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }
    // place them as far as possible when there is a tie put on the lower number of children (subtree size);
    debug() << imie(h) ;
    dfs(1, -1, 1) ;
    subtree(1, -1) ;
    debug() << imie(sub) ;
    vector<int> v ;
    for(int i = 1; i < n + 1; i++){
        int diff = sub[i] - dist[i]; 
        v.emplace_back(diff) ;
    }
    sort(v.rbegin(), v.rend()) ;
    int ans = 0 ;
    for(int i = 0; i < n - k; i++){
        ans += v[i] ;
    }
    cout << ans << endl;
    return 0; 
}