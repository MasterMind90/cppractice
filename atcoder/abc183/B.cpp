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
const double EPS = 1e-6 ; 
signed main(){
    fastio
    int a , b , x , y ; 
    cin >> a >> b >> x >> y ; 
    if ( a > x ) {
        swap(a, x) ;
        swap(b, y) ;
    }
    long double L = a ; 
    long double R = x ; 
    long double ans = -1 ;
    for(int rep = 0; rep < 200; rep++){
        long double mid = (L + R) / 2 ;
        long double opp1 = b ; 
        long double adj1 = mid - a; 
        long double angle1 = atan(opp1 / adj1) ;
        long double opp2 = y ; 
        long double adj2 = x - mid ;
        long double angle2 = atan(opp2 / adj2) ;
        ans = mid ;
        if ( angle1 < angle2 ) {
            R = mid ; 
        }
        else L = mid ; 
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0; 
}
//5
//1 2 3 4 5
//1 3 4 5 6
//3 3 6 7 8
//6 6 6 10 11
//10 10 10 10 15
//15 15 15 15 15 
//
//1 2 3
//1 3 4
//3 3 6
//6 6 6
