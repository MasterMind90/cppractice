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
~debug() { cerr << endl; }
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

int main(){
    fastio
    ll n , m ;
    cin >> n >> m ;
    vector<ll> div ; 
    for(ll i = 1; i * i <= m; i++){
        if ( m % i == 0 ){
            div.push_back(i) ; 
            if ( m / i != i ) div.push_back(m / i) ; 
        }
    }
    sort(div.begin(), div.end()) ; 
    ll t = (ll) div.size() ;
    for(ll i = t - 1; i >= 0; i--){
        ll sum = 0 ;
        for(ll j = 0; j < n; j++){
            sum += div[i] ; 
        }
        if ( sum > m ) continue ;
        else {
            if ( (m - sum) % div[i] == 0 ){
                return cout << div[i] << endl, 0 ; 
            }
        }
    }
    return 0 ;
}