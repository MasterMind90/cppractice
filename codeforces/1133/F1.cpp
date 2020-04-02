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
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ;
int n , m ;
vector<vector<int> > v ; 
vector<bool> vis ;
map<pair<int,int>, int> mp ;
void dfs(int x){
    debug() << imie(x) ;
    for(int& c : v[x]){
        if ( not vis[c] ){
            vis[c] = true ;
            int a = c , b = x ; 
            if ( a > b ) swap(a, b) ;
            mp[make_pair(a, b)]++;
            dfs(c) ;
        }
    }
}
signed main(){
    fastio 
    cin >> n >> m ; 
    v.resize(n + 1) ; 
    vis.resize(n + 1) ; 
    vector<int> deg(n + 1) ;
    for(int i = 0; i < m; i++){
        int x , y ;
        cin >> x >> y ; 
        v[x].push_back(y) ;
        v[y].push_back(x) ;
        deg[x]++ , deg[y]++ ;
    }
    int vertex = 1 ; 
    int nax = 0 ;
    for(int i = 1; i <= n; i++){
        if ( deg[i] > nax ){
            nax = deg[i] ; 
            vertex = i ; 
        }
    }
    vis[vertex] = true ;
    for(int& c : v[vertex]){
        vis[c] = true ;
        int a = c , b = vertex ; 
        if ( a > b ) swap(a, b) ; 
        mp[make_pair(a, b)]++;
    }
    for(int& c : v[vertex]){
        dfs(c) ;
    }
    assert(mp.size() == n - 1) ;
    for(auto p : mp){
        cout << p.first.first << ' ' << p.first.second << endl;
    }
    return 0 ; 
}