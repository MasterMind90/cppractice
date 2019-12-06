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
    int n ; 
    cin >> n;
    vector<int> v(n) ; 
    int nax = 0 ; 
    int g = 1 ; 
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]) ; 
        if ( i == 0 ){
            nax = v[i] ; 
            continue ; 
        }
        if ( v[i] == nax ) g++; 
    }
    int half = n / 2 ; 
    int s = g + 1 ;
    while(g + s < n && v[g + s - 1] == v[g + s] ) s++ ;
    int b = half - g - s ; 
    while(g + s + b < n && v[g + s + b - 1] == v[g + s + b] ) b--;
    if ( g > 0 && s > 0 && b > 0 && g < s && g < b && g + s + b <= half ){
        printf("%d %d %d\n", g, s, b) ; 
    }
    else printf("0 0 0\n") ; 
}
int main(){
    //fastio
    int t ;
    scanf("%d", &t) ; 
    while(t--){
        solve() ;
    }
    return 0; 
}