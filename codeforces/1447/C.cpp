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
    int n , W;
    cin >> n >> W ;
    vector<pair<int,int> > v(n) ;
    int sum = 0 ;
    for(int i = 0; i < n; i++){
        cin >> v[i].first ;
        v[i].second = i ;
        sum += v[i].first ;
    }
    sort(v.begin(), v.end()) ;
    if ( sum < (W + 1) / 2 ){
        cout << -1 << endl;
        return ;
    }
    if ( v[0].first > W ){
        cout << -1 << endl;
        return ;
    }
    int cur = 0 ;
    vector<int> ans ;
    while(not v.empty()){
        if ( cur >= (W + 1) / 2 ){
            break ;
        }
        if ( v.back().first + cur > W ) {
            v.pop_back() ;
        }
        else {
            cur += v.back().first ; 
            ans.push_back(v.back().second) ;
            v.pop_back() ;
        }
    }
    if ( cur < (W + 1) / 2 ) {
        cout << -1 << endl;
        return ;
    }
    cout << (int)ans.size() << endl;
    for(int &c : ans){
        cout << c + 1 << ' ' ;
    }
    cout << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) {
        solve() ;
    }
    return 0; 
}