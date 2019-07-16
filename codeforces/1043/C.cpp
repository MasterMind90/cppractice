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
    int n = (int) s.size() ;
    vector<int> ans(n);
    bool flag = true ; 
    for(int i=0;i<n;){
    	debug() << "before: " imie(i) ; 
    	int bef = i ; 
    	bool ok = false ; 
    	while(i < n && s[i] == 'b' && flag ) {
    		if ( flag ) ok = true ; 
    		i++ ;
    	}
    	if ( bef == i ){
    		i = i + 1 ; continue ; 
    	}
    	debug() << "After: " imie(i) ; 
    	if ( ok )
    		flag = false , ans[i-1] = 1 ;
    	ok = false ;
    	while( i < n && s[i] == 'a' && !flag ) {
    		if ( !flag ) ok = true ; 
    		i++ ;
    	}
    	if ( !flag && !ok ){
    		ans[i-1] = 0 ; 
    		continue ;
    	}
    	if ( ok )
    		flag = true , ans[i-1] = 1 ; 
    	
    }
    for(int &c : ans){
    	cout << c << ' ' ; 
    }
    cout << endl;
    return 0 ;
}
/*
abbbbbbbbaaaa
bbbbbbbbaaaaa

babbbbbbbaaaa

bbbbbbbaaaaaa
abab

baab

aabaaaabaaabb
baaaaaabaaabb
aaaaaabbaaabb
bbaaaaaaaaabb


*/
