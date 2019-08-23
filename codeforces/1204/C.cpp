
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
int main(){
    fastio
    int n ; 
    cin >> n ; 
    vector<vector<int> > graph(n+1) ;
    for(int i=0;i<n;i++){
    	string s ; 
    	cin >> s ;
    	for(int j=0;j<(int)s.size();j++){
    		if ( s[j] == '1' )
    			graph[i+1].push_back(j+1) ;
    	}
    }
    debug() << imie(graph) ; 
    int m ; 
    cin >> m ;
    vector<int> p(m) ; 
    for(int i=0;i<m;i++){
    	cin >> p[i] ; 
    }
    vector<vector<int> > dist(n+1,vector<int>(n+1,INF));
    for(int i=0;i<m;i++){
    	int v = p[i] ;
    	vector<int> &d = dist[v] ; 
    	queue<int> q ; 
    	q.push(v) ; 
    	d[v] = 0 ; 
    	while(not q.empty()){
    		int f = q.front() ; q.pop() ;
    		for(int &c : graph[f]){
    			if ( d[c] > d[f] + 1 ){
    				d[c] = d[f] + 1; 
    				q.push(c) ; 
    			}
    		}
    	}
    }
    vector<int> ans ; 
    ans.push_back(p[0]) ;
    for(int i=1;i<m-1;i++){
    	int b = ans.back() , cur = p[i], a = p[i+1] ; 
    	if ( dist[b][a] < dist[b][cur] + 1 )
    		ans.push_back(p[i]) ; 
    }
    ans.push_back(p[m-1]) ;
    int sz = (int) ans.size() ;
    cout << sz << endl;
    for(int &c : ans){
    	cout << c << ' '; 
    }
    cout << endl;
    return 0 ;
}
/*
5
01001
00100
00010
10000
00100
4
1 2 3 4
*/