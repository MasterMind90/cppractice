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
int main(){
    fastio
    ll n ; 
    cin >> n ; 
    vector<ll> v(n) ; 
    ll R1 = 0 ; 
    for(ll i = 0; i < n; i++) {
        cin >> v[i] ; 
        R1 = max(R1, v[i]) ; 
    }
    ll m ; 
    cin >> m ;
    vector<ll> p1(m) ; 
    for(ll i = 0; i < m; i++) cin >> p1[i] ;
    ll k ; 
    cin >> k ; 
    vector<ll> p2(k) ; 
    for(ll i = 0; i < k; i++) cin >> p2[i] ; 
    ll A , B ; 
    cin >> A >> B ; 
    sort(p2.begin(), p2.end()) ; 
    auto go = [&](ll r1,ll p1, ll p2){
        return sqrt( (r1 * r1  * p1 * B) / (double)(p2 * A + p1 * B));
    };
    double nax = 0 ;
    for(ll j = 0; j < m; j++){
        ll L = 0, R = k - 1 ; 
        while(L <= R){
            ll mid = L + (R - L) / 2 ; 
            double val = go(R1,p1[j],p2[mid]);
            nax = max(nax, val);
            double val2 = 0;
            if ( mid + 1 < k ){
                val2 = go(R1, p1[j], p2[mid + 1]);
            }
            nax = max(nax, val2) ;
            if ( val2 > val ) L = mid + 1 ;
            else R = mid - 1;
        }
    }
    cout << fixed << setprecision(12) << nax << endl;
    return 0; 
}