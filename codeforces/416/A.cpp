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
~debug() { cerr << endl; }
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
const ll nax = 2e9 ; 
int main(){
    fastio
    int n ; 
    cin >> n ; 
    ll L = -nax , R = nax ; 
    for(int i = 0; i < n; i++){
        string s ;
        ll x ;
        char c ; 
        cin >> s >> x >> c ; 
        if ( s == ">=" ){
            if ( c == 'Y' ){
                L = max(L, x) ; 
            }
            else{
                R = min(R, x - 1) ; 
            }
        }
        else if ( s == "<=" ){
            if ( c == 'Y' ){
                R = min(R, x) ; 
            }
            else{
                L = max(L, x + 1) ; 
            }
        }
        else if ( s == ">" ){
            if ( c == 'Y' ){
                L = max(L, x + 1) ; 
            }
            else{
                R = min(R, x) ; 
            }
        }
        else if ( s == "<" ){
            if ( c == 'Y' ){
                R = min(R, x - 1) ; 
            }
            else{
                L = max(L, x) ; 
            }
        }
    }
    debug() << imie(L) imie(R) ; 
    if ( L <= R ) cout << L << endl;
    else cout << "Impossible" << endl;
    return 0 ; 
}