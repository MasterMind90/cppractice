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
int n ; 
int fix(int x){
	return (x%n+n)%n ; 
}
int main(){
    fastio
    cin >> n ; 
    vector<int> d(n) ; 
    for(int i=0;i<n;i++){
    	cin >> d[i] ; 
    }
    int L = 0 , R = min(d[n-1],d[0]);
    while(L<=R){
    	int mid = L + (R-L) / 2 ; 
    	debug() << imie(mid) ;
    	int x = d[n-1] - mid ; 
    	int y = d[0] - mid ; 
    	debug() << imie(x) imie(y) ; 
    	for(int i=1;i<n;i++){
    		if ( i == n - 1 ){
    			y = x - y ; 
    			continue;
    		}
    		y = d[i] - y;
    	}
    	debug() << imie(x) imie(y) ; 
    	if ( y == 0 ){
    		cout << mid*2 ;
    		int c = d[0] - mid ; 
    		for(int i=1;i<n;i++){
    			cout << ' ' << c * 2 ;
    			c = d[i] - c ; 
    		}
    		return 0 ; 
    	}
    	if ( y < 0 ){
    		R = mid - 1; 
    	}
    	else L = mid + 1 ; 
    }
    return 0 ;
}
