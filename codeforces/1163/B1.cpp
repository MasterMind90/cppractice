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
const int MAXN = (int)1e5 + 10 ; 
int main(){
    fastio
    int n ; 
    cin >> n ; 
    vector<int> v(n) ; 
    for(int &x : v){
    	cin >> x ; 
    }
    vector<vector<int> > cnt(11,vector<int>(MAXN,0));
    for(int i=0;i<n;i++){
    	cnt[v[i]][i+1] = 1 ; 
    }
    for(int i=1;i<=10;i++){
    	for(int j=1;j<=n;j++){
    		cnt[i][j] += cnt[i][j-1] ; 
    	}
    }
    int ans = 1 ; 
    for(int i=n;i>1;i--){
    	vector<int> res ; 
    	for(int j=1;j<=10;j++){
    		if ( cnt[j][i] ){
    			res.push_back(cnt[j][i]) ; 
    		}
    	}
    	sort(res.begin(),res.end()) ; 
    	int t = (int) res.size() ; 
    	if ( t == 1 ){
    		ans = i ; 
    		break ; 
    	}
    	if ( res[0] == 1 && res[1] == res[t-1]){
    		ans = i ; 
    		break ; 
    	}
    	if ( res[0] == res[t-2] && res[t-1] - res[0] == 1 ){
    		ans = i ; 
    		break; 
    	}
    }
    cout << ans << endl;
    return 0 ;
}

/*
2 3
*/