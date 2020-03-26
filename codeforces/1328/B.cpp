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
int solve(int x){
    return x * (x + 1) / 2 ;
}
int n , k ;
int fix(int x){
    return ( x % n + n ) % n ; 
}
void solve(){
    cin >> n >> k ; 
    string s = "" ; 
    for(int i = 0; i < n - 2; i ++){
        s.push_back('a') ;
    }
    s.push_back('b') ; 
    s.push_back('b') ; 
    if ( k == 1 ){
        cout << s << endl;
        return ; 
    }
    int L = 0, R = 1e9 ; 
    int ans = -1 ;
    while(L <= R){
        int mid = L + (R - L) / 2 ;
        if ( solve(mid) <= k ){
            ans = mid ;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    int v = solve(ans) ;
    ans--;
    string t = s ;
    for(int i = 0; i < n; i++){
        t[fix(i-ans)] = s[i] ;
    }
    for(int i = v; i < k; i++){
        next_permutation(t.begin(), t.end()) ;
    }
    cout << t << endl;
}
signed main(){
    int t; 
    cin >> t ;
    while(t--){
        solve() ; 
    }
    return 0 ;
}