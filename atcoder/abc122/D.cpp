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
ll n;
map<pair<ll,string>, ll> dp ;
string s = "ACGT" ;
const long long MOD = 1e9 + 7 ; 
bool ok(string x){
    if ( x.substr(0,3) == "AGC" || x.substr(1,3) == "AGC" ) return false;
    swap(x[0],x[1]) ; 
    if ( x.substr(0,3) == "AGC" || x.substr(1,3) == "AGC" ) return false;
    swap(x[0],x[1]) ; 
    swap(x[1],x[2]) ; 
    if ( x.substr(0,3) == "AGC" || x.substr(1,3) == "AGC" ) return false;
    swap(x[1],x[2]) ; 
    swap(x[2],x[3]);
    if ( x.substr(0,3) == "AGC" || x.substr(1,3) == "AGC" ) return false;
    return true ;
}
ll dfs(ll x, string last3){
    if ( x == n ){
        return 1 ;
    }
    if ( dp[make_pair(x,last3)] ) return dp[make_pair(x,last3)];
    ll ans = 0 ; 
    for(ll i = 0; i < 4; i++){
        if ( ok(last3 + s.substr(i,1) ) ){
            ans = ans % MOD + dfs(x + 1, last3.substr(1) + s.substr(i,1) )  % MOD ;
        }
    }
    return dp[make_pair(x,last3)] = ans % MOD ;
}
int main(){
    fastio
    cin >> n ;
    ll ans = dfs(0, "TTT") ;
    cout << ans << endl;
    return 0 ;
}
