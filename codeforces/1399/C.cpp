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
void solve(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    map<int,int> mp ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
        mp[v[i]]++;
    }
    int nax = *max_element(v.begin(), v.end()) ;
    nax += nax ;
    int ans = 0 ;
    for(int i = 1; i <= nax; i++){
        debug() << imie(i) ;
        map<int,int> cnt = mp ;
        int teams = 0 ;
        for(int j = 0; j < n; j++){
            if ( v[j] < i ){
                if ( i - v[j] == v[j] ){
                    if ( cnt[v[j]] > 1 ) {
                        cnt[v[j]] -= 2 ;
                        teams++ ;
                    }
                    continue ;
                }
                if ( cnt.count(v[j]) && cnt.count(i - v[j]) && cnt[v[j]] > 0 && cnt[i - v[j]] > 0 ){
                    cnt[v[j]]--;
                    cnt[i - v[j]]--;
                    teams++ ;
                }
            }
        }
        debug() << imie(teams) ;
        ans = max(ans, teams) ;
    }
    cout << ans << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}
