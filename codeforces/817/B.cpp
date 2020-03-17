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
signed main(){
    fastio
    int n ;
    cin >> n ; 
    vector<int> v(n) ; 
    for(int i = 0; i < n; i++){
        cin >> v[i] ; 
    }
    vector<int> t = v ; 
    vector<int> c(3) ; 
    sort(t.begin(), t.end()) ; 
    for(int i = 0; i < 3; i++){
        c[i] = t[i] ; 
    }
    set<int> s(c.begin(), c.end()) ; 
    vector<vector<int> > cnt(3, vector<int>(n + 1) ) ; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            if ( c[j] == v[i] ){
                cnt[j][i + 1] = 1 ;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= n; j++){
            cnt[i][j] += cnt[i][j - 1] ; 
        }
    }
    int ans = 0 ;
    for(int i = 1; i < n; i++){
        int index = -1 ; 
        int fre = 0 ; 
        for(int j = 0; j < 3; j++){
            if ( c[j] == v[i] ){
                index = j ; 
                fre++ ; 
            }
        }
        if ( index == -1 ) continue ; 
        if ( s.size() == 1 ){
            ans += cnt[0][i] * (cnt[0][n] - cnt[0][i + 1]);
        }
        else if ( s.size() == 2 ){
            if ( fre == 1 ){
                for(int j = 0; j < 3; j++){
                    if ( j == index ) continue ;
                    ans += cnt[j][i] * (cnt[j][n] - cnt[j][i + 1]);
                    break;
                }
            }
            else {
                int first = -1 , second = -1 ; 
                for(int j = 0; j < 3; j++){
                    if ( j == index ) continue ;
                    if ( first == -1 ) first = j ;
                    else second = j ; 
                }
                ans += cnt[first][i] * (cnt[second][n] - cnt[second][i + 1]);
                ans += cnt[second][i] * (cnt[first][n] - cnt[first][i + 1]);
            }
        }
        else{
            int first = -1 , second = -1 ; 
            for(int j = 0; j < 3; j++){
                if ( j == index ) continue ;
                if ( first == -1 ) first = j ;
                else second = j ; 
            }
            ans += cnt[first][i] * (cnt[second][n] - cnt[second][i + 1]);
            ans += cnt[second][i] * (cnt[first][n] - cnt[first][i + 1]);
        }
    }
    cout << ans << endl;
    return 0; 
}