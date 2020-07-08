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
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    debug() << imie(s) ;
    vector<vector<int> > v(n) ;
    vector<int> freq(26) ;
    for(int i = 0; i < n; i++){
        freq[s[i] - 'a']++;
        v[i] = freq ;
        debug() << imie(freq) ;
        debug() << imie(v[i]) ;
    }
    int q ;
    cin >> q ;
    while(q--){
        string x ;
        cin >> x ;
        vector<int> cnt(26) ;
        for(char &c : x){
            cnt[c - 'a']++ ;
        }
        int L = 0, R = n - 1; 
        int ans = -1 ;
        while(L <= R){
            int mid = L + (R - L) / 2;
            vector<int> &c = v[mid] ;
            bool ok = true ;
            for(int i = 0; i < 26; i++){
                if ( cnt[i] > c[i] ) {
                    ok = false ;
                    break ;
                }
            }
            if ( ok ) {
                ans = mid ;
                R = mid - 1;
            }
            else L = mid + 1;
        }
        assert(ans != -1) ;
        cout << ans + 1 << endl; 
    }
    return 0; 
}