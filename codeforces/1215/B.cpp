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
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    int n ; 
    cin >> n ; 
    vector<int> v(n) ; 
    for(int &c : v){
        cin >> c ; 
    }
    vector<int> cnt(n + 1)  ;
    for(int i = 0; i < n; i++){
        cnt[i + 1] = cnt[i] + (v[i] < 0) ; 
    }
    vector<int> odd(n + 1) ; 
    odd[n] = cnt[n] % 2 ; 
    for(int i = n - 1; i >= 0; i--){
        odd[i] = odd[i + 1] + (cnt[i] % 2) ; 
    }
    debug() << imie(cnt) ;
    debug() << imie(odd) ;
    int ans = 0; 
    for(int i = 1; i <= n; i++){
        int len = n - i + 1 ; 
        int even = len - odd[i] ; 
        if ( cnt[i - 1] % 2 == 0 ){
            ans += even ; 
        }
        else ans += odd[i] ; 
    }
    cout << (n * (n + 1) / 2) - ans <<  ' ' << ans << endl;
    return 0; 
}