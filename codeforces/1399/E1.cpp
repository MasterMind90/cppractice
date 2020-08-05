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
int n , s ;
vector<vector<int> > g ;
map<pair<int,int>, int> edge ;
vector<int> sz ;
priority_queue<pair<int,pair<int,int> > > q ;
void dfs(int x, int p){
    bool flag = false ;
    sz[x] = 0 ;
    for(int &c : g[x]){
        if ( c == p ) continue ;
        flag = true ;
        dfs(c, x) ;
        sz[x] += sz[c] ;
    }
    if ( not flag ) sz[x] = 1;
}
int sum = 0 ;
void dfs2(int x, int p){
    for(int &c : g[x]){
        if ( c == p ) continue ;
        int cost = edge[make_pair(x, c)] ;
        int delta = cost * sz[c] - cost / 2 * sz[c] ;
        q.push(make_pair(delta, make_pair(sz[c], cost))) ;
        sum += cost * sz[c] ;
        dfs2(c, x) ;
    }
}
void solve(){
    cin >> n >> s ;
    g = vector<vector<int> >(n) ;
    sz = vector<int>(n) ;
    edge.clear() ;
    q = priority_queue<pair<int,pair<int,int> > >() ;
    sum = 0 ;
    for(int i = 0; i < n - 1; i++){
        int a , b , c ;
        cin >> a >> b >> c ;
        a--, b-- ;
        g[a].emplace_back(b) ;
        g[b].emplace_back(a) ;
        edge[make_pair(a, b)] = c ;
        edge[make_pair(b, a)] = c ;
    }
    dfs(0, -1) ;
    debug() << imie(sz) ;
    dfs2(0, -1) ;
    // while(not q.empty()){
    //     debug() << imie(q.top()) ; q.pop() ;
    // }
    debug() << imie(sum) ;
    int moves = 0 ;
    while(sum > s){
        auto t = q.top() ; q.pop() ;
        debug() << imie(t) ;
        int delta = t.first ;
        int cost = t.second.second ;
        int rep = t.second.first ;
        sum -= delta ;
        moves++ ;
        cost /= 2 ;
        delta = cost * rep - cost / 2 * rep ;
        q.push(make_pair(delta, make_pair(rep, cost))) ;
    }
    cout << moves << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t; 
    while(t--){
        solve() ;
    }
    return 0; 
}
/*

7 1
1 3 100
1 5 10
3 2 123
3 6 50
3 7 30
5 4 55

*/