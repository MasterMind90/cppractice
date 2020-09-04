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
int n , x , y ;
int best(){
    int t = x + y ;
    int highest = x == n ? n - 1 : n ;
    int L = 1 , R = n ;
    int ans = -1 ;
    while(L <= R){
        int mid = L + (R - L) / 2 ;
        if ( highest + mid > t ) {
            ans = mid ;
            R = mid - 1; 
        }
        else L = mid + 1 ;
    }
    if ( ans == -1 ) {
        return n ;
    }
    return ans ;
}
int worst(){
    int t = x + y ;
    int lowest = x == 1 ? x + 1 : 1 ; 
    int L = 1 , R = n ;
    int ans = -1 ;
    while(L <= R){
        int mid = L + (R - L) / 2 ;
        if ( lowest + mid <= t ) {
            ans = mid ;
            L = mid + 1 ;
        }
        else R = mid - 1 ;
    }
    if ( ans == -1 ) {
        return 1 ;
    }
    if ( y > ans ) return ans + 1 ;
    else return ans ;
}
void solve(){
    cin >> n >> x >> y ;
    if ( x > y ) swap(x, y) ;
    if ( n == 1 ) {
        cout << 1 << ' ' << 1 << endl;
        return ;
    }
    int rank1 = best() ;
    int rank2 = worst() ;
    cout << rank1 << ' ' << rank2 << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}