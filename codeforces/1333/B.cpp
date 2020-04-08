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
const ll MOD = 1e9 + 7 ;
const ll N = 1e5 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    int n ; 
    cin >> n ; 
    vector<int> a(n) , b(n) ; 
    for(int i = 0; i < n; i++){
        cin >> a[i] ; 
    }
    for(int i = 0; i < n; i++){
        cin >> b[i] ; 
    }
    vector<int> minusOne(n) ;
    minusOne[0] = 0 ; 
    bool ok = (a[0] == -1);
    for(int i = 1; i < n; i++){
        minusOne[i] = ok ; 
        ok = max(ok, a[i] == -1) ;
    }
    vector<int> One(n) ;
    One[0] = 0 ; 
    ok = (a[0] == 1) ;
    for(int i = 1; i < n; i++){
        One[i] = ok ; 
        ok = max(ok, a[i] == 1) ;
    }
    ok = true;
    for(int i = 0; i < n; i++){
        if ( a[i] == b[i] ) continue ;
        if ( a[i] < b[i] && not One[i] ) ok = false ;
        if ( a[i] > b[i] && not minusOne[i] ) ok = false;
    }
    if ( ok ){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}
signed main(){
    fastio 
    int t; 
    cin >> t ;
    while(t--) solve() ; 
    return 0 ; 
}