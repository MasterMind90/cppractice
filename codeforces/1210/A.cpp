#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define int long long
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
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    map<pair<int,int> ,bool> mp ; 
    for(int i = 1; i < 7; i++){
        for(int j = i; j < 7; j++){
            mp[make_pair(i, j)] = true ;
        }
    }
    int n , m ; 
    cin >> n >> m ; 
    vector<int> g[n + 1] ; 
    for(int i = 0; i < m; i++){
        int x , y ; 
        cin >> x >> y ; 
        g[x].push_back(y) ; 
        g[y].push_back(x) ;
    }
    vector<int> p ; 
    for(int i = 1; i <= n; i++){
        int val = i % 6 ; 
        val++ ; 
        p.push_back(val);
    }
    sort(p.begin(), p.end());
    debug() << imie(p) ;
    int ans = 0 ;
    do{
        vector<int> val(n + 1) ; 
        for(int i = 0; i < n; i++){
            val[i + 1] = p[i] ; 
        }
        map<pair<int,int>, bool> tmp = mp; 
        int cnt = 0 ; 
        for(int i = 1; i <= n; i++){
            for(int c : g[i]){
                if ( tmp[make_pair(val[i], val[c])] == true ){
                    cnt++ ; 
                    tmp[make_pair(val[i], val[c])] = false;
                }
            }
        }
        ans = max(ans, cnt) ;
    }while(next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0; 
}