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
const ll N = 110 ; 
string s ;
ll n ;
ll dp[N][10] ; 
ll dfs(ll x, ll cur){
    if ( x == n ){
        if ( cur == 0 ) return 0 ; 
        return -INF ; 
    }
    if ( dp[x][cur] != -1 ) return dp[x][cur] ; 
    ll choice1 = dfs(x + 1, cur) ; 
    ll choice2 = 1 + dfs(x + 1, (cur * 10 + (s[x] - '0')) % 8 );
    return dp[x][cur] = max(choice1, choice2) ; 
}
string t = "" ; 
void build(ll x,ll cur){
    if ( x == n ) {
        return ; 
    }
    ll choice1 = dfs(x + 1, cur) ; 
    ll choice2 = 1 + dfs(x + 1, (cur * 10 + (s[x] - '0')) % 8 );
    ll optimal = dfs(x, cur) ;
    if ( optimal == choice1 ){
        build(x + 1, cur) ; 
    }
    else if ( optimal == choice2 ) {
        t += s[x] ; 
        build(x + 1, (cur * 10 + (s[x] - '0')) % 8 ) ; 
    }
}
int main(){
    fastio
    memset(dp, -1, sizeof dp) ; 
    cin >> s ;
    n = (ll) s.size() ; 
    ll ans = dfs(0, 0) ; 
    if ( ans == 0 ) puts("NO") ; 
    else{
        build(0 , 0) ;
        cout << "YES" << endl;
        cout << t << endl;
    }
    return 0 ;
}