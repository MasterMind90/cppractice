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
void solve(){
    int n ;
    cin >> n ;
    vector<int> v ;
    for(int i = 1; i < n + 1; i++){
        v.push_back(i) ;
    }
    vector<pair<int,int> > ans ;
    while((int)v.size() >= 2){
        int a = v.back() ; v.pop_back() ;
        int b = v.back() ; v.pop_back() ;
        ans.emplace_back(a, b) ;
        v.push_back((a + b + 1) / 2) ;
    }
    cout << v.back() << endl;
    for(auto &p : ans){
        cout << p.first << ' ' << p.second << endl;
    }
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}
// 1 3 

// 2 4

// 2 2 4

// 1 2 3 4
// 1 3 3
// 1 3
// // 1 2 3 4 5 6

// 1 2 3 4 5 6
// 1 3 4 4 5
// 1 4 4 4
// 1 4 4
// 1 4 
// 3


// 2 3 4 4 5
// 3 3 4 5
// 3 4 4
// 3 4
// 4 

// 7
// 1 2 3 4 5 6 7
// 2 3 4 4 5 6

// 1 2 3
// 1 3

// 1 2 3 4 5 6 7 8 9

// 2 9
// 1 3 4 5 6 6 7 8
// 1 3 4 5 6 7 8
// 1 3 4 5 7
// 1 3 4 6
// 1 4
// 3

// 1 2 3 4 5 6 7 8
// 1 3
// 2 


