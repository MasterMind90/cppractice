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
    string s ; 
    cin >> s ; 
    int n = (int) s.size() ; 
    vector<vector<int>> sum(26,vector<int>(n+1,0)) ; 
    for(int i=0;i<n;i++){
    	sum[s[i]-'a'][i+1] = 1 ; 
    }
    for(int i=0;i<26;i++){
    	for(int j=1;j<=n;j++){
    		sum[i][j] += sum[i][j-1] ; 
    	}
    }
    debug() << imie(sum) ; 
    int L = 1 , R = n ; 
    int ans = -1 ; 
    while(L<=R){
    	int mid = L + (R-L) / 2 ; 
    	debug() << imie(mid) ; 
    	int sub = 0 ; 
    	int cnt[26] = {0} ; 
    	for(int i=0;i<=n-mid;i++){
    		for(int j=0;j<26;j++){
    			cnt[j] += ((sum[j][i+mid] - sum[j][i] ) != 0 ) ;
    		}
    		sub++ ; 
    	}
    	debug() << imie(sub) ; 
    	bool flag = false ; 
    	for(int i=0;i<26;i++){
    		if ( cnt[i] == sub ) flag = true ; 
    	}
    	debug() << range(cnt,cnt+26) ; 
    	if ( flag ) {
    		ans = mid ; 
    		R = mid - 1 ; 
    	}
    	else L = mid + 1 ; 
    }
    cout << ans << endl;
    return 0 ;
}
