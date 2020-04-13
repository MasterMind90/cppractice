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
    map<int,int> cnt ; 
    int counter = 0 ;
    int val = 0 ; 
    int counter2 = 0 ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ; cnt[v[i]]++ ;
        int c = cnt[v[i]] ;
        if ( c > counter ){
            val = v[i] ;
            counter = c; 
        }
    }
    for(auto &p : cnt){
        if ( p.first == val ) continue ;
        counter2++ ;
    }
    if ( n == 1 ){
        cout << 0 << endl;
        return ; 
    }
    if ( counter == 1 ){
        cout << 1 << endl;
        return ;
    }
    debug() << imie(counter) imie(counter2) ;
    int ans = min(counter, counter2) ;
    cout << max(ans, min(counter - 1, counter2 + 1)) << endl;
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