#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
~debug() { cerr << endl; }
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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 
const ll INF = 1e9 + 10 ;
const int N = 1e5 + 10 ; 
int n ; 
vector<int> X(N), H(N);
int dp[N][2] ;
int dfs(int x,bool direction){
    if ( x == n ){
        return 0 ; 
    }
    if ( x == n - 1 ){
        return 1;
    }
    if ( dp[x][direction] != -1 ) return dp[x][direction] ; 
    int point = 0 ; 
    if ( direction == 0 ){ // the last tree was cut to the left
        point = X[x - 1];
    }
    else{
        point = X[x - 1] + H[x - 1] ;
    }
    int ans = 0 ; 
    if ( X[x] - H[x] > point ){
        ans += 1 + dfs(x + 1, 0);
    }
    else if ( X[x] + H[x] < X[x + 1] ){
        ans += 1 + dfs(x + 1, 1);
    }
    else ans += dfs(x + 1, 0);
    return dp[x][direction] = ans ; 
}
int main(){
    fastio
    memset(dp, -1, sizeof dp);
    cin >> n ; 
    for(int i = 0; i < n; i++){
        cin >> X[i] >> H[i] ; 
    }
    // do not forget to add one to the answer for the first tree
    int ans = dfs(1,0) ; 
    cout << ans + 1 << endl;
    return 0 ;
}

