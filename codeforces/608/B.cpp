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
signed main(){
    fastio
    string a , b ;
    cin >> a >> b ; 
    int n = (int) a.size() ; 
    int m = (int) b.size() ; 
    int ones = 0 ; 
    for(char &c : a){
        if ( c == '1' ) ones++ ; 
    }
    int zero = n - ones ; 
    vector<int> pre(n + 1) ; 
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + (a[i - 1] == '1') ; 
    }
    debug() << imie(pre) ;
    int ans = 0 ;
    for(int i = 0; i < m; i++){
        if ( i < n ){
            int move = m - n ; 
            int o = pre[i + 1] - pre[max(i - move, 0LL)] ; 
            int len = i + 1 - max(i - move, 0LL) ; 
            int z = len - o ; 
            debug() << imie(move) imie(len) imie(o) imie(z) ;
            if ( b[i] == '1' ) ans += z ; 
            else ans += o ; 
        }
        else{
            int after = m - i ;
            if ( after >= n ){
                if ( b[i] == '1' ) ans += zero ; 
                else ans += ones ; 
            }
            else{
                int o = pre[n] - pre[n - after] ; 
                int len = after ;
                int z = len - o ; 
                debug() << imie(i) imie(o) imie(len) imie(z) ;
                if ( b[i] == '1' ) ans += z ; 
                else ans += o ; 
            }
        }
        debug() << imie(i) imie(ans) ;
    }
    cout << ans << endl;
    return 0; 
}