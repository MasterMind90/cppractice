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
int n ;
string s[2] ;
signed main(){
    fastio
    cin >> n ;
    cin >> s[0] >> s[1] ;
    string a , b ;
    a.push_back(s[0][0]);
    b.push_back(s[1][0]) ;
    for(int i = 1; i < n; i++){
        if ( s[0][i] == s[0][i - 1] ) continue ;
        a.push_back(s[0][i]) ;
        b.push_back(s[1][i]) ;
    }
    debug() << imie(a) ;
    debug() << imie(b) ;
    int ans = 1 ; 
    if ( a[0] == b[0] ) ans = 3;
    else ans = 6 ;
    for(int i = 1; i < (int)a.size(); i++){
        if ( a[i] != b[i] && a[i - 1] != b[i - 1] ) {
            ans *= 3 ;
            ans %= MOD ;
        }
        else if ( a[i] != b[i] ) {
            ans *= 2 ;
            ans %= MOD ;
        }
        else if ( a[i - 1] == b[i - 1] ){
            ans *= 2 ;
            ans %= MOD; 
        }
    }
    debug() << imie(ans) ;
    cout << ans << endl;
    return 0; 
}
// 10
// RvvXYaaccdu
// RllXYbbeedu