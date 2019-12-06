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
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    string s ;
    cin >> s ; 
    s = "d" + s + "d" ; 
    int n = (int) s.size()  ;
    for(int i = 1; i <= n; i++){
        if ( s[i] == '?' ){
            if ( s[i + 1] == '?' ){
                char c = ((s[i - 1] - 'a' - 1) % 3 + 3) % 3 + 'a' ; 
                s[i] = c ; 
            }
            else{
                for(int j = 0; j < 3; j++){
                    char c = j + 'a' ; 
                    if ( c != s[i - 1] && c != s[i + 1] ){
                        s[i] = c ; 
                    }
                }
            }
        }
    }
    debug() << imie(s) ; 
    for(int i = 1; i <= n; i++){
        if ( s[i] == s[i - 1] ){
            cout << -1 << endl;
            return ; 
        }
    }
    cout << s.substr(1, n - 2) << endl;
}
int main(){
    fastio
    int t ;
    cin >> t ;
    while(t--){
        solve() ;
    }
    return 0; 
}
