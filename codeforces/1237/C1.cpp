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
    int n ; 
    cin >> n ;
    vector<int> x(n) , y(n) , z(n) ; 
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> z[i] ; 
    }
    vector<int> used(n) ; 
    for(int i = 0; i < n; i++){
        if ( not used[i] ){
            used[i] = true ; 
            bool first = true ;
            int cur = 0 ;
            for(int j = 0; j < n; j++){
                if ( not used[j] ){
                    if ( first ){
                        first = false ;
                        cur = j ;
                    }
                    else{
                        if ( x[j] >= min(x[i], x[cur]) && x[j] <= max(x[i], x[cur]) && y[j] >= min(y[i], y[cur]) && y[j] <= max(y[i], y[cur]) && z[j] >= min(z[i], z[cur]) && z[j] <= max(z[i], z[cur]) ){
                            cur = j ; 
                        }
                    }
                }
            }
            used[cur] = true ;
            cout << i + 1 << ' ' << cur + 1 << endl;
        }
    }
    return 0 ;
}