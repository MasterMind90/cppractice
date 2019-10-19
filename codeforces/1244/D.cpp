#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
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
~debug() { cerr << endl; }
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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 
const ll INF = 1e18 + 10 ;
const ll N = 1e5 + 10 ;
vector<vector<ll>> graph;
ll c[3][N];
vector<ll> color ; 
void dfs(ll x, ll pcolor, ll gcolor){
    if ( color[x] != -1 ) return ; 
    color[x] = 3 - pcolor - gcolor; 
    for(ll &v : graph[x]){
        dfs(v, color[x], pcolor);
    }
}
int main(){
    fastio
    ll n ; 
    cin >> n ; 
    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < n; j++){
            cin >> c[i][j] ;
        }
    }
    vector<ll> deg(n) ; 
    graph.resize(n) ; 
    pair<ll,ll> p ; 
    for(ll i = 0; i < n - 1; i++){
        ll x , y ; 
        cin >> x >> y ; 
        x--, y--; 
        p = make_pair(x, y) ; 
        deg[x]++;
        deg[y]++;
        if ( deg[x] >= 3 || deg[y] >= 3 ) return cout << -1 << endl, 0 ; 
        graph[x].push_back(y) ; 
        graph[y].push_back(x) ; 
    }
    ll X[] = {0, 0, 1, 2, 1, 2};
    ll Y[] = {1, 2, 0, 0, 2, 1};
    ll nix = INF ; 
    vector<ll> tmp ;
    debug() << imie(p) ;
    for(ll i = 0; i < 6; i++){
        color.resize(n, -1) ; 
        for(ll j = 0; j < n; j++) color[j] = -1;
        color[p.first] = X[i];
        color[p.second] = Y[i] ;
        for(ll &v : graph[p.first]){
            if ( v == p.second ) continue ;
            debug() << imie(v) ; 
            dfs(v, color[p.first], color[p.second]);
        }
        for(ll &v : graph[p.second]){
            if ( v == p.first ) continue ;
            debug() << imie(v) ; 
            dfs(v, color[p.second], color[p.first]);
        }
        ll cost = 0 ;
        for(ll j = 0; j < n; j++){
            cost += c[color[j]][j];
        }
        debug() << imie(cost) ;
        debug() << imie(color) ;
        if ( nix > cost ){
            nix = cost ;
            tmp = color ;
        }
        debug() << imie(tmp) ;
    }
    cout << nix << endl;
    for(ll &v : tmp){
        cout << v + 1 << ' ' ;
    }
    cout << endl;
    return 0 ; 
}