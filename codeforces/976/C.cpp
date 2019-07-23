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
    int n ;
    cin >> n ; 
    vector<pair<pair<int,int>,int> > v(n) ; 
    for(int i=0;i<n;i++){
    	cin >> v[i].first.first >> v[i].first.second ; 
    	v[i].first.second = -v[i].first.second; 
    	v[i].second = i ; 
    }
    sort(v.begin(),v.end()) ; 
    for(auto &p : v){
    	p.first.second = -p.first.second ; 
    }
    debug() << imie(v) ; 
    int x = v[0].first.first , y = v[0].first.second ; 
    int cur = v[0].second ; 
    for(int i=0;i<n;i++){
    	if ( v[i].second == cur ) continue ;
    	if ( v[i].first.first >= x && v[i].first.second <= y ){
    		cout << v[i].second+1 << ' ' << cur+1 << endl;
    		return 0 ; 
    	}
    	else if ( v[i].first.second > y ){
    		x = v[i].first.first , y = v[i].first.second ;  
    		cur = v[i].second ; 
    	}
    }
    cout << -1 << ' ' << -1 << endl;
    return 0 ;
}
