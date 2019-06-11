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
	int t; 
	cin >> t ; 
	while(t--){
		int n , m ; 
		cin >> n >> m ; 
		vector<bool> vis(n) ; 
		vector<int> graph[n] ; 
		vector<int> deg(n) ; 
		for(int i=0;i<m;i++){
			int x , y ; 
			cin >> x >> y ; 
			x--,y-- ; 
			graph[x].push_back(y) ; 
			graph[y].push_back(x) ; 
			deg[x]++ ; 
			deg[y]++ ; 
		}
		vector<pair<int,int> > degree ; 
		for(int i=0;i<n;i++){
			degree.push_back({deg[i],i}) ; 
		}
		sort(degree.rbegin(),degree.rend());
		debug() << imie(degree) ; 
		vector<int> ans ; 
		for(auto p : degree){
			if ( !vis[p.second] ){
				// add one to the answer 
				ans.push_back(p.second) ; 
				vis[p.second] = true ; 
				for(int c : graph[p.second]){
					vis[c] = true ; 
				}
			}
		}
		debug() << imie(degree) ; 
		debug() << imie(vis) ; 
		if ( (int) ans.size() <= n/2 ){
			cout << (int)ans.size() << endl;
			for(int c : ans){
				cout << c+1 << ' ' ; 
			}
			cout << endl;
		}
		else{
			set<int> ss(ans.begin(),ans.end()) ; 
			vector<int> res ; 
			for(int i=0;i<n;i++){
				if ( ss.find(i) == ss.end() ){
					res.push_back(i+1) ; 
				}
			}
			cout << (int)res.size() << endl;
			for(int c : res){
				cout << c << ' ' ; 
			}
			cout << endl;
		}
	}
	return 0 ;
}
