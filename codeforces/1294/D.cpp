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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
int main(){
    ll q , x ;
    scanf("%I64d%I64d", &q, &x);
    set<ll> s ; 
    ll curMex = 0 ; 
    while(q--){
        ll a ; 
        scanf("%I64d", &a);
        if ( s.find(a) != s.end() ){
            ll L = 1, R = 1e9 ; 
            ll ans = -1 ;
            while(L <= R){
                ll mid = L + (R - L) / 2 ;
                if ( s.find( mid * x + a ) == s.end() ){
                    ans = mid ; 
                    R = mid - 1 ;
                }
                else L = mid + 1 ;
            }
            if ( ans != -1 ) a = a + ans * x ; 
        }
        else{
            ll L = 1, R = 1e9 ; 
            ll ans = -1 ;
            while(L <= R){
                ll mid = L + (R - L) / 2 ;
                if ( a - mid * x < 0 ) {
                    R = mid - 1 ;
                    debug() << "===" << imie(mid);
                    continue ;
                }
                if ( s.find( a - mid * x ) == s.end() ){
                    ans = mid ; 
                    L = mid + 1 ;
                }
                else R = mid - 1 ;
            }
            if ( ans != -1 ) a = a - ans * x ; 
        }
        s.insert(a) ;
        while ( s.find(curMex) != s.end() ) curMex++ ;
        printf("%I64d\n", curMex);
    }
    return 0; 
}