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
typedef long long ll;
int n ; 
bool ok(vector<int> &v,vector<int> &ans){
	for(int i=0;i<n;i++){
		if ( v[i] != ans[i] ) return false ;
	}
	return true ; 
}

int main(){
    cin >> n ; 
    vector<int> v(n) ;
    for(int &x : v){
    	cin >> x ; 
    }
    int ans = 0 ; 
    while((int)v.size()){
    	debug() << "Before : " imie(v) ; 
    	while( (int) v.size() && v[0] == 0 ){
    		v.erase(v.begin()) ; 
    	}
    	while( (int) v.size() && v[(int)v.size()-1] == 0 ){
    		v.pop_back() ; 
    	}
    	for(int i=0;i<(int)v.size()-1;i++){
    		while ( v[i] == 0 && v[i+1] == 0 ) {
    			v.erase(v.begin()+i) ; 
    		}
    	}
    	debug() << "After : " imie(v) ; 
    	int cnt = 0 ; 
    	bool ok = false ; 
    	for(int i=0;i<(int)v.size();i++){
    		ok = true ; 
    		if ( v[i] > 0 ) v[i]--;
    		else cnt++ ; 
    	}
    	if ( ok ) ans += cnt + 1 ; 
    	debug() << imie(ans) ; 
    }
    cout << ans << endl;
    return 0 ;
}
