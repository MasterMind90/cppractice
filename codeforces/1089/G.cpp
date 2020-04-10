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
const ll N = 1e5 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    int k ; 
    cin >> k ;
    vector<int> v(7) ;
    int sum = 0 ;
    for(int i = 0; i < 7; i++){
        cin >> v[i] ;
        sum += v[i] ;
    }
    // same week 
    int ans = INF ;
    for(int i = 0; i < 7; i++){
        for(int j = i; j < 7; j++){
            int study = 0 ;
            for(int c = i; c <= j; c++){
                study += v[c] ;
            }
            if ( study == k ){
                ans = min(ans, j - i + 1) ;
            }
        }
    }
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            int study = 0 ;
            int days = 0 ; 
            for(int c = i; c < 7; c++){
                study += v[c] ;
                days++ ;
            }
            for(int c = 0; c <= j; c++){
                study += v[c] ;
                days++ ;
            }
            if ( study == k ) ans = min(ans, days) ;
            int res = -1 ;
            int cur = k - study ;
            int L = 0, R = 1e9 ;
            while(L <= R){
                int mid = L + (R - L) / 2;
                if ( mid * sum == cur ){
                    res = mid ;
                    break ;
                }
                else if ( mid * sum > cur ){
                    R = mid - 1;
                }
                else L = mid + 1;
            }
            if ( res != -1 ) {
                ans = min(ans, res * 7 + days) ;
            }
        }
    }
    cout << ans << endl;
}
signed main(){
    fastio 
    int t; 
    cin >> t ;
    while(t--) solve() ; 
    return 0 ; 
}