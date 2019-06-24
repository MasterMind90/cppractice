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
    int n , m ; 
    cin >> n >> m ; 
    vector<pair<int,int> > v(m) ; 
    for(auto &p : v){
    	cin >> p.first >> p.second ; 
    }
    vector<int> ans ; 
    ans.push_back(v[0].first) ; 
    ans.push_back(v[0].second) ; 
    int a = v[0].first ;
    int b = v[0].second ;
    for(int i=1;i<m;i++){
    	if ( !(v[i].first == a || v[i].first == b || v[i].second == a || v[i].second == b) ){
    		ans.push_back(v[i].first);
    		ans.push_back(v[i].second) ;
    		break;
    	}
    }
    if ( (int) ans.size() == 2 ){
    	cout << "YES" << endl;
    	return 0 ; 
    }
    for(int i=0;i<(int)ans.size();i++){
    	for(int j=i+1;j<(int)ans.size();j++){
    		int cnt = 0 ; 
    		for(int k=0;k<m;k++){
    			if ( v[k].first == ans[i] || v[k].second == ans[i] || v[k].first == ans[j] || v[k].second == ans[j] ) cnt++ ; 
    		}
    		if ( cnt == m ){
    			cout << "YES" << endl;
    			return 0 ;
    		}
    	}
    }
    cout << "NO" << endl;
    return 0 ;
}
