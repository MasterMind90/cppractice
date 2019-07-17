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
const ll MAXN = 1e5 + 10 ; 
const ll mod = (ll)1e9 + 7 ; 
ll n , k ; 
vector<ll> parent(MAXN) ; 
vector<ll> r(MAXN) ; 
ll Find(ll x){
	if ( x == parent[x] ) return x ; 
	parent[x] = Find(parent[x]) ; 
	return parent[x] ; 
}
void Union(ll x,ll y){
	ll Px = Find(x) ;
	ll Py = Find(y) ;
	if ( Px == Py ) return  ;
	if ( r[Px] < r[Py] ){
		parent[Px] = Py ; 
	}
	else if ( r[Py] < r[Px] ){
		parent[Py] = Px ;
	}
	else{
		parent[Px] = Py ; 
		r[Py]++;
	}
}
ll power(ll x, ll y){
	ll ans = 1 ;
	for(ll i=0;i<y;i++){
		ans = ( (ans % mod) * (x % mod) ) % mod ; 
	}
	return ans % mod ; 
}
ll fix(ll x){
	return (x%mod+mod)%mod;
}
int main(){
    fastio
    cin >> n >> k ; 
    for(ll i=0;i<=n;i++){
    	parent[i] = i ; 
    	r[i] = 0 ; 
    }
    for(ll i=0;i<n-1;i++){
    	ll x , y , c ; 
    	cin >> x >> y >> c ; 
    	if ( c == 0 ){
    		Union(x,y) ; 
    	}
    }
    vector<ll> cnt(n+1) ; 
    vector<bool> flag(n+1) ; 
    for(ll i=1;i<=n;i++){
    	cnt[Find(i)]++;
    }
    ll total = power(n,k) ; 
    for(ll i=1;i<=n;i++){
    	ll p = Find(i) ; 
    	if ( !flag[p] ){
    		total = fix((total % mod - power(cnt[p],k) % mod) % mod);
    		flag[p] = true ;
    	}
    }
    cout << total << endl;
    return 0 ;
}
