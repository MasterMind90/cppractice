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
typedef long long ll;
int main(){
	ll n ; 
	cin >> n ; 
	vector<pair<ll,ll> > tree[n+1] ; 
	vector<ll> dist(n+1) ; 
	vector<ll> vis(n+1) ; 
	for(ll i=0;i<n-1;i++){
		ll x , y , c ; 
		cin >> x >> y >> c ; 
		tree[x].push_back({y,c}) ; 
		tree[y].push_back({x,c});
	}
	ll m , start ; 
	cin >> m >> start ; 
	queue<pair<ll,ll> > q ; 
	q.push({start,0});
	vis[start] = true ; 
	dist[start] = 0 ; 
	while(q.size()){
		auto f = q.front() ; q.pop() ; 
		for(auto p : tree[f.first]){
			if ( !vis[p.first] ) {
				dist[p.first] = dist[f.first] + p.second ; 
				vis[p.first] = true ; 
				q.push({p.first,dist[p.first]});
			}
		}
	}
	debug() << imie(dist) ; 
	while(m--){
		ll x , y ; 
		cin >> x >> y ; 
		cout << dist[x] + dist[y] << endl;
	}
    return 0 ;
}
