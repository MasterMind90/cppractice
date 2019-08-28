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
    vector<int> v(n) ; 
    map<int,int> mp ;
    bool flag = false;
    for(int i=0;i<n;i++){
    	cin >> v[i] ; 
    	mp[v[i]]++;
    	if ( mp[v[i]] > 1 ) flag = true ;
    }
    // compressing data to fit in array giving them ids so accessing them would be O(1)
    int id = 1 ;
    for(auto &p : mp){
    	p.second = id++ ;
    }
    for(int i=0;i<n;i++){
    	v[i] = mp[v[i]] ; 
    }
    debug() << imie(v) ; 
    if ( !flag ) return cout << 0 << endl , 0;

    int ans = 1e9 + 10 ;
    for(int i=0;i<n;i++){
    	int L = i , R = n-1 ;
    	while(L<=R){
    		int mid = L + (R-L) / 2 ;
    		set<int> s ;
    		vector<int> cnt(2001) ;
    		bool ok = true ;
    		for(int j=0;j<i;j++){
    			cnt[v[j]]++;
    			if ( cnt[v[j]] > 1 ) ok = false ;
    		}
    		for(int j=mid+1;j<n;j++){
    			cnt[v[j]]++;
    			if ( cnt[v[j]] > 1 ) ok = false ;
    		}
    		if ( ok ){
    			ans = min(ans,mid - i + 1) ;
    			R = mid - 1;
    		}
    		else L = mid + 1 ;
    	}
    }
    cout << ans << endl;
    return 0 ;
}
