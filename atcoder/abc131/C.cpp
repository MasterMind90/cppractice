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
ll lcm(ll a,ll b){
	return a*b/__gcd(a,b) ; 
}
int main(){
    fastio
    ll a , b , c , d ; 
    cin >> a >> b >> c >> d ; 
    ll LCM = lcm(c,d) ; 
    ll both = b/LCM - a/LCM ; 
    if ( a % LCM == 0 ) both++ ; 
    ll first = b/c - a/c ;
    if ( a % c == 0 ) first++ ; 
    ll second = b/d - a/d ; 
    if ( a % d == 0 ) second++ ; 
    debug() << imie(first) imie(second) imie(both) ;
    ll ans = (b-a+1) - (first + second - both) ; 
    cout << ans << endl;
    return 0 ;
}
