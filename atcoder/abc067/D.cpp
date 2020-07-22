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
int n ;
vector<vector<int> > g ;
vector<vector<int> > newG ; 
int dfs(int x, int p = -1){
    debug() << imie(x) imie(p) ;
    int ans = 1 ;
    for(int &c : newG[x]){
        if ( c == p ) continue ;
        ans += dfs(c, x) ;
    }
    return ans ;
}
signed main(){
    fastio
    cin >> n ;
    g = vector<vector<int> >(n) ;
    newG = vector<vector<int> >(n) ;
    vector<int> X(n) , Y(n) ;
    for(int i = 0; i < n - 1; i++){
        int &x = X[i] , &y = Y[i] ;
        cin >> x >> y ; 
        x--, y--;
        g[x].emplace_back(y) ;
        g[y].emplace_back(x) ; 
    }
    vector<int> dist(n, INF) ;
    vector<int> from(n, -1) ;
    dist[0] = 0 ;
    from[0] = 0 ;
    queue<int> q ;
    q.push(0) ;
    while(not q.empty()){
        int f = q.front() ; q.pop() ;
        for(int &c : g[f]){
            if ( dist[c] > dist[f] + 1 ){
                dist[c] = dist[f] + 1; 
                from[c] = f ;
                q.push(c) ;
            }
        }
    }
    int start = n - 1  ;
    vector<int> t ;
    t.push_back(start) ;
    while(from[start] != start){
        t.push_back(from[start]) ;
        start = from[start] ;
    }
    int m = (int) t.size() ;
    debug() << imie(t) ;
    reverse(t.begin(), t.end()) ;
    assert((int) t.size() >= 2) ;
    pair<int,int> edge = make_pair(t[(m - 1) / 2],t[(m - 1) / 2 + 1])  ;
    debug() << imie(edge) ;
    for(int i = 0; i < n - 1; i++){
        int &x = X[i] , &y = Y[i] ;
        if ( (x == edge.first && y == edge.second) || (x == edge.second && y == edge.first) ) continue ;
        debug() << imie(x) imie(y) ;
        newG[x].emplace_back(y) ;
        newG[y].emplace_back(x) ;
    }
    int F = dfs(0) ;
    int S = dfs(n - 1) ;
    debug() << imie(F) ;
    debug() << imie(S) ;
    if ( F > S ){
        cout << "Fennec" << endl;
    }
    else cout << "Snuke" << endl;

    return 0; 
}