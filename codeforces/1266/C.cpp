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
const ll INF = 1e9 + 10 ;
ll lcm(ll a, ll b){
    return a * b / __gcd(a, b) ; 
}
int main(){
    fastio
    ll r , c ;
    cin >> r >> c ; 
    if ( r == 1 && c == 1 ){
        cout << 0 << endl;
        return 0 ; 
    }
    else if ( r == 1 ){
        for(int i = 0; i < c; i++){
            cout << i + 2 << ' ' ; 
        }
        cout << endl;
        return 0 ; 
    }
    else if ( c == 1 ){
        for(int i = 0; i < r; i++){
            cout << i + 2 << endl;
        }
        return 0 ; 
    }
    vector<vector<ll> > v(r + 1, vector<ll>(c + 1));
    for(ll i = 1; i <= r; i++){
        v[i][1] = i + 1;
    }
    ll col = r + 2 ; 
    ll t = r + 2 ;
    vector<ll> column(c + 1) ; 
    for(ll i = 2; i <= c; i++) column[i] = t++;
    for(ll i = 2; i <= c; i++){
        v[1][i] = lcm(v[1][1], col++);
    }
    for(ll i = 2; i <= r; i++){
        for(ll j = 2; j <= c; j++){
            v[i][j] = lcm(column[j], v[i][1]);
        }
    }
    for(ll i = 1; i <= r; i++){
        for(ll j = 1; j <= c; j++){
            cout << v[i][j] << ' ' ;
        }
        cout << endl;
    }
    return 0; 
}