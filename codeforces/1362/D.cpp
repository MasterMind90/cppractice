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
// #define int long long
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
    vector<vector<int> > g(n + 1) ; 
    for(int i = 0; i < m; i++){
        int x , y ;
        cin >> x >> y ; 
        g[x].push_back(y) ; 
        g[y].push_back(x) ; 
    }
    vector<int> t(n + 1) ;
    priority_queue<pair<int,int> > q ;
    for(int i = 1; i < n + 1; i++){
        int x ;
        cin >> x ;
        t[i] = x;
        q.push(make_pair(-x, i));
    }
    vector<int> ans ;
    while(not q.empty()){
        ans.push_back(q.top().second);
        q.pop() ;
    }
    debug() << imie(ans) ;
    bool ok = true ;
    vector<int> done(n + 1, 0) ;
    for(int i = 0; i < n; i++){
        int currentBlog = ans[i] ;
        done[currentBlog] = 1 ;
        set<int> s ;
        for(int &c : g[currentBlog]){
            if ( done[c] ){
                s.insert(t[c]) ;
            }
        }
        if ( s.empty() ){
            if ( t[currentBlog] != 1 ) {
                ok = false ;
                break ;
            }
        }
        else{
            auto it = s.end() ;
            it--;
            if ( (int)s.size() != t[currentBlog] - 1 ||  *it != t[currentBlog] - 1 ){
                ok = false ;
                break ;
            }
        }
        
    }
    if ( not ok ) {
        cout << -1 << endl;
    }
    else{
        for(int &c : ans){
            cout << c << ' ';
        }
        cout << endl;
    }
    return 0; 
}