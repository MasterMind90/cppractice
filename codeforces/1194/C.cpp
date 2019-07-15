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
    int q ; 
    cin >> q ; 
    while(q--){
    	string s , t , p ; 
    	cin >> s >> t >> p ; 
    	int a = (int) s.size() ; 
    	int b = (int) t.size() ; 
    	int cura = 0 ; 
    	bool flag = true ;
    	for(int i=0;i<b;i++){
    		bool ok = false ;
    		if (cura < a && t[i] == s[cura] ){
    			ok = true ; 
    			cura++ ; 
    		}
    		if ( ok ) continue ; 
    		int c = (int) p.size() ; 
    		for(int j=0;j<c;j++){
    			if ( t[i] == p[j] ){
    				ok = true ; 
    				p.erase(p.begin()+j);
    				break;
    			}
    		}
    		if ( !ok ) {
    			flag = false ;
    			break;
    		}
    	}
    	if ( flag ) {
    		debug() << imie(cura) ; 
    		if ( cura == a )
    			cout << "YES" << endl;
    		else cout << "NO" << endl;
    	}
    	else cout << "NO" << endl;
    }
    return 0 ;
}
