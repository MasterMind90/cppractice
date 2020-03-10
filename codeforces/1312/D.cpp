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
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
const double EPS = 1e-6 ; 
const int M = 998244353 ;
int fast(int a, int b){
    if ( b == 0 ) return 1 ;
    if ( b == 1 ) return a ; 
    int y = fast(a, b / 2) ; 
    int c = 1 ; 
    if ( b & 1 ){
        c = a ; 
    }
    return (((y % M) * (y % M)) % M * c) % M;
}
int inv(int x){
    return fast(x, M - 2) ;
}
signed main(){
    fastio
    int n , m ; 
    cin >> n >> m ; 
    // remove duplicate number, we are left with n - 1
    // how to add the duplicate number (we know that we can duplicate all number except the max one so we have (n - 2) choices but note we have to divide by 2 to cancel repitition)
    // How many ways can we make arrays of n - 1 elements from m distinct elements. 
    // The answer mC(n-1)
    // Each element of the array can go to the left or to the right except the max one. so 2^(n - 2)
    int ans = 1;
    for(int i = 1; i <= m; i++){
        ans = ((ans % M) * i) % M ;
    }
    for(int i = 1; i <= m - (n - 1); i++){
        ans = ((ans % M) * inv(i)) % M ;
    }
    for(int i = 1; i <= (n - 1); i++){
        ans = ((ans % M) * inv(i)) % M ;
    }
    ans = ((ans % M) * (fast(2, n - 2) % M)) % M;
    ans = (ans * (n - 2)) % M * inv(2) ; 
    ans %= M ; 
    cout << ans << endl;
    return 0; 
}