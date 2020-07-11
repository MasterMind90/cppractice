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
~debug() { cerr << endl; }
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
int main(){
    fastio
    int n , m ;
    cin >> n >> m ;
    char g[n + 2][m + 2] ;
    for(int i = 0; i < n + 2; i++){
        for(int j = 0; j < m + 2; j++){
            g[i][j] = '.' ;
        }
    }
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            cin >> g[i][j] ;
        }
    }
    int X[] = {-1, 1, 0, 0} ;
    int Y[] = {0, 0, -1, 1} ;
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            if ( g[i][j] == '#' ){
                bool ok = false ;
                for(int k = 0; k < 4; k++){
                    if ( g[i + X[k]][j + Y[k]] == '#' )  ok = true ;
                }
                if ( not ok ){
                    cout << "No" << endl;
                    return 0 ;
                }
            }
        }
    }
    cout << "Yes" << endl; 
    return 0 ;
}