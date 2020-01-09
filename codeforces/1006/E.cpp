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
int n , q ;
vector<priority_queue<int> > graph ; 
vector<int> v ; 
vector<vector<int> > gg ; 
vector<int> dp;
int cur = 1 ; 
int recur(int x){
    if ( gg[x].size() == 0 ) return dp[x] = 1 ;
    int ans = 0 ; 
    for(int c : gg[x]){
        ans += recur(c) ; 
    }
    return dp[x] = 1 + ans ; 
}
void dfs(int x){
    v[cur++] = x ; 
    priority_queue<int> &q = graph[x] ; 
    while(not q.empty()){
        int f = -q.top(); q.pop() ; 
        dfs(f) ; 
    }
}
int main(){
    fastio
    cin >> n >> q ;
    graph.resize(n + 1) ;
    v.resize(n + 1) ; 
    dp.resize(n + 1) ;
    gg.resize(n + 1) ;
    for(int i = 2; i <= n; i++){
        int x ; 
        cin >> x ;
        graph[x].push(-i) ; 
        gg[x].push_back(i) ;
    }
    recur(1) ;
    dfs(1) ; 
    vector<int> pos(n + 1) ; 
    for(int i = 1; i <= n; i++){
        pos[v[i]] = i ; 
    }
    debug() << imie(dp) ;
    while(q--){
        int u , k ; 
        cin >> u >> k ; 
        if ( k > dp[u] ){
            cout << -1 << endl;
        }
        else{
            cout << v[pos[u] + k - 1] << endl;
        }
    }
    return 0; 
}