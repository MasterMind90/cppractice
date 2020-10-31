#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sim template < class c
#define int long long
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
typedef tree< pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
string s ;
int n ;
// 33010
// 1033
vector<vector<vector<int> > > dp ;
int dfs(int x, int zero, int sum){
    if ( x == n ) {
        if ( sum == 0 ) {
            return 0 ;
        }
        return INF ;
    }
    if ( dp[x][zero][sum] != -1 ) return dp[x][zero][sum] ;
    int ans = INF ;
    if ( s[x] != '0' ) {
        ans = min(ans, dfs(x + 1, 0, (sum + s[x] - '0') % 3 )) ;
        ans = min(ans, 1 + dfs(x + 1, zero, sum)) ;
    }
    else{
        if ( zero ) {
            ans = min(ans, 1 + dfs(x + 1, zero, sum)) ;
        }
        else {
            ans = min(ans, dfs(x + 1, zero, sum)) ;
        }
    }
    return dp[x][zero][sum] = ans ;
}
string answer ;
void build(int x, int zero, int sum){
    if ( x == n ) {
        return ;
    }
    int ans = INF ;
    int option1 , option2 , option3, option4 ;
    option1 = option2 = option3 = option4 = INF ;
    if ( s[x] != '0' ) {
        option1 = min(ans, dfs(x + 1, 0, (sum + s[x] - '0') % 3 )) ;
        option2 = min(ans, 1 + dfs(x + 1, zero, sum)) ;
    }
    else{
        if ( zero ) {
            option3 = min(ans, 1 + dfs(x + 1, zero, sum)) ;
        }
        else {
            option4 = min(ans, dfs(x + 1, zero, sum)) ;
        }
    }
    int optimal = dfs(x, zero, sum) ;
    if ( optimal == option1 ) {
        answer.push_back(s[x]) ;
        build(x + 1, 0, (sum + s[x] - '0') % 3 ) ;
    }
    else if ( optimal == option2 ) {
        build(x + 1, zero, sum) ;
    }
    else if ( optimal == option3 ) {
        build(x + 1, zero, sum) ;
    }
    else if (optimal == option4) {
        answer.push_back(s[x]) ;
        build(x + 1, zero, sum) ;
    }
}
signed main(){
    fastio
    cin >> s ;
    n = (int) s.size() ;
    dp = vector<vector<vector<int> > >(n, vector<vector<int> >(2, vector<int>(3, -1))) ;
    bool zero = false ;
    for(char &c : s){
        if ( c == '0' ) {
            zero = true ;
        }
    }
    // reverse(s.begin(), s.end()) ;
    // 3301
    int ans = dfs(0, 1, 0) ;
    if ( ans == n ) {
        if ( zero ) {
            cout << 0 << endl;
            return 0 ;
        }
        cout << -1 << endl;
        return 0 ;
    }
    build(0, 1, 0) ;
    debug() << imie(ans) ;
    cout << answer << endl;
    return 0; 
}