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
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio 
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    vector<int> cnt(3) ;
    for(char &c : s){
        cnt[c - '0']++;
    }
    int need = n / 3;
    for(int i = 0; i < n; i++){
        int c = s[i] - '0' ; 
        if ( cnt[c] <= need ) continue ;
        if ( cnt[c] > need ){
            if ( c != 0 ){
                if ( cnt[0] < need ){
                    cnt[0]++;
                    s[i] = '0' ;
                    cnt[c]--;
                }
            }
        }
    }
    for(int i = n - 1; i >= 0; i--){
        int c = s[i] - '0' ; 
        if ( cnt[c] <= need ) continue ;
        if ( cnt[c] > need ){
            if ( c != 2 ){
                if ( cnt[2] < need ){
                    cnt[2]++;
                    s[i] = '2' ;
                    cnt[c]--;
                }
            }
        }
    }
    for(int i = n - 1; i >= 0; i--){
        int c = s[i] - '0' ; 
        if ( cnt[c] <= need ) continue ;
        if ( cnt[c] > need ){
            if ( c == 0 ){
                if ( cnt[1] < need ){
                    cnt[1]++;
                    s[i] = '1' ;
                    cnt[c]--;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        int c = s[i] - '0' ; 
        if ( cnt[c] <= need ) continue ;
        if ( cnt[c] > need ){
            if ( c == 2 ){
                if ( cnt[1] < need ){
                    cnt[1]++;
                    s[i] = '1' ;
                    cnt[c]--;
                }
            }
        }
    }
    debug() << imie(s) ;
    cout << s << endl;
    return 0 ; 
}