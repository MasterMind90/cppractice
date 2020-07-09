#ifndef LOCAL
#pragma GCC optimize("O3")
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
map<int,int> mp ;
void factor(int x){
    for(int i = 2; i * i <= x; i++){
        bool ok = false ;
        int cnt = 0 ;
        while(x % i == 0){
            ok = true ;
            cnt++ ;
            x /= i ;
        }
        if ( ok ){
            if ( mp.count(i) ) {
                mp[i] = max(mp[i], cnt) ;
            }
            else mp[i] = cnt ;
        }
    }
    if ( x > 1 ) {
        if ( mp.count(x) ) {
            mp[x] = max(mp[x], 1LL) ;
        }
        else mp[x] = 1 ;
    }
}
int fast(int a, int b){
    if ( b == 0 ) return 1 ;
    if ( b == 1 ) return a ; 
    int y = fast(a, b / 2) % MOD ;
    int ans = y * y; 
    ans %= MOD ;
    if ( b & 1 ) ans *= a ; 
    return ans % MOD ;
}
int inverse(int x){
    return fast(x, MOD - 2) ;
}
signed main(){
    fastio
    debug() << imie((12 * inverse(12) % MOD)) ;
    // int ans = 36 * inverse(2) ;
    // ans %= MOD ;
    // ans *= inverse(3) ;
    // ans %= MOD ;
    // ans *= inverse(4) ;
    // ans %= MOD ;
    // debug() << imie(ans) ;
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
        factor(v[i]) ;
    }
    debug() << imie(mp) ;
    int ans = 1; 
    for(auto &p : mp){
        for(int i = 0; i < p.second; i++){
            ans *= p.first ;
            ans %= MOD ;
        }
    }
    int sum = 0 ;
    for(int i = 0; i < n; i++){
        int c = ans * inverse(v[i]) ;
        c %= MOD ;
        sum += c ;
        sum %= MOD ;
    }
    cout << sum << endl ;
    return 0; 
}