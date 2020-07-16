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
    int n , m ;
    cin >> n >> m ;
    int ans = INF ;
    for(int i = 1; i <= m - 1; i++){
        int a = i * n ; 
        int rem = m - i ;
        int b = n / 2 * rem ;
        int c = (n + 1) / 2 * rem ;
        vector<int> v = {a, b ,c} ;
        sort(v.begin(), v.end()) ;
        ans = min(ans, v[2] - v[0]) ;
        b = rem / 2 * n ;
        c = (rem + 1) / 2 * n ;
        vector<int> t = {a, b , c} ;
        sort(t.begin(), t.end()) ;
        ans = min(ans, t[2] - t[0]) ;
    }
    for(int i = 1; i <= n - 1; i++){
        int a = i * m ;
        int rem = n - i ;
        int b = m / 2 * rem ;
        int c = (m + 1) / 2 * rem ;
        vector<int> v = {a, b ,c} ;
        sort(v.begin(), v.end()) ;
        ans = min(ans, v[2] - v[0]) ;
        b = rem / 2 * m ;
        c = (rem + 1) / 2 * m ;
        vector<int> t = {a, b , c} ;
        sort(t.begin(), t.end()) ;
        ans = min(ans, t[2] - t[0]) ;
    }
    cout << ans << endl;
    return 0; 
}