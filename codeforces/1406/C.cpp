#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define int long long
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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 1 ;
const ll INF = 1e18 + 10 ;
int n ; 
vector<vector<int> > g ;
vector<int> sz ;
void dfs(int x, int p){
    sz[x] = 1 ;
    for(int &c : g[x]){
        if ( c == p ) continue ;
        dfs(c, x) ;
        sz[x] += sz[c] ;
    }
}
vector<int> comp ;
void dfs2(int x, int p){
    for(int &c : g[x]){
        if ( c == p ) continue ;
        dfs2(c, x) ;
    }
    if ( p == -1 ){
        int nax = 0 ;
        for(int &c : g[x]){
            nax = max(nax, sz[c]) ;
        }
        comp[x] = nax ;
    }
    else{
        int nax = n - sz[x] ;
        for(int &c : g[x]){
            if ( c == p ) continue ;
            nax = max(nax, sz[c]) ;
        }
        comp[x] = nax ;
    }
}
void solve(){
    cin >> n ;
    g = vector<vector<int> >(n) ;
    sz = vector<int>(n) ;
    comp = vector<int>(n) ;
    for(int i = 0; i < n - 1; i++){
        int a , b ; 
        cin >> a >> b ; 
        a--, b-- ;
        g[a].emplace_back(b) ;
        g[b].emplace_back(a) ;
    }
    dfs(0, -1) ;
    debug() << imie(sz) ;
    dfs2(0, -1) ;
    debug() << imie(comp) ;
    int nix = *min_element(comp.begin(), comp.end()) ;
    vector<int> v ; 
    for(int i = 0; i < n; i++){
        if ( comp[i] == nix ) {
            v.emplace_back(i) ;
        }
    }
    if ( (int)v.size() == 1 ) {
        int vertex = v.back() ;
        cout << vertex + 1 << ' ' << g[vertex].back() + 1 << endl;
        cout << vertex + 1 << ' ' << g[vertex].back() + 1 << endl;
        return ;
    }
    else{
        int from = v[0] ;
        int to = v[1] ;
        for(int &c : g[from]){
            if ( c == to ) continue ;
            cout << from + 1 << ' ' << c + 1 << endl;
            cout << to + 1 << ' ' << c + 1 << endl;
            return ;
        }
        for(int &c : g[to]){
            if ( c == from ) continue ;
            cout << to + 1 << ' ' << c + 1 << endl ;
            cout << from + 1 << ' ' << c + 1 << endl;
            return ; 
        }
    }
}
signed main(){
    fastio;
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}
