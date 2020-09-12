#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define int long long
#define sim template < class c
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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 1 ;
const ll INF = 1e18 + 10 ;
int n ;
vector<int> v ;
//int dfs(int x, int cur, ){
//    if ( x == n ) {
//        if ( cur == 0 ) return 1 ;
//
//    }
//    int ans = dfs(x + 1, cur) ;
//    if ( cur ) {
//        ans = max(ans, v[x] * dfs(x + 1, cur - 1)) ;
//    }
//    return ans ;
//}
void solve(){
    cin >> n ;
    v = vector<int>(n) ;
    deque<int> neg, pos ;
    int have = 0 ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
        if ( v[i] == 0 ) have = 1 ;
        if ( v[i] < 0 ) neg.emplace_back(v[i]) ;
        else pos.emplace_back(v[i]);
    }
    sort(neg.begin(), neg.end()) ;
    sort(pos.begin(), pos.end()) ;
    int ans = -INF ; // high high
    for(int i = 0; i <= min(5LL, (int) neg.size()); i++){
        int tmp = 1 ;
        for(int j = 0; j < i; j++){
            tmp *= neg[j] ;
        }
        if ( i == 5 ) ans = max(ans, tmp) ;
        if ( (int)pos.size() < 5 - i ) continue ;
        for(int j = 0; j < 5 - i; j++){
            tmp *= pos[(int) pos.size() - j - 1] ;
        }
        ans = max(ans, tmp) ;
    }
    reverse(neg.begin(), neg.end()) ; // low neg high pos 
    for(int i = 0; i <= min(5LL, (int) neg.size()); i++){
        int tmp = 1 ;
        for(int j = 0; j < i; j++){
            tmp *= neg[j] ;
        }
        if ( i == 5 ) ans = max(ans, tmp) ;
        if ( (int)pos.size() < 5 - i ) continue ;
        for(int j = 0; j < 5 - i; j++){
            tmp *= pos[(int) pos.size() - j - 1] ;
        }
        ans = max(ans, tmp) ;
    }
    reverse(pos.begin(), pos.end()) ; // low neg low pos 
    for(int i = 0; i <= min(5LL, (int) neg.size()); i++){
        int tmp = 1 ;
        for(int j = 0; j < i; j++){
            tmp *= neg[j] ;
        }
        if ( i == 5 ) ans = max(ans, tmp) ;
        if ( (int)pos.size() < 5 - i ) continue ;
        for(int j = 0; j < 5 - i; j++){
            tmp *= pos[(int) pos.size() - j - 1] ;
        }
        ans = max(ans, tmp) ;
    }
    reverse(neg.begin(), neg.end()) ; // high neg , low pos 
    for(int i = 0; i <= min(5LL, (int) neg.size()); i++){
        int tmp = 1 ;
        for(int j = 0; j < i; j++){
            tmp *= neg[j] ;
        }
        if ( i == 5 ) ans = max(ans, tmp) ;
        if ( (int)pos.size() < 5 - i ) continue ;
        for(int j = 0; j < 5 - i; j++){
            tmp *= pos[(int) pos.size() - j - 1] ;
        }
        ans = max(ans, tmp) ;
    }
    if ( have ){
        cout << max(ans, 0LL) << endl;
    }
    else cout << ans << endl;
}
signed main(){
    fastio;
    int t; 
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}
