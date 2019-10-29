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
struct Point{
    int a, b, c, d;
    Point(int a, int b, int c, int d){
        this->a = a ;
        this->b = b ;
        this->c = c ;
        this->d = d ;
    }
};
int main(){
    fastio
    int n , m ; 
    cin >> n >> m ; 
    vector<vector<int> > v(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j] ;
        }
    }
    vector<Point> ans ; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if ( v[i][j] & 1 ){
                if ( j + 1 < m ){
                    ans.push_back(Point{i, j, i, j + 1});
                    v[i][j]--;
                    v[i][j + 1]++;
                }
                else if ( i + 1 < n ){
                    ans.push_back(Point{i, j, i + 1, j});
                    v[i][j]--;
                    v[i + 1][j]++;
                }
            }
        }
    }
    cout << (int)ans.size() << endl;
    for(Point &p : ans){
        cout << p.a + 1 << ' ' << p.b + 1 << ' ' << p.c + 1 << ' ' << p.d + 1 << endl;
    }
    return 0 ;
}