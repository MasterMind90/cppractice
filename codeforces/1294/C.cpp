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
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;

void solve(){
    ll n ; 
    cin >> n ; 
    vector<ll> div ; 
    for(ll i = 2; i * i <= n; i++){
        if ( n % i == 0 ){
            div.push_back(i) ; 
            if ( n / i != i ) div.push_back(n / i) ;
        }
    }
    if ( (ll)div.size() == 0 || (ll)div.size() == 1){
        cout << "NO" << endl;
        return ;
    }
    sort(div.begin(), div.end()) ;
    ll m = div.size() ;
    for(ll i = 0; i < m / 2; i++){
        ll a = div[i] ;
        ll b = div[m - i - 1] ;
        vector<ll> d ;
        for(ll j = 2; j * j <= b; j++){
            if ( b % j == 0 ){
                d.push_back(j) ;
                if ( b / j != j ) d.push_back(b / j);
            }
        }
        sort(d.begin(), d.end()) ;
        ll cc = d.size() ;
        for(ll j = 0; j < cc / 2 ; j++){
            ll x = d[j] ; 
            if ( x == a ) continue ;
            ll y = d[cc - j - 1] ;
            if ( x == y ) continue ;
            if ( y == a ) continue ;
            cout << "YES" << endl;
            cout << a << ' ' << x << ' ' << y << endl;
            return ;
        }
    }
    cout << "NO" << endl;
}
int main(){
    fastio
    ll t; 
    cin >> t ; 
    while(t--) solve() ; 
    return 0; 
}