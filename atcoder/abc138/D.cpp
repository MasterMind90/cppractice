#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 

int main(){
    fastio
    ll n , m ; 
    cin >> n >> m ; 
    vector<vector<ll> > graph(n+1) ; 
    for(ll i=0;i<n-1;i++){
    	ll x , y ; 
    	cin >> x >> y ; 
    	graph[x].push_back(y) ; 
    	graph[y].push_back(x) ; 
    }
    vector<ll> val(n+1) ; 
    for(ll i=0;i<m;i++){
    	ll x , c ; 
    	cin >> x >> c ; 
    	val[x] += c ; 
    }
    vector<ll> dist(n+1) ; 
    vector<bool> vis(n+1) ; 
    dist[1] = val[1] ;
    queue<ll> q ;
    q.push(1) ;
    vis[1] = true ;
    while(not q.empty()){
    	ll f = q.front() ; q.pop() ;
    	for(ll &p : graph[f]){
    		if ( vis[p] ) continue ;
    		dist[p] = val[p] + dist[f] ; 
    		vis[p] = true ; 
    		q.push(p) ; 
    	}
    }
    for(ll i=1;i<=n;i++){
    	cout << dist[i] << ' ' ;
    }
    cout << endl;
    return 0 ;
}
