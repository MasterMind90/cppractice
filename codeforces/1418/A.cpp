#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define int long long
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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 1 ;
const ll INF = 1e18 + 10 ;
void solve(){
    int x , y , k ;
    cin >> x >> y >> k ; 
    int right = k + y * k - 1 ;
    int add = x - 1 ;
    debug() << imie(right) imie(add) ;
    int ans = (right + add - 1) / add ;
    cout << ans + k << endl;
    //int total = k + y * k ; 
    //int L = 0, R = 4e9 ;
    //int ans = -1 ;
    //while(L <= R){
    //    int mid = L + (R - L) / 2 ;
    //    debug() << imie(mid) ;
    //    int sticks = mid * (x - 1) + 1 ;
    //    debug() << imie(sticks) ;
    //    if ( sticks >= total ) {
    //        ans = mid ;
    //        R = mid - 1 ;
    //    }
    //    else L = mid + 1 ;
    //}
    //cout << ans + k << endl;
}
signed main(){
    fastio;
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}

//1
//2
//3
//4
//
//1
//5
//
//trades * (x - 1) + 1 >= k + trades / y
//
//sticks = trade * (x - 1) + 1 
//
//sticks -= k 
//
//sticks / y >= k 
//
//
//
//0 : 1
//1 : 2
//2 : mid * (x - 1) + 1 

