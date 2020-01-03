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
bool isPowerofTwo(ll x){
    for(ll i = 0; i <= 32; i++){
        if ( (1LL << i) == x ) return true ;
    }
    return false ;
}
int main(){
    fastio
    ll n ; 
    cin >> n ; 
    vector<ll> v(n) ; 
    for(ll i = 0; i < n; i++){
        cin >> v[i] ; 
    }
    sort(v.begin(), v.end()) ; 
    for(ll i = 1; i < n; i++){
        ll start = v[i] ; 
        for(ll j = 0; j <= 32; j++){
            ll left = start - (1LL << j) ; 
            ll L = 0, R = n - 1; 
            ll ans = -1 ; 
            while(L <= R){
                ll mid = L + (R - L) / 2 ;
                if ( v[mid] == left ){
                    ans = mid ; 
                    break;
                }
                else if ( v[mid] > left ){
                    R = mid - 1 ;
                }
                else L = mid + 1; 
            }
            if ( ans != -1 ){
                for(ll k = 0; k <= 32; k++){
                    ll right = start + (1LL << k) ; 
                    if ( !isPowerofTwo(right - left) ) continue ;
                    L = 0 , R = n - 1 ;
                    while(L <= R){
                        ll mid = L + (R - L) / 2 ;
                        if ( v[mid] == right ){
                            cout << 3 << endl;
                            cout << left << ' ' << start << ' ' << right << endl;
                            return 0 ; 
                        }
                        else if ( v[mid] > right ){
                            R = mid - 1;
                        }
                        else L = mid + 1 ;
                    }
                }
            }
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j <= 32; j++){
            ll start = v[i] + (1LL << j) ; 
            ll L = 0, R = n - 1 ;
            while(L <= R){
                ll mid = L + (R - L) / 2;
                if ( v[mid] == start ){
                    cout << 2 << endl;
                    cout << v[i] << ' ' << start << endl;
                    return 0 ; 
                }
                else if ( v[mid] > start ) R = mid - 1; 
                else L = mid + 1 ;
            }
        }
    }
    cout << 1 << endl;
    cout << v[0] << endl;
    return 0; 
}