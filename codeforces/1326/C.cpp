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
const ll MOD = 998244353 ;
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    int n , k;
    cin >> n >> k ; 
    vector<int> v(n) ; 
    for(int i = 0; i < n; i++){
        cin >> v[i] ; 
    }
    vector<int> t = v ;
    sort(t.begin(), t.end()) ;
    set<int> s ;
    int sum = 0 ; 
    for(int i = 0; i < k; i++){
        s.insert(t[n - i - 1]);
        sum += t[n - i - 1] ;
    }
    vector<int> pos ; 
    for(int i = 0; i < n; i++){
        if ( s.count(v[i]) ){
            pos.push_back(i) ; 
        }
    }
    vector<int> diff ; 
    for(int i = 1; i < pos.size(); i++){
        diff.push_back(pos[i] - pos[i - 1]);
    }
    debug() << imie(diff) ;
    int ans = 1 ; 
    for(int i = 0; i < diff.size(); i++){
        ans = ( (ans % MOD) * (diff[i] % MOD) ) % MOD ; 
    }
    cout << sum << ' ' << ans << endl;
    return 0; 
}