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
    string s ;
    cin >> s ;
    int n = (int) s.size() ;
    vector<int> pos[26] ;
    for(int i = 0; i < n; i++){
        char& c = s[i] ;
        pos[c - '0'].emplace_back(i) ;
    }
    int ans = 0;
    for(int i = 0; i < 26; i++){
        ans = max(ans, (int)pos[i].size() ) ;
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if ( i == j ) continue ;
            bool ok = true ;
            int cur = -1 ;
            int cnt = 0 ;
            debug() << imie(i) imie(j) ;
            while(ok){
                vector<int>& f = pos[i] ;
                vector<int>& se = pos[j] ;
                int idx1 = upper_bound(f.begin(), f.end(), cur) - f.begin() ;
                if ( idx1 == (int)f.size() ){
                    break ;
                }
                idx1 = f[idx1] ;
                int idx2 = upper_bound(se.begin(), se.end(), idx1) - se.begin();
                if ( idx2 == (int) se.size() ) {
                    break ;
                }
                cur = se[idx2] ;
                cnt++ ;
            }
            ans = max(ans, 2 * cnt) ;
        }
    }
    cout << n - ans << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}