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
    int n , k ; 
    cin >> n >> k ; 
    vector<int> both , alice, bob;
    for(int i = 0; i < n; i++){
        int t , a , b ;
        cin >> t >> a >> b ;
        if ( a == 1 && b == 1 ) both.emplace_back(t) ;
        else if ( a == 1 ){
            alice.emplace_back(t) ;
        }
        else if ( b == 1 ){
            bob.emplace_back(t) ;
        }
    }
    sort(both.begin(), both.end()) ;
    sort(alice.begin(), alice.end()) ;
    sort(bob.begin(), bob.end()) ;
    debug() << imie(both) ;
    debug() << imie(alice) ;
    debug() << imie(bob) ;
    vector<int> a((int)both.size() + 1) ;
    vector<int> b((int)alice.size() + 1) ;
    vector<int> c((int)bob.size() + 1) ;
    for(int i = 0; i < (int)both.size(); i++){
        a[i + 1] = a[i] + both[i] ;
    }
    for(int i = 0; i < (int)alice.size(); i++){
        b[i + 1] = b[i] + alice[i] ;
    }
    for(int i = 0; i < (int)bob.size(); i++){
        c[i + 1] = c[i] + bob[i] ;
    }
    int ans = INF ;
    if ( both.size() >= k ) {
        ans = a[k] ;
    }
    for(int i = 0; i < (int) both.size() + 1; i++){
        int cur = a[i] ;
        int rem = k - i ;
        if ( rem >= 0 && rem < (int)b.size() && rem < (int) c.size()){
            ans = min(ans, cur + b[rem] + c[rem]) ;
        }
    }
    if ( ans == INF ) cout << -1 << endl;
    else cout << ans << endl;
    return 0; 
}