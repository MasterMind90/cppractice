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
    int n ; 
    cin >> n ; 
    pair<vector<int>,int> v[n] ;  
    multiset<int> ms ; 
    for(int i=0;i<n;i++){
    	int x ; 
    	cin >> x ; 
    	ms.insert(x) ; 
    	v[x].first.push_back(i) ; 
    	v[x].second = 0 ; 
    }
    vector<int> colour(n) ; 
    int color = 1 ;
    while((int)ms.size()){
    	int c = *ms.begin() ;
    	debug() << imie(c) imie(color) ; 
    	if ( color > n ) return cout << "Impossible" << endl , 0 ; 
    	if ( v[c].second < v[c].first.size() )
    		colour[v[c].first[v[c].second++]] = color ; 
    	else return cout << "Impossible" << endl , 0 ; 
    	debug() << imie(v[c].second) ; 
    	auto it = ms.find(c) ; 
    	ms.erase(it) ; 
    	for(int i=0;i < n - c - 1 ;i++){
    		auto itt = ms.find(c) ; 
    		if ( itt == ms.end() ) return cout << "Impossible" << endl , 0 ; 
    		if ( color > n ) return cout << "Impossible" << endl , 0 ; 
    		debug() << imie(v[c].second) ; 
    		if ( v[c].second < v[c].first.size() )
    			colour[v[c].first[v[c].second++]] = color ; 
    		else return cout << "Impossible" << endl , 0 ; 
    		ms.erase(itt) ; 
    	}
    	color++ ; 
    }
    cout << "Possible" << endl;
    for(int i=0;i<n;i++){
    	cout << colour[i] << ' ' ; 
    }
    cout << endl;
    return 0 ;
}
