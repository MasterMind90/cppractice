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
void solve(){
    int n , q ;
    cin >> n >> q ;
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    int ans = v[0] ;
    for(int i = 1; i < n; i++){
        if ( v[i] > v[i - 1] ) ans += v[i] - v[i - 1] ;
    }
    cout << ans << endl;
    while(q--){
        int l , r ;
        cin >> l >> r ;
        l--, r-- ;
        if ( l == r ) {
            cout << ans << endl;
            continue ;
        }
        if ( l == 0 ) {
            ans -= v[0] ;
            // 2 5 3 1
            // l   r 
            if ( l + 1 == r ) {
                if ( v[r] - v[l] > 0 ) ans -= v[r] - v[l] ;
                if ( r + 1 < n && v[r + 1] - v[r] > 0 ) ans -= v[r + 1] - v[r] ;
                swap(v[l], v[r]) ;
                ans += v[0] ;
                if ( v[r] - v[l] > 0 ) ans += v[r] - v[l] ;
                if ( r + 1 < n && v[r + 1] - v[r] > 0 ) ans += v[r + 1] - v[r] ;
            }
            else{
                if ( v[l + 1] - v[l] > 0 ) ans -= v[l + 1] - v[l] ;
                if ( v[r] - v[r - 1] > 0 ) ans -= v[r] - v[r - 1] ;
                if ( r + 1 < n && v[r + 1] - v[r] > 0 ) ans -= v[r + 1] - v[r] ;
                swap(v[l], v[r]) ;
                ans += v[0] ;
                if ( v[l + 1] - v[l] > 0 ) ans += v[l + 1] - v[l] ;
                if ( v[r] - v[r - 1] > 0 ) ans += v[r] - v[r - 1] ;
                if ( r + 1 < n && v[r + 1] - v[r] > 0 ) ans += v[r + 1] - v[r] ;
            }
        }
        else{
            // 3 2 1 5 9 8
            //   l r   
            if ( l + 1 == r ) {
                if ( v[l] - v[l - 1] > 0 ) ans -= v[l] - v[l - 1] ;
                if ( v[r] - v[l] > 0 ) ans -= v[r] - v[l] ;
                if ( r + 1 < n && v[r + 1] - v[r] > 0 ) ans -= v[r + 1] - v[r] ;
                swap(v[l], v[r]) ;
                if ( v[l] - v[l - 1] > 0 ) ans += v[l] - v[l - 1] ;
                if ( v[r] - v[l] > 0 ) ans += v[r] - v[l] ;
                if ( r + 1 < n && v[r + 1] - v[r] > 0 ) ans += v[r + 1] - v[r] ;
            }
            // 3 2 1 5 9 8
            //   l     r
            else{
                if ( v[l] - v[l - 1] > 0 ) ans -= v[l] - v[l - 1] ;
                if ( v[l + 1] - v[l] > 0 ) ans -= v[l + 1] - v[l] ;
                if ( v[r] - v[r - 1] > 0 ) ans -= v[r] - v[r - 1] ;
                if ( r + 1 < n && v[r + 1] - v[r] > 0 ) ans -= v[r + 1] - v[r] ;
                swap(v[l], v[r]) ;
                if ( v[l] - v[l - 1] > 0 ) ans += v[l] - v[l - 1] ;
                if ( v[l + 1] - v[l] > 0 ) ans += v[l + 1] - v[l] ;
                if ( v[r] - v[r - 1] > 0 ) ans += v[r] - v[r - 1] ;
                if ( r + 1 < n && v[r + 1] - v[r] > 0 ) ans += v[r + 1] - v[r] ;
            }
        }
        cout << ans << endl;
    }
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}