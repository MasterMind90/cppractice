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

int main(){
    int n ;
    cin >> n ;
    vector<vector<int> > a(n, vector<int>(n, -1)) ;
    for(int i = 0; i < n; i++){
        int m ;
        cin >> m ;
        for(int j = 0; j < m; j++){
            int x , y ;
            cin >> x >> y ;
            x--;
            a[i][x] = y ;
        }

    }
    for(int i = 0; i < n; i++){
        debug() << range(a[i].begin(), a[i].end() );
    }
    int ans = 0 ;
    for(int mask = 1; mask < (1 << n); mask++){
        vector<int> honest(n) ;
        for(int i = 0; i < n; i++){
            if ( mask & (1 << i) ){
                honest[i] = 1 ;
            }
        }
        debug() << imie(honest) ;
        vector<int> flag(n, -1) ;
        bool ok = true ;
        for(int i = 0; i < n; i++){
            if ( honest[i] ){
                for(int j = 0; j < n; j++){
                    if ( a[i][j] == -1 ) continue ;
                    else if ( flag[j] == a[i][j] ) continue ;
                    else if ( flag[j] == -1 ){
                        flag[j] = a[i][j] ;
                        if ( flag[j] != honest[j] ) ok = false ;
                    }
                    else ok = false ;
                }
            }
        }
        if ( ok ){
            int cnt = 0 ;
            for(int i = 0; i < n; i++){
                if ( honest[i] ) cnt++ ;
            }
            debug() << "TEST " << imie(honest) ;
            ans = max(ans, cnt) ;
        }
    }
    cout << ans << endl;
    return 0 ;
}
