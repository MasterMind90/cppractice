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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 1 ;
const ll INF = 1e9 + 10 ;
int n , k ;
string s ;
vector<vector<int> > dp ;
int dfs(int x, int cur){
    if ( x == n ) {
        return 0 ; 
    }
    if ( dp[x][cur] != -1 ) return dp[x][cur] ;
    int ans = INF ;
    if ( x == 0 ) {
        for(int i = 0; i < k; i++){
            if ( s[x] == i + 'A' ) {
                ans = min(ans, dfs(x + 1, i) ) ;
            }
            else{
                ans = min(ans, 1 + dfs(x + 1, i)) ;
            }
        }
    }
    else{
        if ( s[x] == cur + 'A' ){
            for(int i = 0; i < k; i++){
                if ( s[x] == i + 'A' ) continue ;
                ans = min(ans, 1 + dfs(x + 1, i)) ;
            }
        }
        else{
            ans = min(ans, dfs(x + 1, s[x] - 'A')) ;
        }
    }
    return dp[x][cur] = ans ; 
}
string answer ; 
void build(int x, int cur){
    if ( x == n ) {
        return ;
    }
    vector<int> ans(k, INF) ;
    int extra = INF ;
    if ( x == 0 ) {
        for(int i = 0; i < k; i++){
            if ( s[x] == i + 'A' ) {
                ans[i] = min(ans[i], dfs(x + 1, i) ) ;
            }
            else{
                ans[i] = min(ans[i], 1 + dfs(x + 1, i)) ;
            }
        }
    }
    else{
        if ( s[x] == cur + 'A' ){
            for(int i = 0; i < k; i++){
                if ( s[x] == i + 'A' ) continue ;
                ans[i] = min(ans[i], 1 + dfs(x + 1, i)) ;
            }
        }
        else{
            extra = min(extra, dfs(x + 1, s[x] - 'A')) ;
        }
    }
    int optimal = dfs(x, cur) ;
    if ( optimal == extra ){
        answer.push_back(s[x]) ;
        build(x + 1, s[x] - 'A') ;
    }
    else{
        for(int i = 0; i < k; i++){
            if ( ans[i] == optimal ){
                answer.push_back(i + 'A') ;
                build(x + 1, i) ;
                break ;
            }
        }
    }
}
signed main(){
    fastio;
    cin >> n >> k ; 
    dp = vector<vector<int> >(n, vector<int>(28, -1)) ;
    cin >> s ;
    debug() << imie(s) ;
    int ans = dfs(0, s[0] - 'A') ;
    build(0, s[0] - 'A') ;
    cout << ans << endl;
    cout << answer << endl;
    return 0; 
}
