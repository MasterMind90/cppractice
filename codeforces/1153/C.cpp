#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define int long long
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
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    int n ;
    cin >> n ; 
    string s ; 
    cin >> s ; 
    if ( s[0] == '?' ) s[0] = '(' ;
    if ( s[n - 1] == '?' ) s[n - 1] = ')' ; 
    if ( s[0] != '(' || s[n - 1] != ')' || n % 2 == 1){
        cout << ":(" << endl;
        return 0 ;
    }
    int open = 0 , close = 0 ; 
    for(int i = 1; i < n - 1; i++){
        if ( s[i] == '(' ) open++ ; 
        else if ( s[i] == ')' ) close++ ;
    }
    int len = n - 2 ;
    if ( open > len / 2 || close > len / 2 ){
        cout << ":(" << endl;
        return 0 ;
    }
    open = len / 2 - open ;
    close = len / 2 - close;
    for(int i = 1; i < n - 1; i++){
        if ( s[i] == '?' ){
            if (open > 0){
                s[i] = '(' ; 
                open-- ; 
            }
            else if (close > 0){
                s[i] = ')' ; 
                close-- ;
            }
        }
    }
    int ok = 0 ; 
    for(int i = 1; i < n - 1; i++){
        char c = s[i] ; 
        assert(c != '?' );
        if ( c == '(' ) ok++ ;
        else ok-- ; 
        if ( ok < 0 ) {
            break ; 
        }
    }
    if ( ok != 0 ){
        cout << ":(" << endl;
        return 0 ;
    }
    cout << s << endl;
    return 0 ;
}