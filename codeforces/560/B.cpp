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
void no(){
    cout << "NO" << endl;
    exit(0) ; 
}
void yes(){
    cout << "YES" << endl;
    exit(0) ; 
}
int main(){
    fastio
    ll n , m ; 
    cin >> n >> m ; 
    int a , b , c , d ;
    cin >> a >> b >> c >> d ; 
    if ( max(a, b) + max(c, d) <= m && max(min(a,b) , min(c, d)) <= n ) yes() ; 
    if ( max(a, b) + min(c, d) <= m && max(min(a, b), max(c, d)) <= n ) yes() ; 
    if ( min(a, b) + min(c, d) <= m && max(max(a, b), max(c, d)) <= n ) yes() ; 

    if ( max(a, b) + max(c, d) <= n && max(min(a,b) , min(c, d)) <= m ) yes() ; 
    if ( max(a, b) + min(c, d) <= n && max(min(a, b), max(c, d)) <= m ) yes() ; 
    if ( min(a, b) + min(c, d) <= n && max(max(a, b), max(c, d)) <= m ) yes() ; 
    no() ;
    return 0 ; 
}