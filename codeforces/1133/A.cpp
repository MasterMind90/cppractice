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
signed main(){
    fastio 
    int h1 , h2, m1, m2 ; 
    char c ; 
    cin >> h1 >> c >> m1 ; 
    cin >> h2 >> c >> m2 ;
    int min = (h2 - h1) * 60 + m2 - m1 ; 
    min /= 2; 
    h1 += (min / 60);
    h1 %= 24 ; 
    m1 += min % 60 ;
    h1 += m1 / 60 ; 
    h1 %= 24 ;
    m1 = m1 % 60 ; 
    if ( h1 < 10 ) {
        cout << 0 << h1 ; 
    }
    else cout << h1 ; 
    cout << ":" ; 
    if ( m1 < 10 ){
        cout << 0 << m1 ; 
    }
    else cout << m1 ; 
    cout << endl;
    return 0 ; 
}