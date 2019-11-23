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
    vector<vector<int> > B(n, vector<int>(m));
    vector<vector<int> > A(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> B[i][j] ; 
            A[i][j] = 1 ; 
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( B[i][j] == 0 ){
                for (int c = 0; c < n; c++) {
                    A[c][j] = B[i][j];
                }
                for (int c = 0; c < m; c++) {
                    A[i][c] = B[i][j];
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( A[i][j] != 0 ){
                A[i][j] = 1 ; 
            }
        }
    }
    vector<int> row(n), col(m) ; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( A[i][j] ) {
                row[i] = 1 ; 
                col[j] = 1 ; 
            }
        }
    }
    vector<vector<int> > C(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        if ( row[i] ){
            for(int j = 0; j < m; j++){
                C[i][j] = 1 ; 
            }
        }
    }
    for(int i = 0; i < m; i++){
        if ( col[i] ){
            for(int j = 0; j < n; j++){
                C[j][i] = 1 ; 
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( B[i][j] != C[i][j] ) return cout << "NO" << endl, 0 ; 
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << A[i][j] << ' ' ; 
        }
        cout << endl;
    }
    return 0 ; 
}