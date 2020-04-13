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
char v[9][9] ;
void check(int x, int y){
    for(int j = 1; j < 10; j++){
        if ( v[x][y] == j + '0' ) continue ;
        v[x][y] = j + '0' ; 
        break ;
    }
}
void solve(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> v[i][j] ;
        }
    }
    check(0, 0) ;
    check(1, 3) ;
    check(2, 6) ;
    check(3, 1) ;
    check(4, 5) ;
    check(5, 7) ;
    check(6, 2) ;
    check(7, 4) ;
    check(8, 8) ;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << v[i][j] ;
        }
        cout << endl;
    }
}
signed main(){
    fastio 
    int t ;
    cin >> t; 
    while(t--){
        solve() ;
    }
    return 0 ; 
}