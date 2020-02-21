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
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int toInt(string bin){
    int n = (int) bin.size() ;
    reverse(bin.begin(), bin.end()) ;
    int ans = 0 ; 
    for(int i = 0; i < n; i++){
        if ( bin[i] == '1' ) ans += (1 << i) ;
    }
    return ans ; 
}
void solve(){
    string s ;
    cin >> s ;
    int n = (int) s.size() ;
    int cnt = 0 ;
    int ans = 0 ; 
    for(int i = 0; i < n; i++){
        if ( s[i] == '1' ){
            for(int j = 0; j < 18; j++){
                if ( i + j + 1 > n ) break;
                int t = toInt(s.substr(i , j + 1));
                if ( cnt + j + 1 >= t ) ans++ ;
                else break ;
            }
            cnt = 0 ; 
        }
        else cnt++ ;
    }
    cout << ans << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}