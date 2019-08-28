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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


int main(){
    fastio
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    map<int,int> mp ;
    bool flag = false;
    for(int i = 0; i < n; i++){
    	cin >> v[i] ;
    	mp[v[i]]++;
    	if ( mp[v[i]] > 1 ) flag = true ;
    }
    if ( !flag ) return cout << 0 << endl , 0;

    int ans = n ;
    for(int i = 0; i < n; i++){
        set<int> s ;
        for(int j = 0; j < i; j++){
            if ( s.find(v[j]) != s.end() ){
                i = n ;
                break;
            }
            s.insert(v[j]) ;
        }
        for(int j = n - 1; j >= i; j-- ){
            if ( s.find(v[j]) != s.end() ){
                ans = min(ans, n - (int) s.size() );
                break;
            }
            s.insert(v[j]) ;
        }
    }
    cout << ans << endl;
    return 0 ;
}
