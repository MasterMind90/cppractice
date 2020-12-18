#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sim template < class c
#define int long long
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
~debug() { cerr << '\n'; }
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
typedef tree< pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    int n , m ;
    cin >> n >> m ;
    vector<int> a , b ;
    for(int i = 0; i < n / 2; i++){
    	int x ; 
    	cin >> x ;
    	a.emplace_back(x % m) ;
    }
    for(int i = n / 2; i < n; i++){
    	int x ; 
    	cin >> x ;
    	b.emplace_back(x % m) ;
    }
    int A = (int)a.size() ;
    int B = (int)b.size() ;
    vector<int> sumA , sumB ; 
    for(int mask = 0; mask < (1LL << A); mask++){
    	int sum = 0 ;
    	for(int i = 0; i < A; i++){
    		if ( (1LL << i) & mask ) {
    			sum += a[i] ;
    		}
    	}
    	sumA.emplace_back(sum % m) ;
    }
    for(int mask = 0; mask < (1LL << B); mask++){
    	int sum = 0 ;
    	for(int i = 0; i < B; i++){
    		if ( (1LL << i) & mask ) {
    			sum += b[i] ;
    		}
    	}
    	sumB.emplace_back(sum % m) ;
    }
    sort(sumA.begin(), sumA.end()) ;
    sort(sumB.begin(), sumB.end()) ;
    int answer = 0 ;
    for(int &c : sumA){
    	answer = max(answer, c) ;
    }
    for(int &c : sumB){
    	answer = max(answer, c) ;
    }
    for(int &c : sumA){
    	int target = m - c - 1 ;
    	int L = 0, R = (int)sumB.size() - 1 ;
    	int ans = -1 ;
    	while(L <= R){
    		int mid = L + (R - L) / 2 ;
    		if ( sumB[mid] <= target ) {
    			ans = mid ;
    			L = mid + 1 ;
    		}
    		else R = mid - 1; 
    	}
    	if ( ans != -1 ) {
    		answer = max(answer, c + sumB[ans] ) ;
    	}
    }
    cout << answer << endl;
    return 0; 
}