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
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    string s ;
    cin >> s ;
    int n = (int) s.size() ; 
    set<int> SET[26] ;
    for(int i = 0; i < n; i++){
        SET[s[i] - 'a'].insert(i + 1) ;
    }
    int q ; 
    cin >> q ;
    while(q--){
        int t ; 
        cin >> t ;
        if ( t == 1 ){
            int pos ; 
            char c ;
            cin >> pos >> c ;
            for(int j = 0; j < 26; j++){
                if ( SET[j].count(pos) ) {
                    SET[j].erase(pos);
                    break;
                }
            }
            SET[c - 'a'].insert(pos);
        }
        else{
            int l , r ;
            cin >> l >> r ;
            int ans = 0 ; 
            for(int j = 0; j < 26; j++){
                if ( SET[j].empty() ) continue ;
                auto it = SET[j].lower_bound(l) ; 
                if ( it == SET[j].end() ) continue ; 
                int c = *it ;
                if ( c <= r ) ans++ ;
            }
            cout << ans << endl;
        }
    }
    return 0; 
}