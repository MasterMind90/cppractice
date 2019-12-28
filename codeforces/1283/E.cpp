#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e9 + 10 ;
int main(){
    fastio
    int n ; 
    cin >> n ; 
    vector<int> v(n) ; 
    for(int i = 0; i < n; i++){
        cin >> v[i] ; 
    }
    sort(v.begin(), v.end()) ; 
    set<int> nax ; 
    nax.insert(v[0] - 1) ; 
    for(int i = 1; i < n; i++){
        int x = v[i] ; 
        if ( nax.find(x - 1) == nax.end() ) nax.insert(x - 1) ; 
        else if ( nax.find(x) == nax.end() ) nax.insert(x) ; 
        else if ( nax.find(x + 1) == nax.end() ) nax.insert(x + 1) ; 
    }
    debug() << imie(nax) ; 
    set<int> nix ; 
    nix.insert(v[0] + 1) ; 
    for(int i = 1; i < n; i++){
        int x = v[i] ; 
        if ( nix.find(x - 1) == nix.end() ) {
            if ( nix.find(x) == nix.end() ) {
                if ( nix.find(x + 1) == nix.end() ) {
                    nix.insert(x + 1) ; 
                }
            }
        }
    }
    cout << nix.size() << ' ' << nax.size() << endl;
    return 0; 
}