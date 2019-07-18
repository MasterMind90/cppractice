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

int main(){
    fastio
    int n , m ;
    cin >> n >> m ; 
    vector<vector<int> > a(n,vector<int>(m));
    vector<vector<bool> > doneA(n,vector<bool>(m));
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin >> a[i][j] ; 
    		doneA[i][j] = false ;
    	}
    }
    debug() << imie(a) ;
    vector<vector<int> > b(n,vector<int>(m));
    vector<vector<bool> > doneB(n,vector<bool>(m));
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin >> b[i][j] ; 
    	}
    }
    vector<multiset<int>> first ;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if ( !doneA[i][j] ){
    			multiset<int> mm ; 
    			for(int x=i,y=j;x<n&&y>=0;x++,y--){
    				doneA[x][y] = true ; 
    				mm.insert(a[x][y]);
    			}
    			first.push_back(mm) ; 
    		}
    	}
    }
    vector<multiset<int>> second ; 
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if ( !doneB[i][j] ){
    			multiset<int> mm ; 
    			for(int x=i,y=j;x<n&&y>=0;x++,y--){
    				doneB[x][y] = true ; 
    				mm.insert(b[x][y]);
    			}
    			second.push_back(mm) ; 
    		}
    	}
    }
    for(int i=0;i<(int)first.size();i++){
    	if ( first[i] != second[i] ){
    		cout << "NO" << endl;
    		return 0 ;
    	}
    }
    cout << "YES" << endl;
    return 0 ;
}
