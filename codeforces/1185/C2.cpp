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
const int MAXT = 110 ; 
int main(){
    fastio
    int n , m ; 
    cin >> n >> m ; 
    vector<int> cnt(MAXT,0);
    int sum = 0 ; 
    for(int i=0;i<n;i++){
    	int x ; 
    	cin >> x ; 
    	sum += x ; 
    	if ( sum <= m ){
    		cout << 0 << ' ' ; 
    	}
    	else{
    		int cur = sum ; 
    		int res = 0 ; 
    		for(int j=100;j>=1;j--){
    			if ( cnt[j] ){
    				int L = 1 , R = cnt[j] ; 
    				int ans = -1 ; 
    				while(L<=R){
    					int mid = L + (R-L) / 2 ;
    					if ( cur-m <= mid*j ){
    						ans = mid ; 
    						R = mid - 1; 
    					}
    					else L = mid + 1 ; 
    				}
    				if ( ans == -1 ){
    					cur -= j*cnt[j];
    					res += cnt[j] ; 
    				}
    				else{
    					res += ans ; 
    					cout << res << ' ' ; 
    					break;
    				}
    			}
    		}
    	}
    	cnt[x]++;
    }
    return 0 ;
}
