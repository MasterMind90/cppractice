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
const ll MOD = 1e9 + 7 ;
const ll N = 1e5 + 10 ;
int main(){
    fastio
    int n , k ; 
    cin >> n >> k ; 
    vector<int> v(k + 1) ;
    vector<bool> mark(n * k + 1) ; 
    for(int i = 1; i <= k; i++){
        cin >> v[i] ; 
        mark[v[i]] = true ; 
    }
    vector<int> res ; 
    for(int i = 1; i <= n * k; i++){
        if ( !mark[i] ) res.push_back(i) ;
    }
    for(int i = 1; i <= k; i++){
        cout << v[i]; 
        for(int j = 0; j < n - 1; j++){
            cout << ' ' << res.back() ; 
            res.pop_back();
        }
        cout << endl;
    }
    return 0 ;
}