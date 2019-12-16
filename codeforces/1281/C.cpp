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
const ll N = 2e6 + 10 ;
const ll INF = 1e18 + 10 ;
ll fix(ll x){
    return (x % MOD + MOD) % MOD ; 
}
void solve(){
    ll x ;
    cin >> x ; 
    string s ;
    cin >> s ; 
    ll cur = 1;
    ll initial = (ll) s.size() ; 
    while((ll)s.size() < x){
        string tmp = s.substr(cur) ;
        if ( s[cur - 1] == '2' ) s += tmp ; 
        else if ( s[cur - 1] == '3' ) s += tmp + tmp ; 
        cur++;
    }
    ll n = (ll) s.size() ; 
    for(ll i = 0; i < x; i++){
        debug() << imie(initial) imie(s[i]);
        if ( s[i] == '2' ) {
            initial = (initial % MOD + fix(initial - i - 1) % MOD) % MOD;
        }
        else if ( s[i] == '3' ){
            initial = (((initial % MOD) + fix(initial - i - 1) % MOD) % MOD + (initial - i - 1) % MOD) % MOD;
        }
        debug() << imie(initial) ;
    }
    cout << initial % MOD << endl;
}
int main(){
    fastio
    ll t ;
    cin >> t ; 
    while(t--){
        solve() ; 
    }
    return 0; 
}