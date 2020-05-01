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
int getColor(int x,int y){
    if (y & 1){
        if ( x & 1 ) return 0 ; // white ;
        return 1 ; // black ; 
    }
    else{
        if ( x & 1 ){
            return 1 ;
        }
        else return 0 ; 
    }
}
int getWhite(int x,int y, int a, int b){
    int c = a ; 
    int d = y ;
    int n = x ;
    int m = b ; 
    int total = ( a - x + 1 ) * ( b - y + 1 ) ; 
    if (getColor(x, y) == getColor(a, b) && getColor(c, d) == getColor(n, m) && getColor(x, y) == getColor(n , m) && getColor(x, y) == 0 ) return (total + 1) / 2;
    return total / 2 ;
}
int getBlack(int x,int y, int a, int b){
    int c = a ; 
    int d = y ;
    int n = x ;
    int m = b ; 
    int total = ( a - x + 1 ) * ( b - y + 1 ) ; 
    if (getColor(x, y) == getColor(a, b) && getColor(c, d) == getColor(n, m) && getColor(x, y) == getColor(n , m) && getColor(x, y) == 1 ) return (total + 1) / 2;
    return total / 2 ;
}
bool overlap(int x, int y, int n, int m, int a, int b, int c, int d){
    if ( a > n || c < x ) return false ;
    if ( b > m || d < y ) return false ;
    return true ;
}
void solve(){
    int n , m ;
    cin >> n >> m ;
    int x1, y1, x2, y2 ;
    cin >> x1 >> y1 >> x2 >> y2 ;
    swap(x1, y1) ;
    swap(x2, y2) ;
    int white = getWhite(1, 1, n, m) ;
    int black = getBlack(1, 1, n, m) ;
    black -= getBlack(x1, y1, x2, y2) ;
    white += getBlack(x1, y1, x2, y2) ;
    int a , b , c , d ;
    cin >> a >> b >> c >> d ;
    swap(a, b) ;
    swap(c, d) ;
    if ( overlap(x1, y1, x2, y2, a, b, c , d) ){
        int lowerX = max(x1, a) ; 
        int lowerY = max(y1, b) ;
        int topX = min(x2, c) ;
        int topY = min(y2, d) ;
        int bb = getBlack(lowerX, lowerY, topX, topY);
        int tb = getBlack(a, b, c, d) ;
        tb -= bb ; 
        int w = getWhite(lowerX, lowerY, topX, topY);
        int tw = getWhite(a, b, c, d) ;
        tw -= w ;
        white -= tw ; 
        black += tw ;
        white -= (topX - lowerX + 1) * (topY - lowerY + 1) ;
        black += (topX - lowerX + 1) * (topY - lowerY + 1) ;
    }
    else{
        white -= getWhite(a, b, c, d) ;
        black += getWhite(a, b, c, d) ;
    }
    cout << white << ' ' << black << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}