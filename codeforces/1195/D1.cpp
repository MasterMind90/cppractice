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
const ll mod = 998244353;
ll power(ll x,ll y){
	ll ans = 1 ;
	for(int i=0;i<y;i++){
		ans = ( (ans % mod) * (x % mod) ) % mod ;
	}
	return ans ; 
}
ll fix(int x){
	return (x % mod + mod ) % mod ; 
}
int main(){
    fastio
    int n ;
    cin >> n ; 
    ll sum = 0 ;
    for(int i=0;i<n;i++){
    	string s ; 
    	cin >> s ;
    	int m = (int) s.size() ; 
    	ll ans = 0 ; 
    	for(int c=0,j=m+m-1;c<m;c++,j-=2){
    		ans = ans % mod + (s[c]-'0')*power(10,j) % mod ; 
    	}
    	ans = ( (ans % mod) * ( n % mod) ) % mod ; 
    	sum = ( sum % mod + ans % mod ) % mod ; 
    	ans = 0 ; 
    	for(int c=m-1,j=0;c>=0;c--,j+=2){
    		ans = ans % mod + (s[c]-'0')*power(10,j) % mod ; 
    	}
    	ans = ( (ans % mod) * ( (n) % mod) ) % mod ; 
    	sum = ( sum % mod + ans % mod ) % mod ; 
    }
    cout << fix(sum) << endl;
    return 0 ;
}
