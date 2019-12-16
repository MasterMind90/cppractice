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
const ll N = 2e6 + 10 ;
const ll INF = 1e9 + 10 ;
void solve(){
    int n , m ; 
    cin >> n >> m; 
    vector<vector<char> > g(n + 2, vector<char>(m + 2));
    vector<vector<int> > sum(n + 2, vector<int>(m + 2));
    bool ok = false ;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j] ; 
            if ( g[i][j] == 'A' ) ok = true ;
            else sum[i][j] = 1;
        }
    }
    if ( !ok ) {
        cout << "MORTAL" << endl;
        return ; 
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] ; 
        }
    }
    int ans = INF ; 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if ( g[i][j] == 'A' ){
                // lets do horizontal.
                int x = 0 ; 
                for(int k = j + 1; k <= m; k++){
                    if ( g[i][k] == 'P' ) break;
                    x++ ; 
                }
                int up = sum[i][j + x] - sum[i][j - 1] ; 
                int down = sum[n][j + x] - sum[i][j + x] - sum[n][j - 1] + sum[n - 1][j + x - 1] ; 
                int right = sum[n][m] - sum[n][j + x] ; 
                int left = sum[n][j - 1] ; 
                debug() << imie(up) imie(down) imie(right) imie(left) ; 
                int cur = 0 ; 
                if ( up && down ) cur += 2 ;
                else if ( up ) cur++ ; 
                else if ( down ) cur++ ; 

                if ( right && left ) cur += 2 ;
                else if ( right ) cur++ ; 
                else if ( left ) cur++ ; 
                ans = min(ans, cur) ; 
                x = 0 ; 
                for(int k = i + 1; k <= n; k++){
                    if ( g[k][j] == 'P' ) break;
                    x++;
                }
                up = sum[i - 1][m];
                down = sum[n][m] - sum[i + x][m]; 
                right = sum[i + x][m] - sum[i - 1][m] - sum[i + x][j - 1] + sum[i - 1][j - 1]; ; 
                left = sum[i + x][j - 1] - sum[i - 1][j - 1] ; 
                cur = 0 ; 
                if ( up && down ) cur += 2 ;
                else if ( up ) cur++ ; 
                else if ( down ) cur++ ; 

                if ( right && left ) cur += 2 ;
                else if ( right ) cur++ ; 
                else if ( left ) cur++ ; 
                ans = min(ans, cur) ;
            }
        }
    }
    cout << ans << endl;
}
int main(){
    fastio
    ll t ;
    cin >> t ; 
    while(t--){
        solve() ; 
    }
    return 0; 
}