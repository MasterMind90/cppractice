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
const int MAXN = 1e5+10 ; 
int n ; 
vector<int> graph[MAXN] ; 
map<pair<int,int> ,int> weight ; 
int vis[MAXN] ; 
int clr[MAXN] ; 
void dfs(int x,int color){
	if ( vis[x] ) return ; 
	vis[x] = true ; 
	if ( clr[x] == -1 ){
		clr[x] = color ; 
	}
	for(int c : graph[x]){
		if ( weight[{x,c}] % 2 == 0 ){
			clr[c] = clr[x] ; 
		}
		else clr[c] = !clr[x] ; 
		dfs(c,clr[c]);
	}
}
int main(){
	cin >> n ;     
	memset(clr,-1,sizeof clr);
	for(int i=0;i<n-1;i++){
		int x , y , w; 
		cin >> x >> y >> w ; 
		graph[x].push_back(y) ; 
		graph[y].push_back(x) ; 
		weight[{x,y}] = w ;
		weight[{y,x}] = w ;
	}
	for(int i=1;i<=n;i++){
		if ( !vis[i] ){
			dfs(i,0);
		}
	}
	for(int i=1;i<=n;i++){
		cout << clr[i] << endl;
	}
    return 0 ;
}
