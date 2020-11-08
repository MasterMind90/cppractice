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
signed main(){
    fastio
    int n , m , a , b ;
    cin >> n >> m >> a >> b ;
    vector<vector<int> > v(n, vector<int>(m)) ;
    for(int i = 0; i < a; i++){
        int x , y ;
        cin >> x >> y ; 
        x-- , y-- ;
        v[x][y] = 1 ;
    }
    for(int i = 0; i < b; i++){
        int x , y ;
        cin >> x >> y ; 
        x-- , y-- ;
        v[x][y] = -1 ;
    }
    vector<vector<bool> > ans(n, vector<bool>(m)) ;
    for(int i = 0; i < n; i++){
        bool ok = false ;
        for(int j = 0; j < m; j++){
            if ( v[i][j] == 1 ) {
                ok = true ;
            }
            else if ( v[i][j] == -1 ) {
                ok = false ;
            }
            if ( ok ) ans[i][j] = true ;
        }
    }
    for(int i = 0; i < n; i++){
        bool ok = false ;
        for(int j = m - 1; j >= 0; j--){
            if ( v[i][j] == 1 ) {
                ok = true ;
            }
            else if ( v[i][j] == -1 ) {
                ok = false ;
            }
            if ( ok ) ans[i][j] = true ;
        }
    }
    for(int i = 0; i < m; i++){
        bool ok = false ;
        for(int j = 0; j < n; j++){
            if ( v[j][i] == 1 ) {
                ok = true ;
            }
            else if ( v[j][i] == -1 ) {
                ok = false ;
            }
            if ( ok ) ans[j][i] = true ;
        }
    }
    for(int i = 0; i < m; i++){
        bool ok = false ;
        for(int j = n - 1; j >= 0; j--){
            if ( v[j][i] == 1 ) {
                ok = true ;
            }
            else if ( v[j][i] == -1 ) {
                ok = false ;
            }
            if ( ok ) ans[j][i] = true ;
        }
    }
    int answer = 0 ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( ans[i][j] ) answer++ ;
        }
    }
    cout << answer << endl;
    return 0; 
}