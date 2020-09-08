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
    int n ; 
    cin >> n ;
    if ( n == 1 ) {
        cout << "! 1" << endl; 
        cout.flush() ;
        return 0;
    }
    vector<int> ans(n + 1) ;
    for(int i = 1; i < n + 1; i += 2){
        if ( i + 1 <= n ) {
            cout << "? " << i << ' ' << i + 1 << endl ;
            cout.flush() ;
            int a ;
            cin >> a ;
            cout << "? " << i + 1 << ' ' << i << endl ;
            cout.flush() ;
            int b ;
            cin >> b ;
            if ( a > b ) {
                ans[i] = a ; 
            }
            else {
                ans[i + 1] = b ;
            }
            // 5 3
            // 1 2 ==> 2
            // 2 1 ==> 3
        }
    }
    if ( n == 2 ) {
        if ( ans[1] != 0 ) {
            cout << "! " << ans[1] << " " << 3 - ans[1] << endl ;
        }
        else{
            cout << "! " << 3 - ans[2] << " " << ans[2] << endl ;
        }
        return 0;
    }
    int start = ans[1] == 0 ? 1 : 2 ;
    for(int i = 3; i < n + 1; i++){
        if ( ans[i] == 0 ) {
            cout << "? " << start << ' ' << i << endl ;
            cout.flush() ;
            int a ;
            cin >> a ;
            cout << "? " << i << ' ' << start << endl ;
            cout.flush() ;
            int b ;
            cin >> b ;
            if ( a > b ) {
                ans[start] = a ;
                start = i ;
            }
            else {
                ans[i] = b ;
            }
        }
    }
    debug() << imie(ans) ;
    set<int> s ;
    for(int i = 1; i < n + 1; i++){
        if ( ans[i] != 0 ) s.emplace(ans[i]) ;
    }
    for(int i = 1; i < n + 1; i++){
        if ( ans[i] == 0 ) {
            for(int j = 1; j < n + 1; j++){
                if ( s.count(j) == 0 ) {
                    ans[i] = j ;
                    break ;
                }
            }
            break ;
        }
    }
    cout << "!" ; 
    for(int i = 1; i < n + 1; i++){
        cout << ' ' << ans[i] ;
    }
    cout << endl; 
    cout.flush() ;
    return 0; 
}
// 5 3 4 1 2
// 0 3 0 1 0

// 2 5 3 4 1
// 2 0 3 4 0