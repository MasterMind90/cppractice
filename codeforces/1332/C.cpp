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
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    int n , k ; 
    cin >> n >> k ; 
    string s ;
    cin >> s ;
    string t = s ;
    for(int i = 0; i < k / 2; i++){
        vector<int> cnt(26) ;
        for(int j = i; j < n; j += k){
            int v = s[j] - 'a' ;
            cnt[v]++;
        }
        vector<int> cnt2(26) ;
        for(int j = k - i - 1; j < n; j += k){
            int v = s[j] - 'a' ;
            cnt2[v]++;
        }
        char first = 'a' ; 
        int nax = 0 ; 
        for(int j = 0; j < 26; j++){
            cnt[j] += cnt2[j] ; 
            if ( cnt[j] > nax ){
                nax = cnt[j] ; 
                first = j + 'a' ; 
            }
        }
        for(int j = i; j < n; j += k){
            t[j] = first ;
        }
        for(int j = k - i - 1; j < n; j += k){
            t[j] = first ;
        }
    }
    if ( k % 2 == 1 ){
        vector<int> cnt(26) ;
        int nax = 0 ;
        char c = 'a' ;
        for(int i = k / 2; i < n; i += k){
            int v = s[i] - 'a' ;
            cnt[v]++;
            if ( cnt[v] > nax ){
                nax = cnt[v] ;
                c = s[i] ;
            }
        }
        for(int i = k / 2; i < n; i += k){
            t[i] = c ;
        }
    }
    debug() << imie(s) ;
    debug() << imie(t) ;
    int ans = 0 ;
    for(int i = 0; i < n; i++){
        if ( s[i] != t[i] ) ans++;
    }
    cout << ans << endl;
}
signed main(){
    fastio 
    int t ;
    cin >> t ;
    while(t--) solve() ; 
    return 0 ; 
}