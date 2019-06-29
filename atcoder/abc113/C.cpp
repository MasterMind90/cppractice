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
string format(int x){
	stringstream ss ; 
	ss << x ; 
	string s ; 
	ss >> s ; 
	while((int)s.size()<6){
		s = "0" + s ; 
	}
	return s ; 
}
int main(){
    fastio
    int n , m ; 
    cin >> n >> m ; 
    vector<int> v[n+1] ; 
    vector<pair<int,int> > vp(m) ; 
    for(int i=0;i<m;i++){
    	int p , y ; 
    	cin >> p >> y ; 
    	vp[i] = {p,y} ; 
    	v[p].push_back(y) ; 
    }
    for(int i=1;i<=n;i++){
    	sort(v[i].begin(),v[i].end()) ; 
    }
    for(int i=0;i<m;i++){
    	int index = lower_bound(v[vp[i].first].begin(), v[vp[i].first].end(),vp[i].second) - v[vp[i].first].begin() ; 
    	index++ ; 
    	cout << format(vp[i].first) + format(index) << endl;
    }
    return 0 ;
}
