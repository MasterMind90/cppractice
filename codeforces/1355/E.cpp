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
signed main(){
    fastio
    int n , a , r , m ; 
    cin >> n >> a >> r >> m ; 
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    auto cost1 = [&](int need, int extra){
        int c = min(need, extra) ;
        need -= c ;
        extra -= c ;
        return c * m + need * a + extra * r ;
    };
    auto cost2 = [&](int need, int extra){
        return need * a + extra * r;
    };
    int L = 0, R = 2e9 ;
    int ans = INF ;
    while(L <= R){
        int mid = L + (R - L) / 2;
        debug() << imie(mid) ;
        int extra = 0 ;
        int need = 0 ;
        for(int i = 0; i < n; i++){
            if ( v[i] >= mid ) extra += v[i] - mid ;
            else need += mid - v[i] ;
        }
        int ans1 = cost1(need, extra) ;
        int ans2 = cost2(need, extra) ;
        debug() << imie(need) imie(extra) imie(ans1) imie(ans2) ;
        int X = min(ans1, ans2) ;
        extra = 0 ; 
        need = 0 ;
        int c = mid + 1;
        for(int i = 0; i < n; i++){
            if ( v[i] >= c ) extra += v[i] - c ;
            else need += c - v[i] ;
        }
        ans1 = cost1(need, extra) ;
        ans2 = cost2(need, extra) ;
        int Y = min(ans1, ans2) ;
        debug() << imie(X) ;
        debug() << imie(Y) ;
        ans = min(ans, X) ;
        ans = min(ans, Y) ;
        if ( X < Y ){
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << ans << endl;
    return 0; 
}