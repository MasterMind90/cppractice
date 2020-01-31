#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    ll n , x ; 
    cin >> n >> x ; 
    string s ; 
    cin >> s ; 
    ll one = 0 , zero = 0 ; 
    for(char c : s ){
        if ( c == '1' ) one++ ; 
    }
    zero = n - one ; 
    if ( zero - one == 0 ){
        int z = 0 , o = 0 ; 
        for(int i = 0; i < n; i++){
            if ( s[i] == '0' ) z++ ; 
            else o++ ; 
            if ( z - o == x ){
                cout << -1 << endl;
                return ; 
            }
        }
    }
    ll z = 0 , o = 0 ; 
    int ans = 0 ; 
    for(ll i = 0; i < n; i++){
        if ( s[i] == '0' ) z++ ;
        else o++ ; 
        int diff = zero - one ;
        int c = x - z + o ; 
        if ( diff == 0 ) continue ; 
        int t = c % diff ; 
        int res = c / diff ; 
        debug() << imie(diff) imie(c) imie(c % diff);
        if ( res >= 0 && t == 0 ) ans++ ; 
    }
    if ( x == 0 ) ans++ ; 
    cout << ans << endl;
}
int main(){
    fastio
    ll t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}