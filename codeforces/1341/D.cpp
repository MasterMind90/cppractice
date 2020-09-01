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
// #define int long long
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
int n , k ;
vector<string> v ;
vector<string> a = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"} ;
bool can(string x, int id){
    string orignal = a[id] ;
    for(int i = 0; i < 7; i++){
        if ( x[i] == '1' && orignal[i] == '0' ) return false ;
    }
    return true ;
}
int get(string x, int id){
    string orignal = a[id] ;
    int cnt = 0 ;
    for(int i = 0; i < 7; i++){
        if ( orignal[i] == '1' && x[i] == '0' ) cnt++;
    }
    return cnt ;
}
int dp[2001][2001] ;
bool dfs(int x, int cur){
    if ( x == n ) {
        return cur == 0 ;
    }
    if ( dp[x][cur] != -1 ) return dp[x][cur] ;
    bool ans = false ;
    for(int i = 9; i >= 0; i--){
        if ( can(v[x], i) ){
            int need = get(v[x], i) ;
            if ( need <= cur ){
                ans |= dfs(x + 1, cur - need) ;
                if ( ans ) {
                    return dp[x][cur] = 1 ;
                }
            }
        }
    }
    return dp[x][cur] = 0;
}
string answer ;
void build(int x, int cur){
    if ( x == n ) {
        return ;
    }
    bool ans = false ;
    for(int i = 9; i >= 0; i--){
        if ( can(v[x], i) ){
            int need = get(v[x], i) ;
            if ( need <= cur ){
                ans |= dfs(x + 1, cur - need) ;
                if ( ans ) {
                    answer.push_back(i + '0') ;
                    build(x + 1, cur - need) ;
                    return ;
                }
            }
        }
    }
}
signed main(){
    fastio
    memset(dp, -1, sizeof dp) ;
    cin >> n >> k ;
    v = vector<string>(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    bool ans = dfs(0, k);
    if ( not ans ) {
        cout << -1 << endl; 
    }
    else{
        build(0, k) ;
        cout << answer << endl;
    }
    return 0; 
}