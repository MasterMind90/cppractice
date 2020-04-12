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
const ll N = 1e5 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio 
    int n ; 
    cin >> n ;
    string s ;
    cin >> s ;
    int R = 0 , G = 0, B = 0 ;
    for(char &c : s){
        if ( c == 'R' ) R++ ;
        else if ( c == 'B' ) B++ ;
        else G++ ;
    }
    int ans = 0 ;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n; j++){
            int before = i - j ; 
            int after = i + j ;
            if ( before < 0 || after >= n ) break ;
            set<int> ss ; 
            ss.insert(s[i]) ;
            ss.insert(s[before]) ;
            ss.insert(s[after]) ;
            if ( ss.size() == 3 ) ans++ ;
        }
    }
    debug() << imie(ans) ;
    int curR = 0 , curB = 0 , curG = 0 ;
    int total = 0 ;
    for(int i = 0; i < n; i++){
        if ( s[i] == 'R' ){
            int beforeB = curB ;
            int afterG = G - curG ;
            total += beforeB * afterG ;
            int beforeG = curG ;
            int afterB = B - curB ;
            total += beforeG * afterB ;
            curR++ ;
        }
        else if ( s[i] == 'B' ){
            int beforeR = curR ;
            int afterG = G - curG ;
            total += beforeR * afterG ;
            int beforeG = curG ;
            int afterR = R - curR ;
            total += beforeG * afterR ;
            curB++ ;
        }
        else{
            int beforeR = curR ;
            int afterB = B - curB ;
            total += beforeR * afterB ;
            int beforeB = curB ;
            int afterR = R - curR ;
            total += beforeB * afterR ;
            curG++ ;
        }
    }
    cout << total - ans << endl;
    return 0 ; 
}