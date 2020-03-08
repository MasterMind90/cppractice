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
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
const double EPS = 1e-6 ; 
signed main(){
    fastio
    string s ;
    cin >> s ;
    int n = (int) s.size() ; 
    int q ;
    cin >> q; 
    bool isReversed = false ;
    string left = "" , right = "" ;
    while(q--){
        int t ;
        cin >> t ;
        if ( t == 1 ){
            isReversed ^= 1 ; 
        }
        else{
            int k ;
            char c ;
            cin >> k >> c ; 
            if ( not isReversed ){
                if ( k == 1 ){
                    left.push_back(c) ;
                }
                else right.push_back(c) ;
            }
            else{
                if ( k == 1 ){
                    right.push_back(c) ;
                }
                else left.push_back(c) ;
            }
        }
    }
    if ( isReversed ){
        for(int i = (int)right.size() - 1; i >= 0; i--){
            cout << right[i] ; 
        }
        for(int i = (int)s.size() - 1; i >= 0; i--){
            cout << s[i] ; 
        }
        cout << left << endl ; 
    }
    else{
        for(int i = (int)left.size() - 1; i >= 0; i--){
            cout << left[i] ; 
        }
        cout << s << right << endl;
    }
    return 0; 
}