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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 
const ll INF = 1e18 + 10 ; 
int main(){
    fastio
    string s ; 
    cin >> s ; 
    int n = (int) s.size() ;
    vector<vector<int> > cnt(26) ; 
    for(int i = 0; i < n; i++){
        cnt[s[i] - 'a'].push_back(i);
    }
    for(int i = 0; i < n; i++){
        vector<int> &v = cnt[s[i] - 'a'];
        int nextE = upper_bound(v.begin(), v.end(), i) - v.begin();
        int c = 1;
        for(int j = nextE; j < (int) v.size(); j++){
            int len = v[j] - i + 1;
            int half = len / 2 ;
            c++;
            if ( c > half ){
                return cout << i + 1 << ' ' << v[j] + 1 << endl, 0;
            }
        }
    }
    cout << -1 << ' ' << -1 << endl;
    return 0 ;
}