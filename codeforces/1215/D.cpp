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
void no(){
    cout << "Bicarp" << endl;
    exit(0) ;
}
void yes(){
    cout << "Monocarp" << endl;
    exit(0) ;
}
signed main(){
    fastio
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    int a = 0 , b = 0 ;
    int first = 0 , second = 0 ;
    for(int i = 0; 2 * i < n ; i++){
        a += s[i] == '?' ;
        b += s[n - i - 1] == '?' ;
        if ( s[i] >= '0' && s[i] <= '9' ) first += s[i] - '0' ;
        if ( s[n - i - 1] >= '0' && s[n - i - 1] <= '9' ) second += s[n - i - 1] - '0' ;
    }
    debug() << imie(first) imie(second) ;
    debug() << imie(a) imie(b) ;
    if ( a + b == n ) {
        no();
    }
    if ( a == b ) {
        if ( first != second ) {
            yes() ;
        }
        else no() ;
    }
    // ?0??450?
    if ( a > b ) {
        int rem = a - b ;
        int mono = (rem + 1) / 2 ;
        int bi = rem / 2 ;
        int naxMono = first + 9 * mono ;
        int biNix = naxMono ;
        int biNax = naxMono + 9 * bi ;
        if ( second < biNix || second > biNax ) {
            yes() ;
        }
        int nixMono = first ;
        biNix = first ;
        biNax = first + 9 * bi ;
        if ( second < biNix || second > biNax ){
            yes() ;
        }
        no() ;
    }
    if ( a < b ) {
        int rem = b - a ;
        int mono = (rem + 1) / 2 ;
        int bi = rem / 2 ;
        int naxMono = second + 9 * mono ;
        int biNix = naxMono ;
        int biNax = naxMono + 9 * bi ;
        if ( first < biNix || first > biNax ){
            yes() ;
        }
        int nixMono = second ;
        biNix = second ;
        biNax = second + 9 * bi ;
        if ( first < biNix || first > biNax ){
            yes() ;
        }
        no() ;
    }
    return 0; 
}