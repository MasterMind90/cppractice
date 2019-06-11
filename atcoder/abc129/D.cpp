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
    vector<int> rows[n] , cols[m] ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j] ;
            if ( grid[i][j] == '#' ){
                rows[i].push_back(j) ;
                cols[j].push_back(i) ;
            }
        }
    }
    int ans = 0 ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if ( grid[i][j] == '.' ){
                int index = upper_bound(rows[i].begin(),rows[i].end(),j) - rows[i].begin() ;
                // do not forget to minus one after you find row and col
                int row = 0 ;

                if ( (int) rows[i].size() == 0 )
                    row = m ;
                else if ( index == 0 ) {
                    row = rows[i][index] ;
                }
                else if ( index == (int) rows[i].size() ){
                    row = m - rows[i][index-1] - 1;
                }
                else {
                    row = rows[i][index] - rows[i][index-1] - 1;
                }
                index = upper_bound(cols[j].begin(),cols[j].end(),i) - cols[j].begin() ;

                int col = 0 ;
                if ( (int) cols[j].size() == 0 )
                    col = n ;
                else if ( index == 0 ) {
                    col = cols[j][index] ;
                }
                else if ( index == (int) cols[j].size() ){
                    col = n - cols[j][index-1] - 1;
                }
                else {
                    col = cols[j][index] - cols[j][index-1] - 1 ;
                }
                ans = max(ans,row+col-1) ;
                debug() << imie(i) imie(j) imie(row) imie(col) imie(ans) ;
            }
        }
    }
    cout << ans << endl;
    return 0 ;
}
