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
const ll INF = 1e18 + 10 ;
bool isPrime(ll x){
    if ( x <= 1 ) return false ;
    for(ll i = 2; i * i <= x; i++){
        if ( x % i == 0 ) return false ; 
    }
    return true ;
}
vector<bool> prime(N, true) ; 
vector<ll> primes ; 
void seive(){
    prime[0] = prime[1] = false ; 
    for(ll i = 2; i < N; i++){
        if ( prime[i] ){
            for(ll j = i + i; j < N; j += i) prime[j] = false;
        }
    }
    for(ll i = 0; i < N; i++){
        if ( prime[i] ) {
            primes.emplace_back(i) ;
        }
    }
}
int main(){
    fastio
    seive() ;
    ll n ;
    cin >> n ; 
    if ( isPrime(n) ){
        cout << 1 << endl;
        cout << n << endl;
        return 0 ; 
    }
    ll cur = n ;
    while(cur--){
        if ( isPrime(cur) ){
            debug() << imie(cur) ; 
            if ( cur + 2 == n ){
                cout << 2 << endl;
                cout << 2 << ' ' << cur << endl;
                return 0 ; 
            }
            int target = n - cur ; 
            debug() << imie(target) ; 
            int L = 0, R = (int)primes.size() - 1 ; 
            while(L <= R){
                if ( primes[L] + primes[R] == target ){
                    cout << 3 << endl;
                    cout << primes[L] << ' ' << primes[R] << ' ' << cur << endl;
                    return 0 ;
                }
                else if ( primes[L] + primes[R] > target ) R--;
                else {
                    debug() << imie(L) imie(R) ; 
                    debug() << imie(primes[L]) imie(primes[R]);
                    L++; 
                }
            }
        }
    }
    return 0; 
}
