#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sim template < class c
#define int long long
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
typedef tree< pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int n , m ;
vector<vector<char> > g ;
vector<vector<int> > turns , vis ;
bool inRange(int x, int y){
    if ( x < 0 || x >= n ) return false ;
    if ( y < 0 || y >= m ) return false ;
    // if ( vis[x][y] ) return false ;
    if ( g[x][y] == '*' ) return false ;
    // if ( cur > 2 ) return false ;
    return true ;
}
signed main(){
    fastio
    cin >> n >> m ; 
    g = vector<vector<char> >(n, vector<char>(m)) ;
    turns = vector<vector<int> >(n, vector<int>(m, INF)) ;
    vis = vector<vector<int> >(n, vector<int>(m, 0)) ;
    pair<int,int> start , end ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j] ;
            if ( g[i][j] == 'S' ) start = make_pair(i, j) ;
            else if ( g[i][j] == 'T' ) end = make_pair(i, j) ;
        }
    }
    // 0 --> right 
    // 1 --> left 
    // 2 --> up 
    // 3 --> down 
    // 4 no direction 
    deque<pair<pair<int,int>,int> > q ; 
    //
    q.emplace_back(make_pair(start.first , start.second), 0) ; 
    q.emplace_back(make_pair(start.first , start.second), 1) ; 
    q.emplace_back(make_pair(start.first , start.second), 2) ; 
    q.emplace_back(make_pair(start.first , start.second), 3) ; 
    turns[start.first][start.second] = 0 ;
    int X[] = {0, 0, 1, -1} ; 
    int Y[] = {-1, 1, 0, 0} ;
    while(not q.empty()){
        auto f = q.front() ; q.pop_front() ;
        debug() << imie(f) ;
        int curx = f.first.first , cury = f.first.second , dir = f.second ;
        for(int i = 0; i < 4; i++){
            int newx = curx + X[i] ;
            int newy = cury + Y[i] ;
            if ( not inRange(newx, newy) ) continue ;
            if ( dir == 0 || dir == 1 ) { // right
                if ( i == 0 || i == 1) { // right
                    if ( turns[newx][newy] > turns[curx][cury] ) {
                        turns[newx][newy] = turns[curx][cury] ; 
                        q.push_front(make_pair(make_pair(newx, newy), i)) ;
                    }
                }
                else{
                    if ( turns[newx][newy] > turns[curx][cury] + 1 ) {
                        turns[newx][newy] = turns[curx][cury] + 1 ; 
                        q.push_back(make_pair(make_pair(newx, newy), i)) ;
                    }
                }
            }
            else if ( dir == 2 || dir == 3 ) { // right
                if ( i == 0 || i == 1) { // right
                    if ( turns[newx][newy] > turns[curx][cury] + 1 ) {
                        turns[newx][newy] = turns[curx][cury] + 1 ; 
                        q.push_back(make_pair(make_pair(newx, newy), i)) ;
                    }
                }
                else {
                    if ( turns[newx][newy] > turns[curx][cury] ) {
                        turns[newx][newy] = turns[curx][cury] ; 
                        q.push_front(make_pair(make_pair(newx, newy), i)) ;
                    }
                }
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         if ( turns[i][j] == INF ) cout << '*' ;
    //         else cout << turns[i][j] ;
    //     }
    //     cout << endl;
    // }
    if ( turns[end.first][end.second] <= 2 ) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0; 
}
 
// ------------------------#----------
// -----------S------------#----------
// ------------------------#----------
// ---##########-----------#----------
// ------------------------#----------
// -------------####################--
// -----------------------------------
// #########################----------