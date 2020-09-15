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
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ;
int n;
vector<vector<int> > v(100000 , vector<int> (3));
int dp[100000 + 1][4];
int dfs(int i , int last) {
    if(i == n) {
        return 0;
    }
    if(dp[i][last] != -1) return dp[i][last] ;
    int ans = 0;

    if(last == 0) {
        ans = max(ans , dfs(i + 1 , 1) + v[i][0]);
        ans = max(ans , dfs(i + 1 , 2) + v[i][1]);
        ans = max(ans , dfs(i + 1 , 3) + v[i][2]);
    }
    else if(last == 1){
        ans = max(ans , dfs(i + 1 , 2) + v[i][1]);
        ans = max(ans , dfs(i + 1 , 3) + v[i][2]);
    }
    else if ( last == 2 ) {
        ans = max(ans , dfs(i + 1 , 1) + v[i][0]);
        ans = max(ans , dfs(i + 1 , 3) + v[i][2]);
    }
    else if ( last == 3 ) {
        ans = max(ans , dfs(i + 1 , 1) + v[i][0]);
        ans = max(ans , dfs(i + 1 , 2) + v[i][1]);
    }
    return dp[i][last] = ans ; 
}
signed main(){
    fastio
    memset(dp , -1 , sizeof dp);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }
    int ans = dfs(0 , 0);
    cout << ans << endl;
    return 0; 
}