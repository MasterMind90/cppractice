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
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio 
    int n , m ; 
    cin >> n >> m ; 
    vector<vector<int> > v(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j] ; 
        }
    }
    vector<vector<int> > rowNix(n, vector<int>(m));
    vector<vector<int> > colNix(n, vector<int>(m));
    vector<vector<int> > rowNax(n, vector<int>(m));
    vector<vector<int> > colNax(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        set<int> s ;
        for(int j = 0; j < m; j++){
            int &x = v[i][j] ;
            s.insert(x) ; 
        }
        vector<int> t ;
        for(auto p : s){
            t.push_back(p) ; 
        }
        for(int j = 0; j < m; j++){
            int &x = v[i][j] ;
            int L = 0, R = (int)t.size() - 1;
            int ans = -1 ;
            while(L <= R){
                int mid = L + (R - L) / 2;
                if ( t[mid] == x ){
                    ans = mid ; 
                    break;
                }
                if ( t[mid] < x ){
                    L = mid + 1;
                }
                else R = mid - 1;
            }
            assert(ans != -1) ;
            rowNix[i][j] = ans ; 
            rowNax[i][j] = (int) t.size() - ans - 1 ;
        }
    }
    for(int i = 0; i < m; i++){
        set<int> s ;
        for(int j = 0; j < n; j++){
            int &x = v[j][i] ;
            s.insert(x) ; 
        }
        vector<int> t ;
        for(auto p : s){
            t.push_back(p) ; 
        }
        for(int j = 0; j < n; j++){
            int &x = v[j][i] ;
            int L = 0, R = (int) t.size() - 1;
            int ans = -1 ;
            while(L <= R){
                int mid = L + (R - L) / 2;
                if ( t[mid] == x ){
                    ans = mid ; 
                    break;
                }
                if ( t[mid] < x ){
                    L = mid + 1;
                }
                else R = mid - 1;
            }
            assert(ans != -1) ;
            colNix[j][i] = ans ;
            colNax[j][i] = (int) t.size() - ans - 1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << max(rowNix[i][j], colNix[i][j]) + 1 + max(rowNax[i][j], colNax[i][j]) << ' ';
        }
        cout << endl;
    }
    return 0 ; 
}