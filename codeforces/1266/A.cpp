#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
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
const ll N = 2e6 + 10 ;
const ll INF = 1e9 + 10 ;
int main(){
    fastio
    int t; 
    cin >> t ;
    while(t--){
        string s ; 
        cin >> s ; 
        bool zero = false ;
        bool other = false ;
        int index = -1 ; 
        int n = (int) s.size() ; 
        for(int i = 0; i < n;i++){
            if ( s[i] == '0' ) {
                zero = true ; 
                index =  i ;
            }
            else other = true ; 
        }
        if ( !zero ){
            cout << "cyan" << endl;
            continue ; 
        }
        if ( zero && !other ){
            cout << "red" << endl;
            continue ; 
        }
        bool even = false ;
        for(int i = 0; i < n;i++){
            if ( index == i ) continue ; 
            if ( (s[i] - '0') % 2 == 0 ) even = true ; 
        }
        if ( !even ) {
            cout << "cyan" << endl;
            continue ; 
        }
        int sum = 0 ; 
        for(char c : s){
            sum += (c - '0') ;
        }
        if ( sum % 3 == 0 )
            cout << "red" << endl;
        else
            cout << "cyan" << endl;
    }
    return 0; 
}