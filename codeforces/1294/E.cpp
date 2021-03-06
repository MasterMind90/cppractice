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
int n , m ; 
int fix(int x){
    return ( x % n + n ) % n;
}
int main(){
    //fastio
    scanf("%d%d", &n , &m);
    int g[n][m] ; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &g[i][j]);
            g[i][j]--;
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        vector<int> cnt(n) ; 
        for(int j = 0; j < n; j++){
            if ( g[j][i] % m == i ){
                int pos = g[j][i] / m ; 
                if ( pos < n ) cnt[fix(j - pos)]++;
            }
        }
        int nix = n - cnt[0] ; 
        for(int shift = 1; shift < n; shift++){
            nix = min(nix, n - cnt[shift] + shift);
        }
        ans += nix ;
    }
    cout << ans << endl;
    return 0; 
}