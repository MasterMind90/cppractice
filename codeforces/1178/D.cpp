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
bool isPrime(int x){
    for(int i = 2; i * i <= x; i++){
        if ( x % i == 0 ) return false;
    }
    return true ;
}
signed main(){
    fastio
    int n ; 
    cin >> n ; 
    vector<int> g[n + 1] ; 
    for(int i = 1; i < n; i++){
        g[i].push_back(i + 1) ; 
    }
    g[n].push_back(1);
    int ans = n ; 
    while(not isPrime(ans)){
        ans++;
    }
    int diff = ans - n ; 
    vector<int> deg(n + 1, 2) ; 
    for(int i = 1; i < n; i++){
        if ( diff <= 0 ) break;
        if ( deg[i] == 2 ){
            for(int j = i + 2; j <= n; j++){
                if ( deg[j] == 2 ){
                    deg[i]++ ;
                    deg[j]++;
                    g[i].push_back(j) ;
                    diff--;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++){
        for(int &c : g[i]){
            cout << i << ' ' << c << endl;
        }
    }
    return 0; 
}