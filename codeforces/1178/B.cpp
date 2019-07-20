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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 

int main(){
    fastio
    string s ; 
    cin >> s ; 
    ll n = (ll) s.size() ;
    vector<ll> ans ; 
    int start = -1; 
    for(ll i=0;i<n;i++){
    	if ( s[i] == 'v' ) {
    		start = i ; 
    		break ; 
    	}
    }
    if ( start == -1 ){
    	cout << 0 << endl;
    	return 0 ; 
    }
    int first = true ; 
    for(int i=start;i<n;){
    	if ( first ){
    		int cnt = 0 ; 
    		while(i < n && s[i] == 'v') cnt++, i++ ; 
    		ans.push_back(cnt);
    		first = false ; 
    	}
    	else{
    		int cnt = 0 ; 
    		while(i < n && s[i] == 'o') cnt++, i++ ; 
    		ans.push_back(cnt);
    		first = true ; 
    	}
    }
    debug() << imie(ans) ; 
    int m = (int) ans.size() ; 
    int cnt = 0 ; 
    vector<ll> res(m) ;
    for(int i=0;i<m;i++){
    	if ( i % 2 == 0 ) cnt += (ans[i]-1) ;
    	else res[i] = cnt ; 
    }
    cnt = 0 ; 
    vector<ll> res2(m) ;
    if ( m % 2 == 0 ){
    	for(int i=m-2;i>=0;i--){
    		if ( i % 2 == 0 ) {
    			cnt += (ans[i]-1);
    		}
    		else res2[i] = cnt ; 
    	}
    }
    else{
    	for(int i=m-1;i>=0;i--){
    		if ( i % 2 == 0 ){
    			cnt += (ans[i]-1);
    		}
    		else res2[i] = cnt ; 
    	}
    }
    ll total = 0 ; 
    for(int i=1;i<m;i+=2){
    	debug() << imie(ans[i]) imie(res[i]) imie(res2[i]);
    	total += ans[i] * res[i] * res2[i] ;
    }
    debug() << imie(res) ; 
    debug() << imie(res2) ; 
    cout << total << endl;
    return 0 ;
}
