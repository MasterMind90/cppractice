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
signed main(){
    fastio
    int n  ;
    cin >> n ; 
    for(int k = 5; k * k <= n; k++){
        if ( n % k == 0 && n / k >= 5){
            int x = k , y = n / k ; 
            string vowel = "aeiou" ; 
            vector<vector<char> > v(x, vector<char>(y, 'a'));
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    v[i][j] = vowel[(j + i) % 5] ; 
                }
            }
            for(int i = 5; i < x; i++){
                for(int j = 0; j < 5; j++){
                    v[i][j] = vowel[j] ; 
                }
            }
            for(int i = 5; i < y; i++){
                for(int j = 0; j < 5; j++){
                    v[j][i] = vowel[j] ; 
                }
            }
            for(auto &c : v){
                debug() << imie(c) ;
            }
            debug() << imie(x) imie(y) ;
            for(int i = 0; i < x; i++){
                for(int j = 0; j < y; j++){
                    cout << v[i][j] ;
                }
            }
            cout << endl ; 
            return 0  ;
        }
    }
    cout << -1 << endl;
    return 0; 
}