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
const ll N = 1e5 + 10 ;
const ll INF = 1e18 + 10 ;
const double EPS = 1e-6 ; 
vector<int> parent(N) ; 
int Find(int x){
    if ( x == parent[x] ) return x ;
    return parent[x] = Find(parent[x]) ; 
}
void Union(int x,int y){
    int X = Find(x) ; 
    int Y = Find(y) ; 
    if ( X == Y ) return ;
    parent[X] = Y ; 
}
signed main(){
    fastio
    for(int i = 0; i < N; i++){
        parent[i] = i ; 
    }
    int n , m , k ; 
    cin >> n >> m >> k ; 
    vector<int> v[n + 1] ; 
    set<int> blocked[n + 1] ;
    vector<int> ans(n + 1) ; 
    for(int i = 0; i < m; i++){
        int x , y ; 
        cin >> x >> y ; 
        v[x].push_back(y);
        v[y].push_back(x);
        Union(x, y) ;
    }
    for(int i = 0; i < k; i++){
        int x , y ; 
        cin >> x >> y ; 
        blocked[x].insert(y) ; 
        blocked[y].insert(x) ;
    }
    for(int i = 1; i < n + 1; i++){
        ans[Find(i)]++ ; 
    }
    debug() << imie(ans) ;
    for(int i = 1; i < n + 1; i++){
        int net = ans[Find(i)];
        net-- ; 
        for(int c : blocked[i]){
            if ( Find(c) == Find(i) ) net--;
        }
        cout << net - v[i].size() << ' ' ;
    }
    cout << endl;
    return 0; 
}