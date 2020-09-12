#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define int long long
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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int n , cost ;
vector<int> a , b ;
// cur = 1 : Stairs 
// cur = 2 : Elevator 
int dp[N][3] ;
int dfs(int x, int cur){
    if ( x == -1 ) {
        return 0 ;
    }
    if ( dp[x][cur] != -1 ) return dp[x][cur] ;
    int ans = INF ; 
    if ( cur == 0 ) {
        ans = min(ans, a[x] + dfs(x - 1, 1)) ;
        ans = min(ans, cost + b[x] + dfs(x - 1, 2)) ;
    }
    else if ( cur == 1 ){
        ans = min(ans, a[x] + dfs(x - 1, 1)) ;
        ans = min(ans, cost + b[x] + dfs(x - 1, 2)) ;
    }
    else if ( cur == 2 ){
        ans = min(ans, a[x] + dfs(x - 1, 1)) ;
        ans = min(ans, b[x] + dfs(x - 1, 2)) ;
    }
    return dp[x][cur] = ans ;
}
signed main(){
    fastio;
    memset(dp, -1, sizeof dp) ;
    cin >> n >> cost ;
    a = b = vector<int>(n - 1) ;
    for(int i = 0; i < n - 1; i++){
        cin >> a[i] ; 
    }
    for(int i = 0; i < n - 1; i++){
        cin >> b[i] ; 
    }
    debug() << imie(a) ;
    debug() << imie(b) ;
    vector<int> answer ;
    for(int i = n - 2; i >= 0; i--){
        int ans = dfs(i, 0) ;
        debug() << imie(ans) ;
        answer.emplace_back(ans) ;
    }
    answer.emplace_back(0) ;
    reverse(answer.begin(), answer.end()) ;
    for(int &c : answer){
        cout << c << ' ' ;
    }
    cout << endl;
    //dfs(0, 0) ;
    //for(int i = 0; i < n; i++){
    //    debug() << imie(i) imie(dp[i][0]) imie(dp[i][1]) imie(dp[i][2]) ;
    //}

    return 0; 
}
