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
const ll INF = 1e18; 
int main(){
    fastio
    ll n , m ; 
    cin >> n >> m ; 
    vector<pair<ll,ll> > graph[n+1] ; 
    for(ll i=0;i<m;i++){
    	ll a , b , c ; 
    	cin >> a >> b >> c ; 
    	graph[a].push_back({c,b});
    	graph[b].push_back({c,a});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> > , greater<pair<ll,ll> > > q ;
    vector<ll> dist(n+1,INF) ; 
    vector<ll> parent(n+1) ; 
    for(ll i=0;i<=n;i++){
    	parent[i] = i ; 
    }
    dist[1] = 0 ; 
    q.push({0,1});
    while(not q.empty()){
    	auto top = q.top() ; q.pop() ; 
    	for(auto &p : graph[top.second]){
    		if ( dist[p.second] > dist[top.second] + p.first ){
    			dist[p.second] = dist[top.second] + p.first ;
    			parent[p.second] = top.second ; 
    			q.push(p) ; 
    		}
    	}
    }
    if ( dist[n] == INF ){
    	cout << -1 << endl ; 
    }
    else{
    	stack<ll> s ; 
    	ll start = n ; 
    	s.push(n) ; 
    	while(parent[start] != start){
    		s.push(parent[start]);
    		start = parent[start] ; 
    	}
    	while(not s.empty()){
    		cout << s.top() << ' ' ; 
    		s.pop() ; 
    	}
    }
    return 0 ;
}
