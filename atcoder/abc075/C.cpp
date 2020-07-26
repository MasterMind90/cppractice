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
vector<pair<int,int> > edge ;
int n , m ;
vector<int> rep ;
int Find(int x){
    if ( rep[x] == x ) return x ;
    return rep[x] = Find(rep[x]) ;
}
void Union(int x, int y){
    int X = Find(x) ;
    int Y = Find(y) ; 
    if ( X == Y ) return ;
    rep[X] = Y ;
}
bool build(int x){
    for(int i = 0; i < n; i++){
        rep[i] = i ;
    }
    for(int i = 0; i < m; i++){
        if ( i == x ) continue ;
        int a = edge[i].first , b = edge[i].second ;
        Union(a, b) ;
    }
    if ( Find(edge[x].first) == Find(edge[x].second) ) return false ;
    return true ;
}
signed main(){
    fastio
    cin >> n >> m ;
    rep = vector<int>(n) ;
    edge = vector<pair<int,int> > (m) ;
    for(int i = 0; i < m; i++){
        cin >> edge[i].first >> edge[i].second ;
        edge[i].first-- , edge[i].second-- ;
    }
    int ans = 0 ;
    for(int i = 0; i < m; i++){
        ans += build(i) ;
    }
    cout << ans << endl;
    return 0; 
}
