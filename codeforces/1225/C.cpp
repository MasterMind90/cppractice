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
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
int solve(int x){
    if ( x == 0 ) return 1 ;
    if ( x == 1 ) return 2 ;
    if ( x & 1 ){
        return 2 + solve(x - 1)  ;
    }
    else return solve(x / 2) + solve(x / 2) ; 
}
signed main(){
    fastio
    int n , p ;
    cin >> n >> p ; 
    for(int i = 1; i <= 1000000; i++){
        int val = n - p * i ; 
        if ( val <= 0 ) continue ;
        int cnt = 0 ; 
        int tmp = 0 ; 
        for(int j = 0; j < 32; j++){
            if ( (1LL << j) & val ) {
                cnt++; 
                tmp += solve(j) ;
            }
        }
        if ( cnt <= i ){
            if ( tmp >= i ) {
                cout << i << endl;
                return 0 ;
            }
        }
    }
    cout << -1 << endl;
    return 0; 
}