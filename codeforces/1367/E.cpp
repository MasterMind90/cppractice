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
int n , k ;
int get(int len, vector<int> cnt){
    int L = 1, R = 1e5 ;
    int ans = -1;
    while(L <= R){
        int mid = L + (R - L) / 2 ;
        if ( mid * len > n ){
            R = mid - 1;
            continue ;
        }
        debug() << imie(mid) imie(len) imie(ans) ;
        int t = 0 ;
        for(int &c : cnt){
            t += c / mid ;
        }
        debug() << imie(t)  ;
        if ( t < len ){
            R = mid - 1;
        }
        else {
            ans = mid ;
            L = mid + 1;
        }
    }
    debug() << imie(ans) ;
    assert(ans != -1) ;
    return ans * len ;
}
void solve(){
    cin >> n >> k ; 
    string s ;
    cin >> s ;
    vector<int> cnt(26) ;
    for(char &c : s){
        ++cnt[c - 'a'] ;
    }
    int ans = 1;
    for(int i = 0; i < n; i++){
        if ( k % (i + 1) == 0 ){
            ans = max(ans, i + 1) ;
            ans = max(ans, get(i + 1, cnt));
        }
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

// aaaaaaabbbbbcdddddde
// a 7 
// b 5
// c 1
// d 6
// e 1

// abaddabaddabadd
// ...............
// ...............

