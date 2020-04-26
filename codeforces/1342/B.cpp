#ifndef LOCAL
#pragma GCC optimize("O3")
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
bool isSub(string a, string b){
    vector<int> pos[2] ;
    for(int i = 0; i <(int) b.size(); i++){
        pos[b[i] - '0'].push_back(i) ;
    }
    int index = -1 ;
    for(int i = 0; i < (int) a.size(); i++){
        int cur = upper_bound(pos[a[i] - '0'].begin(), pos[a[i] - '0'].end(), index) - pos[a[i] - 'a'].begin() ;
        if ( cur == (int)pos[a[i] - '0'].size() ) return false;
        index = cur ;
    }
    return true ;
}
void solve(){
    string t ;
    cin >> t ;
    int m = (int) t.size() ;
    set<char> s ; 
    for(char &c : t) s.insert(c) ;
    if ( s.size() == 1 ){
        cout << t << endl;
        return ;
    }
    if ( t[0] == '0' ){
        for(int i = 0; i < 2 * m; i++){
            if ( i % 2 == 0 ){
                cout << 0 ;
            }
            else cout << 1 ; 
        }
    }
    else{
        for(int i = 0; i < 2 * m; i++){
            if ( i % 2 == 0 ){
                cout << 1 ;
            }
            else cout << 0 ; 
        }
    }
    cout << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) {
        solve() ;
    }
    return 0; 
}