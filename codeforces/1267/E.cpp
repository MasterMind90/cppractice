#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define int long long
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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 1 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio;
    int n , m ;
    cin >> n >> m ;
    vector<vector<int> > g(m, vector<int>(n)) ;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j] ;
        }
    }
    vector<int> indices ;
    for(int i = 0; i < m; i++){
        indices.emplace_back(i + 1) ;
    }
    for(int i = 0; i < n - 1; i++){
        vector<pair<pair<int,int>, pair<int,int> > > v ;
        int sumA , sumB ;
        sumA = sumB = 0 ;
        for(int j = 0; j < m; j++){
            auto p = make_pair(
                    make_pair(g[j][n - 1] - g[j][i], j),
                    make_pair(g[j][i], g[j][n - 1]) ) ;
            sumA += g[j][i] ;
            sumB += g[j][n - 1] ;
            v.emplace_back(p) ;

        }
        debug() << imie(v) ;
        sort(v.begin(), v.end()) ;
        vector<int> ans ; 
        while(sumA < sumB){
            sumA -= v.back().second.first ;
            sumB -= v.back().second.second ;
            ans.emplace_back(v.back().first.second + 1) ;
            v.pop_back() ;
        }
        if ( (int) ans.size() < (int) indices.size() ) {
            indices = ans ;
        }
    }
    cout << (int)indices.size() << endl;
    for(int &c : indices){
        cout << c << ' ' ;
    }
    cout << endl  ;
    return 0; 
}
