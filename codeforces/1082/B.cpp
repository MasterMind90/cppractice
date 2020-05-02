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
signed main(){
    fastio
    int n ;
    cin >> n ; 
    string s ;
    cin >> s ; 
    int cnt = 0 ;
    for(char &c : s){
        if ( c == 'G' ) cnt++ ;
    }
    vector<int> L(n + 1) ;
    vector<int> R(n + 2) ;
    for(int i = 0; i < n; i++){
        if ( s[i] == 'G' ) L[i + 1] = 1 ;
    }
    for(int i = 1; i < n + 1; i++){
        L[i] += L[i - 1] ;
        if ( s[i - 1] == 'S' ) {
            L[i] = 0 ; 
        }
    }
    for(int i = 0; i < n; i++){
        if ( s[n - i - 1] == 'G' ){
            R[n - i] = 1 ; 
        }
    }
    for(int i = 0; i < n; i++){
        R[n - i] += R[n - i + 1] ;
        if ( s[n - i - 1] == 'S' ){
            R[n - i] = 0 ; 
        }
    }
    int ans = 0 ;
    for(int i = 0; i < n; i++){
        ans = max(ans, L[i + 1]) ;
        if ( s[i] == 'S' ){
            int p = i + 1 ; 
            ans = max(ans, L[p - 1] + R[p + 1] + 1);
        }
    }
    ans = min(ans, cnt) ;
    cout << ans << endl;
    return 0; 
}