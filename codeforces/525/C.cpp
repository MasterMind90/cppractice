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
const ll MOD = 1e9 + 7 ;
const ll N = 1e6 + 10 ;
int main(){
    fastio
    ll n ;
    cin >> n ; 
    vector<ll> freq(N) ; 
    for(ll i = 0; i < n; i++){
        ll x ; 
        cin >> x ; 
        freq[x]++ ; 
    }
    ll carry = 0 ; 
    ll total = 0 ; 
    for(ll i = N - 1; i > 0; i--){
        if ( freq[i] == 0 ) continue ; 
        if ( carry == 0 ){
            ll rectangles = freq[i] / 4 ; 
            ll area = i * i ; 
            total += rectangles * area ; 
            ll remain = freq[i] % 4 ; 
            if ( remain == 1 && freq[i - 1] ) freq[i - 1]++ ; 
            else if ( remain == 2 ) carry = i ; 
            else if ( remain == 3 ) {
                carry = i ; 
                if ( freq[i - 1] ) freq[i - 1]++ ; 
            }
        }
        else{
            if ( freq[i] == 1 ) {
                if ( freq[i - 1] ) freq[i - 1]++ ; 
            }
            else{
                total += carry * i ; 
                freq[i] -= 2 ; 
                carry = 0 ; 
                ll rectangles = freq[i] / 4 ; 
                ll area = i * i ; 
                total += rectangles * area ; 
                ll remain = freq[i] % 4 ; 
                if ( remain == 1 && freq[i - 1] ) freq[i - 1]++ ; 
                else if ( remain == 2 ) carry = i ; 
                else if ( remain == 3 ) {
                    carry = i ; 
                    if ( freq[i - 1] ) freq[i - 1]++ ; 
                }
            }
        }
    }
    cout << total << endl;
    return 0 ; 
}