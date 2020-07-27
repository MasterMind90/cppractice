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
int digit(int x){
    int cnt = 0 ;
    while(x != 0){
        x /= 10 ;
        cnt++ ;
    }
    return cnt ;
}
int POW(int x, int y){
    int ans = 1;
    for(int i = 0; i < y; i++){
        ans *= x ;
    }
    return ans ;
}
signed main(){
    fastio
    int n ; 
    cin >> n ;
    map<pair<int,int>, int > mp ;
    for(int i = 1; i < n + 1; i++){
        pair<int,int> p = make_pair(i / POW(10, digit(i) - 1), i % 10);
        mp[p]++;
    }
    int ans = 0 ;
    for(int i = 1; i < n + 1; i++){
        int first = i / POW(10, digit(i) - 1) ;
        int last = i % 10 ;
        if ( mp.count(make_pair(last, first)) ){
            ans += mp[make_pair(last, first)];
        }
    }
    cout << ans << endl;
    return 0; 
}