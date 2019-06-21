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
const ll MAXN = 1e5 + 1 ;
int main(){
    fastio
    ll n , q ; 
    cin >> n >> q ; 
    deque<ll> deq ; 
    pair<ll,ll> first[n+1] ; 
    ll nax = -1 ; 
    for(ll i=0;i<n;i++){
    	ll x ;
    	cin >> x ; 
    	nax = max(nax,x) ; 
    	deq.push_back(x) ; 
    }
    debug() << imie(deq) ; 
    ll cur = 1  ;
    while(deq.front() != nax){
    	ll a = deq.front() ; deq.pop_front() ; 
    	ll b = deq.front() ; deq.pop_front() ; 
    	first[cur++] = {a,b} ; 
    	if ( a >= b ){
    		deq.push_front(a) ; 
    		deq.push_back(b) ; 
    	}
    	else{
    		deq.push_front(b) ; 
    		deq.push_back(a) ; 
    	}
    }
    vector<ll> v(deq.begin(),deq.end()) ; 
    debug() << imie(v) ; 
    first[cur] = {v[0],v[1]} ; 
    debug() << range(first,first+n+1) ; 
    while(q--){
    	ll x ; 
    	cin >> x ; 
    	if ( x <= cur ){
    		cout << first[x].first << ' ' << first[x].second << endl;
    		continue ; 
    	}
    	cout << v[0] << ' ' << v[( x - cur ) % (n-1) + 1] << endl;
    }
    return 0 ;
}
