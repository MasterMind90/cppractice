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
int n ;
vector<int> a , b , c ;
vector<vector<vector<int> > > dp ;
int dfs(int x, int last, int start){
    if ( x == n ) {
        if ( start == 0 ) {
            return last != a[0] ;
        }
        if ( start == 1 ) {
            return last != b[0] ;
        }
        if ( start == 2 ) {
            return last != c[0] ;
        }
        return 0 ;
    }
    if ( dp[x][last][start] != -1 ) return dp[x][last][start] ;
    int ans = 0 ;
    int choice1 = 0 ;
    int choice2 = 0 ;
    int choice3 = 0 ;
    if ( last == 101 ) {
        choice1 |= dfs(x + 1, a[x], 0) ;
        choice2 |= dfs(x + 1, b[x], 1) ;
        choice3 |= dfs(x + 1, c[x], 2) ;
    }
    if ( last != a[x] ) {
        choice1 |= dfs(x + 1, a[x], start) ;
    }
    if ( last != b[x] ) {
        choice2 |= dfs(x + 1, b[x], start) ;
    }
    if ( last != c[x] ){
        choice3 |= dfs(x + 1, c[x], start) ;
    }
    ans = choice1 | choice2 ;
    ans |= choice3 ;
    return dp[x][last][start] = ans ;
}
vector<int> answer ;
void build(int x, int last, int start){
    if ( x == n ) {
        return ;
    }
    int ans = 0 ;
    int choice1 = 0 ;
    int choice2 = 0 ;
    int choice3 = 0 ;
    if ( last == 101 ) {
        choice1 |= dfs(x + 1, a[x], 0) ;
        choice2 |= dfs(x + 1, b[x], 1) ;
        choice3 |= dfs(x + 1, c[x], 2) ;
    }
    if ( last != a[x] ) {
        choice1 |= dfs(x + 1, a[x], start) ;
    }
    if ( last != b[x] ) {
        choice2 |= dfs(x + 1, b[x], start) ;
    }
    if ( last != c[x] ){
        choice3 |= dfs(x + 1, c[x], start) ;
    }
    ans = choice1 | choice2 ;
    ans |= choice3 ;
    int optimal = dfs(x, last, start) ;
    if ( optimal == choice1 ) {
        answer.push_back(a[x]) ;
        build(x + 1, a[x], start) ;
    }
    else if ( optimal == choice2 ) {
        answer.push_back(b[x]) ;
        build(x + 1, b[x], start) ;
    }
    else if ( optimal == choice3 ){
        answer.push_back(c[x]) ;
        build(x + 1, c[x], start) ;
    }
}
void solve(){
    cin >> n ;
    a = b = c = vector<int>(n) ;
    dp = vector<vector<vector<int> > >(n, vector<vector<int> >(102, vector<int>(4, -1)));
    for(int i = 0; i < n; i++){
        cin >> a[i] ;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i] ;
    }
    for(int i = 0; i < n; i++){
        cin >> c[i] ;
    }
    answer.clear() ;
    int ans = dfs(0, 101, 0) ;
    build(0, 101, 0) ;
    for(int &c : answer){
        cout << c << ' ' ;
    }
    cout << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) {
        solve() ;
    }
    return 0; 
}