#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define int long long
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
typedef long long ll;
const ll MOD = 998244353 ;
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    int n ;
    cin >> n ; 
    string s ;
    cin >> s ; 
    int pre = 0 ; 
    char cur = s[0] ; 
    for(int i = 0; i < n; i++){
        if ( cur == s[i] ) pre++ ; 
        else break ; 
    }
    cur = s[n - 1] ; 
    int suf = 0 ; 
    for(int i = 0; i < n; i++){
        if ( cur == s[n - i - 1] ) suf++ ; 
        else break ; 
    }
    // do not forget the mod ; 
    if ( s[0] != s[n - 1] ){
        cout << pre + suf + 1 << endl;
    }
    else if ( s[0] == s[n - 1] ){
        int ans = pre * (suf + 1) + (suf + 1) ; 
        ans %= MOD ; 
        cout << ans << endl;
    }
    return 0; 
}