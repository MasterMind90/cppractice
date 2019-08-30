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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 
const int INF = 1e9 + 10 ;
vector<vector<int> > graph ; 
vector<int> cat ; 
vector<bool> vis ; 
vector<int> leafs ; 
int n , m ;
void dfs(int x,int cur,int nax){
	vis[x] = true ;
	bool ok = false ;
	for(int &p : graph[x]){
		if ( !vis[p] ){
			ok = true ;
			if ( cat[p] ) dfs(p, cur + 1, max(nax,cur+1) ) ; 
			else dfs(p, 0, max(nax,cur) ) ; 
		}
	}
	if ( !ok ){
		leafs[x] = nax ;
	}
}
int main(){
	fastio
	cin >> n >> m ;
	graph.resize(n) ; 
	cat.resize(n) ; 
	vis.resize(n) ; 
	leafs.resize(n,INF) ; 
	for(int i = 0; i < n; i++){
		cin >> cat[i] ; 
	}
	for(int i = 0; i < n - 1; i++){
		int x , y ; 
		cin >> x >> y ; 
		x--, y--;
		graph[x].push_back(y) ;
		graph[y].push_back(x) ;
	}
	dfs(0,cat[0],cat[0]) ; 
	debug() << imie(leafs) ;
	int cnt = 0 ; 
	for(int &c : leafs){
		if ( c <= m ) cnt++ ;
	}
	cout << cnt << endl;
	return 0 ;
}
