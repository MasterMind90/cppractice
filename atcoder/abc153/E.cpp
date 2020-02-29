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
int H , n ;
vector<int> A , B ; 
int dp[(int)1e3 + 5][(int) 1e4 + 5] ;
int dfs(int x, int cur){
    if ( cur >= H ) return 0 ; 
    if ( x == n ){
        return INF ;
    }
    if ( dp[x][cur] != -1 ) return dp[x][cur] ; 
    int choice1 = INF ; 
    int choice2 = INF ; 
    choice1 = dfs(x + 1, cur) ;
    choice2 = B[x] + dfs(x, cur + A[x]) ;
    return dp[x][cur] = min(choice1, choice2) ; 
}
signed main(){
    fastio
    memset(dp, -1, sizeof dp) ;
    cin >> H >> n ; 
    A.resize(n) ;
    B.resize(n) ;
    for(int i = 0; i < n; i++){
        cin >> A[i] >> B[i] ; 
    }
    int ans = dfs(0, 0) ;
    cout << ans << endl;
    return 0; 
}