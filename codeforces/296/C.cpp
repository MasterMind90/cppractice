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
signed main(){
    fastio
    int n , m , k ;
    cin >> n >> m >> k ;
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    vector<pair<pair<int,int>,int> > interval(m) ;
    for(int i = 0; i < m; i++){
        cin >> interval[i].first.first >> interval[i].first.second >> interval[i].second ;
        interval[i].first.first--;
        interval[i].first.second--;
    }
    vector<int> p(m + 1) ;
    for(int i = 0; i < k; i++){
        int l , r ;
        cin >> l >> r ;
        l--, r--;
        p[l] += 1 ;
        p[r + 1] -= 1 ;
    }
    for(int i = 1; i < m + 1; i++){
        p[i] += p[i - 1] ;
    }
    debug() << imie(p) ;
    vector<int> newp(n + 1) ;
    for(int i = 0; i < m; i++){
        int L = interval[i].first.first ;
        int R = interval[i].first.second ;
        int D = interval[i].second * p[i] ;
        newp[L] += D ;
        newp[R + 1] -= D ;
    }
    for(int i = 1; i < n + 1; i++){
        newp[i] += newp[i - 1] ;
    }
    debug() << imie(newp) ;
    for(int i = 0; i < n; i++){
        cout << v[i] + newp[i] << ' ' ;
    }
    cout << endl;
    return 0; 
}