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
const int MAXN = 1e5 + 10 ;
const int INF = 1e9 + 10 ; 
int n , m ;
vector<vector<int> > v(MAXN) ; 
vector<int> dist(MAXN,-1) ; 
int dfs(int x){
	if ( (int)v[x].size() == 0 ){
		return 0 ; 
	}
	if ( dist[x] != -1 ) return dist[x] ;
	int ans = 0 ; 
	for(int &c : v[x]){
		ans = max(ans,1+dfs(c));
	}
	debug() << imie(ans) ;
	return dist[x] = ans ; 
}
int main(){
    fastio
    cin >> n >> m ; 
    vector<int> deg(n) ; 
    for(int i=0;i<m;i++){
    	int x , y ; 
    	cin >> x >> y ; 
    	x--, y-- ; 
    	v[x].push_back(y) ; 
    	deg[y]++;
    }
    int ans = 0 ; 
    for(int i=0;i<n;i++){
    	if ( deg[i] == 0 ){
    		ans = max(ans,dfs(i)) ; 
    	}
    }
    cout << ans << endl;
    return 0 ;
}
