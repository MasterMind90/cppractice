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
    string s ; 
    cin >> s ;
   	vector<string> t = { "dream" , "dreamer" , "erase" , "eraser" } ;  
   	while((int)s.size()>=5){
   		int n = (int) s.size() ; 
   		debug() << imie(n) ;
   		if ( s.substr(n-5) == t[0] || s.substr(n-5) == t[2] ){
   			debug() << imie(s.substr(n-5));
   			s.erase(n-5) ; 
   			debug() << imie(s);
   			continue ; 
   		}
   		else if ( n >= 6 && s.substr(n-6) == t[3] ){
   			debug() << imie(s.substr(n-6));
   			s.erase(n-6) ; 
   			debug() << imie(s) ; 
   			continue ; 
   		}
   		else if ( n >= 7 && s.substr(n-7) == t[1]){
   			debug() << imie(s.substr(n-7));
   			s.erase(n-7) ; 
   			debug() << imie(s) ;
   			continue ; 
   		}
   		break;
   	}
   	if ( s.size() == 0 ){
   		cout << "YES" << endl;
   	}
   	else cout << "NO" << endl;
   	return 0 ;
   }

