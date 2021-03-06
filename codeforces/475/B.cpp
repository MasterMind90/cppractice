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
vector<vector<bool> > vis ;
int n , m ;
string h , v ; 
bool inRange(int x, int y){
    if ( x < 0 ) return false ;
    if ( x >= n ) return false ;
    if ( y < 0 ) return false ;
    if ( y >= m ) return false ;
    if ( vis[x][y] ) return false; 
    return true ;
}
void dfs(int x, int y){
    vis[x][y] = true ;
    if ( h[x] == '>' ) {
        if ( inRange(x, y + 1) ){
            dfs(x, y + 1) ;
        }
    }
    else{
        if ( inRange(x, y - 1) ) {
            dfs(x, y - 1) ;
        }
    }
    if ( v[y] == '^' ) {
        if ( inRange(x - 1, y) ){
            dfs(x - 1, y) ;
        }
    }
    else{
        if ( inRange(x + 1, y) ) {
            dfs(x + 1, y) ;
        }
    }

}
signed main(){
    fastio
    cin >> n >> m ;
    cin >> h >> v ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vis = vector<vector<bool> >(n, vector<bool>(m));
            for(auto &vv : vis){
                debug() << imie(vv) ;
            }
            dfs(i, j) ;
            bool ok = true ;
            for(int k = 0; k < n; k++){
                for(int u = 0; u < m; u++){
                    if ( not vis[k][u] ) {
                        ok = false ;
                        break ;
                    }
                }
            }
            if ( not ok ) {
                cout << "NO" << endl;
                return 0 ;
            }
        }
    }
    cout << "YES" << endl;
    return 0; 
}