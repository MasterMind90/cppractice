#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define int long long
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
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    int n ; 
    cin >> n ; 
    vector<int> v(n) ;
    map<int,vector<int> > pos ;
    int ans = 0 ; 
    for(int i = 0; i < n; i++){
        cin >> v[i] ; 
        pos[v[i]].push_back(i) ;
        ans = max(ans, (int)pos[v[i]].size()) ;
    }
    for(int i = 1; i < 27; i++){
        vector<int> &t = pos[i] ; 
        if ( t.empty() ) continue ;
        debug() << imie(t) ;
        int m = (int) t.size() ;
        for(int j = 0; j < m ; j++){
            for(int k = j; k < m; k++){
                int b = k - j + 1;
                for(int c = 1; c < 27; c++){
                    if ( i == c ) continue ;
                    vector<int> &e = pos[c] ; 
                    if ( e.empty() ) continue ;
                    int firstIndex = t[j] ;
                    int lastIndex = t[k] ; 
                    int len = (int)e.size() ;
                    int idx = upper_bound(e.begin(), e.end(), lastIndex) - e.begin() ;
                    int after = len - idx ;
                    idx = upper_bound(e.begin(), e.end(), firstIndex) - e.begin() ;
                    int before = idx;
                    debug() << imie(e) ;
                    debug() << imie(before) imie(after) ;
                    if ( before == 0 || after == 0 ) continue ;
                    int nix = min(before, after) ;
                    ans = max(ans, nix + b + nix) ;
                    debug() << imie(ans) ;
                }
            }
        }
    }
    cout << ans << endl;
}
signed main(){
    fastio 
    int t ;
    cin >> t; 
    while(t--){
        solve() ;
    }
    return 0 ; 
}