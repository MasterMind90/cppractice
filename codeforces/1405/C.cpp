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
void solve(){
    int n , k ;
    cin >> n >> k ;
    string s ;
    cin >> s ;
    vector<int> zero(n + 1) , one(n + 1) , q(n + 1) ;
    for(int i = 0; i < n; i++){
        if ( s[i] == '0' ) {
            zero[i + 1] = 1 ;
        }
        else if ( s[i] == '1' ) {
            one[i + 1] = 1 ;
        }
        else q[i + 1] = 1 ;
    }
    for(int i = 1; i < n + 1; i++){
        zero[i] += zero[i - 1] ;
        one[i] += one[i - 1] ;
        q[i] += q[i - 1] ;
    }
    int half = k / 2 ;
    for(int i = 1; i + k - 1 < n + 1; i++){
        int z = zero[i + k - 1] - zero[i - 1] ;
        int o = one[i + k - 1] - one[i - 1] ;
        // debug() << imie(i + k) imie(one[i + k]) imie(one[i - 1]) ;
        int qq = q[i + k - 1] - q[i - 1] ;
        // debug() << imie(z) imie(o) ;
        qq -= s[i - 1] == '?' ;
        if ( z > half || o > half ){
            cout << "NO" << endl;
            return ;
        }
    }
    for(int i = 0; i < k; i++){
        int o = 0 , z = 0 ; 
        for(int j = i; j < n; j += k){
            if ( s[j] == '1' ) o++ ;
            else if ( s[j] == '0' ) z++ ;
        }
        if ( o && z ) {
            cout << "NO" << endl; 
            return ; 
        }
        if ( o ) {
            for(int j = i; j < n; j += k){
                s[j] = '1' ; 
            }
        }
        else if ( z ) {
            for(int j = i; j < n; j += k){
                s[j] = '0' ; 
            }
        }
    }
    int ONE = 0 , ZERO = 0; 
    for(int i = 0; i < k; i++){
        if ( s[i] == '1' ) ONE++ ;
        else if ( s[i] == '0' ) ZERO++ ; 
    }
    int remOne = k / 2 - ONE ; 
    int remZero = k / 2 - ZERO ; 
    for(int i = 0; i < k; i++){
        if ( s[i] == '?' && remZero ) {
            for(int j = i; j < n; j += k){
                s[j] = '0' ; 
            }
            remZero-- ;
        }
        else if ( s[i] == '?' && remOne ) {
            for(int j = i; j < n; j += k){
                s[j] = '1' ; 
            }
            remOne-- ;
        }
    }
    debug() << imie(s) ;
    zero.clear() ;
    zero.resize(n + 1) ;
    one.clear() ;
    one.resize(n + 1) ;
    for(int i = 0; i < n; i++){
        if ( s[i] == '0' ) {
            zero[i + 1] = 1 ;
        }
        else if ( s[i] == '1' ) {
            one[i + 1] = 1 ;
        }
    }
    for(int i = 1; i < n + 1; i++){
        zero[i] += zero[i - 1] ;
        one[i] += one[i - 1] ;
    }
    for(int i = 1; i + k - 1 < n + 1; i++){
        int z = zero[i + k - 1] - zero[i - 1] ;
        int o = one[i + k - 1] - one[i - 1] ;
        // debug() << imie(i + k) imie(one[i + k]) imie(one[i - 1]) ;
        int qq = q[i + k - 1] - q[i - 1] ;
        // debug() << imie(z) imie(o) ;
        qq -= s[i - 1] == '?' ;
        debug() << imie(i) imie(z) imie(o) ; 
        if ( z > half || o > half ){
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}

// 10011
// ?1?1