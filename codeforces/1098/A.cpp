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
const ll N = 1e5 + 10 ;
const ll INF = 1e18 + 10 ;
int n ;
vector<vector<int> > v ;
vector<int> s ; 
vector<int> a ; 
vector<int> p ; 
int dfs(int x){
    int ans = s[x] ; 
    if ( s[x] == -1 ) ans = INF ;
    for(int &c : v[x]){
        ans = min(ans, dfs(c));
    }
    debug() << imie(s[x]) imie(ans) ;
    if ( s[x] != -1 && ans < s[x] ){
        cout << -1 << endl;
        exit(0) ;
    }
    if ( s[x] == -1 && ans == INF ){
        s[x] = s[p[x]];
    }
    if ( s[x] == -1 && ans != INF ){
        s[x] = ans ;
    }
    return ans ;
}
void recur(int x){
    if ( x != 1 ){
        a[x] = s[x] - s[p[x]];
    }
    for(int& c : v[x]){
        recur(c) ;
    }
}
signed main(){
    fastio 
    cin >> n ; 
    v.resize(n + 1) ; 
    s.resize(n + 1) ; 
    a.resize(n + 1) ; 
    p.resize(n + 1) ;
    for(int i = 2; i <= n; i++){
        cin >> p[i] ;
        v[p[i]].push_back(i) ;
    }
    for(int i = 1; i <= n; i++){
        cin >> s[i] ; 
    }
    dfs(1) ;
    debug() << imie(s) ;
    a[1] = s[1] ;
    recur(1) ;
    debug() << imie(a) ;
    int ans = 0 ;
    for(int i = 1; i <= n; i++){
        ans += a[i] ;
    }
    cout << ans << endl;
    return 0 ; 
}