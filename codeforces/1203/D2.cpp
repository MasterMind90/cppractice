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
string s , t ;
int n , m ;
signed main(){
    fastio
    cin >> s >> t ;
    n = (int) s.size() ;
    m = (int) t.size() ;
    int pos = 0 ;
    vector<int> left(n) , right(n);
    for(int i = 0; i < n; i++){
        if ( pos < m && s[i] == t[pos] ){
            left[i] = 1 ;
            pos++ ;
        }
    }
    pos = m - 1 ;
    for(int i = n - 1; i >= 0; i--){
        if ( pos >= 0 && s[i] == t[pos] ){
            // right[i] = m - pos ;
            right[i] = 1 ;
            pos-- ;
        }
    }
    debug() << imie(left) ;
    debug() << imie(right) ;
    vector<int> sumLeft(n + 1) , sumRight(n + 1) ;
    for(int i = 0; i < n; i++){
        sumLeft[i + 1] = sumLeft[i] + left[i] ;
    }
    for(int i = n - 1; i >= 0; i--){
        sumRight[i] = sumRight[i + 1] + right[i] ;
    }
    debug() << imie(sumLeft) ;
    debug() << imie(sumRight) ;
    int ans = 0 ; 
    for(int i = 0; i < n + 1; i++){
        int target = m - sumLeft[i] ;
        int L = 0 , R = n ; 
        int index = -1 ;
        while(L <= R){
            int mid = L + (R - L) / 2 ;
            if ( sumRight[mid] >= target ){
                index = mid ;
                L = mid + 1;
            }
            else{
                R = mid - 1 ;
            }
        }
        ans = max(ans, index - i) ;
    }
    cout << ans << endl;
    return 0; 
}