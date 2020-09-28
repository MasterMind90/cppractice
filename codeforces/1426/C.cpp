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
map<int,int> mp ;
void solve(){
    int n ;
    cin >> n ;
    if ( n == 1 ) {
        cout << 0 << endl;
        return ;
    }
    int ans = n - 1 ;
    for(int i = 1; i <= 5e4; i++){
        int val = i + 1 ;
        if ( val >= n ) {
            ans = min(ans, i) ;
        }
        else{
            ans = min(ans, i + ((n - val) + val - 1) / val) ;
        }
    }
    cout << ans << endl;
    // if ( mp.count(n) ) {
    //     cout << mp[n] << endl;
    //     return ;
    // }
    // // int x = 1 ;
    // // int ans = 0 ;
    // // while(x < n){
    // //     x += x ;
    // //     ans++ ;
    // // }
    // // cout << ans << endl;
    // queue<int> q ;
    // q.push(1) ;
    // while(not q.empty()){
    //     int f = q.front() ; q.pop() ;
    //     if ( f >= n ){
    //         break ;
    //     }
    //     if ( mp.count(f + f) == 0 ){
    //         mp[f + f] = f + 1 ;
    //         q.push(f + f) ;
    //     }
    //     if ( mp.count(f + 1) == 0 ) {
    //         mp[f + 1] = f + 1 ;
    //         q.push(f + 1) ;
    //     }
    // }
    // cout << mp[n] << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}