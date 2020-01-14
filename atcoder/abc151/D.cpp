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
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int main(){
    fastio
    int n , m ;
    cin >> n >> m ; 
    char g[n][m] ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j] ; 
        }
    }
    int ans = 0 ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( g[i][j] == '.' ){
                int dist[n][m] ;
                memset(dist, -1, sizeof dist);
                queue<pair<int,int> > q; 
                q.push(make_pair(i, j));
                dist[i][j] = 0 ; 
                while(not q.empty()){
                    auto f = q.front(); q.pop() ;
                    int x = f.first ; 
                    int y = f.second ; 
                    if ( x + 1 < n && g[x + 1][y] != '#' && dist[x + 1][y] == -1 ){
                        q.push(make_pair(x + 1, y)) ; 
                        dist[x + 1][y] = dist[x][y] + 1;
                        ans = max(ans, dist[x + 1][y]);
                    }
                    if ( x - 1 >= 0 && g[x - 1][y] != '#' && dist[x - 1][y] == -1 ){
                        q.push(make_pair(x - 1, y)) ; 
                        dist[x - 1][y] = dist[x][y] + 1;
                        ans = max(ans, dist[x - 1][y]);
                    }
                    if ( y - 1 >= 0 && g[x][y - 1] != '#' && dist[x][y - 1] == -1 ){
                        q.push(make_pair(x, y - 1)) ; 
                        dist[x][y - 1] = dist[x][y] + 1;
                        ans = max(ans, dist[x][y - 1]);
                    }
                    if ( y + 1 < m && g[x][y + 1] != '#' && dist[x][y + 1] == -1 ){
                        q.push(make_pair(x, y + 1)) ; 
                        dist[x][y + 1] = dist[x][y] + 1;
                        ans = max(ans, dist[x][y + 1]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0; 
}