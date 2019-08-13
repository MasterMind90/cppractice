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

bool check(string &a, string &b, int m, int n){
   int j = 0; 
   for (int i=0; i<n&&j<m; i++) 
       if (a[j] == b[i]) 
         j++; 
  
   return (j==m); 
}
int main(){
    fastio
    string s , t ; 
    cin >> s >> t ;
    int n = (int) s.size() ; 
    int m = (int) t.size() ; 
    int L = 0 , R = n - m ; 
    int ans = -1 ;
    while( L <= R ){
    	int mid = L + (R-L) / 2 ;
    	debug() << imie(mid) ;
    	bool ok = false;
    	for(int i=0;i+mid<=n;i++){
    		string ss = s.substr(0,i) + s.substr(i+mid); 
    		debug() << imie(ss) ; 
    		int a = (int) ss.size() ; 
    		if ( check(t,ss,m,a) ) {
    			ok = true ; 
    			break;
    		}
    	}
    	if ( ok ){
    		ans = mid ; 
    		L = mid + 1; 
    	}
    	else R = mid - 1;
    }
    if ( ans == -1 ){
    	cout << 0 << endl;
    }
    else cout << ans << endl;
    return 0 ;
}
