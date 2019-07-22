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
    int n , k ; 
    cin >> n >> k ; 
    vector<int> v(n) ; 
    for(int &x : v){
    	cin >> x ; 
    }
    vector<int> diff(n) ; 
    for(int i=1;i<n;i++){
    	diff[i] = abs(v[i-1] - v[i]) ; 
    }
    vector<int> tmp = diff ; 
    sort(tmp.rbegin(),tmp.rend());
    debug() << imie(tmp) ; 
    multiset<int> mm ; 
    for(int i=0;i<k-1;i++){
    	mm.insert(tmp[i]);
    }
    debug() << imie(mm) ; 
    // take care when k = 1 ; 
    vector<bool> flag(n) ; 
    for(int i=1;i<n;i++){
    	auto it = mm.find(diff[i]);
    	if ( it == mm.end() ) continue ; 
    	flag[i-1] = true ; 
    	mm.erase(it) ; 
    }    	
    debug() << imie(flag) ; 
    int nix = 1e9 + 10 ; 
    int nax = 0 ;
    ll ans = 0 ; 
    for(int i=0;i<n;i++){
    	nix = min(nix,v[i]) ; 
    	nax = max(nax,v[i]) ; 
    	debug() << imie(nix) imie(nax) ; 
    	if ( flag[i] ){
    		ans += (nax - nix) ; 
    		nix = 1e9 + 10 ; 
    		nax = 0 ;
    	}
    }
    if ( k == 1 ){
    	cout << nax - nix << endl;
    }
    else {
    	if ( flag[n-1] == false )
    		cout << ans + (nax-nix) << endl;
    	else cout << ans << endl;
    }
    return 0 ;
}
