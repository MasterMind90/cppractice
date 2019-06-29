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
const ll INF = 1e18 ; 
int main(){
    fastio
    ll n , m ; 
    cin >> n >> m ; 
    vector<ll> v[n+1] ; 
    vector<bool> vis(n+1) ; 
    vector<int> indegree(n+1) ;
    for(ll i=0;i<m;i++){
    	ll x , y ; 
    	cin >> x >> y ; 
    	v[x].push_back(y) ; 
    	indegree[y]++;
    }
    ll s , t ;
    cin >> s >> t ; 
    if ( indegree[t] == 0 ){
    	cout << -1 << endl;
    	return 0;
    }
    vector<ll> dist(n+1,INF) ; 
    dist[s] = 0 ; 
    vis[s] = true ; 
    queue<ll> q; 
    q.push(s) ; 
    while(!q.empty()){
    	ll f = q.front() ; q.pop() ; 
    	for(ll c : v[f]){
    		for(ll k : v[c]){
    			for(ll h : v[k]){
    				if ( !vis[h] ){
    					dist[h] = dist[f] + 1 ;
    					if ( h == t ){
    						cout << dist[h] << endl;
    						return 0 ; 
    					}
    					vis[h] = true ; 
    					q.push(h) ; 
    				}
    			}
    		}
    	}
    }
    cout << -1 << endl;
    return 0 ;
}
