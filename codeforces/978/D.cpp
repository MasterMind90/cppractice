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
const ll INF = 1e9 + 10 ;
int main(){
    fastio
    int n ;
    cin >> n ;
    vector<int> v(n) ; 
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    if ( n <= 2 ){
        cout << 0 << endl;
        return 0;
    }
    int X[] = {0, 1, -1} ; 
    int ans = INF; 
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int a = v[0] + X[i] ;
            int b = v[1] + X[j] ; 
            int diff = b - a ;
            int cnt = (X[i] != 0) + (X[j] != 0) ;
            bool ok = true ;
            for(int k = 2; k < n; k++){
                int c = b + diff ;
                if ( c == v[k] ){

                }
                else if ( c == v[k] + 1 ){
                    cnt++ ;
                }
                else if ( c == v[k] - 1 ){
                    cnt++;
                }
                else{
                    ok = false ; 
                    break;
                }
                b = c ; 
            }
            if ( ok ){
                ans = min(ans, cnt) ;
            }
        }
    }
    if ( ans == INF ){
        cout << -1 << endl;
    }
    else cout << ans << endl;
    return 0; 
}