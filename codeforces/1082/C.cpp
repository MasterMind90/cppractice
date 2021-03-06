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
    vector<vector<int> > v(m) ;
    for(int i = 0; i < n; i++){
        int s , r ;
        cin >> s >> r ;
        s-- ;
        v[s].push_back(r) ;
    }
    // vector<vector<int> > sum(m) ;
    vector<int> answer(n + 1) ;
    for(int i = 0; i < m; i++){
        vector<int> &t = v[i] ;
        sort(t.begin(), t.end()) ;
        int sz = (int) t.size() ;
        vector<int> total(sz + 1);
        for(int j = 0; j < sz; j++){
            total[j + 1] = total[j] + t[j] ;
        }
        for(int j = 1; j <= sz; j++){
            if ( total[sz] - total[sz - j] >= 0 ) answer[j] += total[sz] - total[sz - j] ;
        }
        // sum[i] = total ;
    }
    // bool ok = false ;
    // auto solve = [&](int mid){
    //     int cur = 0 ;
    //     for(int i = 0; i < m; i++){
    //         int curSum = 0 ;
    //         if ( (int)v[i].size() >= mid ){
    //             ok = true ;
    //             vector<int> & tt = sum[i]; 
    //             int sz = (int) tt.size() ;
    //             curSum = tt[sz - 1] - tt[sz - mid - 1] ;
    //             if ( curSum > 0 ) cur += curSum ;
    //         }
    //     }
    //     return cur ;
    // };
    int ans = 0 ;
    for(int i = 1; i <= n; i++){
        ans = max(ans, answer[i]) ;
    }
    cout << ans << endl;
    return 0; 
}