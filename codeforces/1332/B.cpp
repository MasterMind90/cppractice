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
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    int n ; 
    cin >> n ; 
    vector<int> v(n) ; 
    set<int> s[n] ; 
    set<int> total  ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ; 
        int x = v[i] ; 
        for(int j = 2; j * j <= x; j++){
            bool ok = false ;
            while( x % j == 0 ){
                ok = true ;
                x /= j ; 
            }
            if ( ok ){
                s[i].insert(j);
                total.insert(j) ;
            } 
        }
        if ( x > 1 ) {
            s[i].insert(x) ; 
            total.insert(x) ; 
        }
    }
    vector<int> ans(n) ; 
    int color = 1;
    for(int c : total){
        bool used = false;
        for(int i = 0; i < n; i++){
            if ( ans[i] ) continue ; 
            if ( s[i].count(c) ){
                ans[i] = color ; 
                used = true ;
            }
        }
        if ( used ) color++ ;
    }
    int nax = 0 ; 
    for(int i = 0; i < n; i++){
        nax = max(nax, ans[i]) ;
    }
    assert(nax <= 11) ;
    cout << nax << endl;
    for(int &c : ans){
        cout << c << ' ' ;
    }
    cout << endl;
}
signed main(){
    fastio 
    int t ;
    cin >> t ;
    while(t--) solve() ; 
    return 0 ; 
}