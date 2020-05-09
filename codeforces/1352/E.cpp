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
//#define int long long
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
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    vector<int> sum(n + 1) ;
    for(int i = 0; i < n; i++){
        sum[i + 1] = sum[i] + v[i] ;
    }
    vector<bool> flag(8001) ;
    for(int i = 1; i < 8001; i++){
        for(int j = 0; j < n - 1; j++){
            int L = j + 1, R = n ; 
            int ans = 0 ;
            while(L <= R){
                int mid = L + (R - L) / 2;
                if ( sum[mid] - sum[j] == i && mid - j > 1){
                    debug() << imie(i) imie(mid) imie(j) ;
                    ans = 1 ;
                    break ; 
                }
                else if ( sum[mid] - sum[j] > i ){
                    R = mid - 1;
                }
                else L = mid + 1;
            }
            if ( ans ) {
                flag[i] = true ;
                break; 
            }
        }
    }
    int ans = 0 ;
    for(int i = 0; i < n; i++){
        if ( flag[v[i]] ) ans++ ;
    }
    cout << ans << endl;
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