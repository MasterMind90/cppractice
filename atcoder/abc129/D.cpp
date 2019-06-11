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
using ll = long long ;

int main(){
    int n , m ;
    cin >> n >> m ;
    char grid[n][m] ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j] ;
        }
    }
    int right[n][m] ;
    int left[n][m] ;
    int up[n][m] ;
    int down[n][m] ;
    // right
    for(int i=0;i<n;i++){
        int cnt = 0 ;
        for(int j=m-1;j>=0;j--){
            if ( grid[i][j] == '#' ) cnt = 0, right[i][j] = 0 ;
            else if ( j == m-1 ) right[i][j] = 1 ;
            else right[i][j] = right[i][j+1] + 1 ;
        }
    }
    // left
    for(int i=0;i<n;i++){
        int cnt = 0 ;
        for(int j=0;j<m;j++){
            if ( grid[i][j] == '#' ) cnt = 0 , left[i][j] = 0 ;
            else if ( j == 0 ) left[i][j] = 1 ;
            else left[i][j] = left[i][j-1] + 1 ;
        }
    }
    // up
    for(int j=0;j<m;j++){
        int cnt = 0 ;
        for(int i=0;i<n;i++){
            if ( grid[i][j] == '#' ) cnt = 0 , up[i][j] = 0 ;
            else if ( i == 0 ) up[i][j] = 1 ;
            else up[i][j] = up[i-1][j]+1 ;
        }
    }
    // down
    for(int j=0;j<m;j++){
        int cnt = 0 ;
        for(int i=n-1;i>=0;i--){
            if ( grid[i][j] == '#' ) cnt = 0 , down[i][j] = 0 ;
            else if ( i == n-1 ) down[i][j] = 1 ;
            else down[i][j] = down[i+1][j] + 1 ;
        }
    }
    int ans = 0 ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if ( grid[i][j] == '.' ){
                ans = max(ans, right[i][j] + left[i][j] + up[i][j] + down[i][j] - 3);
            }
        }
    }
    cout << ans << endl;
    return 0 ;
}
