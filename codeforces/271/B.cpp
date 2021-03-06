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
const int MAXN = 1e5 + 10 ; 
bool prime[MAXN] ; 
int main(){
    fastio
    prime[0] = 1 ; 
    prime[1] = 1 ; 
    vector<int> primes ; 
    for(int i=2;i*i<MAXN;i++){
    	if ( !prime[i] ){
    		for(int j=i+i;j<MAXN;j+=i){
    			prime[j] = true ; 
    		}
    	}
    }
    for(int i=0;i<MAXN;i++){
    	if ( !prime[i] ){
    		primes.push_back(i) ; 
    	}
    }
    int n , m ; 
    cin >> n >> m ; 
    int g[n][m] ; 
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin >> g[i][j] ; 
    	}
    }
    int dist[n][m] ; 
    int ans = 1e9 + 10 ; 
    for(int i=0;i<n;i++){
    	int cnt = 0 ; 
    	for(int j=0;j<m;j++){
    		int index = lower_bound(primes.begin(),primes.end(),g[i][j]) - primes.begin() ;
    		dist[i][j] = primes[index] - g[i][j];
    		cnt += dist[i][j] ; 
    	}
    	ans = min(ans,cnt) ; 
    }
    for(int i=0;i<m;i++){
    	int cnt = 0 ; 
    	for(int j=0;j<n;j++){
    		cnt += dist[j][i] ; 
    	}
    	ans = min(ans,cnt) ; 
    }
    cout << ans << endl;
    return 0 ;
}
