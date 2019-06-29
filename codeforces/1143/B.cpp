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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

int main(){
    fastio
    string s ; 
    cin >> s ;  
    string x = s ; 
    int n = (int) s.size() ; 
    int ans = 1 ; 
    int index = n ; 
    for(int i=0;i<n;i++){
    	ans *= (s[i] - '0') ; 
    	if ( s[i] == '0' ) x[i] = '9' ; 
    }
    for(int i=index-1;i>=0;i--){
    	if ( i == 0 && s[i] == '1' ){
    		int res = 1 ; 
    		for(int j=1;j<n;j++){
    			res *= (x[j]-'0') ; 
    		}
    		ans = max(ans,res) ; 
    		continue ; 
    	} 
    	if ( s[i] == '0' ) continue ; 
    	string tmp = x; 
    	tmp[i] -= 1 ; 
    	debug() << imie(tmp) ; 
    	int res = 1 ; 
    	for(char &c : tmp){
    		res *= (c-'0') ; 
    	}
    	ans = max(ans,res) ; 
    	x[i] = '9' ; 
    }
    cout << ans << endl;
    return 0 ;
}
