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
int rem1(int x){
    int L = 0, R = 1e9 ; 
    int ans = -1 ;
    while(L <= R){
        int mid = L + (R - L) / 2 ;
        if ( 1 + mid * 3 <= x){
            ans = mid ; 
            L = mid + 1 ;
        }
        else R = mid - 1;
    }
    if ( ans == -1 ) return 0 ;
    return ans + 1 ; 
}
int n , l , r ;
int zero , one , two ; 
int dp[N][3] ; 
int dfs(int x, int rem){
    if ( x == n ){
        return 1 ;
    }
    if ( dp[x][rem] != -1 ) return dp[x][rem] ; 
    int ans = 0 ; 
    if ( x == n - 1 ){
        if ( rem == 0 ){
            ans = ((zero % MOD) * (dfs(x + 1, rem) % MOD)) % MOD ;
        }
        else if ( rem == 1 ){
            ans = ((two % MOD) * (dfs(x + 1, (rem + 2) % 3) % MOD)) % MOD ;
        }
        else{
            ans = ((one % MOD) * (dfs(x + 1, (rem + 1) % 3) % MOD)) % MOD ;
        }
    }
    else{
        int choice1 = ((zero % MOD) * (dfs(x + 1, rem) % MOD)) % MOD ;
        int choice2 = ((one % MOD) * (dfs(x + 1, (rem + 1) % 3) % MOD)) % MOD ;
        int choice3 = ((two % MOD) * (dfs(x + 1, (rem + 2) % 3) % MOD)) % MOD ;
        ans = choice1 + choice2 + choice3 ;
    }
    return dp[x][rem] = ans % MOD;
}
signed main(){
    fastio
    memset(dp, -1, sizeof dp) ;
    cin >> n >> l >> r ;
    int total = r - l + 1 ;
    zero = r / 3 - (l - 1) / 3 ;
    debug() << imie(rem1(r)) imie(rem1(l - 1)) ;
    one = rem1(r) - rem1(l - 1) ; 
    two = total - zero - one ; 
    debug() << imie(zero) imie(one) imie(two) ;
    int ans = dfs(0, 0) ;
    cout << ans << endl;
    return 0; 
}