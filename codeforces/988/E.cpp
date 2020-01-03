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
const ll INF = 1e18 + 10 ;
ll toInt(char c){
    return c - '0' ; 
}
ll go(string p, string s){
    ll n = (ll) s.size() ;
    reverse(s.begin(), s.end()) ; 
    ll cnt = 0 ;
    if ( p[0] != s[0] ){
        ll index = -1; 
        for(ll i = 1; i < n; i++){
            if ( s[i] == p[0] ){
                index = i ; 
                break;
            }
        }
        if ( index != -1 ){
            for(ll i = index; i > 0; i--){
                swap(s[i],s[i - 1]);
                cnt++ ; 
            }
        }
        else return INF ; 
    }
    if ( p[1] != s[1] ){
        ll index = -1; 
        for(ll i = 2; i < n; i++){
            if ( s[i] == p[1] ){
                index = i ; 
                break;
            }
        }
        if ( index != -1 ){
            for(ll i = index; i > 1; i--){
                swap(s[i],s[i - 1]);
                cnt++ ; 
            }
        }
        else return INF ; 
    }
    debug() << imie(p) imie(s) imie(cnt) ;
    if ( cnt == 0 ) return INF ; 
    reverse(s.begin(), s.end());
    if ( s[0] == '0' ){
        ll index = -1 ; 
        for(ll i = 1; i < n; i++){
            if ( s[i] != '0' ) {
                index = i ; 
                break;
            }
        }
        if ( index == n - 1 || index == n - 2 ) return INF ; 
        for(ll i = index; i > 0; i--){
            swap(s[i], s[i - 1]);
            cnt++;
        }
    }
    debug() << imie(p) imie(s) imie(cnt) ;
    return cnt ; 
}
int main(){
    fastio
    string s ;
    cin >> s ; 
    ll n = (ll) s.size() ; 
    if ( n < 2 ){
        cout << -1 << endl;
        return 0 ; 
    }
    ll ar[] = {0, 25, 50, 75};
    for(ll i = 0; i < 4; i++){
        ll x = toInt(s[n - 2]) * 10 + toInt(s[n - 1]) ; 
        if ( ar[i] == x ){
            cout << 0 << endl;
            return 0 ; 
        }
    }
    ll ans = min({go("00",s),go("52",s),go("05",s),go("57",s)});
    if ( ans == INF ){
        cout << -1 << endl;
    }
    else cout << ans << endl;
    return 0; 
}