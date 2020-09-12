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
void solve(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    multiset<int> ms ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
        ms.insert(v[i]) ;
    }
    int first = -1 ; 
    for(int i = 0; i <= 101; i++){
        if ( ms.count(i) == 0 ) {
            debug() << imie(first) ;
            if ( first != -1 ) {
                cout << first + i << endl ; 
            }
            else cout << i + i << endl;
            return ;
        }
        else if ( ms.count(i) == 1 && first == -1 ) {
            first = i ; 
        }
    }
}
signed main(){
    fastio;
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}
