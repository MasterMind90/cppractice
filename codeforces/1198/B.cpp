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
    int n ; 
    cin >> n ; 
    vector<int> v(n) ; 
    for(int i = 0; i < n; i++){
        cin >> v[i] ; 
    }
    vector<int> last(n, -1) ;
    int q ;
    cin >> q ;
    vector<int> nax(q) ; 
    int ans = -1 ;
    for(int i = 0; i < q; i++){
        int t ; 
        cin >> t ;
        if ( t == 1 ){
            int pos , val ; 
            cin >> pos >> val ; 
            pos-- ; 
            v[pos] = val ; 
            last[pos] = i ; 
            nax[i] = 0 ; 
        }
        else{
            int val ; 
            cin >> val ; 
            nax[i] = val ; 
            ans = max(ans, val) ;
        }
    }
    for(int i = q - 2; i >= 0; i--){
        nax[i] = max(nax[i], nax[i + 1]);
    }
    for(int i = 0; i < n; i++){
        if ( last[i] == -1 ){
            v[i] = max(v[i], ans) ;
        }
        else{
            v[i] = max(v[i], nax[last[i]]);
        }
    }
    for(int i = 0; i < n; i++){
        cout << v[i] << ' ' ; 
    }
    cout << endl;
    return 0; 
}