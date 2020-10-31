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
    int n , k ;
    cin >> n >> k ; 
    vector<int> a(k) ;
    for(int i = 0; i < k; i++){
        cin >> a[i] ;
    }
    vector<int> v ;
    for(int i = 0; i < n; i++){
        v.emplace_back(i + 1) ;
    }
    int leader = 0 ;
    for(int i = 0; i < k; i++){
        int cur = a[i] ;
        int m = (int) v.size() ;
        cur %= m ;
        int index = (leader + cur) % m ;
        // 1 2 3 4 5
        // 0 1 2 3 4
        cout << v[index] << ' ' ;
        int after = v[(index + 1) % m] ;
        v.erase(v.begin() + index) ;
        debug() << imie(v) ;
        for(int j = 0; j < v.size(); j++){
            if ( v[j] == after ) {
                leader = j ;
                debug() << "ok" imie(j) ;
                break ;
            }
        }
    }
    cout << endl;
    return 0; 
}