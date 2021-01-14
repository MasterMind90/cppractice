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
vector<int> color ; 
int n ;
vector<vector<int> > g ;
vector<int> dp , dp2 ;
void dfs(int x, int p){
    dp[x] = color[x] == 1 ? 1 : -1 ;
    int sum = 0 ;
    for(int &c : g[x]){
        if ( c == p ) continue ;
        dfs(c, x) ;
        if ( dp[c] > 0 ) sum += dp[c] ;
    }
    dp[x] += sum ;
}
void dfs2(int x, int p){
    for(int &c : g[x]){
        if ( c == p ) continue ;
        if ( dp[c] > 0 ) {
            int newx = dp[x] - dp[c] ;
            if ( newx > 0 ) dp[c] += newx ;
        }
        else{
            if ( dp[x] > 0 ) {
                dp[c] += dp[x] ;
            }
        }
        dfs2(c, x) ;
    }
}
signed main(){
    fastio
    cin >> n ;
    g = vector<vector<int> >(n) ;
    dp2 = dp = color = vector<int>(n) ;
    for(int i = 0; i < n; i++){
        cin >> color[i] ;
    }
    for(int i = 0; i < n - 1; i++){
        int a , b ;
        cin >> a >> b ; a--, b-- ;
        g[a].emplace_back(b) ;
        g[b].emplace_back(a) ;
    }
    dfs(0, -1) ;
    dp2 = dp ;
    debug() << imie(dp2) ;
    dfs2(0, -1) ;
    debug() << imie(dp) ;
    for(int i = 0; i < n; i++){
        cout << max(dp[i], dp2[i]) << ' ' ;
    }
    cout << endl; 
    return 0; 
}