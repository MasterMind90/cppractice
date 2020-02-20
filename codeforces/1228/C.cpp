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
int fastPow(int x,int y){
    if ( y == 0 ) return 1 ; 
    if ( y == 1 ) return x % MOD ; 
    int z = fastPow(x, y / 2) % MOD ; 
    if ( y % 2 == 0 ) return ( (z % MOD) * (z % MOD) ) % MOD ; 
    else return (( ( (z % MOD) * (z % MOD) ) % MOD ) * (x % MOD) ) % MOD ; 
}
map<int,int> mp ;
void factor(int x){
    for(int i = 2; i * i <= x; i++){
        while(x % i == 0){
            mp[i]++ ; 
            x /= i ; 
        }
    }
    if ( x > 1 ) mp[x]++ ; 
}
int fix(int x){
    return (x % MOD + MOD) % MOD ; 
}
signed main(){
    fastio
    int x , n ;
    cin >> x >> n ; 
    factor(x) ;
    int ans = 1 ;
    for(auto &c : mp){
        ll cur = n ; 
        ll cnt = 0 ; 
        while(cur){
            cnt += cur / c.first ; 
            cur /= c.first ;
        }
        ans = (ans * fastPow(c.first, cnt)) % MOD ;
    }
    cout << ans  << endl;

    // vector<int> div ; 
    // for(int i = 1; i * i <= x; i++){
    //     if ( x % i == 0 ){
    //         div.push_back(i) ; 
    //         if ( x / i != i ) div.push_back(x / i);
    //     }
    // }
    // sort(div.begin(), div.end()) ; 
    // int ans = 1; 
    // for(int &c : div){
    //     if ( c <= n ) ans = ( (ans % MOD) * (c % MOD) ) % MOD ; 
    //     else break;
    // }
    // cout << ans << endl;
    // int ans = 1 ; 
    // map<int,int> mm ; 
    // for(int i = 1; i < n + 1; i++){
    //     mm[f(x, i)]++;
    //     debug() << imie(x) imie(i) imie(f(x, i));
    //     ans = ((ans % MOD) * (f(x, i) % MOD)) % MOD ; 
    // }
    // cout << ans << endl;
    // debug() << imie(mp) ;
    // debug() << imie(mm) ;
    return 0; 
}