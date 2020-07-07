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
int toInt(string s){
    stringstream ss ;
    ss << s ;
    int x ;
    ss >> x ;
    return x ;
}
signed main(){
    fastio
    // double x ;
    // cin >> x ;
    // stringstream ss ;
    // ss << x ;
    // string s ;
    // ss >> s ;
    // debug() << imie(x) ;
    // debug() << imie(s) ;
    string s ;
    cin >> s;
    int n = (int) s.size() ;
    if ( s.substr(2) == "0e0" ){
        cout << s[0] << endl ;
        return 0 ;
    }
    int e = 0 ;
    for(int i = 0; i < n; i++){
        if ( s[i] == 'e' ) e = i ;
    }
    int b = toInt(s.substr(e + 1));
    int len = 0 ;
    bool flag = false; 
    int dot = 0 ; 
    for(int i = 0; i < n; i++){
        char &c = s[i] ;
        if ( c == 'e' ) break ;
        if ( c == '.' ) {
            dot = i ; 
            flag = true ;
        }
        else if ( flag ) len++ ;
    }
    debug() << imie(len) ;
    debug() << imie(b) ;
    if ( len >= b ){
        for(int i = 0; i < dot + b + 1; i++){
            if ( s[i] == '.' ) continue ;
            cout << s[i] ;
        }
        if ( len != b ) cout << '.' ; 
        for(int i = dot + b + 1; i < n; i++){
            if ( s[i] == 'e' ) break ;
            cout << s[i] ; 
        }
        cout << endl ; 
    }
    else{
        for(int i = 0; i < n - 1; i++){
            if ( s[i] == 'e' ) break ;
            if ( s[i] == '.' ) continue ;
            cout << s[i] ;
        }
        for(int i = 0; i < b - len; i++){
            cout << '0' ; 
        }
        cout << endl ;
    }

    return 0; 
}
