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
class Rectangle{
public:
    int a , b , x , y ;
    Rectangle(int a, int b, int x, int y){
        this->a = a ;
        this->b = b ;
        this->x = x ;
        this->y = y ;
    }
    Rectangle(){}
    int overlapArea(Rectangle r2){
        if ( r2.a >= this->x ) return 0 ; // black is to the right of white
        if ( r2.b >= this->y ) return 0 ; // black is above white 
        if ( r2.x <= this->a ) return 0 ; // black is to the left of white
        if ( r2.y <= this->b ) return 0 ; // black is below white
        int A = max(this->a, r2.a) ;
        int B = max(this->b, r2.b) ;
        int X = min(this->x, r2.x) ;
        int Y = min(this->y, r2.y) ;
        return ( X - A ) * ( Y - B ) ;
    }
    Rectangle overlapRectangle(Rectangle r2){
        if ( r2.a >= this->x ) return Rectangle(0, 0, 0, 0) ; // black is to the right of white
        if ( r2.b >= this->y ) return Rectangle(0, 0, 0, 0) ; // black is above white 
        if ( r2.x <= this->a ) return Rectangle(0, 0, 0, 0) ; // black is to the left of white
        if ( r2.y <= this->b ) return Rectangle(0, 0, 0, 0) ; // black is below white
        int A = max(this->a, r2.a) ;
        int B = max(this->b, r2.b) ;
        int X = min(this->x, r2.x) ;
        int Y = min(this->y, r2.y) ;
        return Rectangle(A, B, X, Y) ;
    }
};
int getArea(Rectangle r){
    return ( r.x - r.a ) * ( r.y - r.b ) ;
}
signed main(){
    fastio
    Rectangle r[3] ;
    for(int i = 0; i < 3; i++){
        cin >> r[i].a >> r[i].b >> r[i].x >> r[i].y ;
    }
    int total = getArea(r[0]) ;
    int blackOverlap = r[0].overlapArea(r[1].overlapRectangle(r[2])) ;
    total -= r[0].overlapArea(r[1]) ;
    total -= r[0].overlapArea(r[2]) ;
    total += blackOverlap ; 
    if ( total <= 0 ) {
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
    return 0; 
}