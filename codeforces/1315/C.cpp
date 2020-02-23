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
void solve(){
    int n ;
    cin >> n ; 
    vector<int> b(n) ; 
    vector<int> used(2 * n + 1) ; 
    for(int i = 0; i < n; i++){
        cin >> b[i] ;
        used[b[i]] = true ;
    }
    vector<int> a(2 * n) ; 
    for(int i = 0, j = 0; i < 2 * n; j++, i += 2){
        a[i] = b[j];
    }
    debug() << imie(a) ;
    for(int i = 1; i < 2 * n; i += 2){
        for(int j = 1; j < 2 * n + 1; j++){
            if ( !used[j] && j > a[i - 1] ){
                a[i] = j ; 
                used[j] = true ;
                break;
            }
        }
    }
    debug() << imie(a) ;
    vector<int> cnt(2 * n + 1) ; 
    for(int i = 0; i < 2 * n; i++){
        if ( a[i] == 0 ) {
            cout << -1 << endl;
            return ;
        }
        cnt[a[i]]++ ; 
        if ( cnt[a[i]] > 1 ){
            cout << -1 << endl;
            return ;
        }
    }
    for(int i = 0; i < 2 * n; i++){
        cout << a[i] << ' ' ; 
    }
    cout << endl;
}
signed main(){
    fastio
    int t ; 
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}