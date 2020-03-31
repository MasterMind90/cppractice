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
int a , b , c , d ;
int x , y , x1, y1, x2, y2 ; 
bool inside(int x, int y){
    if ( x >= x1 && x <= x2 && y >= y1 && y <= y2 ){
        return true ; 
    }
    return false;
}
void solve(){
    cin >> a >> b >> c >> d ;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2 ; 
    if ( a >= b ) x -= (a - b) ; 
    else x += (b - a) ; 
    if ( c >= d ) y -= (c - d) ; 
    else y += (d - c) ; 
    if ( inside(x, y) ){
        if ( (a || b) && abs(x1 - x2) == 0 ){
            cout << "No" << endl;
        }
        else if ( (c || d) && abs(y1 - y2) == 0 ){
            cout << "No" << endl;
        }
        else cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
signed main(){
    fastio 
    int t ;
    cin >> t ;
    while(t--) solve() ; 
    return 0 ; 
}