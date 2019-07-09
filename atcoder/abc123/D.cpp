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
    ll x , y , z , k ; 
    cin >> x >> y >> z >> k ; 
    vector<ll> X(x) , Y(y) , Z(z) ; 
    for(ll i=0;i<x;i++){
    	cin >> X[i] ; 
    }
    for(ll i=0;i<y;i++){
    	cin >> Y[i] ; 
    }
    for(ll i=0;i<z;i++){
    	cin >> Z[i] ; 
    }
    sort(X.rbegin(),X.rend());
    sort(Y.rbegin(),Y.rend());
    sort(Z.rbegin(),Z.rend());
    vector<ll> ans ; 
    for(ll i=0;i<x;i++){
    	for(ll j=0;j<y;j++){
    		ans.push_back(X[i]+Y[j]);
    	}
    }
    sort(ans.rbegin(),ans.rend());
    ll n = (int) ans.size() ; 
    vector<ll> res ; 
    for(int i=0;i<min(k,n);i++){
    	for(int j=0;j<z;j++){
    		res.push_back(ans[i]+Z[j]);
    	}
    }
    sort(res.rbegin(),res.rend());
    for(int i=0;i<k;i++){
    	cout << res[i] << endl;
    }
    return 0 ;
}

