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

int main(){
    int n , m ;
    cin >> n >> m ;
    vector<vector<int> > graph(3*n) ;
    for(int i=0;i<m;i++){
        int x , y ;
        cin >> x >> y ;
        x--, y-- ;
        graph[x].push_back(y+n) ;
        graph[x+n].push_back(y+2*n) ;
        graph[x+2*n].push_back(y) ;
    }
    int s , t ;
    cin >> s >> t ;
    s--,t-- ;
    vector<int> dist(n*3,-1) ;
    queue<int> q ;
    dist[s] = 0 ;
    q.push(s) ;
    while(!q.empty()){
        int f = q.front() ; q.pop() ;
        for(int c : graph[f]){
            if ( dist[c] == -1 ){
                dist[c] = dist[f] + 1 ;
                if ( c == t ){
                    cout << dist[c]/3 << endl;
                    return 0 ;
                }
                q.push(c) ;
            }
        }
    }
    cout << -1 << endl;
    return 0 ;
}
